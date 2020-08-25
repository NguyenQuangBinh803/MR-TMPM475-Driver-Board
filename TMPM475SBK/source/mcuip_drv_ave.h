/**
 ****************************************************************************
 * @file	 mcuip_drv_ave.h
 * @brief	 PMD and VE driver
 * @version  V1.0
 *****************************************************************************
 */
#ifndef _MCUIP_DRV_H
#define _MCUIP_DRV_H

#undef EXTERN
#ifdef DEFINE_APP
#define EXTERN
#else
#define EXTERN	extern
#endif



/*===================================================================*
	  Register bit position Definition
 *===================================================================*/
/* VExFMODE */
#define	B_SPWMEN				1U
#define	B_C2PEN					0U

/* VExMCTLF */
#define	B_LAVFM					1U
#define	B_PLSLF					4U

/* PMDxEMGSTA */
#define	B_EMGST					0U
#define	B_EMGI					1U

/* PMDxEMGCR */
#define	B_EMGEN					0U
#define	B_EMGRS					1U

/* PMDxOVVCR */
#define	B_OVVEN					0U

/* PMDxMDPOT */
#define	B_POLL					2U
#define	B_POLH					3U


/*===================================================================*
	  Constant Data Definition
 *===================================================================*/
/* PMD Trigger Interrupt Select Registers */
#define	cPINTS_A				0U
#define	cPINTS_B				1U

/* PMD CH */
#define	cPMD0					0U
#define	cPMD1					1U

/** For PMD,VE ******************************************************/

/* Define the constant data for MODESEL */
#define WBUF_BUS				0								/* W-BUF data from Bus (by software) */
#define WBUF_VE 				0x0f							/* W-BUF data from VE (automatic)	 */


/****************************************************************************************/
/* Define the constant data for MDCR */
/****************************************************************************************/
/* PWM carrier waveform */
#define	PWMMD_SAWTOOTH			0U								/* edge-aligned PWM, sawtooth wave */
#define	PWMMD_TRIANGULAR		1U								/* center-aligned PWM, triangular wave */

/* PWM interrupt period */
#define	INTPRD_HALF				0U								/* Interrupt request at every 0.5 PWM period (<PWMMD>= "1" only) */
#define	INTPRD_1				1U								/* Interrupt request at every PWM period */
#define	INTPRD_2				2U								/* Interrupt request at every 2 PWM periods */
#define	INTPRD_4				3U								/* Interrupt request at every 4 PWM periods */

/* PWM interrupt timing */
#define	PINT_BOTTOM				0U								/* Interrupt request when PWM counter PMDxMDCNT<MDCNT[15:0]> = 0x0001 */
#define	PINT_TOP				1U								/* Interrupt request when PWM counter PMDxMDCNT<MDCNT[15:0]> = <MDPRD[15:0]> */

/* Duty mode */
#define	DTYMD_COMMON			0U								/* 0: 3-phase common mode */
#define	DTYMD_INDEPENDENT		1U								/* 1: 3-phase independent mode */

/* Port output mode */
#define	SYNTMD_0				0U
#define	SYNTMD_1				1U

/* PWM period extension mode */
#define	PWMCK_NORMAL			0U								/* Normal period */
#define	PWMCK_4FOLD				1U								/* 4x period */

/* Deadtime correction */
#define	DTCREN_DISABLE			0U
#define	DTCREN_ENABLE			1U

/* Double buffer update timing for the duty compare register and PWM period register. */
#define	DSYNCS_INTCYC			0U								/* Depends on interrupt cycle setting */
#define	DSYNCS_BOTTOM			1U								/* Updates at PWM carrier bottom */
#define	DSYNCS_TOP				2U								/* Updates at PWM carrier peak */
#define	DSYNCS_BOTTOM_TOP		3U								/* Updates at both PWM carrier peak and bottom */

/*Edge setting */
#define	PWMES_CENTER			0U								/* Edge unfixed (center-aligned PWM) */
#define	PWMES_RISING			2U								/* PWM rising-edge fixed (to the PWM carrier bottom) */
#define	PWMES_FALLING			3U								/* PWM falling-edge fixed (to the PWM carrier bottom) */

/*--------------------------------------------------------------------------------------*/
#define	cWPWMES					PWMES_CENTER					/* W-phase edge setting */
#define	cVPWMES					PWMES_CENTER					/* V-phase edge setting */
#define	cUPWMES					PWMES_CENTER					/* U-phase edge setting */
#define	cDSYNCS					DSYNCS_INTCYC					/* Double buffer update timing */
#define	cDTCREN					DTCREN_DISABLE					/* Deadtime correction */
#define	cPWMEXCLK				PWMCK_NORMAL					/* Divide PWM clock */
#define	cPWMSYNT				SYNTMD_0						/* Special PWM mode */
#define	cPWMSPCFY				DTYMD_INDEPENDENT				/* Duty mode */
#define	cPWMINT					PINT_BOTTOM						/* INTPWM timing */
#define	cPWMINTPRD				INTPRD_1						/* INTPWM period */
#define	cPWMWAVE				PWMMD_TRIANGULAR				/* PWM mode */
/*--------------------------------------------------------------------------------------*/
#define cMDCR_INI				( (cWPWMES	 << 14) | (cVPWMES	  << 12) | (cUPWMES   << 10) \
								| (cDSYNCS	 << 8 ) | (cDTCREN	  << 7 ) \
								| (cPWMEXCLK << 6 ) | (cPWMSYNT   << 5 ) | (cPWMSPCFY << 4) \
								| (cPWMINT	 << 3 ) | (cPWMINTPRD << 1 ) | (cPWMWAVE  << 0))
/****************************************************************************************/


/****************************************************************************************/
/* Define the constant data for MDOUT */
/****************************************************************************************/
#define cMDOUT_OFF				BIT16(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)	/* OUTPUT all L */
#define cMDOUT_ON				BIT16(0,0,0,0,0,1,1,1,0,0,1,1,1,1,1,1)	/* OUTPUT all PWM/~PWM */
								/* 0  | | | | | | | | | | | | | | | +--	UOC X out 0:OFF 1:ON	*/
								/* 1  | | | | | | | | | | | | | | +----		U out 0:OFF 1:ON	*/
								/* 2  | | | | | | | | | | | | | +------	VOC Y out 0:OFF 1:ON	*/
								/* 3  | | | | | | | | | | | +--------		V out 0:OFF 1:ON	*/
								/* 4  | | | | | | | | | | | +----------	WOC Z out 0:OFF 1:ON	*/
								/* 5  | | | | | | | | | | +------------		W out 0:OFF 1:ON	*/
								/* 6  | | | | | | | | | +--------------	0						*/
								/* 7  | | | | | | | | +----------------	0						*/
								/* 8  | | | | | | | +------------------	UPWM U out 0:H/L 1:PWM	*/
								/* 9  | | | | | | +--------------------	UPWM U out 0:H/L 1:PWM	*/
								/*10  | | | | | +----------------------	UPWM U out 0:H/L 1:PWM	*/
								/*11  | | | | +------------------------	0						*/
								/*12  | | | +--------------------------	0						*/
								/*13  | | +----------------------------	0						*/
								/*14  | +------------------------------	0						*/
								/*15  +--------------------------------	0						*/

/****************************************************************************************/

/****************************************************************************************/
/* Define the constant data for MDPOT */
/****************************************************************************************/
/* Selects PMDxMDOUT(VExOUTCR) transfer timing (trigger synchronous setting). */
#define	SYNCS_ASYNC				0U								/* asynchronous */
#define	SYNCS_INTENC			1U								/* when INTENCx (ENCx interrupt request) occurs */
#define	SYNCS_NTTB				2U								/* when INTTBx0 (TMRBx interrupt request) occurs */
#define	SYNCS_CTRGO				3U								/* when CTRGO(ENCx MCMP completed) occurs */

/* Selects PMDxMDOUT(VExOUTCR) transfer timing (PWM synchronous setting). */
#define	PSYNCS_WRITE			0U								/* Reflect when write */
#define	PSYNCS_BOTTOM			1U								/* Reflect when PWM counter MDCNT="1"(minimum) */
#define	PSYNCS_TOP				2U								/* Reflect when PWM counter MDCNT=PMDxMDPRD<MDPRD>(maximum) */
#define	PSYNCS_BOTTOM_TOP		3U								/* Reflect when PWM counter MDCNT="1"(minimum) or PMDxMDPRD<MDPRD>(maximum) */

/* Port polarity */
#define	POLH_LACT				0U
#define	POLH_HACT				1U
#define	POLL_LACT				0U
#define	POLL_HACT				1U

/*--------------------------------------------------------------------------------------*/
#define	cSYNCS					(SYNCS_ASYNC)
#define	cPSYNCS					(PSYNCS_TOP)
/*--------------------------------------------------------------------------------------*/
#define cMDPOT_INI				((cSYNCS << 8) | (cPSYNCS << 0))
/****************************************************************************************/


/****************************************************************************************/
/* Define the constant data for PORTMD */
/****************************************************************************************/
/* Port control settings at tool break. */
#define	PORTMD_ALLHIZ			0U								/* Upper phases = High-z / lower phases = High-z */
#define	PORTMD_UHIZ_LON			1U								/* Upper phases = High-z / ower phases = PMD output */
#define	PORTMD_UON_LHIZ			2U								/* Upper phases = PMD output / lower phases = High-z */
#define	PORTMD_ALLON			3U								/* Upper phases = PMD output / lower phases = PMD output */

/*--------------------------------------------------------------------------------------*/
#define	cPORTMD					PORTMD_ALLHIZ
/*--------------------------------------------------------------------------------------*/
#define	cPORTMD_INI				((cPORTMD) << 0)
/****************************************************************************************/

/****************************************************************************************/
/* Define the constant data for TRGCR */
/****************************************************************************************/
#define	TRGMD_DIS				0U								/* Trigger output disabled */
#define	TRGMD_DOWN				1U								/* Trigger output at down-count match */
#define	TRGMD_UP				2U								/* Trigger output at up-count match */
#define	TRGMD_UPDOWM			3U								/* Trigger output at up-/down-count match */
#define	TRGMD_PEAK				4U								/* Trigger output at PWM carrier peak */
#define	TRGMD_BOTTOM			5U								/* Trigger output at PWM carrier bottom */
#define	TRGMD_PEAKBOTTOM		6U								/* Trigger output at PWM carrier peak/bottom */
#define	TRGMD_DIS7				7U								/* Trigger output disabled */

#define	TRGBE_SYNC				0U								/* sync */
#define	TRGBE_ASYNC				1U								/* The value written to PMDTRGx is immediately reflected.) */


/*--------------------------------------------------------------------------------------*/
#define	cTRGMD					TRGMD_PEAK						/* Trigger timing setting */
#define	cBUFSYNC				TRGBE_SYNC						/* Triger Buffer update timing */
/*--------------------------------------------------------------------------------------*/
#define cTRG0_SETTING			((cBUFSYNC << 3) | (cTRGMD))
#define cTRG1_SETTING			((cBUFSYNC << 3) | (TRGMD_DIS))
#define cTRG2_SETTING			((cBUFSYNC << 3) | (TRGMD_DIS))
#define cTRG3_SETTING			((cBUFSYNC << 3) | (TRGMD_DIS))
/*--------------------------------------------------------------------------------------*/
#define cTRG_SETTING 	 		((cTRG3_SETTING << 12) | (cTRG2_SETTING << 8) | (cTRG1_SETTING << 4) | (cTRG0_SETTING << 0))
/****************************************************************************************/


/****************************************************************************************/
/* Define the constant data for TRGMD */
/****************************************************************************************/
/* Trigger output mode */
#define	TRGOUT_FIX				0U								/* Fixed trigger output */
#define	TRGOUT_SEL				1U								/* Variable trigger output */

/* Output enable in EMG protection state */
#define	EMGTGE_DISABLE			0U								/* Disable trigger output in the protection state */
#define	EMGTGE_ENABLE			1U								/* Enable trigger output in the protection state */

/*--------------------------------------------------------------------------------------*/
#define	cEMGTGE					EMGTGE_ENABLE
/*--------------------------------------------------------------------------------------*/
#define	cTRGMD_SETTING			( (TRGOUT_SEL << 1) | (cEMGTGE << 0) )
/****************************************************************************************/

/****************************************************************************************/
/* Define the constant data for TRGSYNCR */
/****************************************************************************************/
/* Trigger Update Timing Setting */
#define	TSYNCS_TRGMD			0U								/* PWM carrier bottom or PWM carrier peak is set for each trigger by setting PMDxTRGCR<TRGxMD>. */
#define	TSYNCS_BOTTOM			1U								/* PWM carrier bottom */
#define	TSYNCS_TOP				2U								/* PWM carrier peak */
#define	TSYNCS_BOTTOM_TOP		3U								/* PWM carrier peak and PWM carrier bottom */

/*--------------------------------------------------------------------------------------*/
#define	cTRGSYNCR_INI			(TSYNCS_BOTTOM_TOP)
/****************************************************************************************/


/****************************************************************************************/
/* Define the constant data for EMGCR */
/****************************************************************************************/
/* Tool break enable/disable */
#define	INHEN_DISABLE			0U
#define	INHEN_ENABLE			1U

/* EMG protection mode select */
#define	EMGMD_ALLHIZ			0U								/* PWM output control disabled / Port output = All phases High-Z */
#define	EMGMD_UON_LHIZ			1U								/* All upper phases ON, all lower phases OFF / Port output = Lower phases High-Z */
#define	EMGMD_UHIZ_LON			2U								/* All upper phases OFF, all lower phases ON / Port output = Upper phases High-Z */
#define	EMGMD_ALLHIZ2			3U								/* All phases OFF / Port output = All phases High-Z */

/* EMG protection release */
#define	EMGRS_NOP				0U
#define	EMGRS_RELEASE			1U

/* EMG protection circuit enable/disable */
#define	EMGEN_DISABLE			0U
#define	EMGEN_ENABLE			1U

/*--------------------------------------------------------------------------------------*/
#define	cEMGCNT					5U								/* Detection counter unit.16/fsys  ex.200ns@80MHz */
#define	cINHEN					INHEN_ENABLE					/* Tool Break */
#define	cEMGMD					EMGMD_ALLHIZ					/* Stop mode */
/*--------------------------------------------------------------------------------------*/
#define cEMG_ENA				((cEMGCNT << 8) | (cINHEN << 5) | (cEMGMD << 3) | (EMGEN_ENABLE << 0))
#define cEMG_DIS				((cEMGCNT << 8) | (cINHEN << 5) | (cEMGMD << 3) | (EMGEN_DISABLE << 0) )
#define	cEMG_Release			((cEMGCNT << 8) | (cINHEN << 5) | (cEMGMD << 3) | (EMGRS_RELEASE << 1) | (EMGEN_ENABLE << 0))
/****************************************************************************************/


/****************************************************************************************/
/* Define the constant data for OVVCR */
/****************************************************************************************/
/* ADC B monitor interrupt input enable */
#define	ADIN1EN_DISABLE			0U
#define	ADIN1EN_ENABLE			1U

/* ADC A monitor interrupt input enable */
#define	ADIN0EN_DISABLE			0U
#define	ADIN0EN_ENABLE			1U

/* OVV protection mode */
#define	OVVMD_NOCON				0U
#define	OVVMD_UON_LOFF			1U
#define	OVVMD_UOFF_LON			2U
#define	OVVMD_ALLOFF			3U


/* OVV input select */
#define	OVVISEL_PORT			0U
#define	OVVISEL_ADC				1U

/* OVV protection release */
#define	OVVRS_NORMAL			0U
#define	OVVRS_AUTO				1U

/* OVV protection circuit enable/disable */
#define	OVVEN_DISABLE			0U
#define	OVVEN_ENABLE			1U

/*--------------------------------------------------------------------------------------*/
#define	cOVVCNT					5U								/* Detection counter unit.16/fsys  ex.200ns@80MHz */
#define	cADIN1EN				ADIN1EN_DISABLE					/* AD1 watch input */
#define	cADIN0EN				ADIN0EN_DISABLE					/* AD0 watch input */
#define	cOVVMD					OVVMD_ALLOFF					/* Stop mode */
#define	cOVVISEL				OVVISEL_PORT					/* Sourse of OVV */
#define	cOVVRS					OVVRS_NORMAL					/* Auto release */
/*--------------------------------------------------------------------------------------*/
#define cOVV_ENA				( (cOVVCNT << 8) | (cADIN1EN << 6) | (cADIN0EN << 5) | \
								  (cOVVMD << 3) | (cOVVISEL << 2) | (cOVVRS << 1) | (OVVEN_ENABLE << 0) )

#define cOVV_DIS				( (cOVVCNT << 8) | (cADIN1EN << 6) | (cADIN0EN << 5) | \
								  (cOVVMD << 3) | (cOVVISEL << 2) | (cOVVRS << 1) | (OVVEN_DISABLE << 0) )
/****************************************************************************************/


/** For VE ******************************************************/


/****************************************************************************************/
/* Define the constant data for FMODE */
/****************************************************************************************/
/* Selects a PWM shift mode. */
#define	SPWMMD_SPWM1			0U								/* Shift 1 */
#define	SPWMMD_SPWM2U			1U								/* Shift 2 (U-phase Normal PWM) */
#define	SPWMMD_SPWM2V			2U								/* Shift 2 (V-phase Normal PWM) */
#define	SPWMMD_SPWM2W			3U								/* Shift 2 (W-phase Normal PWM) */

/* Disables/enables synchronous current sampling control using two units of the ADC. */
#define	SADCEN_DISABLE			0U								/* Synchronous sampling is disabled. */
#define	SADCEN_ENABLE			1U								/* Synchronous sampling is enabled. */

/* Disables/enables phase transformation. */
#define	PHCVDIS_ENABLE			0U								/* 2-3 phase transformation is enabled. (3-phase AC output) */
#define	PHCVDIS_DISABLE			1U								/* 2-3 phase transformation is disabled. (2-phase AC output) */

/* Controls voltage scalar limitation */
#define	VSLIMMD_DIS				0U								/* Scalar limitation is disabled. (The limitation of each axis is enabled.) */
#define	VSLIMMD_D				1U								/* Limits the voltage on the d-axis. */
#define	VSLIMMD_Q				2U								/* Limits the voltage on the q-axis. */
#define	VSLIMMD_DQ				3U								/* dq proportional limitation */

/* Keep the previous value of SIN/COS/SECTOR */
#define	MREGDIS_EFFECTIVE		0U
#define	MREGDIS_NOEFFECTIVE		1U

/* Trigger correction */
#define	CRCEN_DISABLE			0U								/* Disable trigger correction. */
#define	CRCEN_ENABLE			1U								/* Enable trigger correction. */

/* Current detection mode */
#define IDMODE					0U

/*--------------------------------------------------------------------------------------*/
#define	cSPWMMD					(SPWMMD_SPWM1)
#define	c2ADCEN					(SADCEN_DISABLE)
#define	cPHCVDIS				(PHCVDIS_ENABLE)
#define	cVSLIMMD				(VSLIMMD_DIS)
#define	cMREGDIS				(MREGDIS_EFFECTIVE)
#define	cCRCEN					(CRCEN_ENABLE)

/*--------------------------------------------------------------------------------------*/
#define	cFMODE_INI				(					(c2ADCEN << 13) | (cPHCVDIS << 12) | (cVSLIMMD << 10) | (cMREGDIS << 9) | (IDMODE << 2) )
/****************************************************************************************/


/****************************************************************************************/


/****************************************************************************************/
#define	TAPP_OUT_CON			0U			/* Output control 1 */
#define	TAPP_TRG_GEN			1U			/* Trigger generation */
#define	TAPP_IN_PRC				2U			/* Input process 1 */
#define	TAPP_IN_PHSCNV			3U			/* Input phase transformation */
#define	TAPP_IN_AXISCNV			4U			/* Input coordinate axis transformation */
#define	TAPP_CRT_CON			5U			/* Current control */
#define	TAPP_SINCOS				6U			/* SIN/COS calculation */
#define	TAPP_OUT_AXISCNV		7U			/* Output coordinate axis transformation */
#define	TAPP_OUT_PHSCNV			8U			/* Output phase transformation 1[SVM] */
#define	TAPP_OUT_CON2			9U			/* Output control 2 */
#define	TAPP_IN_PRC2			10U			/* Input process 2 */
#define	TAPP_OUT_PHSCNV2		11U			/* Output phase transformation 2[I-Clarke] */
#define	TAPP_ATAN2				12U			/* ATAN2 */
#define	TAPP_SQRT				13U			/* SQRT */

#define	SCH_1					1U
#define	SCH_2					2U
#define	SCH_3					3U
#define	SCH_4					4U
#define	SCH_5					5U
#define	SCH_6					6U
#define	SCH_7					7U
#define	SCH_8					8U
#define	SCH_9					9U
#define	SCH_10					10U
#define	SCH_11					11U
#define	SCH_12					12U
#define	SCH_13					13U
#define	SCH_14					14U
#define	SCH_15					15U
/****************************************************************************************/


/****************************************************************************************/
/* VETRGMODE */
/****************************************************************************************/
#define	TRGMODE_IGNORE			0U
#define	TRGMODE_UNITA			1U
#define	TRGMODE_UNITB			2U
/*--------------------------------------------------------------------------------------*/
#define	cTRGMODE1_INI			(TRGMODE_UNITB)
#define	cTRGMODE0_INI			(TRGMODE_UNITA)
/****************************************************************************************/


/****************************************************************************************/
/* VEERRINTEN */
/****************************************************************************************/
/* Controls a task completion interrupt. */
#define	INTTEN_DISABLE			0U
#define	INTTEN_ENABLE			1U

/* Controls an interrupt at error detection. */
#define	VERREN_DISABLE			0U
#define	VERREN_ENABLE			1U

/*--------------------------------------------------------------------------------------*/
#define	cINTTEN					INTTEN_DISABLE
#define	cVERREN					VERREN_DISABLE
/*--------------------------------------------------------------------------------------*/
#define	cVERREN_INI				((cINTTEN << 2) | (cVERREN << 0))
/****************************************************************************************/

/****************************************************************************************/
/* VECOMPEND */
/****************************************************************************************/
#define	VCEND_TERMINATE			1U
/*--------------------------------------------------------------------------------------*/
#define	VE_FORCE_STOP_CH0		(VCEND_TERMINATE << 0U)
#define	VE_FORCE_STOP_CH1		(VCEND_TERMINATE << 1U)
/****************************************************************************************/

/****************************************************************************************/
/* VEMODE */
/****************************************************************************************/
/* Current polarity determination */
#define	IPDEN_DISABLE			0U
#define	IPDEN_ENABLE			1U

/* Dead time correction contorol of the PMD */
#define	PMDDTCEN_DISABLE		0U
#define	PMDDTCEN_ENABLE			1U

/* Duty of 100% setting when the upper-limit */
#define	PWMFLEN_DISABLE			0U
#define	PWMFLEN_ENABLE			1U

/* Duty of 0% setting when the lower-limit */
#define	PWMBLEN_DISABLE			0U
#define	PWMBLEN_ENABLE			1U

/* Non-interference control */
#define	NICEN_DISABLE			0U
#define	NICEN_ENABLE			1U

/* Expansion control (Non-interference control and voltage scalar limitation) */
#define	T5ECEN_DISABLE			0U
#define	T5ECEN_ENABLE			1U

/* Specifies anti-windup (AWU) control */
#define	AWUMD_DISABLE			0U
#define	AWUMD_ENABLE4			1U
#define	AWUMD_ENABLE2			2U
#define	AWUMD_ENABLE1			3U

/* Phase clipping control */
#define	CLPEN_DISABLE			0U
#define	CLPEN_ENABLE			1U

/* Specifies ATAN calculation control */
#define	ATANMD_DISABLE			0U
#define	ATANMD_IDQ				2U
#define	ATANMD_EDQ				3U

/* Selects the supply voltage store register */
#define	VDCSEL_VDC				0U
#define	VDCSEL_VDCL				1U

/* Output control */
#define	OCRMD_OUT_OFF			0U
#define	OCRMD_OUT_ON			1U
#define	OCRMD_OUT_ON_LOWPH		2U
#define	OCRMD_OUT_OFF_EMGRET	3U

/* Zero current detection */
#define	ZIEN_DISABLE			0U
#define	ZIEN_ENABLE				1U

/* Phase interpolation */
#define	PVIEN_DISABLE			0U
#define	PVIEN_ENABLE			1U

/*--------------------------------------------------------------------------------------*/
#define	cIPDEN					(IPDEN_DISABLE)					/* Current polarity determination */
#define	cPMDDTCEN				(PMDDTCEN_DISABLE)				/* Dead time correction contorol of the PMD */
#define	cPWMFLEN				(PWMFLEN_DISABLE)				/* Duty of 100% setting when the upper-limit */
#define	cPWMBLEN				(PWMBLEN_DISABLE)				/* Duty of 0% setting when the lower-limit */
#define	cNICEN					(NICEN_DISABLE)					/* Non-interference control */
#define	cT5ECEN					(T5ECEN_DISABLE)				/* Expansion control */
#define	cAWUMD					(AWUMD_DISABLE)					/* Specifies anti-windup (AWU) control */
#define	cCLPEN					(CLPEN_DISABLE)					/* Phase clipping control */
#define	cATANMD					(ATANMD_DISABLE)				/* Specifies ATAN calculation control */
#define	cVDCSEL					(VDCSEL_VDC)					/* Selects the supply voltage store register */
#define	cZIEN					(ZIEN_DISABLE)					/* Zero current detection */
#define	cPVIEN					(PVIEN_DISABLE)					/* Phase interpolation */
/*--------------------------------------------------------------------------------------*/
#define	VEMODE_STOP				( (cIPDEN << 15) | (cPMDDTCEN << 14) | (cPWMFLEN << 13) | (cPWMBLEN << 12) \
								| (cNICEN << 11) | (cT5ECEN << 10) | (cAWUMD << 8) | (cCLPEN << 7) | (cATANMD << 5) | (cVDCSEL << 4) \
								| (OCRMD_OUT_OFF << 2) | (cZIEN << 1) | (cPVIEN << 0) )

#define	VEMODE_BOOT				( (cIPDEN << 15) | (cPMDDTCEN << 14) | (cPWMFLEN << 13) | (cPWMBLEN << 12) \
								| (cNICEN << 11) | (cT5ECEN << 10) | (cAWUMD << 8) | (cCLPEN << 7) | (cATANMD << 5) | (cVDCSEL << 4) \
								| (OCRMD_OUT_ON_LOWPH << 2)  | (cZIEN << 1) | (cPVIEN << 0) )

#define	VEMODE_INITPOS			( (cIPDEN << 15) | (cPMDDTCEN << 14) | (cPWMFLEN << 13) | (cPWMBLEN << 12) \
								| (cNICEN << 11) | (cT5ECEN << 10) | (cAWUMD << 8) | (cCLPEN << 7) | (cATANMD << 5) | (cVDCSEL << 4) \
								| (OCRMD_OUT_ON << 2)  | (cZIEN << 1) | (cPVIEN << 0) )

#define	VEMODE_FORCE			( (cIPDEN << 15) | (cPMDDTCEN << 14) | (cPWMFLEN << 13) | (cPWMBLEN << 12) \
								| (cNICEN << 11) | (cT5ECEN << 10) | (cAWUMD << 8) | (cCLPEN << 7) | (cATANMD << 5) | (cVDCSEL << 4) \
								| (OCRMD_OUT_ON << 2)  | (cZIEN << 1) | (cPVIEN << 0) )

#define	VEMODE_CHGUP			( (cIPDEN << 15) | (cPMDDTCEN << 14) | (cPWMFLEN << 13) | (cPWMBLEN << 12) \
								| (cNICEN << 11) | (cT5ECEN << 10) | (cAWUMD << 8) | (cCLPEN << 7) | (cATANMD << 5) | (cVDCSEL << 4) \
								| (OCRMD_OUT_ON << 2)  | (cZIEN << 1) | (cPVIEN << 0) )

#define	VEMODE_STEADY			( (cIPDEN << 15) | (cPMDDTCEN << 14) | (cPWMFLEN << 13) | (cPWMBLEN << 12) \
								| (cNICEN << 11) | (cT5ECEN << 10) | (cAWUMD << 8) | (cCLPEN << 7) | (cATANMD << 5) | (cVDCSEL << 4) \
								| (OCRMD_OUT_ON << 2)  | (cZIEN << 1) | (cPVIEN << 0) )

#define	VEMODE_EMG				( (cIPDEN << 15) | (cPMDDTCEN << 14) | (cPWMFLEN << 13) | (cPWMBLEN << 12) \
								| (cNICEN << 11) | (cT5ECEN << 10) | (cAWUMD << 8) | (cCLPEN << 7) | (cATANMD << 5) | (cVDCSEL << 4) \
								| (OCRMD_OUT_OFF << 2) | (cZIEN << 1) | (cPVIEN << 0) )
/****************************************************************************************/

/****************************************************************************************/
/* VECPURUNTRG */
/****************************************************************************************/
#define	VCPURT_START			1U
/*--------------------------------------------------------------------------------------*/
#define	VE_START				(VCPURT_START << 0U)
/****************************************************************************************/


#define	SET_TAPP(x)				(x << 0U)
#define	MASK_TAPP				((uint32_t)0xFFFFFFF0)

#define	SET_ACTSCH(x)			(x << 0U)
#define	MASK_ACTSCH				((uint32_t)0xFFFFFFF0)

#define	SET_REPTIME(x)			(x << 0U)
#define	SET_TRGMODE(x)			(x << 0U)
#define	SET_ERRINTEN(x)			(x << 0U)


/** For Encoder ******************************************************/
#define	cENCMULTIPLE			(4)


/** For AMP **********************************************************/
#define	AMPGAIN_FOLD_1_5		0U				/* *1.5 */
#define	AMPGAIN_FOLD_2_5		1U				/* *2.5 */
#define	AMPGAIN_FOLD_3_0		2U				/* *3.0 */
#define	AMPGAIN_FOLD_3_5		3U				/* *3.5 */
#define	AMPGAIN_FOLD_4_0		4U				/* *4.0 */
#define	AMPGAIN_FOLD_6_0		5U				/* *6.0 */
#define	AMPGAIN_FOLD_8_0		6U				/* *8.0 */
#define	AMPGAIN_FOLD_10_0		7U				/* *10.0 */
/*--------------------------------------------------------------------------------------*/
#define	AMP_ENABLE(fold)		((uint8_t)((fold << 1) | 0x01U))
#define	AMP_DISABLE(fold)		((uint8_t)(fold << 1))
/****************************************************************************************/


/** For CMP **********************************************************/
#define	CMPSEL_RAW				0U
#define	CMPSEL_OPAMP			1U
/*--------------------------------------------------------------------------------------*/
#define	CMP_ENABLE(sel)			((uint8_t)((sel << 1) | 0x01U))
#define	CMP_DISABLE(sel)		((uint8_t)(sel << 1))
/****************************************************************************************/


/*===================================================================*
	  Typedef Definition
 *===================================================================*/
typedef enum
{
	cNormal		 	 = 0,
	cEMGProtected	 = 1
} emg_status_e;

/**
  * @brief	PMD Init Structure definition
  */
typedef struct
{
	uint8_t		poll;
	uint8_t		polh;
	uint16_t	pwmfreq;
	uint16_t	deadtime;
} PMD_InitTypeDef;

/**
  * @brief	VE Init Structure definition
  */
typedef struct
{
	uint8_t		ve_ch;
	uint16_t	pwmfreq;
	uint16_t	deadtime;

	uint16_t	reptime;
	uint16_t	trgmode;
	uint16_t	tpwm;

	uint16_t	idkp;
	uint16_t	idki;
	uint16_t	iqkp;
	uint16_t	iqki;

	uint16_t	zerooffset;

} VE_InitTypeDef;


/**
  * @brief	Encoder Init Structure definition
  */
typedef struct
{
	uint16_t	pulsenum;
} EN_InitTypeDef;

/**
  * @brief	Encoder Init Structure definition
  */
typedef struct
{
	uint8_t		iuch;
	uint8_t		ivch;
	uint8_t		iwch;
	uint8_t		vdcch;
	uint8_t		pmd_ch;
	uint8_t		pints;
} AD_InitTypeDef;


/*===================================================================*
	  Proto Type Definition
 *===================================================================*/
EXTERN	emg_status_e	PMD_GetEMG_Status(TSB_PMD_TypeDef* const PMDx);
EXTERN	void	PMD_ReleaseEMG_Protection(TSB_PMD_TypeDef* const PMDx);
EXTERN	void	VE_Start(TSB_VE_TypeDef* const VEx, uint8_t _ch);
EXTERN	void	VE_GetPhaseCurrent(TSB_VE_TypeDef* const VEx, uint8_t _ch, q15_t* _ia, q15_t* _ib, q15_t* _ic);
EXTERN	void	VE_GetCurrentAdcData(TSB_VE_TypeDef* const VEx, uint8_t _ch, uint32_t* _adc_ia, uint32_t* _adc_ib, uint32_t* _adc_ic);
EXTERN	void	VE_GetdataFromVEreg(TSB_VE_TypeDef* const VEx, uint8_t _ch, vector_t* const _motor);
EXTERN	void	VE_SetdataToVEreg_Stop(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor);
EXTERN	void	VE_SetdataToVEreg_Bootstrap(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor);
EXTERN	void	VE_SetdataToVEreg_Initposition_i(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor);
EXTERN	void	VE_SetdataToVEreg_Initposition_v(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor);
EXTERN	void	VE_SetdataToVEreg_Force_i(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor);
EXTERN	void	VE_SetdataToVEreg_Force_v(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor);
EXTERN	void	VE_SetdataToVEreg_Change_up(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor);
EXTERN	void	VE_SetdataToVEreg_Steady_A(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor);
EXTERN	void	VE_SetdataToVEreg_Emergency(TSB_VE_TypeDef* const VEx, uint8_t _ch, const vector_t* const _motor);
EXTERN	void	VE_SetZeroCurrentData(TSB_VE_TypeDef* const VEx, uint8_t _ch, uint32_t _z_ia, uint32_t _z_ib, uint32_t _z_ic);
EXTERN	void	VE_SetVDCreg(TSB_VE_TypeDef* const VEx, uint8_t _ch, q15_t _dat);
EXTERN	void	VE_SetModulType(TSB_VE_TypeDef* const VEx, uint8_t _ch, uint8_t _dat);
EXTERN	void	IP_PMD_init(TSB_PMD_TypeDef* const PMDx, PMD_InitTypeDef* const _initdata);
EXTERN	void	IP_VE_init(TSB_VE_TypeDef* const VEx, VE_InitTypeDef* const _initdata);
EXTERN	void	IP_ADC_init(TSB_AD_TypeDef* const ADx, AD_InitTypeDef* const _initdata);

#undef	EXTERN
#endif /* _MCUIP_DRV_H */

/*********************************** END OF FILE ******************************/


