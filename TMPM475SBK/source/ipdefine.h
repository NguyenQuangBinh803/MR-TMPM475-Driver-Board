/**
 ****************************************************************************
 * @file	 ipdefine.h
 * @brief	 Application Definitions
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _IPDEFINE_H
#define _IPDEFINE_H

#include <arm_math.h>

/* Select MCU */
#include "TMPM475.h"

#include "sys_macro.h"
#include "D_Para.h"

#ifdef DEFINE_APP
#define EXTERN
#else
#define EXTERN	extern
#endif


/*===================================================================*
	  MCU Parameter Definition
 *===================================================================*/
/* Setting fc */
#define	cIMCLK_FRQ					(120)						/* [MHz] */

/*===================================================================*
	  Interruption leve define
 *===================================================================*/
/* High   Low */
/*	0 ---- 7  */

#define	INT4KH_LEVEL			5				/* 4kH interval timer interrupt */
#define	INT_VC_LEVEL			3				/* VE interrupt */
#define	INT_DAC_LEVEL			6				/* SIO interrupt for Dac */

/* CH of PMD,VE */
#define	cCH0					0
#define	cCH1					1

/*****************************************************************
 * Constant data set
 *****************************************************************/
#define PWMPeriod(x)			((uint16_t)((cIMCLK_FRQ * x) / 2U))		/* triangle wave */
#define DeadTime(x)				((uint8_t)((cIMCLK_FRQ * 1000000U * x) / 1000000U / 8U))

#define ADC_V2HEX(x)			((uint16_t)((uint16_t)((0xfff * x) / 5) << 4U))

/* TMRB */
#define	TMRB_DIV2_PRD(x)		(uint16_t)( (uint32_t)x * cIMCLK_FRQ / 2)
#define	TMRB_DIV8_PRD(x)		(uint16_t)( (uint32_t)x * cIMCLK_FRQ / 8)
#define	TMRB_DIV32_PRD(x)		(uint16_t)( (uint32_t)x * cIMCLK_FRQ / 32)
#define	TMRB_DIV64_PRD(x)		(uint16_t)( (uint32_t)x * cIMCLK_FRQ / 64)
#define	TMRB_DIV128_PRD(x)		(uint16_t)( (uint32_t)x * cIMCLK_FRQ / 128)
#define	TMRB_DIV256_PRD(x)		(uint16_t)( (uint32_t)x * cIMCLK_FRQ / 256)
#define	TMRB_DIV512_PRD(x)		(uint16_t)( (uint32_t)x * cIMCLK_FRQ / 512)



/*****************************************************************
 * Define The Typedef
 *****************************************************************/

typedef enum
{
	cStop		  = 0,
	cBootstrap	  = 1,
	cInitposition = 2,
	cForce		  = 3,
	cChange_up	  = 4,
	cSteady_A	  = 5,
	cEmergency	  = 6
} main_stage_e;

typedef enum
{
	cStep0		  = 0,
	cStep1		  = 1,
	cStep2		  = 2,
	cStep3		  = 3,
	cStepEnd	  = 4
} sub_stage_e;

typedef enum
{
	ciStop		  = 0,
	ciBootstrap	  = 1,
	ciInitposition_i = 2,
	ciInitposition_v = 3,
	ciForce_i	  = 4,
	ciForce_v	  = 5,
	ciChange_up	  = 6,
	ciSteady_A	  = 7,
	ciEmergency	  = 8
} itr_stage_e;

typedef enum
{
	cBoot_i		= 0,
	cBoot_v		= 1
} boot_type_e;

typedef struct
{
	main_stage_e main;
	sub_stage_e sub;
	itr_stage_e itr;
} stage_t;

typedef struct
{
	uint16_t reserve: 13; 						/* reserve */
	uint16_t modul: 1;							/* PWM Moduration	0=3phase modulation 	1=2phase modulation 				*/
	uint16_t encoder: 1;						/* Position detect	0=Current				1=Encoder							*/
	uint16_t onoff: 1;							/* PWM output		0=off					1=on								*/
} command_t;

typedef struct
{
	uint16_t reserve: 10; 						/* reserve */
	uint16_t F_vcomm_theta: 1;					/* Omega to Theta	0=command value 		1=Calculate the theta from omega.	*/
	uint16_t F_vcomm_omega: 1;					/* Omega by 		0=command value 		1=Result of Estimation position 	*/
	uint16_t F_vcomm_current: 1;				/* Current by		0=command value 		1=Result of Speed Control			*/
	uint16_t F_vcomm_volt: 1; 					/* Voltage by		0=command value 		1=Result of Current Control 		*/
	uint16_t F_vcomm_Edetect: 1;				/* Position detect	0=off					1=on								*/
	uint16_t F_vcomm_Idetect: 1;				/* Current detect	0=off					1=on								*/
} vectorcmd_t;


typedef union
{
	struct
	{
		uint16_t reserve: 12; 					/* reserve */
		uint16_t emg_DC: 1;						/* 0:normal, 1: Over Vdc				*/
		uint16_t emg_I: 1;						/* 0:normal, 1: Current detect error	*/
		uint16_t emg_S: 1;						/* 0:normal, 1: Over current(soft)		*/
		uint16_t emg_H: 1;						/* 0:normal, 1: Over current(hard)		*/
	} flg;
	uint16_t	all;
} state_t;

typedef struct
{

	stage_t				stage;					/* Stage */

	struct
	{
		q31_u			omega_com;				/* [Hz/maxHz] Command of Omega(electrical angle) */
		q31_u			omega;					/* [Hz/maxHz] Omega(speed): Electrical angle */
		q15_t			omega_dev;				/* [Hz/maxHz] Omega dev			 			*/

		q31_u			Id_com;					/* [A/maxA] Command of d-axis current */
		q31_u			Iq_com;					/* [A/maxA] Command of q-axis current */
		q15_t			Id_ref;					/* [A/maxA] Referense of d-axis current */
		q15_t			Iq_ref;					/* [A/maxA] Referense of q-axis current */
		q15_t			Id;						/* [A/maxA] d-axis current */
		q15_t			Iq;						/* [A/maxA] q-axis current */

		q31_u			Iq_ref_I; 				/* [A/maxA] Referense of q-axis current (Integral) */

		uint16_t		theta_com;				/* [deg/360] Command of theta of motor */
		uint32_u		theta;					/* [deg/360] Theta(position): Electrical angle */

		q15_t			Vdc;					/* [V/maxV] DC voltage */
		q31_u			Vdc_ave;				/* [V/maxV] DC voltage average */

		q31_u			Vd;						/* [V/maxV] d-axis voltage */
		q31_u			Vq;						/* [V/maxV] q-axis voltage */

		q15_t			Vdq;					/* [V/maxV] dq-axis voltage root3 */
		q31_u			Vdq_ave;				/* [V/maxV] dq-axis voltage root3 average */

		q31_t			Vd_out;					/* [V/maxV] d-axis output voltage for VOLT BOOT */

		q15_t			Ed;						/* [V/maxV] d-axis induced voltage	*/
		q15_t			Eq;						/* [V/maxV] q-axis induced voltage	*/

		q31_t			Ed_I;					/* d-axis induced voltage I */
		q31_t			Ed_PI;					/* d-axis induced voltage PI */

		state_t			state;					/* Motor error state */
		command_t		command;				/* Command instruction */
		vectorcmd_t		vector_cmd;				/* Vector control command */

		q15_t			Ia;						/* [A/maxA] a phase current */
		q15_t			Ib;						/* [A/maxA] b phase current */
		q15_t			Ic;						/* [A/maxA] c phase current */

		int32_t			Iao_ave;				/* [A/maxA] a phase average of zero current */
		int32_t			Ibo_ave;				/* [A/maxA] b phase average of zero current */
		int32_t			Ico_ave;				/* [A/maxA] c phase average of zero current */

		uint8_t			spdprd;					/* Speed pi period counter */

		/* Encoder setting */
#if defined(__USE_ENCODER_CH1) || defined(__USE_ENCODER_CH0)
		q15_t			omega_enc;				/* [Hz/maxHz] Omega from encoder */
		q15_t			omega_enc_raw;			/* [Hz/maxHz] Omega(Raw) from encoder */
		q31_u			omega_enc_ave;			/* [Hz/maxHz] Omega(Ave) from encoder */
		uint16_t		theta_enc;				/* [deg/360] Theta from encoder */
		int16_t			EnCnt;					/* Encoder counter value */
		int16_t			EnCnt1;					/* One previous encoder counter value */
		int16_t			EnCnt_dev;				/* Deviation of the encoder counter */
#endif /* __USE_ENCODER */

	} drv;

	struct
	{
		q31_u			omega_user;				/* [Hz/maxHz] Target omega by user */

		q15_t			Id_st_user;				/* [A/maxA] Start d-axis current by user */
		q15_t			Iq_st_user;				/* [A/maxA] Start q-axis current by user */
		uint16_t		lambda_user;			/* [deg/360] Init position(Lambda) by user */

		command_t		com_user; 				/* Control command by User order */
		command_t		com_user_1;				/* before step Scom_user */

	} usr;

	struct
	{
		q15_t			omega_min;				/* [Hz/maxHz] min omega */
		q15_t			omega_v2i;				/* [Hz/maxHz] Switching speed from the voltage type control to the current type control */

		q31_t			vd_pos;					/* [V/maxV] d-axis Output Voltage */
		q31_t			spd_coef;				/* [---] speed coefficient */

		q31_u			sp_ud_lim_f; 			/* Limitation of the increase value (Forced Stage) */
		q31_u			sp_up_lim_s; 			/* Limitation of the increase value (Steady Stage) */
		q31_u			sp_dn_lim_s; 			/* Limitation of the decrease value (Steady Stage) */

		struct
		{
			uint16_t	initpos;				/* Time of Positioning State */
			uint16_t	initpos2;				/* Time of Positioning Wait State */
			uint16_t	bootstp;				/* Time of Bootstrap State */
			uint16_t	go_up;					/* Time of Change-up state */
		} time;

		q31_t			iq_lim;					/* [A/maxA] Limitation of Iq */
		q31_t			id_lim;					/* [A/maxA] Limitation of Id */
		q15_t			err_ovc;				/* [A/maxA] Over current */

		struct
		{
			q31_t		kp;						/* [---] Normalize data Pos Kp */
			q31_t		ki;						/* [---] Normalize data Pos Ki */
			int32_t		ctrlprd;				/* [---] Normalize data ctrlprd */
		} pos;

		struct
		{
			q31_t		kp;						/* [---] Normalize data Spd Kp */
			q31_t		ki;						/* [---] Normalize data Spd Ki */
		} spd;

		struct
		{
			q31_t		r;						/* [---] Normalize data motor R */
			q31_t		Lq;						/* [---] Normalize data motor Lq */
			q31_t		Ld;						/* [---] Normalize data motor Ld */
		} motor;

#if defined(__USE_ENCODER_CH1) || defined(__USE_ENCODER_CH0)
		struct
		{
			int32_t		pls2theta;				/* [---] Convert pulse to theta */
			q15_t		pls2omega;				/* [---] Convert pulse to omega */
			int32_t		plsnum;					/* [---] Encoder pulse number */
			int32_t		ctrlprd;				/* [---] Control period */
			uint16_t	deg_adjust;				/* [---] Theta adjust */
		} enc;
#endif /* __USE_ENCODER */
		int32_t			delta_lambda;			/* [---] Change_up stage lamda */

	} para;

	uint32_t			stage_counter;			/* Stage counter */
	boot_type_e			boot_type;				/* Boot type */

} vector_t;



/*****************************************************************
 * Definition of variable
 *****************************************************************/
EXTERN uint16_t		M_Main_Counter; 		/* Main loop counter */

#if defined(__CONTROL_MOTOR_CH1)
EXTERN vector_t		Motor_ch1;				/* Motor data for ch1 */
#endif /* __CONTROL_MOTOR_CH1 */
#if defined(__CONTROL_MOTOR_CH0)
EXTERN vector_t		Motor_ch0;				/* Motor data for ch0 */
#endif /* __CONTROL_MOTOR_CH0 */

/*===================================================================*
  global functions.
 *===================================================================*/
/****************************************************************************************
 * Module	: calc_ave
 *---------------------------------------------------------------------------------------
 * Function : cals Average
 * Input	: ave, val, shift
 * Output	: Average
 * Note 	:
 ****************************************************************************************/
static __INLINE int32_t calc_ave(int32_t ave, int32_t val, int32_t shift)
{
	return (ave + ((val - ave) >> shift));
}


#endif /* _IPDEFINE_H */


/*************************** END OF FILE **************************************/
