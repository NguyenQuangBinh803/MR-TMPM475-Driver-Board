/**
 ****************************************************************************
 * @file	 initial.c
 * @brief	 Initialize Functions
 * @version  V1.0
 *****************************************************************************
 */
#include "ipdefine.h"
#include "mcuip_drv_ave.h"
#include "D_Para.h"

#include "tmpm475_wdt.h"
#include "tmpm475_tmrb.h"
#include "tmpm475_gpio.h"
#include "tmpm475_enc.h"
#include "tmpm475_uart.h"


#define DEFINE_APP
#include "initial.h"
#undef  DEFINE_APP


/*===================================================================*
	  Constant Data Definition
 *===================================================================*/
/*  */
#define	INT4KH_TB_CH			TSB_TB0
#define	INT4KH_IRQ_INTTX		INTTB00_IRQn
#define INT4KH_IRQ_LEVEL		INT4KH_LEVEL

#define	TMRB_PRD_4KH			TMRB_DIV8_PRD(250)

/**
 *********************************************************************************************
 * @brief		Initialize 4kH interval Timer.
 *
 * @return		none
 *********************************************************************************************
 */
void init_Timer_interval4kH(void)
{
	TMRB_InitTypeDef m_tmrb;

	m_tmrb.Mode = TMRB_INTERVAL_TIMER;
	m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
	m_tmrb.TrailingTiming = TMRB_PRD_4KH;						/* periodic time */
	m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
	m_tmrb.LeadingTiming = TMRB_PRD_4KH;						/* periodic time */

	TMRB_Enable(INT4KH_TB_CH);
	TMRB_Init(INT4KH_TB_CH, &m_tmrb);

	NVIC_SetPriority(INT4KH_IRQ_INTTX, INT4KH_IRQ_LEVEL);
	NVIC_ClearPendingIRQ(INT4KH_IRQ_INTTX);
	NVIC_EnableIRQ(INT4KH_IRQ_INTTX);

	TMRB_SetRunState(INT4KH_TB_CH, TMRB_RUN);
}


/**
 *********************************************************************************************
 * @brief		Initialize encoder
 *
 * @return		none
 *********************************************************************************************
 */
void init_ENCen(void)
{
#if defined(__USE_ENCODER_CH1) || defined(__USE_ENCODER_CH0)
	ENC_InitTypeDef m_enc;
#endif

	/***** For Encoder Setting ****************************************/
#if defined(__USE_ENCODER_CH1) || defined(__USE_ENCODER_CH0)

	m_enc.ModeType = ENC_ENCODER_MODE;
	m_enc.PhaseType = ENC_TWO_PHASE;
	m_enc.EdgeType = ENC_RISING_EDGE;
	m_enc.ZphaseStatus = ENC_ZPHASE_ENABLE;
	m_enc.SetClearCount = ENC_CLEAR_INT;
	m_enc.UpDownType = ENC_COUNT_UP;
	m_enc.CountOperation = ENC_COUNT_CONTINUES;
	m_enc.CompareMode = ENC_COMPARE_MATCH;
	m_enc.DetectionDirection = ENC_CW_CCW_EDGE;
	m_enc.SkipDetection = ENC_DETECTION_DISABLE;
	m_enc.SelectCapture = ENC_CAPTURE_CLEAR;
	m_enc.PulseDivFactor = ENC_PULSE_DIV1;


#if defined(__USE_ENCODER_CH1)
	ENC_Init(TSB_EN1, &m_enc);
	ENC_SetCounterReload(TSB_EN1, cENC_PULSE_NUM_CH1 * cENCMULTIPLE - 1);
	ENC_SetSampleClk(TSB_EN1, ENC_SAMPLE_CLK_FSYS_8);
	ENC_SetNoiseCancelTime(TSB_EN1, (uint32_t)(cENC_NOISE_TIME_CH1 * (cIMCLK_FRQ >> ENC_SAMPLE_CLK_FSYS_8)));
#endif /* __USE_ENCODER_CH1 */

#if defined(__USE_ENCODER_CH0)
	ENC_Init(TSB_EN0, &m_enc);
	ENC_SetCounterReload(TSB_EN0, cENC_PULSE_NUM_CH0 * cENCMULTIPLE - 1);
	ENC_SetSampleClk(TSB_EN0, ENC_SAMPLE_CLK_FSYS_8);
	ENC_SetNoiseCancelTime(TSB_EN0, (uint32_t)(cENC_NOISE_TIME_CH0 * (cIMCLK_FRQ >> ENC_SAMPLE_CLK_FSYS_8)));
#endif /* __USE_ENCODER_CH0 */

#endif /* __USE_ENCODER_CH1 or __USE_ENCODER_CH0 */


#if defined(__USE_ENCODER_CH1)
	/* GPIO initialization */
	GPIO_SetInputEnableReg(GPIO_PF, GPIO_BIT_2, ENABLE);		/* Set PF2 as input */
	GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_1, GPIO_BIT_2);	/* Set PF2 as ENCA1 */
	GPIO_SetInputEnableReg(GPIO_PF, GPIO_BIT_3, ENABLE);		/* Set PF3 as input */
	GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_1, GPIO_BIT_3);	/* Set PF3 as ENCB1 */
	GPIO_SetInputEnableReg(GPIO_PF, GPIO_BIT_4, ENABLE);		/* Set PF4 as input */
	GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_1, GPIO_BIT_4);	/* Set PF4 as ENCZ1 */

	/* Enable ENC */
	ENC_Enable(TSB_EN1);

#endif /* __USE_ENCODER_CH1 */

#if defined(__USE_ENCODER_CH0)
	/* GPIO initialization */
	GPIO_SetInputEnableReg(GPIO_PD, GPIO_BIT_0, ENABLE);		/* Set PD0 as input */
	GPIO_EnableFuncReg(GPIO_PD, GPIO_FUNC_REG_1, GPIO_BIT_0);	/* Set PD0 as ENCA0 */
	GPIO_SetInputEnableReg(GPIO_PD, GPIO_BIT_1, ENABLE);		/* Set PD1 as input */
	GPIO_EnableFuncReg(GPIO_PD, GPIO_FUNC_REG_1, GPIO_BIT_1);	/* Set PD1 as ENCB0 */
	GPIO_SetInputEnableReg(GPIO_PD, GPIO_BIT_2, ENABLE);		/* Set PD2 as input */
	GPIO_EnableFuncReg(GPIO_PD, GPIO_FUNC_REG_1, GPIO_BIT_2);	/* Set PD2 as ENCZ0 */

	/* Enable ENC */
	ENC_Enable(TSB_EN0);

#endif /* __USE_ENCODER_CH0 */

}


/**
 *********************************************************************************************
 * @brief		Initialize ADC
 *
 * @return		none
 *********************************************************************************************
 */
void init_ADCen(void)
{
	AD_InitTypeDef adini;

#if defined(__CONTROL_MOTOR_CH1)
	adini.iuch = cADCH_CURRENT_U_CH1;
	adini.ivch = cADCH_CURRENT_V_CH1;
	adini.iwch = cADCH_CURRENT_W_CH1;
	adini.vdcch = cADCH_VDC_CH1;
	adini.pmd_ch = cPMD1;
	adini.pints = cPINTS_B;

	IP_ADC_init(TSB_ADB, &adini);

#endif /* __CONTROL_MOTOR_CH1 */


#if defined(__CONTROL_MOTOR_CH0)
	adini.iuch = cADCH_CURRENT_U_CH0;
	adini.ivch = cADCH_CURRENT_V_CH0;
	adini.iwch = cADCH_CURRENT_W_CH0;
	adini.vdcch = cADCH_VDC_CH0;
	adini.pmd_ch = cPMD0;
	adini.pints = cPINTS_A;

	IP_ADC_init(TSB_ADA, &adini);

#endif /* __CONTROL_MOTOR_CH0 */

}

/**
 *********************************************************************************************
 * @brief		Initialize PMD
 *
 * @return		none
 *********************************************************************************************
 */
void init_PMDen(void)
{
	PMD_InitTypeDef	pmdini;

#if defined(__CONTROL_MOTOR_CH1)
	pmdini.poll = cPOLL_CH1;
	pmdini.polh = cPOLH_CH1;
	pmdini.pwmfreq = PWMPeriod(cPWMPRD_CH1);
	pmdini.deadtime = DeadTime(cDEADTIME_CH1);

	IP_PMD_init(TSB_PMD1, &pmdini);

#endif /* __CONTROL_MOTOR_CH1 */


#if defined(__CONTROL_MOTOR_CH0)
	pmdini.poll = cPOLL_CH0;
	pmdini.polh = cPOLH_CH0;
	pmdini.pwmfreq = PWMPeriod(cPWMPRD_CH0);
	pmdini.deadtime = DeadTime(cDEADTIME_CH0);

	IP_PMD_init(TSB_PMD0, &pmdini);

#endif /* __CONTROL_MOTOR_CH0 */


}


/**
 *********************************************************************************************
 * @brief		Initialize VE.
 *
 * @return		none
 *********************************************************************************************
 */
void init_VEen(void)
{
	VE_InitTypeDef	veini;

#if defined(__CONTROL_MOTOR_CH1)
	veini.pwmfreq = PWMPeriod(cPWMPRD_CH1);
	veini.reptime = cREPTIME_CH1;
	veini.trgmode = cTRGMODE1_INI;
	veini.tpwm = (uint16_t)(cPWMPRD_CH1 * 1e-6 * cHZ_MAX_CH1 * (1 << 16U));

	veini.idkp = (q15_t)(FIX_15 * cID_KP_CH1 * cA_MAX_CH1 / cV_MAX_CH1);
	veini.idki = (q15_t)(FIX_15 * cID_KI_CH1 * cCTRL_PRD_CH1 * cA_MAX_CH1 / cV_MAX_CH1);
	veini.iqkp = (q15_t)(FIX_15 * cIQ_KP_CH1 * cA_MAX_CH1 / cV_MAX_CH1);
	veini.iqki = (q15_t)(FIX_15 * cIQ_KI_CH1 * cCTRL_PRD_CH1 * cA_MAX_CH1 / cV_MAX_CH1);

	veini.zerooffset = ADC_V2HEX(cSHUNT_ZERO_OFFSET_CH1);

	veini.ve_ch = cCH1;

	NVIC_SetPriority(INTVCN1_IRQn, INT_VC_LEVEL);		/* Interruption level set */
	NVIC_ClearPendingIRQ(INTVCN1_IRQn);
	NVIC_EnableIRQ(INTVCN1_IRQn);						/* INTVCNx enable */

	IP_VE_init(TSB_VE1, &veini);

#endif /* __CONTROL_MOTOR_CH1 */


#if defined(__CONTROL_MOTOR_CH0)
	veini.pwmfreq = PWMPeriod(cPWMPRD_CH0);
	veini.reptime = cREPTIME_CH0;
	veini.trgmode = cTRGMODE0_INI;
	veini.tpwm = (uint16_t)(cPWMPRD_CH0 * 1e-6 * cHZ_MAX_CH0 * (1 << 16U));

	veini.idkp = (q15_t)(FIX_15 * cID_KP_CH0 * cA_MAX_CH0 / cV_MAX_CH0);
	veini.idki = (q15_t)(FIX_15 * cID_KI_CH0 * cCTRL_PRD_CH0 * cA_MAX_CH0 / cV_MAX_CH0);
	veini.iqkp = (q15_t)(FIX_15 * cIQ_KP_CH0 * cA_MAX_CH0 / cV_MAX_CH0);
	veini.iqki = (q15_t)(FIX_15 * cIQ_KI_CH0 * cCTRL_PRD_CH0 * cA_MAX_CH0 / cV_MAX_CH0);

	veini.zerooffset = ADC_V2HEX(cSHUNT_ZERO_OFFSET_CH0);

	veini.ve_ch = cCH0;

	NVIC_SetPriority(INTVCN0_IRQn, INT_VC_LEVEL);		/* Interruption level set */
	NVIC_ClearPendingIRQ(INTVCN0_IRQn);
	NVIC_EnableIRQ(INTVCN0_IRQn);						/* INTVCNx enable */

	IP_VE_init(TSB_VE0, &veini);

#endif /* __CONTROL_MOTOR_CH0 */

}

/**
 *********************************************************************************************
 * @brief		Initialize WDT
 *
 * @return		none
 *********************************************************************************************
 */
void init_WDT(void)
{

	WDT_InitTypeDef WDTini;

	WDTini.DetectTime = WDT_DETECT_TIME_EXP_25;
	WDTini.OverflowOutput = WDT_WDOUT;

	WDT_Init(&WDTini);
	WDT_WriteClearCode();
	WDT_Enable();

}

void init_UART(void)
{
	// TODO: my code here
	UART_DefaultConfig(UART0);
	GPIO_WriteDataBit(GPIO_PA, GPIO_BIT_3, (1));		/* LED3 */
	GPIO_SetOutputEnableReg(GPIO_PA, GPIO_BIT_3, ENABLE);
	// TODO: my code here
}

/*********************************** END OF FILE ******************************/
