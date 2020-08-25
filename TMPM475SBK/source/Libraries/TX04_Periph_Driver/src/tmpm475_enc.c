/**
 *******************************************************************************
 * @file    tmpm475_enc.c
 * @brief   This file provides API functions for ENC driver.
 * @version V2.0.2.1
 * @date    2015/2/13
 * 
 * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LISENCE AGREEMENT.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2014 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm475_enc.h"

#if defined(__TMPM475_ENC_H)

/** @addtogroup TX04_Periph_Driver
  * @{
  */

/** @defgroup ENC
  * @brief ENC driver modules
  * @{
  */

/** @defgroup Encoder_Private_Defines
  * @{
  */

#define ENTNCR_ENRUN_SET               ((uint32_t)0x00000040)
#define ENTNCR_ENCLR_SET               ((uint32_t)0x00000400)
#define ENTNCR_SFTCAP_SET              ((uint32_t)0x00000800)
#define ENTNCR_CMPSEL_SET              ((uint32_t)0xEFFFFFFF)
#define ENTNCR_TRGCAP_SET              ((uint32_t)0xFFFFEFFF)

#define ENINPCR_NCT_MASK               ((uint32_t)0xFFFF80FF)
#define ENINPCR_SYNCSPLEN_MASK         ((uint32_t)0xFFFFFFFE)
#define ENINPCR_SYNCSPLMD_MASK         ((uint32_t)0xFFFFFFFD)
#define ENINPCR_SYNCNCZEN_MASK         ((uint32_t)0xFFFFFFFB)
#define ENINPCR_SYNCSPLEN_SET          ((uint32_t)0x00000001)
#define ENINPCR_SYNCSPLMD_SET          ((uint32_t)0x00000002)

#define ENINPCR_PDSTP_SET              ((uint32_t)0x00000080)
#define ENINPCR_PDSTT_SET              ((uint32_t)0x00000040)
#define ENINPCR_MODE_MASK              ((uint32_t)0x000E0000)


/** @} */
/* End of group ENC_Private_Defines */


/** @defgroup ENC_Private_FunctionPrototypes
  * @{
  */

/** @} */
/* End of group ENC_Private_FunctionPrototypes */

/** @defgroup ENC_Private_Functions
  * @{
  */

/** @} */
/* End of group group ENC_Private_Functions */

/** @defgroup ENC_Exported_Functions
  * @{
  */

/**
  * @brief  Enable the specified encoder operation.
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval None.
  * @register The used register:
  *   ENCTNCR<ENRUN>    
  */
void ENC_Enable(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    tmp = ENx->TNCR;
    /* Set ENTNCR <ENRUN> to enable encoder operation. */
    tmp |= ENTNCR_ENRUN_SET;
    ENx->TNCR = tmp;
}

/**
  * @brief  Disable the specified encoder operation.
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval None.
  * @register The used register:
  *   ENCTNCR<ENRUN>  
  */
void ENC_Disable(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Clear ENTNCR<ENRUN> to disable encoder operation. */
    tmp = ENx->TNCR;
    tmp &= ~ENTNCR_ENRUN_SET;
    ENx->TNCR = tmp;
}

/**
  * @brief  Initialize the specified encoder channel.
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @param  InitStruct: The structure containing basic encoder configuration.
  * @retval None.
  * @register The used register:
  *   ENCTNCR<CMPSEL><UDMD[1:0]><TOVMD><MCMPMD><DECMD><SDTEN><MODE[2:0]><P3EN>
  *   <TRGCAPMD><ZESEL><ZEN><ENDEV[2:0]>
  */
void ENC_Init(TSB_EN_TypeDef * ENx, ENC_InitTypeDef * InitStruct)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_POINTER_NOT_NULL(InitStruct));
    assert_param(IS_ENC_MODE(InitStruct->ModeType));
    assert_param(IS_ENC_DIV_FACTOR(InitStruct->PulseDivFactor));
    /* Configure the encoder mode select  */
    if ((InitStruct->ModeType == ENC_ENCODER_MODE) || (InitStruct->ModeType == ENC_TIMER_MODE) ||
        (InitStruct->ModeType == ENC_PHASE_COUNTER_MODE)) {
        /* Check the parameters */
        assert_param(IS_ENC_ZPHASE_STATUS(InitStruct->ZphaseStatus));
        /*  Enable or disable z-phase detected */
        tmp = (InitStruct->ModeType << 17U) | (InitStruct->ZphaseStatus << 7U);
    } else {
        /* Check the parameters */
        assert_param(IS_ENC_PHASE(InitStruct->PhaseType));
        /* 2-phase / 3-phase input selection */
        tmp = (InitStruct->ModeType << 17U) | (InitStruct->PhaseType << 16U);
    }
    if ((InitStruct->ModeType == ENC_TIMER_MODE)
        || (InitStruct->ModeType == ENC_PHASE_COUNTER_MODE)) {
        /* Check the parameters */
        assert_param(IS_ENC_EDGE(InitStruct->EdgeType));
        /* Edge selection of ENCZ  */
        tmp |= (InitStruct->EdgeType << 8U);
    } else {
        /* Do nothing  */
    }
    if (InitStruct->ModeType == ENC_TIMER_MODE) {
        /* Check the parameters */
        assert_param(IS_ENC_CLEAR_CONDITION(InitStruct->SetClearCount));
        /* clear register for Counter */
        tmp |= (InitStruct->SetClearCount << 28U);
    } else {
        /* Do nothing  */
    }
    if ((InitStruct->ModeType == ENC_SENSOR_PHASE_MODE)
        || (InitStruct->ModeType == ENC_PHASE_COUNTER_MODE)) {

        /* Check the parameters */
        assert_param(IS_ENC_COUNT_MODE(InitStruct->UpDownType));
        /* set up or down counter RATE */
        tmp |= (InitStruct->UpDownType << 26U);
    } else {
        /* Do nothing  */
    }
    if ((InitStruct->ModeType == ENC_ENCODER_MODE)
        || (InitStruct->ModeType == ENC_SENSOR_EVENT_MODE)) {
        /* Do nothing  */
    } else {
        /* Check the parameters */
        assert_param(IS_ENC_COUNT_STOP(InitStruct->CountOperation));
        /* set counter RELOAD operation */
        tmp |= (InitStruct->CountOperation << 25U);
    }
    if ((InitStruct->ModeType == ENC_SENSOR_TIME_MODE) || (InitStruct->ModeType == ENC_TIMER_MODE)) {
        /* Check the parameters */
        assert_param(IS_ENC_COMPARE_MODE(InitStruct->CompareMode));
        /* Compare  match or size */
        tmp |= (InitStruct->CompareMode << 24U);
    } else {
        /* Do nothing  */
    }
    if ((InitStruct->ModeType == ENC_ENCODER_MODE)
        || (InitStruct->ModeType == ENC_SENSOR_EVENT_MODE)
        || (InitStruct->ModeType == ENC_SENSOR_TIME_MODE)
        || (InitStruct->ModeType == ENC_SENSOR_PHASE_MODE)) {

        /* Check the parameters */
        assert_param(IS_ENC_EDGE_DIRECTION(InitStruct->DetectionDirection));
        /* Sets the detection direction for the decoder */
        tmp |= (InitStruct->DetectionDirection << 22U);
    } else {
        /* Do nothing  */
    }
    if ((InitStruct->ModeType == ENC_SENSOR_TIME_MODE)
        || (InitStruct->ModeType == ENC_SENSOR_EVENT_MODE)
        || (InitStruct->ModeType == ENC_SENSOR_PHASE_MODE)) {
        /* Check the parameters */
        assert_param(IS_ENC_DETECT_SKIP(InitStruct->SkipDetection));
        /* Set skip detection at 3-phase decoding */
        tmp |= (InitStruct->SkipDetection << 21U);
    } else {
        /* Do nothing  */
    }
    if ((InitStruct->ModeType == ENC_TIMER_MODE) || (InitStruct->ModeType == ENC_PHASE_COUNTER_MODE)
        || (InitStruct->ModeType == ENC_SENSOR_TIME_MODE)
        || (InitStruct->ModeType == ENC_SENSOR_PHASE_MODE)) {
        /* Check the parameters */
        assert_param(IS_ENC_CAPTURE_MODE(InitStruct->SelectCapture));
        /* Set Trigger capture operationselection */
        tmp |= (InitStruct->SelectCapture << 12U);
    } else {
        /* Do nothing  */
    }
    /* Configure the encoder input control register */
    tmp |= (InitStruct->PulseDivFactor);
    ENx->TNCR = tmp;
}

/**
  * @brief  Get operation mode.
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval getMode: Get the encoder operation mode.
  *   This parameter can be one of the following values:
  *   ENC_ENCODER_MODE, ENC_SENSOR_EVENT_MODE, ENC_SENSOR_TIME_MODE,
  *   ENC_TIMER_MODE, ENC_SENSOR_PHASE_MODE, ENC_PHASE_COUNTER_MODE.   
  * @register The used register:
  *   ENCTNCR<MODE[2:0]>
  */
uint32_t ENC_GetControlMode(TSB_EN_TypeDef * ENx)
{
    uint32_t getMode = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Read Operation Mode */
    getMode = ENx->TNCR;
    getMode &= ENINPCR_MODE_MASK;
    getMode >>= 17U;
    return getMode;
}

/**
  * @brief  Set the specified encoder to executes software capture (timer mode/sensor mode (at timer count/phase count)/phase counter mode)
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval Success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  * @register The used register:
  *   ENCTNCR<SFTCAP> 
  */
Result ENC_SetSWCapture(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    uint32_t mode = 0U;
    Result retval = ERROR;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Set the specified encoder to executes software capture */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_TIMER_MODE)
        || (mode == ENC_SENSOR_PHASE_MODE) || (mode == ENC_PHASE_COUNTER_MODE)) {
        tmp = ENx->TNCR;
        tmp |= ENTNCR_SFTCAP_SET;
        ENx->TNCR = tmp;
        retval = SUCCESS;
    } else {
        /* Do nothing  */
    }
    return retval;
}

/**
  * @brief  Clear pulse counter for the specified encoder
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval None
  * @register The used register:
  *   ENCTNCR<ENCLR> 
  */
void ENC_ClearCounter(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Clear pulse counter for the specified encoder */
    tmp = ENx->TNCR;
    tmp |= ENTNCR_ENCLR_SET;
    ENx->TNCR = tmp;
}

/**
  * @brief  Get status of flag
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval The encoder flag.
  * @register The used register:
  *   ENCSTS<REVERR><UD><ZDET><SKPDT><PDERR><INERR>
  */
ENC_FlagStatus ENC_GetENCFlag(TSB_EN_TypeDef * ENx)
{
    ENC_FlagStatus retval = { 0U };
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* get status */
    retval.All = ENx->STS;
    return retval;
}

/**
  * @brief  Set the encoder counter period
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @param  PeriodValue: Set the encoder counter period
  *   In sensor mode (timer count) and timer mode,
  *   This parameter can be 0x00000000 - 0xFFFFFFFF.
  *   In other mode,
  *   This parameter can be 0x0000 - 0xFFFF.
  * @retval None.
  * @register The used register:
  *   ENCRELOAD<RELOADH[15:0]><RELOADL[15:0]>
  */
void ENC_SetCounterReload(TSB_EN_TypeDef * ENx, uint32_t PeriodValue)
{
    uint32_t mode = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Set the encoder counter period */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_TIMER_MODE)) {
        ENx->RELOAD = PeriodValue;
    } else {
        assert_param(IS_ENC_16BITVALUE(PeriodValue));
        ENx->RELOAD = (PeriodValue << 16U);
    }
}

/**
  * @brief  Set the encoder counter compare value
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @param  CompareValue:Set the encoder counter compare value
  *   In sensor mode ((event count)) and encoder mode and sensor mode (phase count) 
  *   and phase counter mode:
  *   This parameter can be 0x0000 - 0xFFFF.
  *   In sensor mode (timer count) and timer mode,
  *   This parameter can be 0x00000000 - 0xFFFFFFFF.            
  * @retval None.
  * @register The used register:
  *   ENCINT<INTH[15:0]><INTL[15:0]>
  */
void ENC_SetCompareValue(TSB_EN_TypeDef * ENx, uint32_t CompareValue)
{
    uint32_t mode = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Set the encoder counter compare value */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_TIMER_MODE)) {
        ENx->INT = CompareValue;
    } else {
        assert_param(IS_ENC_16BITVALUE(CompareValue));
        ENx->INT = (CompareValue << 16U);
    }
}

/**
  * @brief  Get the encoder counter compare value
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval Compare value of the encoder.
  * @register The used register:
  *   ENCINT<INTH[15:0]><INTL[15:0]>
  */
uint32_t ENC_GetCompareValue(TSB_EN_TypeDef * ENx)
{
    uint32_t retval = 0U;
    uint32_t mode = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Set the encoder counter compare value */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_TIMER_MODE)) {
        retval = ENx->INT;
    } else {
        retval = ENx->INT;
        retval = (retval >> 16U);
    }
    return retval;
}

/**
  * @brief  Get the counter value
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval  value of the couter.
  * @register The used register:
  *   ENCCNT<CNTH[15:0]><CNTL[15:0]>
  */
uint32_t ENC_GetCounterValue(TSB_EN_TypeDef * ENx)
{
    uint32_t retval = 0U;
    uint32_t mode = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Get the counter value */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_TIMER_MODE)) {
        retval = ENx->CNT;
    } else {
        retval = ENx->CNT;
        retval = (retval >> 16U);
    }
    return retval;
}

/**
  * @brief  Set Counter MCMP
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @param  McmpValue: Set Counter MCMP of value.
  *   In sensor mode (timer count) and timer mode,
  *   This parameter can be 0x00000000 - 0xFFFFFFFF.
  *   In other mode,
  *   This parameter can be 0x0000 - 0xFFFF.
  * @retval  None.
  * @register The used register:
  *   ENCMCMP<MCMPH[15:0]><MCMPL[15:0]>
  */
void ENC_SetCounterMCMP(TSB_EN_TypeDef * ENx, uint32_t McmpValue)
{
    uint32_t mode = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Set the encoder counter compare value */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_TIMER_MODE)) {
        ENx->MCMP = McmpValue;
    } else {
        assert_param(IS_ENC_16BITVALUE(McmpValue));
        ENx->MCMP = (McmpValue << 16U);
    }
}

/**
  * @brief  Get Counter MCMP
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval value of the couter.
  * @register The used register:
  *   ENCMCMP<MCMPH[15:0]><MCMPL[15:0]>
  */
uint32_t ENC_GetCounterMCMP(TSB_EN_TypeDef * ENx)
{
    uint32_t retval = 0U;
    uint32_t mode = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Get the MCMP value */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_TIMER_MODE)) {
        retval = ENx->MCMP;
    } else {
        retval = ENx->MCMP;
        retval = (retval >> 16U);
    }
    return retval;
}

/**
  * @brief  Set the count frequency of the counter(phase counter mode/sensor mode(at phase count)).
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @param  RateValue: frequency value fsys*<RATE>/2^16.
  *   This parameter can be one of the following values:
  *   0x0000-0xffff or 0x8000-0x7fff.
  * @retval Success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  * @note   Depending on the ENxTNCR<UDMD> setting, the value of <RATE> can 
  *   be specified as a signed bit or unsigned bit.
  * @register The used register:
  *   ENCRATE<RATE[15:0]>
  */
Result ENC_SetPhaseCountRate(TSB_EN_TypeDef * ENx, uint16_t RateValue)
{
    Result retval = ERROR;
    uint32_t mode = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Set count frequency */
    if ((mode == ENC_SENSOR_PHASE_MODE) || (mode == ENC_PHASE_COUNTER_MODE)) {
        ENx->RATE = RateValue;
        retval = SUCCESS;
    } else {
        /* Do nothing  */
    }
    return retval;
}

/**
  * @brief  Set Noise Cancel Time
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1. 
  * @param  Time: noise cancel time.
  *   This parameter can be one of the following values:
  *   0x00U to 0x7FU. 
  * @retval None.
  * @register The used register:
  *   ENCINPCR<NCT[7:0]>
  */
void ENC_SetNoiseCancelTime(TSB_EN_TypeDef * ENx, uint32_t Time)
{
    uint32_t tmp = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_7BITVALUE(Time));
    /* Set Noise Cancel Time */
    tmp = ENx->INPCR;
    tmp &= ENINPCR_NCT_MASK;
    tmp |= (Time << 8U);
    ENx->INPCR = tmp;
}

/**
  * @brief  Get noise cancel time
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.  
  * @retval retval:get noise cancel time
  *   This parameter can be one of the following values:
  *   0x00U to 0x7FU. 
  * @register The used register:
  *   ENCINPCR<NCT[7:0]>
  */
uint32_t ENC_GetNoiseCancelTime(TSB_EN_TypeDef * ENx)
{
    uint32_t retval = 0U;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* get Noise Cancel Time */
    retval = ENx->INPCR;
    retval = retval >> 8U;
    return retval;
}

/**
  * @brief  Set sample mode
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.  
  * @param  SampleMode: Enables the PWM synchronous sampling .
  *   This parameter can be one of the following values:
  *   ENC_PWM_SAMPLE_DISABLE or ENC_PWM_SAMPLE_ENABLE. 
  * @retval Success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  * @note   When the PWM synchronous sampling is set in sensor mode   
  *   (timer count or phase count),if <SYNCSPLEN> is set to "1",
  *   BEMF detection control is enabled on decoding operation.
  * @register The used register:
  *   ENCINPCR<SYNCSPLEN>
  */
Result ENC_SelectSampleMode(TSB_EN_TypeDef * ENx, uint32_t SampleMode)
{
    uint32_t tmp = 0U;
    uint32_t mode = 0U;
    Result retval = ERROR;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_PWM_SAMPLEMD(SampleMode));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Select sample mode */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_SENSOR_PHASE_MODE)) {
        tmp = ENx->INPCR;
        tmp &= ENINPCR_SYNCSPLEN_MASK;
        tmp |= SampleMode;
        ENx->INPCR = tmp;
        retval = SUCCESS;
    } else {
        /* Do nothing  */
    }
    return retval;
}

/**
  * @brief  Get PWM synchronous sampling is enable or disable.
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.  
  * @retval Result: return of result.
  *   This parameter can be one of the following values:
  *   ENC_PWM_SAMPLE_DISABLE or ENC_PWM_SAMPLE_ENABLE.
  * @register The used register:
  *   ENCINPCR<SYNCSPLEN>
  */
uint32_t ENC_GetSampleMode(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    uint32_t result = ENC_PWM_SAMPLE_DISABLE;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get Sample Mode */
    tmp = ENx->INPCR;
    tmp &= ENINPCR_SYNCSPLEN_SET;
    if (tmp) {
        result = ENC_PWM_SAMPLE_ENABLE;
    } else {
        /* Do nothing */
    }
    return result;
}

/**
  * @brief  Set PWM sample mode
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @param  SampleEdge: Selects the PWM synchronous sampling mode.
  *   This parameter can be one of the following values:
  *   ENC_PWM_ON_PERIOD or ENC_PWM_OFF_EDGE.  
  * @retval Success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  * @register The used register:
  *   ENCINPCR<SYNCSPLMD>
  */
Result ENC_SetPWMSampleMode(TSB_EN_TypeDef * ENx, uint32_t SampleEdge)
{
    uint32_t tmp = 0U;
    uint32_t result = ENC_PWM_SAMPLE_DISABLE;
    Result retval = ERROR;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_EDGE_SELECT(SampleEdge));
    /* Get PWM synchronous sampling of status */
    result = ENC_GetSampleMode(ENx);
    /* Set PWM sample mode */
    if (result == ENC_PWM_SAMPLE_ENABLE) {
        tmp = ENx->INPCR;
        tmp &= ENINPCR_SYNCSPLMD_MASK;
        tmp |= SampleEdge << 1U;
        ENx->INPCR = tmp;
        retval = SUCCESS;
    } else {
        /* Do nothing */
    }
    return retval;
}

/**
  * @brief  Get PWM Sample Mode is enable or disable.
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.  
  * @retval Result: return of result.
  *   This parameter can be one of the following values:
  *   ENC_PWM_ON_PERIOD or ENC_PWM_OFF_EDGE.
  * @retval None.
  * @register The used register:
  *   ENCINPCR<SYNCSPLMD>
  */
uint32_t ENC_GetPWMSampleMode(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    uint32_t result = ENC_PWM_ON_PERIOD;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get PWM sample mode */
    tmp = ENx->INPCR;
    tmp &= ENINPCR_SYNCSPLMD_SET;
    if (tmp) {
        result = ENC_PWM_OFF_EDGE;
    } else {
        /* Do nothing  */
    }
    return result;
}

/**
  * @brief  Set PWM stop noise cancel counter
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @param  StopState: Select the cancel counter mode.
  *   This parameter can be one of the following values:
  *   ENC_PWM_COUNT_STOP or ENC_PWM_COUNT_STOP_CLEAR.    
  * @retval Success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  * @register The used register:
  *   ENCINPCR<SYNCNCZEN>
  */
Result ENC_SetPWMStop(TSB_EN_TypeDef * ENx, uint32_t StopState)
{
    uint32_t tmp = 0U;
    uint32_t result1 = ENC_PWM_SAMPLE_DISABLE;
    uint32_t result2 = ENC_PWM_OFF_EDGE;
    Result retval = ERROR;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_PWM_COUNTMD(StopState));
    /* Get PWM Sample Mode */
    result1 = ENC_GetSampleMode(ENx);
    result2 = ENC_GetPWMSampleMode(ENx);
    /* Set PWM stop counter */
    if ((result1 == ENC_PWM_SAMPLE_ENABLE) && (result2 == ENC_PWM_ON_PERIOD)) {
        tmp = ENx->INPCR;
        tmp &= ENINPCR_SYNCNCZEN_MASK;
        tmp |= StopState << 2U;
        ENx->INPCR = tmp;
        retval = SUCCESS;
    } else {
        /* Do nothing  */
    }
    return retval;
}

/**
  * @brief  Set the positiondetection stop command(sensor mode (at timer count/at phase count))
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval  Success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  * @register The used register:
  *   ENCINPCR<PDSTP>
  */
Result ENC_StopPositionDetection(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    uint32_t mode = 0U;
    Result retval = ERROR;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Sets the positiondetection stop command */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_SENSOR_PHASE_MODE)) {
        tmp = ENx->INPCR;
        tmp |= ENINPCR_PDSTP_SET;
        ENx->INPCR = tmp;
        retval = SUCCESS;
    } else {
        /* Do nothing */
    }
    return retval;
}

/**
  * @brief  Set the positiondetection start command(sensor mode (at timer count/at phase count))
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval  Success or not
  *   The value returned can be one of the following values:
  *   SUCCESS or ERROR
  * @register The used register:
  *   ENCINPCR<PDSTT>
  */
Result ENC_StartPositionDetection(TSB_EN_TypeDef * ENx)
{
    uint32_t tmp = 0U;
    uint32_t mode = 0U;
    Result retval = ERROR;
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get operation mode */
    mode = ENC_GetControlMode(ENx);
    /* Sets the positiondetection start command */
    if ((mode == ENC_SENSOR_TIME_MODE) || (mode == ENC_SENSOR_PHASE_MODE)) {
        tmp = ENx->INPCR;
        tmp |= ENINPCR_PDSTT_SET;
        ENx->INPCR = tmp;
        retval = SUCCESS;
    } else {
        /* Do nothing */
    }
    return retval;
}

/**
  * @brief  Set sample disable period
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1. 
  * @param  DelayValue: set sampling disaible period.
  *   This parameter can be one of the following values:
  *   0x00U-0xffU.
  * @retval None.
  * @register The used register:
  *   ENCSMPDLY<SMPDLY[7:0]>
  */
void ENC_SetSampleDelay(TSB_EN_TypeDef * ENx, uint32_t DelayValue)
{
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_8BITVALUE(DelayValue));
    /* set the sample delay value */
    ENx->SMPDLY = DelayValue;
}

/**
  * @brief  Get Input Monitor Status
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1. 
  * @retval Input Status of value.
  * @register The used register:
  *   ENCINPMON<SMPDLYZ><SMPDLYB><SMPDLYA>
  */
ENC_InputStatus ENC_GetInputStatus(TSB_EN_TypeDef * ENx)
{
    ENC_InputStatus value = { 0U };
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /*get input monitor value */
    value.All = ENx->INPMON;
    return value;
}

/**
  * @brief  Get Input Monitor Position 
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1. 
  * @retval  Input Position of value.
  * @register The used register:
  *   ENCINPMON<DETMONZ><DETMONB><DETMONA>
  */
ENC_InputPosition ENC_GetInputPosition(TSB_EN_TypeDef * ENx)
{
    ENC_InputPosition value = { 0U };
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /*get input monitor value */
    value.All = ENx->INPMON;
    return value;
}

/**
  * @brief  Sets the sampling frequency 
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @param  SampleClk: Sample Clock
  *   This parameter can be one of the following values:
  *   ENC_SAMPLE_CLK_FSYS_1,ENC_SAMPLE_CLK_FSYS_2,ENC_SAMPLE_CLK_FSYS_4,
  *   ENC_SAMPLE_CLK_FSYS_8
  * @retval None.
  * @register The used register:
  *   ENCCLKCR<SPLCKS[1:0]>
  */
void ENC_SetSampleClk(TSB_EN_TypeDef * ENx, uint32_t SampleClk)
{
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_FSYS_FACTOR(SampleClk));
    /* set sample clock   */
    ENx->CLKCR = SampleClk;
}

/**
  * @brief  Set Interrupt Control 
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @patam  INTSrc: interrupt state
  *   This parameter can be one of the following values: 
  *   ENC_INTERRUPT_TPLS,ENC_INTERRUPT_CAP,ENC_INTERRUPT_ERR,
  *   ENC_INTERRUPT_CMP,ENC_INTERRUPT_RID,ENC_INTERRUPT_MCMP,
  *   ENC_INTERRUPT_ALL or combination of the effective bits.
  * @param  NewState: disabled or enable the interrupt of channel 
  *   This parameter can be one of the following values:
  *   DISABLE or ENABLE        
  * @retval None.
  * @register The used register:
  *   ENCINTCR<MCMPIE><RLDIE><CMPIE><ERRIE><CAPIE><TPLSIE>
  */
void ENC_SetINTControl(TSB_EN_TypeDef * ENx, uint32_t INTSrc, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    assert_param(IS_ENC_INT_STATUS(INTSrc));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    /* set counter Intcr   */
    if (NewState == ENABLE) {
        /* Interrupt is enabled */
        ENx->INTCR |= INTSrc;
    } else {
        /* Interrupt is disabled */
        ENx->INTCR &= ~INTSrc;
    }
}

/**
  * @brief  Get the Interrupt Event Flag
  * @param  ENx: Select the encoder channel.
  *   This parameter can be one of the following values:
  *   EN0, EN1.
  * @retval Interrupt Event Flag of value.
  * @register The used register:
  *   ENCINTF<MCMPF><RLDCPF><INTCPF><ERRF><CAPF><TPLSF>
  */
ENC_INTFlag ENC_GetINTFlag(TSB_EN_TypeDef * ENx)
{
    ENC_INTFlag tmp = { 0U };
    /* Check the parameters */
    assert_param(IS_ENC_PERIPH(ENx));
    /* Get the  flag */
    tmp.All = ENx->INTF;
    return tmp;
}

/** @} */
/* End of group ENC_Exported_Functions */

/** @} */
/* End of group ENC */

/** @} */
/* End of group TX04_Periph_Driver */

#endif                          /* defined(__TMPM475_ENC_H) */
