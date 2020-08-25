/**
 ****************************************************************************
 * @file	 interrupt.c
 * @brief	 VE Interrupt Functions
 * @version	 V1.0
 *****************************************************************************
 */
#include <stdlib.h>

#include "ipdefine.h"
#include "calc.h"

#include "mcuip_drv_ave.h"

#include "D_Driver.h"
#include "usercon.h"

#define DEFINE_APP
#include "interrupt.h"
#undef	DEFINE_APP


/**
 *********************************************************************************************
 * @brief		INT_interval_4kHz
 *
 * @return		none
 *********************************************************************************************
 */
void INT_interval_4kHz(void)
{
	M_Main_Counter++;									/* Count for main routine Period */

}

/**
 *********************************************************************************************
 * @brief		INTVCN1
 *
 * @return		none
 *********************************************************************************************
 */
void INTVCN1(void)
{

#if defined(__CONTROL_MOTOR_CH1)
	vector_t* const _motor = &Motor_ch1;
	TSB_VE_TypeDef* const VEx = TSB_VE1;

#if (__FIXED_VDC_CH1 == 1)								/* 1: Vdc from constant data */
	/***** Set Vdc data to VE *****/
	VE_SetVDCreg(VEx, cCH1, (q15_t)(FIX_15 * cVDC_CH1 / cV_MAX_CH1));
#endif

	/***** Get data from VE register *****/
	VE_GetdataFromVEreg(VEx, cCH1, _motor);

	/***** Check over current *****/
	VE_GetPhaseCurrent(VEx, cCH1, &_motor->drv.Ia, &_motor->drv.Ib, &_motor->drv.Ic);
	if (D_Check_OverCurrent(_motor->para.err_ovc, _motor->drv.Ia, _motor->drv.Ib, _motor->drv.Ic))
	{
		_motor->drv.state.flg.emg_S = SET;
		_motor->stage.itr = ciEmergency;
	}

	/***** Check over voltage *****/
	if ((_motor->drv.Vdc < (q15_t)(FIX_15 * cVDC_MINLIM_CH1 / cV_MAX_CH1)) || ((q15_t)(FIX_15 * cVDC_MAXLIM_CH1 / cV_MAX_CH1) < _motor->drv.Vdc))
	{
		_motor->drv.state.flg.emg_DC = SET;
		_motor->stage.itr = ciEmergency;
	}

#if defined(__USE_CHECK_IERROR)
	/***** Check Id Error *****/
	if (check_id_error(_motor, &shnterr1))
	{
		_motor->drv.state.flg.emg_I = SET;
		_motor->stage.itr = ciEmergency;
	}
#endif /* __USE_CHECKID */


	if (_motor->drv.state.all == 0)						/* No error? */
	{
		/***** Detect Rotor Position *****/
		D_Detect_Rotor_Position(_motor);

#if defined(__USE_ENCODER_CH1)
		/***** Encoder *****/
		H_Encoder(_motor, TSB_EN1);
#endif /* __USE_ENCODER_CH1 */

		/***** Control Speed *****/
		_motor->drv.spdprd++;
		if (_motor->drv.spdprd >= cSPD_PI_PRD_CH1)
		{
			_motor->drv.spdprd = 0;
			D_Control_Speed(_motor);
		}

	}


	/**** Set data to VE register *****/
	/* Set modulation type */
	VE_SetModulType(VEx, cCH1, _motor->drv.command.modul);

	switch (_motor->stage.itr)
	{
			/*--- Stop Stage -----------------------------*/
		case ciStop:
			VE_SetdataToVEreg_Stop(VEx, cCH1, _motor);
            break;

			/*--- Bootstrap Stage ------------------------*/
		case ciBootstrap:
			VE_SetdataToVEreg_Bootstrap(VEx, cCH1, _motor);
			break;

			/*--- Position Stage (Current type) ----------*/
		case ciInitposition_i:
			VE_SetdataToVEreg_Initposition_i(VEx, cCH1, _motor);
			break;

			/*--- Position Stage (Voltage type) ----------*/
		case ciInitposition_v:
			VE_SetdataToVEreg_Initposition_v(VEx, cCH1, _motor);
			break;

			/*--- Force Stage (Current type) -------------*/
		case ciForce_i:
			VE_SetdataToVEreg_Force_i(VEx, cCH1, _motor);
			break;

			/*--- Force Stage (Voltage type) -------------*/
		case ciForce_v:
			VE_SetdataToVEreg_Force_v(VEx, cCH1, _motor);
			break;

			/*--- ChangeUp Stage -------------------------*/
		case ciChange_up:
			VE_SetdataToVEreg_Change_up(VEx, cCH1, _motor);
			break;

			/*--- Steady_A Stage ---------------------------*/
		case ciSteady_A:
			VE_SetdataToVEreg_Steady_A(VEx, cCH1, _motor);
			break;

			/*--- Emergency Stage ------------------------*/
		case ciEmergency:
			VE_SetdataToVEreg_Emergency(VEx, cCH1, _motor);
			break;
			/*--- Fail-safe ------------------------*/
		default:
			VE_SetdataToVEreg_Stop(VEx, cCH1, _motor);
			break;
	}

#if defined(__USE_DAC)
	UiOutDataStart(1);									/* Dac output for debug */
#endif /* __USE_DAC */

	VE_Start(VEx, cCH1);

#endif /* __CONTROL_MOTOR_CH1 */

}



/**
 *********************************************************************************************
 * @brief		Vector Engine Interruption ch0
 *
 * @return		none
 *********************************************************************************************
 */
void INTVCN0(void)
{
#if defined(__CONTROL_MOTOR_CH0)

	vector_t* const _motor = &Motor_ch0;
	TSB_VE_TypeDef* const VEx = TSB_VE0;

#if (__FIXED_VDC_CH0 == 1)								/* 1: Vdc from constant data */
	/***** Set Vdc data to VE *****/
	VE_SetVDCreg(VEx, cCH0, (q15_t)(FIX_15 * cVDC_CH0 / cV_MAX_CH0));
#endif

	/***** Get data from VE register *****/
	VE_GetdataFromVEreg(VEx, cCH0, _motor);

	/***** Check over current *****/
	VE_GetPhaseCurrent(VEx, cCH0, &_motor->drv.Ia, &_motor->drv.Ib, &_motor->drv.Ic);
	if (D_Check_OverCurrent(_motor->para.err_ovc, _motor->drv.Ia, _motor->drv.Ib, _motor->drv.Ic))
	{
		_motor->drv.state.flg.emg_S = SET;
		_motor->stage.itr = ciEmergency;
	}

	/***** Check over voltage *****/
	if ((_motor->drv.Vdc < (q15_t)(FIX_15 * cVDC_MINLIM_CH0 / cV_MAX_CH0)) || ((q15_t)(FIX_15 * cVDC_MAXLIM_CH0 / cV_MAX_CH0) < _motor->drv.Vdc))
	{
		_motor->drv.state.flg.emg_DC = SET;
		_motor->stage.itr = ciEmergency;
	}

#if defined(__USE_CHECK_IERROR)
	/***** Check Id Error *****/
	if (check_id_error(_motor, &shnterr0))
	{
		_motor->drv.state.flg.emg_I = SET;
		_motor->stage.itr = ciEmergency;
	}
#endif /* __USE_CHECKID */


	if (_motor->drv.state.all == 0)						/* No error? */
	{
		/***** Detect Rotor Position *****/
		D_Detect_Rotor_Position(_motor);

#if defined(__USE_ENCODER_CH0)
		/***** Encoder *****/
		H_Encoder(_motor, TSB_EN0);
#endif /* __USE_ENCODER_CH1 */

		/***** Control Speed *****/
		_motor->drv.spdprd++;
		if (_motor->drv.spdprd >= cSPD_PI_PRD_CH0)
		{
			_motor->drv.spdprd = 0;
			D_Control_Speed(_motor);
		}

		/***** Cal Vdq *****/
		_motor->drv.Vdq = Cal_Vdq(_motor->drv.Vd.half[1], _motor->drv.Vq.half[1]);

		_motor->drv.Vdq_ave.word = calc_ave(_motor->drv.Vdq_ave.word , _motor->drv.Vdq << 16 , cVDQ_AVE);
		_motor->drv.Vdc_ave.word = calc_ave(_motor->drv.Vdc_ave.word , _motor->drv.Vdc << 16 , cVDQ_AVE);
	}


	/**** Set data to VE register *****/
	/* Set modulation type */
	VE_SetModulType(VEx, cCH0, _motor->drv.command.modul);

	switch (_motor->stage.itr)
	{
			/*--- Stop Stage -----------------------------*/
		case ciStop:
			VE_SetdataToVEreg_Stop(VEx, cCH0, _motor);
			break;

			/*--- Bootstrap Stage ------------------------*/
		case ciBootstrap:
			VE_SetdataToVEreg_Bootstrap(VEx, cCH0, _motor);
			break;

			/*--- Position Stage (Current type) ----------*/
		case ciInitposition_i:
			VE_SetdataToVEreg_Initposition_i(VEx, cCH0, _motor);
			break;

			/*--- Position Stage (Voltage type) ----------*/
		case ciInitposition_v:
			VE_SetdataToVEreg_Initposition_v(VEx, cCH0, _motor);
			break;

			/*--- Force Stage (Current type) -------------*/
		case ciForce_i:
			VE_SetdataToVEreg_Force_i(VEx, cCH0, _motor);
			break;

			/*--- Force Stage (Voltage type) -------------*/
		case ciForce_v:
			VE_SetdataToVEreg_Force_v(VEx, cCH0, _motor);
			break;

			/*--- ChangeUp Stage -------------------------*/
		case ciChange_up:
			VE_SetdataToVEreg_Change_up(VEx, cCH0, _motor);
			break;

			/*--- Steady_A Stage ---------------------------*/
		case ciSteady_A:
			VE_SetdataToVEreg_Steady_A(VEx, cCH0, _motor);
			break;

			/*--- Emergency Stage ------------------------*/
		case ciEmergency:
			VE_SetdataToVEreg_Emergency(VEx, cCH0, _motor);
			break;
			/*--- Fail-safe ------------------------*/
		default:
			VE_SetdataToVEreg_Stop(VEx, cCH0, _motor);
			break;
	}

#if defined(__USE_DAC)
	UiOutDataStart(0);									/* Dac output for debug */
#endif /* __USE_DAC */

	VE_Start(VEx, cCH0);

#endif /* __CONTROL_MOTOR_CH0 */

}

/*********************************** END OF FILE ******************************/
