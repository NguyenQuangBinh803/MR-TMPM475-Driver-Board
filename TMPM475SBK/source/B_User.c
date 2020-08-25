/**
 ****************************************************************************
 * @file     B_User.c
 * @brief    Motor control for user Source File
 * @version  V1.0
 *****************************************************************************
 */
#include <stdlib.h>

#include "ipdefine.h"
#include "D_Para.h"
#include "mcuip_drv_ave.h"
#include "usercon.h"

#include "nguyen_motor_app.h"

#define DEFINE_APP
#include "B_User.h"
#undef  DEFINE_APP

/*===================================================================*
	  Local Variable Definition
 *===================================================================*/
#if defined(__CONTROL_MOTOR_CH1)
int32_t	target_spd1;
#endif /* __CONTROL_MOTOR_CH1 */

#if defined(__CONTROL_MOTOR_CH0)
int32_t	target_spd0;
#endif /* __CONTROL_MOTOR_CH0 */


/*===================================================================*
	Function
 *===================================================================*/
/**
 *********************************************************************************************
 * @brief		Initialize at Motor control
 *
 * @return		none
 *********************************************************************************************
 */
void	B_Motor_Init(void)
{
	
#if defined(__CONTROL_MOTOR_CH1)
	/***** Data Initialize for ch1 ********************************************/

	/***** Setting Motor type  *****/
	Motor_ch1.boot_type = cBOOT_TYPE_CH1;

#if defined(__USE_ENCODER_CH1)
	/* Encoder ON:1 OFF:0 */
	Motor_ch1.usr.com_user.encoder = SET;
#endif /* __USE_ENCODER_CH1 */

	/***** Initialize variable *****/
	Motor_ch1.stage.main = cStop;
	Motor_ch1.stage.sub = cStep0;

	Motor_ch1.drv.Iao_ave = Motor_ch1.drv.Ibo_ave = Motor_ch1.drv.Ico_ave = ADC_V2HEX(cSHUNT_ZERO_OFFSET_CH1) << 16;

	/***** user data setting *****/
	/* Start Current (Iq) command */
	Motor_ch1.usr.Iq_st_user = (q15_t)(cIQ_ST_USER_ACT_CH1 * FIX_15 / cA_MAX_CH1);

	/* Start Current (Id) command */
	Motor_ch1.usr.Id_st_user = (q15_t)(cID_ST_USER_ACT_CH1 * FIX_15 / cA_MAX_CH1);

	/* Set initial position */
	Motor_ch1.usr.lambda_user = ELE_DEG(cINITIAL_POSITION_CH1);

	/* Set Phase 3phase:0 2phase:1 */
	Motor_ch1.usr.com_user.modul = 0;

	/***** Set parameter *****/
	/* Motor parameter */
	Motor_ch1.para.motor.r = (q31_t)(FIX_15 * cMOTOR_R_CH1 * cA_MAX_CH1 / cV_MAX_CH1);
	Motor_ch1.para.motor.Lq = (q31_t)(FIX_15 * PAI2 * cA_MAX_CH1 * cHZ_MAX_CH1 * cMOTOR_LQ_CH1 / 1000 / cV_MAX_CH1);
	Motor_ch1.para.motor.Ld = (q31_t)(FIX_15 * PAI2 * cA_MAX_CH1 * cHZ_MAX_CH1 * cMOTOR_LD_CH1 / 1000 / cV_MAX_CH1);

	Motor_ch1.para.vd_pos = (q31_t)(FIX_31 * cVD_POS_CH1 / cV_MAX_CH1);
	Motor_ch1.para.spd_coef = (q31_t)(FIX_15 * cSPD_COEF_CH1);

	/* Acceleration setting */
	Motor_ch1.para.sp_ud_lim_f.word = (q31_t)(FIX_31 * cMAINLOOP_PRD * cFCD_UD_LIM_CH1 / cHZ_MAX_CH1);	/* Speed up/down limit at Force */
	Motor_ch1.para.sp_up_lim_s.word = (q31_t)(FIX_31 * cMAINLOOP_PRD * cSTD_UP_LIM_CH1 / cHZ_MAX_CH1);	/* Speed up limit at Steady */
	Motor_ch1.para.sp_dn_lim_s.word = (q31_t)(FIX_31 * cMAINLOOP_PRD * cSTD_DW_LIM_CH1 / cHZ_MAX_CH1);	/* Speed down limit at Steady */

	/* Time setting */
	Motor_ch1.para.time.bootstp = (uint16_t)(cBOOT_LEN_CH1 / cMAINLOOP_PRD); 							/* Time of Bootstrap */
	Motor_ch1.para.time.initpos = (uint16_t)(cINIT_LEN_CH1 / cMAINLOOP_PRD);							/* Time of Positioning */
	Motor_ch1.para.time.initpos2 = (uint16_t)(cINIT_WAIT_LEN_CH1 / cMAINLOOP_PRD);						/* Time of Positioning wait */
	Motor_ch1.para.time.go_up = (uint16_t)(cGOUP_DELAY_LEN_CH1 / cMAINLOOP_PRD);						/* Time of Change-up */

	/* Omega setting */
	Motor_ch1.para.omega_min = (q15_t)(FIX_15 * cHZ_MIN_CH1 / cHZ_MAX_CH1);
	Motor_ch1.para.omega_v2i = (q15_t)(FIX_15 * cHZ_V2I_CH1 / cHZ_MAX_CH1);
	Motor_ch1.para.delta_lambda = ((q31_t)(FIX_15 * cHZ_MIN_CH1 / cHZ_MAX_CH1) * (q31_t)(FIX_16 * cHZ_MAX_CH1 * cMAINLOOP_PRD)) << 1;

	/* Position est parameter */
	Motor_ch1.para.pos.ki = (q31_t)(FIX_15 * cPOSITION_KI_CH1 * cCTRL_PRD_CH1 * cV_MAX_CH1 / cHZ_MAX_CH1);
	Motor_ch1.para.pos.kp = (q31_t)(FIX_15 * cPOSITION_KP_CH1 * cV_MAX_CH1 / cHZ_MAX_CH1);
	Motor_ch1.para.pos.ctrlprd = (uint32_t)(FIX_16 * cHZ_MAX_CH1 * cCTRL_PRD_CH1);

	/* Speed con parameter */
	Motor_ch1.para.spd.ki = (q31_t)(FIX_15 * cSPEED_KI_CH1 * cSPD_CTRL_PRD_CH1 * cHZ_MAX_CH1 / cA_MAX_CH1);
	Motor_ch1.para.spd.kp = (q31_t)(FIX_15 * cSPEED_KP_CH1 * cHZ_MAX_CH1 / cA_MAX_CH1);

	/* current limit */
	Motor_ch1.para.iq_lim = (q31_t)(FIX_31 * cIQ_LIM_CH1 / cA_MAX_CH1);
	Motor_ch1.para.id_lim = (q31_t)(FIX_31 * cID_LIM_CH1 / cA_MAX_CH1);
	Motor_ch1.para.err_ovc = (q15_t)(FIX_15 * cOVC_CH1 / cA_MAX_CH1);

	/* Encoder parameter */
#if defined(__USE_ENCODER_CH1)
	Motor_ch1.para.enc.pls2theta = ((FIX_16 / (cENC_PULSE_NUM_CH1 * cENCMULTIPLE)) * (cPOLE_CH1 / 2));
	Motor_ch1.para.enc.deg_adjust = ELE_DEG(cENC_DEG_ADJUST_CH1);
	Motor_ch1.para.enc.plsnum = (cENC_PULSE_NUM_CH1 * cENCMULTIPLE);
	Motor_ch1.para.enc.pls2omega = (q15_t)(FIX_15 / ((cENC_PULSE_NUM_CH1 * cENCMULTIPLE) / (cPOLE_CH1 / 2)) / cCTRL_PRD_CH1 / cHZ_MAX_CH1);
	Motor_ch1.para.enc.ctrlprd = (uint32_t)(FIX_16 * cHZ_MAX_CH1 * cCTRL_PRD_CH1);
#endif /* __USE_ENCODER_CH1 */

#endif /* __CONTROL_MOTOR_CH1 */


#if defined(__CONTROL_MOTOR_CH0)
	/***** Data Initialize for ch0 ********************************************/

	/***** Setting Motor type  *****/
	Motor_ch0.boot_type = cBOOT_TYPE_CH0;

#if defined(__USE_ENCODER_CH0)
	/* Encoder ON:1 OFF:0 */
	Motor_ch0.usr.com_user.encoder = SET;
#endif /* __USE_ENCODER_CH0 */

	/***** Initialize variable *****/
	Motor_ch0.stage.main = cStop;
	Motor_ch0.stage.sub = cStep0;

	Motor_ch0.drv.Iao_ave = Motor_ch0.drv.Ibo_ave = Motor_ch0.drv.Ico_ave = ADC_V2HEX(cSHUNT_ZERO_OFFSET_CH0) << 16;

	/***** user data setting *****/
	/* Start Current (Iq) command */
	Motor_ch0.usr.Iq_st_user = (q15_t)(cIQ_ST_USER_ACT_CH0 * FIX_15 / cA_MAX_CH0);

	/* Start Current (Id) command */
	Motor_ch0.usr.Id_st_user = (q15_t)(cID_ST_USER_ACT_CH0 * FIX_15 / cA_MAX_CH0);

	/* Set initial position */
	Motor_ch0.usr.lambda_user = ELE_DEG(cINITIAL_POSITION_CH0);

	/* Set Phase 3phase:0 2phase:1 */
	Motor_ch0.usr.com_user.modul = 0;

	/***** Set parameter *****/
	/* Motor parameter */
	Motor_ch0.para.motor.r = (q31_t)(FIX_15 * cMOTOR_R_CH0 * cA_MAX_CH0 / cV_MAX_CH0);
	Motor_ch0.para.motor.Lq = (q31_t)(FIX_15 * PAI2 * cA_MAX_CH0 * cHZ_MAX_CH0 * cMOTOR_LQ_CH0 / 1000 / cV_MAX_CH0);
	Motor_ch0.para.motor.Ld = (q31_t)(FIX_15 * PAI2 * cA_MAX_CH0 * cHZ_MAX_CH0 * cMOTOR_LD_CH0 / 1000 / cV_MAX_CH0);

	Motor_ch0.para.vd_pos = (q31_t)(FIX_31 * cVD_POS_CH0 / cV_MAX_CH0);
	Motor_ch0.para.spd_coef = (q31_t)(FIX_15 * cSPD_COEF_CH0);

	/* Acceleration setting */
	Motor_ch0.para.sp_ud_lim_f.word = (q31_t)(FIX_31 * cMAINLOOP_PRD * cFCD_UD_LIM_CH0 / cHZ_MAX_CH0);	/* Speed up/down limit at Force */
	Motor_ch0.para.sp_up_lim_s.word = (q31_t)(FIX_31 * cMAINLOOP_PRD * cSTD_UP_LIM_CH0 / cHZ_MAX_CH0);	/* Speed up limit at Steady */
	Motor_ch0.para.sp_dn_lim_s.word = (q31_t)(FIX_31 * cMAINLOOP_PRD * cSTD_DW_LIM_CH0 / cHZ_MAX_CH0);	/* Speed down limit at Steady */

	/* Time setting */
	Motor_ch0.para.time.bootstp = (uint16_t)(cBOOT_LEN_CH0 / cMAINLOOP_PRD); 							/* Time of Bootstrap */
	Motor_ch0.para.time.initpos = (uint16_t)(cINIT_LEN_CH0 / cMAINLOOP_PRD);							/* Time of Positioning */
	Motor_ch0.para.time.initpos2 = (uint16_t)(cINIT_WAIT_LEN_CH0 / cMAINLOOP_PRD);						/* Time of Positioning wait */
	Motor_ch0.para.time.go_up = (uint16_t)(cGOUP_DELAY_LEN_CH0 / cMAINLOOP_PRD);						/* Time of Change-up */

	/* Omega setting */
	Motor_ch0.para.omega_min = (q15_t)(FIX_15 * cHZ_MIN_CH0 / cHZ_MAX_CH0);
	Motor_ch0.para.omega_v2i = (q15_t)(FIX_15 * cHZ_V2I_CH0 / cHZ_MAX_CH0);
	Motor_ch0.para.delta_lambda = ((q31_t)(FIX_15 * cHZ_MIN_CH0 / cHZ_MAX_CH0) * (q31_t)(FIX_16 * cHZ_MAX_CH0 * cMAINLOOP_PRD)) << 1;

	/* Position est parameter */
	Motor_ch0.para.pos.ki = (q31_t)(FIX_15 * cPOSITION_KI_CH0 * cCTRL_PRD_CH0 * cV_MAX_CH0 / cHZ_MAX_CH0);
	Motor_ch0.para.pos.kp = (q31_t)(FIX_15 * cPOSITION_KP_CH0 * cV_MAX_CH0 / cHZ_MAX_CH0);
	Motor_ch0.para.pos.ctrlprd = (uint32_t)(FIX_16 * cHZ_MAX_CH0 * cCTRL_PRD_CH0);

	/* Speed con parameter */
	Motor_ch0.para.spd.ki = (q31_t)(FIX_15 * cSPEED_KI_CH0 * cSPD_CTRL_PRD_CH0 * cHZ_MAX_CH0 / cA_MAX_CH0);
	Motor_ch0.para.spd.kp = (q31_t)(FIX_15 * cSPEED_KP_CH0 * cHZ_MAX_CH0 / cA_MAX_CH0);

	/* current limit */
	Motor_ch0.para.iq_lim = (q31_t)(FIX_31 * cIQ_LIM_CH0 / cA_MAX_CH0);
	Motor_ch0.para.id_lim = (q31_t)(FIX_31 * cID_LIM_CH0 / cA_MAX_CH0);
	Motor_ch0.para.err_ovc = (q15_t)(FIX_15 * cOVC_CH0 / cA_MAX_CH0);

	/* Encoder parameter */
#if defined(__USE_ENCODER_CH0)
	Motor_ch0.para.enc.pls2theta = ((FIX_16 / (cENC_PULSE_NUM_CH0 * cENCMULTIPLE)) * (cPOLE_CH0 / 2));
	Motor_ch0.para.enc.deg_adjust = ELE_DEG(cENC_DEG_ADJUST_CH0);
	Motor_ch0.para.enc.plsnum = (cENC_PULSE_NUM_CH0 * cENCMULTIPLE);
	Motor_ch0.para.enc.pls2omega = (q15_t)(FIX_15 / ((cENC_PULSE_NUM_CH0 * cENCMULTIPLE) / (cPOLE_CH0 / 2)) / cCTRL_PRD_CH0 / cHZ_MAX_CH0);
	Motor_ch0.para.enc.ctrlprd = (uint32_t)(FIX_16 * cHZ_MAX_CH0 * cCTRL_PRD_CH0);
#endif /* __USE_ENCODER_CH0 */

#endif /* __CONTROL_MOTOR_CH0 */

}


/**
 *********************************************************************************************
 * @brief		Set MotorControl data for user.
 *
 * @return		none
 *********************************************************************************************
 */
void	B_User_MotorControl(void)
{
	vector_t* motor_ch;

#if defined(__CONTROL_MOTOR_CH1)
	/***** user data setting for ch1 *****/
	motor_ch = &Motor_ch1;

	/* Get EMG state */
	if (PMD_GetEMG_Status(TSB_PMD1) == cNormal)
	{
		motor_ch->drv.state.flg.emg_H = CLEAR;
	}
	else
	{
		motor_ch->drv.state.flg.emg_H = SET;
	}

	/* Set Speed */
	/* Hz of Electrical angle */
    if(target_spd1 == 0){
        motor_ch->usr.omega_user.word = 0;
    } else {
        motor_ch->usr.omega_user.word = (q31_t)((q15_t)(target_spd1 * FIX_15 / cHZ_MAX_CH1) << 16);
    }

	/* Motor ON/OFF */
	if(Is_Motor_Enable() != 0)
	{
		motor_ch->usr.com_user.onoff = SET;
	}
	else
	{
		motor_ch->usr.com_user.onoff = CLEAR;
		motor_ch->drv.state.all = 0;									/* Clear error status. */

		if (PMD_GetEMG_Status(TSB_PMD1) == cEMGProtected)
		{
			PMD_ReleaseEMG_Protection(TSB_PMD1);
		}
	}
#endif /* __CONTROL_MOTOR_CH1 */


#if defined(__CONTROL_MOTOR_CH0)
	/***** user data setting for ch0 *****/
	motor_ch = &Motor_ch0;

	/* Get EMG state */
	if (PMD_GetEMG_Status(TSB_PMD0) == cNormal)
	{
		motor_ch->drv.state.flg.emg_H = CLEAR;
	}
	else
	{
		motor_ch->drv.state.flg.emg_H = SET;
	}

	/* Set Speed */
	/* Hz of Electrical angle */
	motor_ch->usr.omega_user.word = (q31_t)((q15_t)(target_spd0 * FIX_15 / cHZ_MAX_CH0) << 16);


	/* Motor ON/OFF */
	if(target_spd0 != 0)
	{
		motor_ch->usr.com_user.onoff = SET;
	}
	else
	{
		motor_ch->usr.com_user.onoff = CLEAR;
		motor_ch->drv.state.all = 0;									/* Clear error status. */

		if (PMD_GetEMG_Status(TSB_PMD0) == cEMGProtected)
		{
			PMD_ReleaseEMG_Protection(TSB_PMD0);
		}
	}
#endif /* __CONTROL_MOTOR_CH0 */

}

/*********************************** END OF FILE ******************************/
