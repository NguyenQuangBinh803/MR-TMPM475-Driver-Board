/**
 *******************************************************************************
 * @file    tmpm475_enc.h
 * @brief   This file provides all the functions prototypes for ENC driver. 
 * @version V2.0.2.1
 * @date    2014/11/30
 * 
 * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LISENCE AGREEMENT.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2014 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM475_ENC_H
#define __TMPM475_ENC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM475.h"
#include "tx04_common.h"

/** @addtogroup TX04_Periph_Driver
  * @{
  */
/** @addtogroup ENC
  * @{
  */

/** @addtogroup ENC Exported_types
  * @{
  */

/** @brief ENC input control structure definition
  * @{
  */
    typedef struct {
        uint32_t ModeType;      /* Encoder input mode selection */
        uint32_t PhaseType;     /* 2-phase / 3-phase input selection (sensor mode) */
        uint32_t EdgeType;      /* Edge selection of Z-phase (timer mode/phase counter mode) */
        uint32_t ZphaseStatus;  /* Enable or disable the Z-phase (Encoder mode/timer mode/phase counter mode) */
        uint32_t SetClearCount; /* Select the clear a match for Counter (timer mode) */
        uint32_t UpDownType;    /* Set the Up/Down counter mode (sensor phase mode/phase count mode) */
        uint32_t CountOperation;        /* Set Reload Register of count Enable/Disable */
        uint32_t CompareMode;   /* Compare  match or size (timer mode/sensor timer mode) */
        uint32_t DetectionDirection;    /* Set the detection direction for the decoder (encoder mode/sensor mode) */
        uint32_t SkipDetection; /* Sets skip detection (sensor mode) */
        uint32_t SelectCapture; /* Select trigger capture operation (sensor timer mode/sensor phase mode/timer mode/phase counter mode) */
        uint32_t PulseDivFactor;        /* Set the encoder pulse division factor (encoder mode/sensor event mode) */
    } ENC_InitTypeDef;

/** @brief ENC status flag union definition
  * @{
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t InputERRFlag:1;    /* bit 0, abnormal error (sensor mode) */
            uint32_t DecodeERRFlag:1;   /* bit 1, decoding detection error (encoder mode/sensor mode) */
            uint32_t SkipDetectionFlag:1;       /* bit 2, skip detection flag */
            uint32_t Reserved1:9;       /* bit 3 to bit 11, Reserved */
            uint32_t ZPhaseDetectFlag:1;        /* bit 12,ENC Z-phase detect flag */
            uint32_t RotationDirection:1;       /* bit 13,ENC rotation direction (encoder mode/sensor mode) */
            uint32_t ReverseErrorFlag:1;        /* bit 14,ENC sensor mode (at time count or phase count) reverse error flag */
            uint32_t Reserved2:17;      /* bit 15 to bit 31, Reserved */
        } Bit;
    } ENC_FlagStatus;

/** @brief ENC INT flag union definition
  * @{
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t RotationalFlag:1;  /* bit 0, Rotational edge divided pulse flag (encoder mode/sensor event mode) */
            uint32_t CaptureFlag:1;     /* bit 1, Capture flag (encoder mode/sensor event mode) */
            uint32_t DetectionERRFlag:1;        /* bit 2, Detection error flag (timer mode/phase counter mode) */
            uint32_t INTMatchFlag:1;    /* bit 3, INT match flag */
            uint32_t RLDMatchFlag:1;    /* bit 4, RELOAD match flag (encoder mode/sensor event mode) */
            uint32_t MCMPCompareFlag:1; /* bit 5, MCMP compare completion flag */
            uint32_t Reserved:26;       /* bit 6 to bit 31, Reserved */
        } Bit;
    } ENC_INTFlag;

/** @brief ENC Input Monitor status union definition
  * @{
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t NCAStatus:1;       /* bit 0, Monitors the status of ENCAx after noise cancelling */
            uint32_t NCBStatus:1;       /* bit 1, Monitors the status of ENCBx after noise cancelling */
            uint32_t NCZStatus:1;       /* bit 2, Monitors the status of ENCZx after noise cancelling */
            uint32_t Reserved:29;       /* bit 3 to bit 31, Reserved */
        } Bit;
    } ENC_InputStatus;
/** @brief ENC Input Monitor status union definition
  * @{
  */
    typedef union {
        uint32_t All;
        struct {
            uint32_t Reserved1:4;       /* bit 0 to bit 3, Reserved */
            uint32_t NCAPosition:1;     /* bit 4, Monitors the position detection status for NCA */
            uint32_t NCBPosition:1;     /* bit 5, Monitors the position detection status for NCB */
            uint32_t NCZPosition:1;     /* bit 6, Monitors the position detection status for NCZ */
            uint32_t Reserved2:25;      /* bit 7 to bit 31, Reserved */
        } Bit;
    } ENC_InputPosition;

/** @} */
/* End of ENC_Exported_types */

/** @defgroup ENC_Exported_Constants
  * @{
  */
#define EN0    TSB_EN0
#define EN1    TSB_EN1
#define IS_ENC_PERIPH(param)          (((param) == EN0) || \
                                       ((param) == EN1))

#define ENC_ENCODER_MODE              ((uint32_t)0x00000000)
#define ENC_SENSOR_EVENT_MODE         ((uint32_t)0x00000001)
#define ENC_SENSOR_TIME_MODE          ((uint32_t)0x00000002)
#define ENC_TIMER_MODE                ((uint32_t)0x00000003)
#define ENC_SENSOR_PHASE_MODE         ((uint32_t)0x00000006)
#define ENC_PHASE_COUNTER_MODE        ((uint32_t)0x00000007)
#define IS_ENC_MODE(param)            (((param) == ENC_ENCODER_MODE) || \
                                       ((param) == ENC_SENSOR_EVENT_MODE) || \
                                       ((param) == ENC_SENSOR_TIME_MODE) || \
                                       ((param) == ENC_TIMER_MODE) || \
                                       ((param) == ENC_SENSOR_PHASE_MODE) || \
                                       ((param) == ENC_PHASE_COUNTER_MODE))

#define IS_ENC_ENCODER_MODE(param)    (((param) == ENC_ENCODER_MODE))

#define IS_ENC_SW_MODE(param)         (((param) == ENC_TIMER_MODE) || \
                                       ((param) == ENC_SENSOR_TIME_MODE) || \
                                       ((param) == ENC_SENSOR_PHASE_MODE) || \
                                       ((param) == ENC_PHASE_COUNTER_MODE))

#define ENC_TWO_PHASE                 ((uint32_t)0x00000000)
#define ENC_THREE_PHASE               ((uint32_t)0x00000001)
#define IS_ENC_PHASE(param)           (((param) == ENC_TWO_PHASE) || \
                                       ((param) == ENC_THREE_PHASE))

#define ENC_ZPHASE_DISABLE            ((uint32_t)0x00000000)
#define ENC_ZPHASE_ENABLE             ((uint32_t)0x00000001)
#define IS_ENC_ZPHASE_STATUS(param)   (((param) == ENC_ZPHASE_ENABLE) || \
                                       ((param) == ENC_ZPHASE_DISABLE))

#define ENC_3PHASE_DISABLE            ((uint32_t)0x00000000)
#define ENC_3PHASE_ENABLE             ((uint32_t)0x00000001)
#define IS_ENC_3PHASE_STATUS(param)   (((param) == ENC_3PHASE_ENABLE) || \
                                       ((param) == ENC_3PHASE_DISABLE))

#define ENC_RISING_EDGE               ((uint32_t)0x00000001)
#define ENC_FALLING_EDGE              ((uint32_t)0x00000002)
#define ENC_BOTHEDGES_EDGE            ((uint32_t)0x00000003)
#define IS_ENC_EDGE(param)            (((param) == ENC_RISING_EDGE) || \
                                       ((param) == ENC_FALLING_EDGE) || \
                                       ((param) == ENC_BOTHEDGES_EDGE))

#define ENC_CLEAR_INT                 ((uint32_t)0x00000000)
#define ENC_CLEAR_RELOAD              ((uint32_t)0x00000001)
#define IS_ENC_CLEAR_CONDITION(param) (((param) == ENC_CLEAR_INT) || \
                                       ((param) == ENC_CLEAR_RELOAD))

#define ENC_COUNT_UP                  ((uint32_t)0x00000000)
#define ENC_COUNT_DOWN                ((uint32_t)0x00000001)
#define ENC_COUNT_AUTO                ((uint32_t)0x00000002)
#define IS_ENC_COUNT_MODE(param)      (((param) == ENC_COUNT_UP) || \
                                       ((param) == ENC_COUNT_DOWN) || \
                                       ((param) == ENC_COUNT_AUTO))

#define ENC_COUNT_CONTINUES           ((uint32_t)0x00000000)
#define ENC_COUNT_STOP                ((uint32_t)0x00000001)
#define IS_ENC_COUNT_STOP(param)      (((param) == ENC_COUNT_CONTINUES) || \
                                       ((param) == ENC_COUNT_STOP))

#define ENC_COMPARE_MATCH             ((uint32_t)0x00000000)
#define ENC_COMPARE_SIZE              ((uint32_t)0x00000001)
#define IS_ENC_COMPARE_MODE(param)    (((param) == ENC_COMPARE_MATCH) || \
                                       ((param) == ENC_COMPARE_SIZE))

#define ENC_CW_CCW_EDGE               ((uint32_t)0x00000000)
#define ENC_CW_EDGE                   ((uint32_t)0x00000001)
#define ENC_CCW_EDGE                  ((uint32_t)0x00000002)
#define ENC_CW_CCW_MAINTAIN           ((uint32_t)0x00000003)
#define IS_ENC_EDGE_DIRECTION(param)  (((param) == ENC_CW_CCW_EDGE) || \
                                       ((param) == ENC_CW_EDGE) || \
                                       ((param) == ENC_CCW_EDGE) || \
                                       ((param) == ENC_CW_CCW_MAINTAIN))

#define ENC_DETECTION_DISABLE         ((uint32_t)0x00000000)
#define ENC_DETECTION_ENABLE          ((uint32_t)0x00000001)
#define IS_ENC_DETECT_SKIP(param)     (((param) == ENC_DETECTION_ENABLE) || \
                                       ((param) == ENC_DETECTION_DISABLE))

#define ENC_CAPTURE_CLEAR             ((uint32_t)0x00000000)
#define ENC_CAPTURE_ONLY              ((uint32_t)0x00000001)
#define IS_ENC_CAPTURE_MODE(param)    (((param) == ENC_CAPTURE_CLEAR) || \
                                       ((param) == ENC_CAPTURE_ONLY))

/* Encoder pulse division factor */
#define ENC_PULSE_DIV1                ((uint32_t)0x00000000)
#define ENC_PULSE_DIV2                ((uint32_t)0x00000001)
#define ENC_PULSE_DIV4                ((uint32_t)0x00000002)
#define ENC_PULSE_DIV8                ((uint32_t)0x00000003)
#define ENC_PULSE_DIV16               ((uint32_t)0x00000004)
#define ENC_PULSE_DIV32               ((uint32_t)0x00000005)
#define ENC_PULSE_DIV64               ((uint32_t)0x00000006)
#define ENC_PULSE_DIV128              ((uint32_t)0x00000007)
#define IS_ENC_DIV_FACTOR(param)      (((param) == ENC_PULSE_DIV1) || \
                                       ((param) == ENC_PULSE_DIV2) || \
                                       ((param) == ENC_PULSE_DIV4) || \
                                       ((param) == ENC_PULSE_DIV8) || \
                                       ((param) == ENC_PULSE_DIV16) || \
                                       ((param) == ENC_PULSE_DIV32) || \
                                       ((param) == ENC_PULSE_DIV64) || \
                                       ((param) == ENC_PULSE_DIV128))

#define ENC_SAMPLE_CLK_FSYS_1         ((uint32_t)0x00000000)
#define ENC_SAMPLE_CLK_FSYS_2         ((uint32_t)0x00000001)
#define ENC_SAMPLE_CLK_FSYS_4         ((uint32_t)0x00000002)
#define ENC_SAMPLE_CLK_FSYS_8         ((uint32_t)0x00000003)
#define IS_ENC_FSYS_FACTOR(param)     (((param) == ENC_SAMPLE_CLK_FSYS_1) || \
                                       ((param) == ENC_SAMPLE_CLK_FSYS_2) || \
                                       ((param) == ENC_SAMPLE_CLK_FSYS_4) || \
                                       ((param) == ENC_SAMPLE_CLK_FSYS_8))

#define ENC_PWM_SAMPLE_DISABLE        ((uint32_t)0x00000000)
#define ENC_PWM_SAMPLE_ENABLE         ((uint32_t)0x00000001)
#define IS_ENC_PWM_SAMPLEMD(param)    (((param) == ENC_PWM_SAMPLE_DISABLE) || \
                                       ((param) == ENC_PWM_SAMPLE_ENABLE))

#define ENC_PWM_ON_PERIOD             ((uint32_t)0x00000000)
#define ENC_PWM_OFF_EDGE              ((uint32_t)0x00000001)
#define IS_ENC_EDGE_SELECT(param)     (((param) == ENC_PWM_ON_PERIOD) || \
                                       ((param) == ENC_PWM_OFF_EDGE))

#define ENC_PWM_COUNT_STOP            ((uint32_t)0x00000000)
#define ENC_PWM_COUNT_STOP_CLEAR      ((uint32_t)0x00000001)
#define IS_ENC_PWM_COUNTMD(param)     (((param) == ENC_PWM_COUNT_STOP) || \
                                       ((param) == ENC_PWM_COUNT_STOP_CLEAR))

#define ENC_INTERRUPT_TPLS            ((uint32_t)0x00000001)
#define ENC_INTERRUPT_CAP             ((uint32_t)0x00000002)
#define ENC_INTERRUPT_ERR             ((uint32_t)0x00000004)
#define ENC_INTERRUPT_CMP             ((uint32_t)0x00000008)
#define ENC_INTERRUPT_RID             ((uint32_t)0x00000010)
#define ENC_INTERRUPT_MCMP            ((uint32_t)0x00000020)
#define ENC_INTERRUPT_ALL             ((uint32_t)0x0000003F)
#define IS_ENC_INT_STATUS(param)      ((param) <= ENC_INTERRUPT_ALL)

#define IS_ENC_16BITVALUE(param)      (((param) <= 0xFFFFU))
#define IS_ENC_8BITVALUE(param)       (((param) <= 0xFFU))
#define IS_ENC_7BITVALUE(param)       (((param) <= 0x7FU))

/** @} */
/* End of group ENC_Exported_Constants */


/** @defgroup ENC_Exported_FunctionPrototypes
  * @{
  */
    void ENC_Enable(TSB_EN_TypeDef * ENx);
    void ENC_Disable(TSB_EN_TypeDef * ENx);
    void ENC_Init(TSB_EN_TypeDef * ENx, ENC_InitTypeDef * InitStruct);
    uint32_t ENC_GetControlMode(TSB_EN_TypeDef * ENx);
    Result ENC_SetSWCapture(TSB_EN_TypeDef * ENx);
    void ENC_ClearCounter(TSB_EN_TypeDef * ENx);
    ENC_FlagStatus ENC_GetENCFlag(TSB_EN_TypeDef * ENx);
    void ENC_SetCounterReload(TSB_EN_TypeDef * ENx, uint32_t PeriodValue);
    void ENC_SetCompareValue(TSB_EN_TypeDef * ENx, uint32_t CompareValue);
    uint32_t ENC_GetCompareValue(TSB_EN_TypeDef * ENx);
    uint32_t ENC_GetCounterValue(TSB_EN_TypeDef * ENx);

    void ENC_SetCounterMCMP(TSB_EN_TypeDef * ENx, uint32_t McmpValue);
    uint32_t ENC_GetCounterMCMP(TSB_EN_TypeDef * ENx);
    Result ENC_SetPhaseCountRate(TSB_EN_TypeDef * ENx, uint16_t RateValue);

    void ENC_SetNoiseCancelTime(TSB_EN_TypeDef * ENx, uint32_t Time);
    uint32_t ENC_GetNoiseCancelTime(TSB_EN_TypeDef * ENx);
    Result ENC_SelectSampleMode(TSB_EN_TypeDef * ENx, uint32_t SampleMode);
    uint32_t ENC_GetSampleMode(TSB_EN_TypeDef * ENx);
    Result ENC_SetPWMSampleMode(TSB_EN_TypeDef * ENx, uint32_t SampleEdge);
    uint32_t ENC_GetPWMSampleMode(TSB_EN_TypeDef * ENx);
    Result ENC_SetPWMStop(TSB_EN_TypeDef * ENx, uint32_t StopState);
    Result ENC_StopPositionDetection(TSB_EN_TypeDef * ENx);
    Result ENC_StartPositionDetection(TSB_EN_TypeDef * ENx);

    void ENC_SetSampleDelay(TSB_EN_TypeDef * ENx, uint32_t DelayValue);
    ENC_InputStatus ENC_GetInputStatus(TSB_EN_TypeDef * ENx);
    ENC_InputPosition ENC_GetInputPosition(TSB_EN_TypeDef * ENx);
    void ENC_SetSampleClk(TSB_EN_TypeDef * ENx, uint32_t SampleClk);
    void ENC_SetINTControl(TSB_EN_TypeDef * ENx, uint32_t INTSrc, FunctionalState NewState);
    ENC_INTFlag ENC_GetINTFlag(TSB_EN_TypeDef * ENx);

/** @} */
/* End of group ENC_Exported_FunctionPrototypes */

/** @} */
/* End of group ENC */

/** @} */
/* End of group TX04_Periph_Driver */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM475_ENC_H */
