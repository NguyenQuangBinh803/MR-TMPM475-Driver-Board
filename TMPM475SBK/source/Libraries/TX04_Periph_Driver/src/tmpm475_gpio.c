/**
 *******************************************************************************
 * @file    tmpm475_gpio.c
 * @brief   This file provides API functions for GPIO driver.
 * @version V2.0.2.1
 * @date    2015/01/15
 * 
 * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LISENCE AGREEMENT.
 *
 * (C)Copyright TOSHIBA CORPORATION 2015 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "tmpm475_gpio.h"

#if defined(__TMPM475_GPIO_H)
/** @addtogroup TX04_Periph_Driver
  * @{
  */
/** @defgroup GPIO
  * @brief GPIO driver modules
  * @{
  */
#define GPIO_NUM (13U)          /*total number of gpio */

/**
  * @brief the base address of GPIO port.
  * 
  */
const uint32_t GPIO_Base[GPIO_NUM] = {
    TSB_PA_BASE, TSB_PB_BASE, TSB_PC_BASE, TSB_PD_BASE,
    TSB_PE_BASE, TSB_PF_BASE, TSB_PG_BASE, TSB_PH_BASE,
    TSB_PJ_BASE, TSB_PK_BASE, TSB_PL_BASE, TSB_PN_BASE, TSB_PP_BASE
};

/**
  * @brief:Information of gpio port.
  * Note: for bit0 to bit7 of each member below, its value '0' or '1' has the means:
  *       '0': that bit is not available
  *       '1': that bit is availabe
  * For example, if DATA = 0x7F, it mean the bit0 to bit6 of DATA register are avaiable.
  */
const GPIO_RegTypeDef GPIO_SFRs[GPIO_NUM] = {
/*        DATA    CR      FR1    FR2     FR3    OD     PUP    PDN    IE      */
/* PA */ {0xFFU, 0xFFU, {0xFFU, 0x70U, 0x00U}, 0xFFU, 0xFFU, 0xFFU, 0xFFU},
/* PB */ {0xFFU, 0xFFU, {0xFFU, 0x00U, 0x00U}, 0xFFU, 0xFFU, 0xFFU, 0xFFU},
/* PC */ {0xFFU, 0xFFU, {0xFFU, 0x00U, 0x00U}, 0xFFU, 0xFFU, 0xFFU, 0xFFU},
/* PD */ {0x7FU, 0x7FU, {0x77U, 0x13U, 0x00U}, 0x7FU, 0x7FU, 0x7FU, 0x7FU},
/* PE */ {0xFFU, 0xFFU, {0xFFU, 0x07U, 0x00U}, 0xFFU, 0xFFU, 0xFFU, 0xFFU},
/* PF */ {0x1FU, 0x1FU, {0x1FU, 0x1CU, 0x04U}, 0x1FU, 0x1FU, 0x1FU, 0x1FU},
/* PG */ {0xFFU, 0xFFU, {0xFFU, 0x00U, 0x00U}, 0xFFU, 0xFFU, 0xFFU, 0xFFU},
/* PH */ {0xFFU, 0xFFU, {0x00U, 0x00U, 0x00U}, 0xFFU, 0xFFU, 0xFFU, 0xFFU},
/* PJ */ {0xFFU, 0xFFU, {0x00U, 0x00U, 0x00U}, 0xFFU, 0xFFU, 0xFFU, 0xFFU},
/* PK */ {0x03U, 0x03U, {0x03U, 0x00U, 0x00U}, 0x03U, 0x03U, 0x03U, 0x03U},
/* PL */ {0x03U, 0x03U, {0x03U, 0x00U, 0x00U}, 0x03U, 0x03U, 0x03U, 0x03U},
/* PN */ {0x07U, 0x07U, {0x06U, 0x03U, 0x00U}, 0x07U, 0x07U, 0x07U, 0x07U},
/* PP */ {0x0FU, 0x0FU, {0x00U, 0x00U, 0x00U}, 0x0FU, 0x0FU, 0x0FU, 0x0FU}
};

/** @defgroup GPIO_Exported_Functions
  * @{
  */

/**
  * @brief  Read GPIO Data register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @retval Data: The value of DATA register.
  * @register The used registers:
  *   PxDATA (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
uint8_t GPIO_ReadData(GPIO_Port GPIO_x)
{
    uint8_t Data = 0U;
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];
    Data = (uint8_t) PORT->DATA;
    return Data;
}

/**
  * @brief  Read Bit of GPIO Data register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7.
  * @retval BitValue: The value of specified Bit.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_VALUE_0, GPIO_BIT_VALUE_1
  * @register The used registers:
  *   PxDATA (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
uint8_t GPIO_ReadDataBit(GPIO_Port GPIO_x, uint8_t Bit_x)
{
    uint8_t Data = 0U;
    uint8_t tmp = 0U;
    uint8_t BitValue = 0U;
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_GPIO_BIT(Bit_x));
    assert_param(IS_GPIO_BIT_DATA(GPIO_x, Bit_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];
    Data = (uint8_t) PORT->DATA;
    tmp = (uint8_t) (Data & Bit_x);
    if (tmp) {
        BitValue = GPIO_BIT_VALUE_1;
    } else {
        BitValue = GPIO_BIT_VALUE_0;
    }
    return (BitValue);
}

/**
  * @brief  Write specified value to GPIO DATA register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Data: specified value will be written to GPIO DATA register.
  * @retval None
  * @register The used registers:
  *   PxDATA (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
void GPIO_WriteData(GPIO_Port GPIO_x, uint8_t Data)
{

    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_GPIO_WRITE(GPIO_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];
    PORT->DATA = Data;
}

/**
  * @brief  Write to specified Bit of GPIO DATA register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Bit_x: Select GPIO pin, which can set as output.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @param BitValue:The value of specified Bit.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_VALUE_0, GPIO_BIT_VALUE_1
  * @retval None
  * @register The used registers:
  *   PxDATA  (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
void GPIO_WriteDataBit(GPIO_Port GPIO_x, uint8_t Bit_x, uint8_t BitValue)
{
    uint8_t tmp = 0U;
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_GPIO_BIT_VALUE(BitValue));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinCR;
    } else {
        /* Do nothing */
    }
    /* Check the parameters */
    assert_param(IS_GPIO_BIT_OUT(GPIO_x, Bit_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];
    tmp = GPIO_ReadData(GPIO_x);
    if (BitValue) {
        tmp |= Bit_x;
    } else {
        Bit_x = (~Bit_x);
        tmp &= Bit_x;
    }
    PORT->DATA = tmp;
}

/**
  * @brief  Initialize the specified GPIO pin.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  *   This parameter can be one of the following values:
  * @param  Bit_x: Select GPIO pin.
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @param  GPIO_InitStruct: The structure containing basic GPIO configuration.
  * @retval None
  * @register The used registers:
  *   PxIE (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  *   PxCR (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  *   PxPUP (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  *   PxPDN (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  *   PxOD (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
void GPIO_Init(GPIO_Port GPIO_x, uint8_t Bit_x, GPIO_InitTypeDef * GPIO_InitStruct)
{
    uint8_t tmp = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_POINTER_NOT_NULL(GPIO_InitStruct));
    assert_param(IS_GPIO_IO_MODE_STATE(GPIO_InitStruct->IOMode));
    assert_param(IS_GPIO_PULLUP_STATE(GPIO_InitStruct->PullUp));
    assert_param(IS_GPIO_PULLDOWN_STATE(GPIO_InitStruct->PullDown));
    assert_param(IS_GPIO_OPEN_DRAIN_STATE(GPIO_InitStruct->OpenDrain));

    tmp = GPIO_InitStruct->IOMode;
    switch (tmp) {
    case GPIO_INPUT_MODE:
        GPIO_SetInput(GPIO_x, Bit_x);
        break;
    case GPIO_OUTPUT_MODE:
        GPIO_SetOutput(GPIO_x, Bit_x);
        break;
    default:
        /* Do nothing */
        break;
    }
    tmp = GPIO_InitStruct->PullUp;
    switch (tmp) {
    case GPIO_PULLUP_ENABLE:
        GPIO_SetPullUp(GPIO_x, Bit_x, ENABLE);
        break;
    case GPIO_PULLUP_DISABLE:
        GPIO_SetPullUp(GPIO_x, Bit_x, DISABLE);
        break;
    default:
        /* Do nothing */
        break;
    }
    tmp = GPIO_InitStruct->PullDown;
    switch (tmp) {
    case GPIO_PULLDOWN_ENABLE:
        GPIO_SetPullDown(GPIO_x, Bit_x, ENABLE);
        break;
    case GPIO_PULLDOWN_DISABLE:
        GPIO_SetPullDown(GPIO_x, Bit_x, DISABLE);
        break;
    default:
        /* Do nothing */
        break;
    }
    tmp = GPIO_InitStruct->OpenDrain;
    switch (tmp) {
    case GPIO_OPEN_DRAIN_ENABLE:
        GPIO_SetOpenDrain(GPIO_x, Bit_x, ENABLE);
        break;
    case GPIO_OPEN_DRAIN_DISABLE:
        GPIO_SetOpenDrain(GPIO_x, Bit_x, DISABLE);
        break;
    default:
        /* Do nothing */
        break;
    }
}

/**
  * @brief  Set specified GPIO Pin as output port.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @retval None
  * @register The used registers:
  *   PxIE (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  *   PxCR (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  *   PxFRn (x can be A, B, C, D, E, F, G, K, N; n can be 1, 2, 3)
  */
void GPIO_SetOutput(GPIO_Port GPIO_x, uint8_t Bit_x)
{
    uint8_t tmp = 0U;
    uint32_t i;
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinCR;
    } else {
        /* Do nothing */
    }
    /* Check the parameters */
    assert_param(IS_GPIO_BIT_OUT(GPIO_x, Bit_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];
    tmp = (~Bit_x);
    for (i = 0U; i < FRMAX; i++) {
        if (GPIO_SFRs[GPIO_x].PinFR[i]) {
            PORT->FR[i] &= tmp;
        } else {
            /* Do nothing */
        }
    }
    if (GPIO_SFRs[GPIO_x].PinIE) {
        PORT->IE &= tmp;
    } else {
        /* Do nothing */
    }
    PORT->CR |= Bit_x;
}

/**
  * @brief  Set specified GPIO Pin as input port.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @retval None
  * @register The used registers:
  *   PxIE (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  *   PxCR (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  *   PxFRn (x can be A, B, C, D, E, F, G, K, N; n can be 1, 2, 3)
  */
void GPIO_SetInput(GPIO_Port GPIO_x, uint8_t Bit_x)
{
    uint8_t tmp = 0U;
    uint32_t i;
    TSB_Port_TypeDef *PORT = 0U;
    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinIE;
    } else {
        /* Do nothing */
    }
    /* Check the parameters */
    assert_param(IS_GPIO_BIT_IN(GPIO_x, Bit_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];
    tmp = (~Bit_x);
    for (i = 0U; i < FRMAX; i++) {
        if (GPIO_SFRs[GPIO_x].PinFR[i]) {
            PORT->FR[i] &= tmp;
        } else {
            /* Do nothing */
        }
    }
    if (GPIO_SFRs[GPIO_x].PinCR) {
        PORT->CR &= tmp;
    } else {
        /* Do nothing */
    }
    PORT->IE |= Bit_x;
}

/**
  * @brief  Set or clear the bit setting in output control register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @param NewState: The output state of the pin.
  *   This parameter can be one of the following values:
  *   ENABLE, DISABLE.
  * @retval None
  * @register The used registers:
  *   PxCR (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
void GPIO_SetOutputEnableReg(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinCR;
    } else {
        /* Do nothing */
    }
    /* Check the parameters */
    assert_param(IS_GPIO_BIT_OUT(GPIO_x, Bit_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];
    if (NewState == ENABLE) {
        PORT->CR |= Bit_x;
    } else {
        PORT->CR &= (~(uint32_t) Bit_x);
    }
}

/**
  * @brief  Set or clear the bit setting in input control register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @param NewState: The input state of the pin.
  *   This parameter can be one of the following values:
  *   ENABLE, DISABLE.
  * @retval None
  * @register The used registers:
  *   PxIE (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
void GPIO_SetInputEnableReg(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinIE;
    } else {
        /* Do nothing */
    }

    /* Check the parameters */
    assert_param(IS_GPIO_BIT_IN(GPIO_x, Bit_x));
    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];

    if (NewState == ENABLE) {
        PORT->IE |= Bit_x;
    } else {
        PORT->IE &= (~(uint32_t) Bit_x);
    }
}

/**
  * @brief  Enable or Disable pull-up function of specified GPIO Pin.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @param  NewState: New state of the Pull-Up function.
  *   This parameter can be one of the following values:
  *   ENABLE, DISABLE.
  * @retval None
  * @register The used registers:
  *   PxPUP (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
void GPIO_SetPullUp(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinPUP;
    } else {
        /* Do nothing */
    }
    /* Check the parameters */
    assert_param(IS_GPIO_BIT_PUP(GPIO_x, Bit_x));
    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];

    if (NewState == ENABLE) {
        PORT->PUP |= Bit_x;
    } else {
        PORT->PUP &= (~(uint32_t) Bit_x);
    }
}

/**
  * @brief  Enable or Disable pull-down function of specified GPIO Pin.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @param  NewState: New state of the Pull-Down function.
  *   This parameter can be one of the following values:
  *   ENABLE, DISABLE.
  * @retval None
  * @register The used register:
  *   PxPDN (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
void GPIO_SetPullDown(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinPDN;
    } else {
        /* Do nothing */
    }
    /* Check the parameters */
    assert_param(IS_GPIO_BIT_PDN(GPIO_x, Bit_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];

    if (NewState == ENABLE) {
        PORT->PDN |= Bit_x;
    } else {
        PORT->PDN &= (~(uint32_t) Bit_x);
    }
}

/**
  * @brief  Set specified GPIO Pin as open drain port or CMOS port.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC, GPIO_PD,
  *   GPIO_PE, GPIO_PF, GPIO_PG, GPIO_PH,
  *   GPIO_PJ, GPIO_PK, GPIO_PL, GPIO_PN, GPIO_PP.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @param  NewState: New state of the Open Drian function.
  *   This parameter can be one of the following values:
  *   ENABLE, DISABLE.
  * @retval None
  * @register The used registers:
  *   PxOD (x can be A, B, C, D, E, F, G, H, J, K, L, N, P)
  */
void GPIO_SetOpenDrain(GPIO_Port GPIO_x, uint8_t Bit_x, FunctionalState NewState)
{

    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinOD;
    } else {
        /* Do nothing */
    }
    /* Check the parameters */
    assert_param(IS_GPIO_BIT_OD(GPIO_x, Bit_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];

    if (NewState == ENABLE) {
        PORT->OD |= Bit_x;
    } else {
        PORT->OD &= (~(uint32_t) Bit_x);
    }
}

/**
  * @brief  Enable specified GPIO Function register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC,
  *   GPIO_PD, GPIO_PE, GPIO_PF,
  *   GPIO_PG, GPIO_PK, GPIO_PL, GPIO_PN.
  * @param  FuncReg_x: Select Function register of GPIO.
  *   This parameter can be one of the following values:
  *   GPIO_FUNC_REG_1, GPIO_FUNC_REG_2, GPIO_FUNC_REG_3.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @retval None
  * @register The used registers:
  *   PxFRn (x can be A, B, C, D, E, F, G, K, L, N; n can be 1, 2, 3)
  */
void GPIO_EnableFuncReg(GPIO_Port GPIO_x, uint8_t FuncReg_x, uint8_t Bit_x)
{
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_GPIO_FUNCTION_REG(FuncReg_x));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinFR[FuncReg_x];
    } else {
        /* Do nothing */
    }
    /* Check the parameters */
    assert_param(IS_GPIO_BIT_FR(GPIO_x, FuncReg_x, Bit_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];
    PORT->FR[FuncReg_x] |= Bit_x;
}

/**
  * @brief  Disable specified GPIO Function register.
  * @param  GPIO_x: Select GPIO port.
  *   This parameter can be one of the following values:
  *   GPIO_PA, GPIO_PB, GPIO_PC,
  *   GPIO_PD, GPIO_PE, GPIO_PF,
  *   GPIO_PG, GPIO_PK, GPIO_PL, GPIO_PN.
  * @param  FuncReg_x: Select Function register of GPIO.
  *   This parameter can be one of the following values:
  *   GPIO_FUNC_REG_1, GPIO_FUNC_REG_2, GPIO_FUNC_REG_3.
  * @param  Bit_x: Select GPIO pin.
  *   This parameter can be one of the following values:
  *   GPIO_BIT_0, GPIO_BIT_1, GPIO_BIT_2, GPIO_BIT_3,
  *   GPIO_BIT_4, GPIO_BIT_5, GPIO_BIT_6, GPIO_BIT_7,
  *   GPIO_BIT_ALL, or combination of the effective bits.
  * @retval None
  * @register The used registers:
  *   PxFRn (x can be A, B, C, D, E, F, G, K, L, N; n can be 1, 2, 3)
  */
void GPIO_DisableFuncReg(GPIO_Port GPIO_x, uint8_t FuncReg_x, uint8_t Bit_x)
{
    TSB_Port_TypeDef *PORT = 0U;

    /* Check the parameters */
    assert_param(IS_GPIO_PORT(GPIO_x));
    assert_param(IS_GPIO_FUNCTION_REG(FuncReg_x));

    if (Bit_x == GPIO_BIT_ALL) {
        Bit_x = GPIO_SFRs[GPIO_x].PinFR[FuncReg_x];
    } else {
        /* Do nothing */
    }
    /* Check the parameters */
    assert_param(IS_GPIO_BIT_FR(GPIO_x, FuncReg_x, Bit_x));

    PORT = (TSB_Port_TypeDef *) GPIO_Base[GPIO_x];

    PORT->FR[FuncReg_x] &= (~(uint32_t) Bit_x);
}

/** @} */
/* End of group GPIO_Exported_Functions */
/** @} */
/* End of group GPIO */
/** @} */
/* End of group TX04_Periph_Driver */
#endif                          /* defined(__TMPM475_GPIO_H) */
