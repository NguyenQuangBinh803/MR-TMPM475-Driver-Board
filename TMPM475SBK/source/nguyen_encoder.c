#include <stdlib.h>
#include <stdio.h>

#include "ipdefine.h"
#include "mcuip_drv_ave.h"
#include "D_Para.h"

#include "tmpm475_gpio.h"
#include "tmpm475_enc.h"

#include "nguyen_uart.h"
#include "nguyen_encoder.h"



volatile int32_t enValue = 0;

void Encoder_Initializaion(void){
    #if defined(ENCODER_1) || defined(ENCODER_0)
	ENC_InitTypeDef m_enc;
#endif

	/***** For Encoder Setting ****************************************/
#if defined(ENCODER_1) || defined(ENCODER_0)

	m_enc.ModeType = ENC_ENCODER_MODE;
	m_enc.PhaseType = ENC_THREE_PHASE;
	m_enc.EdgeType = ENC_RISING_EDGE;
	m_enc.ZphaseStatus = ENC_ZPHASE_DISABLE;
	m_enc.SetClearCount = ENC_CLEAR_INT;
	m_enc.UpDownType = ENC_COUNT_UP;
	m_enc.CountOperation = ENC_COUNT_CONTINUES;
	m_enc.CompareMode = ENC_COMPARE_MATCH;
	m_enc.DetectionDirection = ENC_CW_CCW_EDGE;
	m_enc.SkipDetection = ENC_DETECTION_DISABLE;
	m_enc.SelectCapture = ENC_CAPTURE_CLEAR;
	m_enc.PulseDivFactor = ENC_PULSE_DIV1;


#if defined(ENCODER_1)
	ENC_Init(TSB_EN1, &m_enc);
    TSB_EN1->TNCR |= 1U << 16;
	ENC_SetCounterReload(TSB_EN1, cENC_PULSE_NUM_CH1 * cENCMULTIPLE - 1);
	ENC_SetSampleClk(TSB_EN1, ENC_SAMPLE_CLK_FSYS_8);
	ENC_SetNoiseCancelTime(TSB_EN1, (uint32_t)(cENC_NOISE_TIME_CH1 * (cIMCLK_FRQ >> ENC_SAMPLE_CLK_FSYS_8)));
#endif /* __USE_ENCODER_CH1 */

#if defined(ENCODER_0)
	ENC_Init(TSB_EN0, &m_enc);
    TSB_EN0->TNCR |= 1U << 16;
	ENC_SetCounterReload(TSB_EN0, cENC_PULSE_NUM_CH0 * cENCMULTIPLE - 1);
	ENC_SetSampleClk(TSB_EN0, ENC_SAMPLE_CLK_FSYS_8);
	ENC_SetNoiseCancelTime(TSB_EN0, (uint32_t)(cENC_NOISE_TIME_CH0 * (cIMCLK_FRQ >> ENC_SAMPLE_CLK_FSYS_8)));
#endif /* __USE_ENCODER_CH0 */

#endif /* __USE_ENCODER_CH1 or __USE_ENCODER_CH0 */


#if defined(ENCODER_1)
	/* GPIO initialization */
	GPIO_SetInputEnableReg(GPIO_PF, GPIO_BIT_2, ENABLE);		/* Set PF2 as input */
	GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_1, GPIO_BIT_2);	/* Set PF2 as ENCA1 */
	GPIO_SetInputEnableReg(GPIO_PF, GPIO_BIT_3, ENABLE);		/* Set PF3 as input */
	GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_1, GPIO_BIT_3);	/* Set PF3 as ENCB1 */
	GPIO_SetInputEnableReg(GPIO_PF, GPIO_BIT_4, ENABLE);		/* Set PF4 as input */
	GPIO_EnableFuncReg(GPIO_PF, GPIO_FUNC_REG_1, GPIO_BIT_4);	/* Set PF4 as ENCZ1 */

	/* Enable ENC */
	ENC_Enable(TSB_EN1);
    ENC_SetINTControl(TSB_EN1, ENC_INTERRUPT_TPLS, ENABLE);
	NVIC_EnableIRQ(INTENC10_IRQn);

#endif /* ENCODER_1 */

#if defined(ENCODER_0)
	/* GPIO initialization */
	GPIO_SetInputEnableReg(GPIO_PD, GPIO_BIT_0, ENABLE);		/* Set PD0 as input */
	GPIO_EnableFuncReg(GPIO_PD, GPIO_FUNC_REG_1, GPIO_BIT_0);	/* Set PD0 as ENCA0 */
	GPIO_SetInputEnableReg(GPIO_PD, GPIO_BIT_1, ENABLE);		/* Set PD1 as input */
	GPIO_EnableFuncReg(GPIO_PD, GPIO_FUNC_REG_1, GPIO_BIT_1);	/* Set PD1 as ENCB0 */
	GPIO_SetInputEnableReg(GPIO_PD, GPIO_BIT_2, ENABLE);		/* Set PD2 as input */
	GPIO_EnableFuncReg(GPIO_PD, GPIO_FUNC_REG_1, GPIO_BIT_2);	/* Set PD2 as ENCZ0 */

	/* Enable ENC */
	ENC_Enable(TSB_EN0);

#endif /* ENCODER_0 */


}
void INTENC10_IRQHandler(void){ // Encoder 1 capture interrupt
	if(TSB_EN1->STS >>13 & 0x01){
		enValue--;
		GPIO_WriteDataBit(GPIO_PA,GPIO_BIT_0, !GPIO_ReadDataBit(GPIO_PA,GPIO_BIT_0));
	}
	else{
		GPIO_WriteDataBit(GPIO_PA,GPIO_BIT_1, !GPIO_ReadDataBit(GPIO_PA,GPIO_BIT_1));
		enValue++;
	}
}

int32_t Get_Encoder_Counter(void){
    return enValue;
}

int32_t Get_Velocity(void){
    char strtmp[] = "                                                 ";
    static int32_t previousEncoderValue = 0;
    static uint8_t counter = 0;
    static int32_t previousVelocity = 0;
    int32_t velocity;
    if(counter == 0){
        velocity = enValue - previousEncoderValue;
        previousEncoderValue = enValue;
        
        if(abs(velocity - previousVelocity) > 3){
            previousVelocity = velocity;
            sprintf((char*) strtmp, "velocity = %d\r\n", (int)velocity);
            Send_Data_To_PC(strtmp);
        }
    }
    counter = (counter + 1)%100;
    return velocity;
}
void TestEncoder(void){
    char strtmp[] = "                                                 ";
    static uint32_t encoderCounter = 0;
    while(1){
        if(encoderCounter != enValue){
            encoderCounter = enValue;
            sprintf((char*) strtmp, "Start programe %d\r\n", (int)encoderCounter);
            Send_Data_To_PC(strtmp);
        }
    }
}