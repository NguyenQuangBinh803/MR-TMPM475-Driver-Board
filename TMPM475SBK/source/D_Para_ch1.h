/**
 ****************************************************************************
 * @file	 D_Para_ch1.h
 * @brief	 Motor vector control Parameter Header File for CH1
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _D_PARA_CH1_H
#define _D_PARA_CH1_H


/*===================================================================*
	  Select parts
 *===================================================================*/
//#define	__USE_ENCODER_CH1								/* If define __USE_ENCODER, use encoder */

/*===================================================================*
	  Board Parameter Definition
 *===================================================================*/
/* High/Low side driver logic */
#define	cPOLH_CH1					(1)					/* High side	 0:Low active, 1:High active */
#define	cPOLL_CH1					(1)					/* Low	side	 0:Low active, 1:High active */

/* V MAX */
#define	cV_MAX_CH1					(55)				/* [V] Input voltage(Vdc)  at ADC =0xFFF0(5V) */

/* A MAX */
#define	cA_MAX_CH1					(5.0000)			/* [A] Input current(Iabc) at ADC =0xFFF0(5V) */

/* Current detection Type */
#define	cBOOT_TYPE_CH1				(cBoot_i)			/* cBoot_i : Current control, cBoot_v: Volt control */

#define	cSHUNT_ZERO_OFFSET_CH1		(2.5)				/* [V] Shunt ad offset voltage (shunt ad voltage of 0A) */

/* AD Channel */
#define	cADCH_CURRENT_U_CH1			(3)					/* AD channel for U-phase current */
#define	cADCH_CURRENT_V_CH1			(4)					/* AD channel for V-phase current */
#define	cADCH_CURRENT_W_CH1			(5)					/* AD channel for W-phase current */

#define	cADCH_VDC_CH1				(6)					/* AD Channel for power supply voltage */

/* Over current */
#define	cOVC_CH1					(4.50)				/* [A] Over current  */

/* Over voltage */
#define	cVDC_MINLIM_CH1				(1)					/* [V] Vdc min limit */
#define	cVDC_MAXLIM_CH1				(cV_MAX_CH1 - 1)	/* [V] Vdc max limit */

/*===================================================================*
	  Motor Parameter Definition
 *===================================================================*/
/* PWM Parameter */
#define	cPWMPRD_CH1 				(62.5)				/* [us] PWM Period */
#define	cDEADTIME_CH1				(1.0)				/* [us] Dead time */

#define	cREPTIME_CH1				(1)					/* Repeat time */

/* External specification */
#define	cID_ST_USER_ACT_CH1			(0.25)				/* [A] Start current (Id) */
#define	cIQ_ST_USER_ACT_CH1			(0.20)				/* [A] Start current (Iq) */

/* Motor Parameter */
#define	cMOTOR_R_CH1				(30)				/* [Ohm] Winding resistance */
#define	cMOTOR_LQ_CH1				(8.0)				/* [mH] q-axis inductance */
#define	cMOTOR_LD_CH1				(8.0)				/* [mH] d-axis inductance */
#define	cPOLE_CH1					(8)					/* [Pole] Poles of the motor */

/* Control Gain constant */
#define	cID_KP_CH1					(5.4)				/* [V/A]  d-axis current control Proportinal gain */
#define	cID_KI_CH1					(2500)				/* [V/As] d-axis current control Integral gain */
#define	cIQ_KP_CH1					(cID_KP_CH1)		/* [V/A]  q-axis current control Proportinal gain */
#define	cIQ_KI_CH1					(cID_KI_CH1)		/* [V/As] q-axis current control Integral gain */

#define	cPOSITION_KP_CH1			(5.00)				/* [Hz/V]  Position estimation Proportinal gain (Kp) */
#define	cPOSITION_KI_CH1			(0.30)				/* [Hz/Vs] Position estimation Integral gain (Ki) */

#define	cSPEED_KP_CH1				(0.01)				/* [A/Hz]  Speed Control Proportinal gain */
#define	cSPEED_KI_CH1				(0.10)				/* [A/Hzs] Speed Control Integral gain */

#define	cSPD_PI_PRD_CH1				(1)					/* Speed PI period */

#define	cFCD_UD_LIM_CH1				(40)				/* [Hz/s] Limitation of the increase value (Forced Stage) */
#define	cSTD_UP_LIM_CH1				(40)				/* [Hz/s] Limitation of the increase value (Steady Stage) */
#define	cSTD_DW_LIM_CH1				(40)				/* [Hz/s] Limitation of the decrease value (Steady Stage) */

#define	cBOOT_LEN_CH1				(0.3)				/* [s] Time of Bootstrap Stage */
#define	cINIT_LEN_CH1				(0.3)				/* [s] Time of Positioning Stage */
#define	cINIT_WAIT_LEN_CH1			(0.5)				/* [s] Time of Positioning wait time */
#define	cGOUP_DELAY_LEN_CH1			(0.01)				/* [s] Time of Change-up delay time */

#define	cHZ_MAX_CH1 				(200)				/* [Hz] Maximum speed of motor */
#define	cHZ_MIN_CH1 				(29)				/* [Hz] Minimam speed of motor */
														/* When set cHZ_MIN > S_speed_actx, not move Stage from Force */

#define	cID_LIM_CH1 				(3.5) 				/* [A] d-axis limitation current */
#define	cIQ_LIM_CH1 				(3.5) 				/* [A] q-axis limitation current */

#define	cINITIAL_POSITION_CH1		(0)					/* [deg] Initial position */


/*for Voltage control parameter */
#define	cVD_POS_CH1					(6.8)				/* [V] Voltage of positioning */
#define	cSPD_COEF_CH1				(0.23)				/* [-] Speed coefficient */
#define	cHZ_V2I_CH1					(20)				/* [Hz] Speed of switching from voltage control to current control */

/* for Encoder parameter */
#define	cENC_PULSE_NUM_CH1			(2048)				/* [ppr] Number of Encoder pulse */
#define	cENC_DEG_ADJUST_CH1			(ELE_DEG(180))		/* [deg] Adjust Z-phase,0deg of electrical-angle */

#define	cENC_NOISE_TIME_CH1			(1.0)				/* [us] Encoder signal input noise cancel time. unit:fc/8 (66.7ns@120MHz) Max:8.4us@120MHz (for A-ENC only) */

/* for Fixed Vdc parameter */
#define __FIXED_VDC_CH1 			(0)					/* Fixed Vdc */
#define	cVDC_CH1					(282)				/* [V] Power Voltage */



/*===================================================================*/
/* Control period of motor */
#define	cCTRL_PRD_CH1				(cPWMPRD_CH1 * cREPTIME_CH1 * 1e-6)								/* [s] */
#define	cSPD_CTRL_PRD_CH1			(cSPD_PI_PRD_CH1 * cPWMPRD_CH1 * cREPTIME_CH1 * 1e-6)			/* [s] */


/*===================================================================*
	Parameter check
 *===================================================================*/
#if (!((cPOLH_CH1 == 0) || (cPOLH_CH1 == 1)))
#error cPOLH_CH1 define error.
#error cPOLH_CH1 only 0 or 1.
#endif
#if (!((cPOLL_CH1 == 0) || (cPOLL_CH1 == 1)))
#error cPOLL_CH1 define error.
#error cPOLL_CH1 only 0 or 1.
#endif

#endif /* _D_PARA_CH1_H */

/*************************** END OF FILE **************************************/

