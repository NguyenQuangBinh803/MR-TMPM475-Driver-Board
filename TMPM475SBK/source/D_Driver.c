/**
 ****************************************************************************
 * @file	 D_Driver.c
 * @brief	 Motor vector control driver Source File
 * @version	 V1.0
 *****************************************************************************
 */
#include <stdlib.h>
#include "ipdefine.h"
#include "mcuip_drv_ave.h"
#include "D_Para.h"

#include "tmpm475_enc.h"
#include "tmpm475_adc.h"


#define DEFINE_APP
#include "D_Driver.h"
#undef	DEFINE_APP


/**
 *********************************************************************************************
 * @brief		H_Encoder
 *				Adjust Z-phase, 0deg of electrical-angle
 * @param		vector_t* const			_motor	The structure address for motor vector control.
 * @param		TSB_EN_TypeDef * const	ENx		Select the encoder channel.
 *
 * @return		none
 *********************************************************************************************
 */
#if defined(__USE_ENCODER_CH1) || defined(__USE_ENCODER_CH0)
void H_Encoder(vector_t* const _motor, TSB_EN_TypeDef* const ENx)
{
	ENC_FlagStatus	EncFlg;

	EncFlg = ENC_GetENCFlag(ENx);

	/* Phase Z is detected? */
	if (EncFlg.Bit.ZPhaseDetectFlag == SET)
	{
		/* Get Encoder counter value */
		_motor->drv.EnCnt = ENC_GetCounterValue(ENx);
	}

	/* Calculation theta(electrical-angle) from encoder counter */
	_motor->drv.theta_enc = (uint16_t)((_motor->drv.EnCnt * _motor->para.enc.pls2theta) + _motor->para.enc.deg_adjust);

	if (EncFlg.Bit.RotationDirection == 1)
	{
		/* CW */
		if (_motor->drv.EnCnt >= _motor->drv.EnCnt1)
		{
			_motor->drv.EnCnt_dev = (q15_t)(_motor->drv.EnCnt - _motor->drv.EnCnt1);
		}
		else
		{
			_motor->drv.EnCnt_dev = (q15_t)(_motor->para.enc.plsnum + _motor->drv.EnCnt - _motor->drv.EnCnt1);
		}
	}
	else
	{
		/* CCW */
		if (_motor->drv.EnCnt1 >= _motor->drv.EnCnt)
		{
			_motor->drv.EnCnt_dev = (q15_t)((_motor->drv.EnCnt1 - _motor->drv.EnCnt) * (-1));
		}
		else
		{
			_motor->drv.EnCnt_dev = (q15_t)((_motor->para.enc.plsnum + _motor->drv.EnCnt1 - _motor->drv.EnCnt) * (-1));
		}
	}

	_motor->drv.EnCnt1 = _motor->drv.EnCnt;

	/* Cal omega(electrical-angle) from encoder counter deviation */
	_motor->drv.omega_enc_raw = (q15_t)(_motor->drv.EnCnt_dev * _motor->para.enc.pls2omega);
	_motor->drv.omega_enc_ave.word = calc_ave(_motor->drv.omega_enc_ave.word, _motor->drv.omega_enc_raw << 16 , cOMEGAENC_AVE);
	_motor->drv.omega_enc = _motor->drv.omega_enc_ave.half[1];

	if (_motor->drv.command.encoder == SET)
	{
		_motor->drv.omega.word = _motor->drv.omega_enc << 16;

		if (_motor->drv.vector_cmd.F_vcomm_theta == SET)
		{
			if (_motor->drv.vector_cmd.F_vcomm_omega == SET)
			{
				if (EncFlg.Bit.ZPhaseDetectFlag == 1)
				{
					/* Phase Z is detected */
					_motor->drv.theta.word = (_motor->drv.theta_enc << 16);
				}
				else
				{
					/* THETAn = THETAn-1 + OMEGA * t */
					/* theta = (omega * 2^16 * HZ_MAX) * Control period */
					_motor->drv.theta.word += ((_motor->drv.omega_com.half[1] * _motor->para.enc.ctrlprd) << 1);
				}
			}
			else
			{
				_motor->drv.theta.word += (_motor->drv.omega_com.half[1] * _motor->para.enc.ctrlprd) << 1;
			}
		}
		else
		{
			if (EncFlg.Bit.ZPhaseDetectFlag == 1)
			{
				/* Phase Z is detected */
				_motor->drv.theta.word = (_motor->drv.theta_enc << 16);
			}
			else
			{
				_motor->drv.theta.word = (_motor->drv.theta_com << 16);
			}
		}
	}
}
#endif /* __USE_ENCODER */

/**
 *********************************************************************************************
 * @brief		Detect _motor position
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void D_Detect_Rotor_Position(vector_t* const _motor)
{

	q31_t temp32_r, temp32_Lq;
	q31_t temp32_OmegaErrI, temp32_OmegaErrP;
	q31_t omega_calc;

	/**
	 * @note	Voltage equation
	 * 			Vd = R¥Id + Ld¥pId - OMEGA-est¥Lq + Ed
	 * 			  (p = d/dt, IdàConstant value -> pId = 0)
	 */
	if (_motor->drv.vector_cmd.F_vcomm_Edetect == SET)
	{
		/* Voltage drop of resistance	 V = R * I */
		temp32_r = (_motor->para.motor.r * (q31_t)_motor->drv.Id) << 1;


		/* Voltage drop of inductance	 V = 2ƒÎfL * I */
		temp32_Lq = (((_motor->drv.omega.half[1] * _motor->para.motor.Lq) << 1) + cROUND_BIT15) >> 16;	/* Q15 * Q15 -> Q15 */
		temp32_Lq = (temp32_Lq * _motor->drv.Iq) << 1;													/* Q15 * Q15 -> Q31 */

		/* d-axis induced voltage */
		/* Ed = Vd - R¥Id + OMEGA-est¥Lq */
		_motor->drv.Ed = (q15_t)((_motor->drv.Vd.word - temp32_r + temp32_Lq + cROUND_BIT15) >> 16);

		/**
		 * @note	OMEGAest = OMEGAref - K¥Ed
		 */
		/* Set integration value */
		/* OmegaErr(I) * Hz_MAX = FIX_15 * Position_Ki * CtrlPrd * Ed * V_MAX */
		temp32_OmegaErrI = (_motor->para.pos.ki * (q31_t)_motor->drv.Ed) << 1;

		if (_motor->drv.omega_com.half[1] >= 0)
		{
			_motor->drv.Ed_I = __QSUB(_motor->drv.Ed_I, temp32_OmegaErrI);
		}
		else
		{
			_motor->drv.Ed_I = __QADD(_motor->drv.Ed_I, temp32_OmegaErrI);
		}

		/* Set proportionality value */
		/* OmegaErr(P) * Hz_MAX = FIX_15 * Position_Kp * Ed * V_MAX */
		temp32_OmegaErrP = (_motor->para.pos.kp * (q31_t)_motor->drv.Ed) << 1;

		if (_motor->drv.omega_com.half[1] >= 0)
		{
			_motor->drv.Ed_PI = __QSUB(_motor->drv.Ed_I, temp32_OmegaErrP);
		}
		else
		{
			_motor->drv.Ed_PI = __QADD(_motor->drv.Ed_I, temp32_OmegaErrP);
		}

		/* Speed calculation value = Speed command value + Error PI value */
		omega_calc = __QADD(_motor->drv.omega_com.word, _motor->drv.Ed_PI);

		if (_motor->drv.vector_cmd.F_vcomm_omega == SET)
		{
			if (_motor->drv.command.encoder == CLEAR)
			{
				_motor->drv.omega.word = omega_calc;
			}
		}
		else
		{
			/* Initialize of proportionality value, integration value and Omega */
			_motor->drv.omega.word = _motor->drv.omega_com.word;
			_motor->drv.Ed_I = 0;
			_motor->drv.Ed_PI = 0;
		}

		/* Position estimation */
		if (_motor->drv.vector_cmd.F_vcomm_theta == SET)
		{
			if (_motor->drv.command.encoder == CLEAR)
			{
				/* estimated THETAn = THETAn-1 + OMEGA * t */
				_motor->drv.theta.word += ((_motor->drv.omega.half[1] * _motor->para.pos.ctrlprd) << 1);
			}
		}
		else
		{
			_motor->drv.theta.word = (q31_t)(_motor->drv.theta_com << 16);
		}
	}
	else
	{
		_motor->drv.theta.word = (q31_t)(_motor->drv.theta_com << 16);
		_motor->drv.Ed = 0;
	}
}

/**
 *********************************************************************************************
 * @brief		Speed control ( Caricurate q-axis current )
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void D_Control_Speed(vector_t* const _motor)
{
	/* Determination of R_Iq_ref */
	if (_motor->drv.vector_cmd.F_vcomm_current == SET)
	{
		q31_t temp32_PI;
		q31_t temp_iqref;

		/* Speed deviation */
		_motor->drv.omega_dev = (q15_t)(__QSUB(_motor->drv.omega_com.word, _motor->drv.omega.word) >> 16);

		/* Set proportionality value */
		temp32_PI = ((q31_t)_motor->para.spd.ki * _motor->drv.omega_dev) << 1;

		_motor->drv.Iq_ref_I.word = __QADD(_motor->drv.Iq_ref_I.word, temp32_PI);

		/* Limit value excess */
		if (_motor->drv.Iq_ref_I.word > _motor->para.iq_lim)
		{
			_motor->drv.Iq_ref_I.word = _motor->para.iq_lim;
		}
		else if (_motor->drv.Iq_ref_I.word < -_motor->para.iq_lim)
		{
			_motor->drv.Iq_ref_I.word = -_motor->para.iq_lim;
		}


		/* Set integration value */
		temp32_PI = (_motor->para.spd.kp * _motor->drv.omega_dev) << 1;

		temp_iqref = __QADD(_motor->drv.Iq_ref_I.word, temp32_PI);
		/* Limit value excess */
		if (temp_iqref > _motor->para.iq_lim)
		{
			_motor->drv.Iq_ref = (q15_t)(_motor->para.iq_lim >> 16);
		}
		else if (temp_iqref < -_motor->para.iq_lim)
		{
			_motor->drv.Iq_ref = (q15_t)(-_motor->para.iq_lim >> 16);
		}
		else
		{
			_motor->drv.Iq_ref = temp_iqref >> 16;
		}
	}
	else
	{
		/* Without Speed control. R_Iq_com -> R_Iq_ref */
		if (abs(_motor->drv.Iq_com.word) >= _motor->para.iq_lim)
		{
			/* Limit value excess */
			if (_motor->drv.Iq_com.word >= 0)
			{
				_motor->drv.Iq_ref = (q15_t)(_motor->para.iq_lim >> 16);
				_motor->drv.Iq_ref_I.word = _motor->para.iq_lim;
			}
			else
			{
				_motor->drv.Iq_ref = (q15_t)(-_motor->para.iq_lim >> 16);
				_motor->drv.Iq_ref_I.word = -_motor->para.iq_lim;
			}
		}
		else
		{
			/* Initialize of proportionality value and integration value */
			_motor->drv.Iq_ref = _motor->drv.Iq_com.half[1];
			_motor->drv.Iq_ref_I.word = _motor->drv.Iq_com.word;
		}

	}

	/* Determination of R_Id_ref */
	if (abs(_motor->drv.Id_com.word) >= _motor->para.id_lim)
	{
		/* Limit value excess */
		if (_motor->drv.Id_com.word >= 0)
		{
			_motor->drv.Id_ref = (q15_t)(_motor->para.id_lim >> 16);
		}
		else
		{
			_motor->drv.Id_ref = (q15_t)(-_motor->para.id_lim >> 16);
		}
	}
	else
	{
		_motor->drv.Id_ref = _motor->drv.Id_com.half[1];
	}

}


/**
 *********************************************************************************************
 * @brief		D_SetZeroCurrent
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void	D_SetZeroCurrent(vector_t* const _motor, uint8_t _ch)
{

	if (_motor->stage.main == cStop)
	{
		uint32_t	adc_ia, adc_ib, adc_ic;
		TSB_VE_TypeDef* pVE;

		if (_ch == cCH1)
		{
			pVE = TSB_VE1;
		}
		else
		{
			pVE = TSB_VE0;
		}

		VE_GetCurrentAdcData(pVE, _ch, &adc_ia, &adc_ib, &adc_ic);
		_motor->drv.Iao_ave += (((int32_t)(adc_ia << 16) - _motor->drv.Iao_ave) >> cIXO_AVE);
		_motor->drv.Ibo_ave += (((int32_t)(adc_ib << 16) - _motor->drv.Ibo_ave) >> cIXO_AVE);
		_motor->drv.Ico_ave += (((int32_t)(adc_ic << 16) - _motor->drv.Ico_ave) >> cIXO_AVE);

		VE_SetZeroCurrentData(pVE, _ch, _motor->drv.Iao_ave >> 16, _motor->drv.Ibo_ave >> 16, _motor->drv.Ico_ave >> 16);
	}
}

/**
 *********************************************************************************************
 * @brief		Check over current.
 *
 * @param		q15_t			_ovc	current of over error value.
 * @param		q15_t			_iu		current of u phase.
 * @param		q15_t			_iv		current of v phase.
 * @param		q15_t			_iw		current of w phase.
 *
 * @return		bool	TRUE:Over current / FALSE:Nomal
 *********************************************************************************************
 */
bool D_Check_OverCurrent(q15_t _ovc, q15_t _iu, q15_t _iv, q15_t _iw)
{
	if ((abs(_iu) > _ovc)
	    || (abs(_iv) > _ovc)
	    || (abs(_iw) > _ovc))
	{
		return (true);
	}
	else
	{
		return (false);
	}
}


/*********************************** END OF FILE ******************************/
