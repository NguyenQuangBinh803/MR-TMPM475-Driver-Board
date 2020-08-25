/**
 ****************************************************************************
 * @file	 C_Control.c
 * @brief	 Motor vector control Source File
 * @version  V1.0
 *****************************************************************************
 */
#include <stdlib.h>

#include "ipdefine.h"
#include "D_Para.h"
#include "E_Sub.h"
#include "calc.h"

#include "tmpm475_enc.h"

#include "nguyen_uart.h"
#include "nguyen_motor_app.h"
#define DEFINE_APP
#include "C_Control.h"
#undef DEFINE_APP



/**
 *********************************************************************************************
 * @brief		Control RefModel function.
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void C_Control_Ref_Model(vector_t* const _motor)
{
    
#ifdef DEBUG_UART
    char strtmp[] = "                                           ";
    static main_stage_e tempState;
    if(tempState != _motor->stage.main){
        if(Is_Uart_Ready_To_Send()){
            tempState = _motor->stage.main;
            sprintf((char*) strtmp, "tempState = %d\r\n", (int)tempState);
            Send_Data_To_PC(strtmp);
        }
    }
#endif
	if (_motor->usr.com_user.onoff == CLEAR)
	{
		_motor->stage.main = cStop;							/* Set STOP Stage */
		_motor->stage.sub = cStep0;
	} 
    
	else if (_motor->drv.state.all != 0)
	{
		_motor->stage.main = cEmergency;					/* Set Emergency Stage */
		_motor->stage.sub = cStep0;
	}
    
	else if ((_motor->usr.com_user_1.onoff == CLEAR) && (_motor->usr.com_user.onoff == SET))
	{
		_motor->stage.main = cBootstrap;					/* Set bootstrap Stage */
		_motor->stage.sub = cStep0;
	}
	else if ((_motor->stage.main == cBootstrap) && (_motor->stage.sub == cStepEnd))
	{
		_motor->stage.main = cInitposition;					/* Set positioning Stage */
		_motor->stage.sub = cStep0;
	}
	else if ((_motor->stage.main == cInitposition) && (_motor->stage.sub == cStepEnd))
	{
		_motor->stage.main = cForce;						/* Set Force Stage */
		_motor->stage.sub = cStep0;
	}
	else if ((_motor->stage.main == cForce) && (_motor->stage.sub == cStepEnd))
	{
		_motor->stage.main = cChange_up;					/* Set change-up Stage */
		_motor->stage.sub = cStep0;
	}
	else if ((_motor->stage.main == cChange_up) && (_motor->stage.sub == cStepEnd))
	{
		_motor->stage.main = cSteady_A;						/* Set Steady Stage */
		_motor->stage.sub = cStep0;
	}
    //nguyen
    else if(_motor->stage.main == cSteady_A && _motor->drv.omega_com.word == 0){
        _motor->stage.main = cBootstrap;					/* Set bootstrap Stage */
		_motor->stage.sub = cStep0;
    }
    //nguyen
	_motor->usr.com_user_1 = _motor->usr.com_user;			/* Save user command */
}


/**
 *********************************************************************************************
 * @brief		Common function
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void C_Common(vector_t* const _motor)
{
	/* Option setting */
	_motor->drv.command.encoder = _motor->usr.com_user.encoder;
	_motor->drv.command.modul = _motor->usr.com_user.modul;

	/***** Cal Vdq *****/
	_motor->drv.Vdq = Cal_Vdq(_motor->drv.Vd.half[1], _motor->drv.Vq.half[1]);

	_motor->drv.Vdq_ave.word = calc_ave(_motor->drv.Vdq_ave.word , _motor->drv.Vdq << 16 , cVDQ_AVE);
	_motor->drv.Vdc_ave.word = calc_ave(_motor->drv.Vdc_ave.word , _motor->drv.Vdc << 16 , cVDQ_AVE);
}


/**
 *********************************************************************************************
 * @brief		Stop stage function.
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void C_Stage_Stop(vector_t* const _motor)
{
	vectorcmd_t cmdbuf;

	if (_motor->stage.main == cStop)
	{
		switch (_motor->stage.sub)
		{
			case cStep0:
				_motor->stage.sub = cStep1;
				cmdbuf.F_vcomm_theta = CLEAR;
				cmdbuf.F_vcomm_omega = CLEAR;
				cmdbuf.F_vcomm_current = CLEAR;
				cmdbuf.F_vcomm_Edetect = CLEAR;
				/*cmdbuf.F_vcomm_onoff = CLEAR; */
				__disable_irq();
				_motor->drv.vector_cmd = cmdbuf;
				_motor->stage.itr = ciStop;
				_motor->drv.theta_com = 0;
				_motor->drv.theta.word = 0;
				_motor->drv.omega_com.word = 0;
				_motor->drv.omega.word = 0;

				__enable_irq();

				_motor->drv.omega_com.word = 0;
				_motor->drv.Id_com.word = 0;
				_motor->drv.Iq_com.word = 0;
				break;
			case cStep1:
				break;
			default:
				break;
		}
	}
}


/**
 *********************************************************************************************
 * @brief		Emergency stage function.
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void C_Stage_Emergency(vector_t* const _motor)
{
	vectorcmd_t cmdbuf;

	if (_motor->stage.main == cEmergency)
	{
		switch (_motor->stage.sub)
		{
			case cStep0:
				cmdbuf.F_vcomm_theta = CLEAR;
				cmdbuf.F_vcomm_omega = CLEAR;
				cmdbuf.F_vcomm_current = CLEAR;
				cmdbuf.F_vcomm_Edetect = CLEAR;
				/*cmdbuf.F_vcomm_onoff = CLEAR; */
				__disable_irq();
				_motor->drv.vector_cmd = cmdbuf;
				_motor->stage.itr = ciEmergency;
				__enable_irq();
				_motor->stage.sub = cStep1;
				break;
			default:
				break;
		}
	}
}


/**
 *********************************************************************************************
 * @brief		Bootstrap stage function.
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void C_Stage_Bootstrap(vector_t* const _motor)
{
	if (_motor->stage.main == cBootstrap)
	{
		switch (_motor->stage.sub)
		{
			case cStep0:
				__disable_irq();
				_motor->stage.itr = ciBootstrap;
				__enable_irq();
				_motor->stage_counter = 0;

				_motor->stage.sub = cStep1;
				/* No break. Continue to the next statements. */

			case cStep1:
				_motor->stage_counter++;
				if (_motor->stage_counter >= _motor->para.time.bootstp)
				{
					_motor->stage.sub = cStepEnd;
				}
				break;

			default:
				break;
		}
	}
}


/**
 *********************************************************************************************
 * @brief		Initposition stage function.
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void C_Stage_Initposition(vector_t* const _motor)
{
	vectorcmd_t cmdbuf;

	if (_motor->stage.main == cInitposition)
	{
		switch (_motor->stage.sub)
		{
			case cStep0:
				cmdbuf.F_vcomm_theta = CLEAR;
				cmdbuf.F_vcomm_omega = CLEAR;
				cmdbuf.F_vcomm_current = CLEAR;
				cmdbuf.F_vcomm_Edetect = CLEAR;
				/*cmdbuf.F_vcomm_onoff = SET; */
				__disable_irq();
				_motor->drv.vector_cmd = cmdbuf;
				(_motor->boot_type == cBoot_v) ? (_motor->stage.itr = ciInitposition_v) : (_motor->stage.itr = ciInitposition_i);
				_motor->drv.Vd_out = 0;							/* for Volt control */
				__enable_irq();
				_motor->stage_counter = 0;
				_motor->drv.omega_com.word = 0;
				_motor->drv.Iq_com.word = 0;
				_motor->drv.Id_com.word = 0;
				/*_motor->drv.Id_com.word = abs(_motor->usr.Id_st_user) << 16;	*/	/* for PI debug */
				_motor->drv.theta_com = _motor->usr.lambda_user;
				_motor->stage.sub = cStep1;
				/* No break. Continue to the next statements. */

			case cStep1:
				_motor->drv.Id_com.word += (abs(_motor->usr.Id_st_user) << 16) / _motor->para.time.initpos;

				if (_motor->drv.Id_com.word > abs(_motor->usr.Id_st_user) << 16)
				{
					_motor->drv.Id_com.word = abs(_motor->usr.Id_st_user) << 16;
				}

				if (_motor->boot_type == cBoot_v)
				{
					_motor->drv.Vd_out += _motor->para.vd_pos / _motor->para.time.initpos;


					if (_motor->drv.Vd_out > _motor->para.vd_pos)
					{
						_motor->drv.Vd_out = _motor->para.vd_pos;
					}
				}

				/* trans stage */
				_motor->stage_counter++;
				if (_motor->stage_counter >= _motor->para.time.initpos)
				{
					_motor->drv.Id_com.word = abs(_motor->usr.Id_st_user) << 16;
					_motor->drv.Vd_out = _motor->para.vd_pos;	/* for Volt control */

					if (_motor->para.time.initpos == 0)			/* no wait? */
					{
						_motor->stage.sub = cStepEnd;
					}
					else
					{
						_motor->stage_counter = 0;
						_motor->stage.sub = cStep2;
					}

				}
				break;

			case cStep2:
				_motor->stage_counter++;
				if (_motor->stage_counter >= _motor->para.time.initpos2)
				{
					_motor->stage.sub = cStepEnd;
				}
				break;

			case cStepEnd:
				break;

			default:
				break;
		}
	}
}



/**
 *********************************************************************************************
 * @brief		Force stage function.
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void C_Stage_Force(vector_t* const _motor)
{
	vectorcmd_t cmdbuf;

	if (_motor->stage.main == cForce)
	{
		switch (_motor->stage.sub)
		{
			case cStep0:
				cmdbuf.F_vcomm_theta = SET;
				cmdbuf.F_vcomm_omega = CLEAR;
				cmdbuf.F_vcomm_current = CLEAR;
				cmdbuf.F_vcomm_Edetect = SET;
				/*cmdbuf.F_vcomm_onoff = SET; */
				__disable_irq();
				_motor->drv.vector_cmd = cmdbuf;
				(_motor->boot_type == cBoot_v) ? (_motor->stage.itr = ciForce_v) : (_motor->stage.itr = ciForce_i);
				_motor->drv.Iq_com.word = 0;
				_motor->drv.Id_com.word = abs(_motor->usr.Id_st_user) << 16;
				__enable_irq();
				_motor->stage.sub = cStep1;
				/* No break. Continue to the next statements. */

			case cStep1:
				if (_motor->boot_type == cBoot_v)
				{
					if (abs(_motor->drv.omega_com.half[1]) < _motor->para.omega_v2i)
					{
						q31_t	vd_add;
						vd_add = (abs(_motor->drv.omega_com.half[1]) * _motor->para.spd_coef) << 1;
						_motor->drv.Vd_out = vd_add + _motor->para.vd_pos;
					}
					else
					{
						_motor->stage.itr = ciForce_i;			/* current control */
					}
				}

				/* If reach minimum frequency, it change to cStepEnd */
				if (abs(_motor->drv.omega_com.half[1]) >= _motor->para.omega_min)
				{
					_motor->stage.sub = cStepEnd;
				}

				/* No break. Continue to the next statements. */

			case cStepEnd:
				/* Update drive frequency. */
				_motor->drv.omega_com.word = C_command_limit_sub(_motor->drv.omega_com.word,
				                             _motor->usr.omega_user.word,
				                             _motor->para.sp_ud_lim_f.word,
				                             _motor->para.sp_ud_lim_f.word);
				break;
			default:
				break;
		}
	}
}



/**
 *********************************************************************************************
 * @brief		Change_up stage function.
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void C_Stage_Change_up(vector_t* const _motor)
{
	vectorcmd_t cmdbuf;
	q31_t id_temp, iq_temp;
	static q31_u S_lambda_cal;

	if (_motor->stage.main == cChange_up)
	{
		switch (_motor->stage.sub)
		{
			case cStep0:
				_motor->stage.sub = cStep1;
				S_lambda_cal.word = 0;
				cmdbuf.F_vcomm_theta = SET;
				cmdbuf.F_vcomm_omega = SET;
				cmdbuf.F_vcomm_current = CLEAR;
				cmdbuf.F_vcomm_Edetect = SET;
				/*cmdbuf.F_vcomm_onoff = SET; */
				__disable_irq();
				_motor->drv.vector_cmd = cmdbuf;
				_motor->stage.itr = ciChange_up;
				__enable_irq();
				/* No break. Continue to the next statements. */

			case cStep1:
				S_lambda_cal.word += _motor->para.delta_lambda;

				if (S_lambda_cal.word > (ELE_DEG(90) << 16))
				{
					S_lambda_cal.word = ELE_DEG(90) << 16;
				}
				id_temp = (_motor->usr.Id_st_user * E_Cosine(S_lambda_cal.half[1])) << 1;
				iq_temp = (_motor->usr.Iq_st_user * E_Sine(S_lambda_cal.half[1])) << 1;

				id_temp = abs(id_temp);
				iq_temp = abs(iq_temp);
				if (_motor->usr.omega_user.half[1] < 0)
				{
					iq_temp *= (-1);
				}

				__disable_irq();
				_motor->drv.Id_com.word = id_temp;
				_motor->drv.Iq_com.word = iq_temp;
				__enable_irq();

				/* Update drive frequency. */
				_motor->drv.omega_com.word = C_command_limit_sub(_motor->drv.omega_com.word,
				                             _motor->usr.omega_user.word,
				                             _motor->para.sp_ud_lim_f.word,
				                             _motor->para.sp_ud_lim_f.word);

				if (S_lambda_cal.word >= (ELE_DEG(90) << 16))
				{
					_motor->stage_counter = 0;
					_motor->stage.sub = cStep2;
				}
				break;

			case cStep2:
				_motor->drv.Id_com.word = 0;
				_motor->drv.Iq_com.word = abs(_motor->usr.Iq_st_user) << 16;
				if (_motor->usr.omega_user.half[1] < 0)
				{
					_motor->drv.Iq_com.word *= (-1);
				}

				/* Update drive frequency. */
				_motor->drv.omega_com.word = C_command_limit_sub(_motor->drv.omega_com.word,
				                             _motor->usr.omega_user.word,
				                             _motor->para.sp_ud_lim_f.word,
				                             _motor->para.sp_ud_lim_f.word);

				_motor->stage_counter++;
				/* End of change time? */
				if (_motor->stage_counter >= _motor->para.time.go_up)
				{
					/* Set the Force Stage time */
					_motor->stage.sub = cStepEnd;
				}
				break;

			default:
				break;
		}
	}
}


/**
 *********************************************************************************************
 * @brief		Steady_A stage function.
 *
 * @param		vector_t* const	_motor			The structure address for motor vector control.
 *
 * @return		none
 *********************************************************************************************
 */
void C_Stage_Steady_A(vector_t* const _motor)
{
	vectorcmd_t cmdbuf;

	if (_motor->stage.main == cSteady_A)
	{
		switch (_motor->stage.sub)
		{
			case cStep0:
				cmdbuf.F_vcomm_theta = SET;
				cmdbuf.F_vcomm_omega = SET;
				cmdbuf.F_vcomm_current = SET;
				cmdbuf.F_vcomm_Edetect = SET;
				/*cmdbuf.F_vcomm_onoff = SET; */
				__disable_irq();
				_motor->drv.vector_cmd = cmdbuf;
				_motor->stage.itr = ciSteady_A;
				__enable_irq();
				_motor->stage.sub = cStep1;
				/* No break. Continue to the next statements. */

			case cStep1:
				/* Update drive frequency. */
				_motor->drv.omega_com.word = C_command_limit_sub(_motor->drv.omega_com.word,
				                             _motor->usr.omega_user.word,
				                             _motor->para.sp_up_lim_s.word,
				                             _motor->para.sp_dn_lim_s.word);
				_motor->drv.Id_com.word = 0;
				break;

			default:
				break;
		}
	}
}


/**
 *********************************************************************************************
 * @brief		command_limit_sub function.
 *
 * @param		q31_t	_now					Now value
 * @param		q31_t	_target					Target value
 * @param		q31_t	_lim_up					Acceleration value
 * @param		q31_t	_lim_down				Deceleration value
 *
 * @return		q31_t							Update value
 *********************************************************************************************
 */
static q31_t C_command_limit_sub(q31_t _now, q31_t _target, q31_t _lim_up, q31_t _lim_down)
{
	q31_t lim_target;
	/* printf("ABC"); */
	if (_now == _target)
	{
		lim_target = _target;
	}
	else
	{
		if (_now >= 0)
		{
			/* now speed is positive */
			if (_now < _target)
			{
				/* UP */
				lim_target = __QADD(_now, _lim_up);
				lim_target = ((_target > lim_target) ? lim_target : _target);
			}
			else
			{
				/* DOWN */
				lim_target = __QSUB(_now, _lim_down);
				lim_target = ((_target < lim_target) ? lim_target : _target);
			}
		}
		else
		{
			/* now speed is negative */
			if (_now > _target)
			{
				/* UP */
				lim_target = __QSUB(_now, _lim_up);
				lim_target = ((_target < lim_target) ? lim_target : _target);
			}
			else
			{
				/* DOWN */
				lim_target = __QADD(_now, _lim_down);
				lim_target = ((_target > lim_target) ? lim_target : _target);
			}
		}
	}
	return lim_target;
}



/*********************************** END OF FILE ******************************/
