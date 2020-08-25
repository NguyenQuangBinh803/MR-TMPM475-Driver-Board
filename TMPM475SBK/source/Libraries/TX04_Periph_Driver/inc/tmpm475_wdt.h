/**
 *******************************************************************************
 * @file    tmpm475_wdt.h
 * @brief   This file provides all the functions prototypes for WDT driver.
 * @version V2.0.2.1
 * @date    2015/01/15
 * 
 * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LISENCE AGREEMENT.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2015 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM475_WDT_H
#define __TMPM475_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "TMPM475.h"
#include "tx04_common.h"


/** @addtogroup TX04_Periph_Driver
  * @{
  */

/** @addtogroup WDT
  * @{
  */

/** @defgroup WDT_Exported_Types
  * @{
  */

/** 
  * @brief  WDT Init Structure definition 
  */

    typedef struct {
        uint32_t DetectTime;    /*!< Set WDT detection time. */
        uint32_t OverflowOutput;        /*!< Select "Generates NMI interrupt" or "Connects WDT out to reset". */
    } WDT_InitTypeDef;

/** @} */
/* End of group WDT_Exported_Types */

/** @defgroup WDT_Exported_Constants
  * @{
  */

#define WDT_DETECT_TIME_EXP_15          ((uint32_t)0x00000000)
#define WDT_DETECT_TIME_EXP_17          ((uint32_t)0x00000010)
#define WDT_DETECT_TIME_EXP_19          ((uint32_t)0x00000020)
#define WDT_DETECT_TIME_EXP_21          ((uint32_t)0x00000030)
#define WDT_DETECT_TIME_EXP_23          ((uint32_t)0x00000040)
#define WDT_DETECT_TIME_EXP_25          ((uint32_t)0x00000050)

#define IS_WDT_DETECT_TIME(param)   (((param) == WDT_DETECT_TIME_EXP_15) || \
                                     ((param) == WDT_DETECT_TIME_EXP_17) || \
                                     ((param) == WDT_DETECT_TIME_EXP_19) || \
                                     ((param) == WDT_DETECT_TIME_EXP_21) || \
                                     ((param) == WDT_DETECT_TIME_EXP_23) || \
                                     ((param) == WDT_DETECT_TIME_EXP_25))

#define WDT_WDOUT            ((uint32_t)0x00000001)
#define WDT_NMIINT           ((uint32_t)0x00000000)

#define IS_WDT_OUTPUT(param)      (((param) == WDT_WDOUT) || \
                                   ((param) == WDT_NMIINT))

/** @} */
/* End of WDT_Exported_Constants */

/** @addtogroup WDT_Exported_types
  * @{
  */

/** @} */
/* End of WDT_Exported_types */

/** @defgroup WDT_Exported_FunctionPrototypes
  * @{
  */

    void WDT_SetDetectTime(uint32_t DetectTime);
    void WDT_SetOverflowOutput(uint32_t OverflowOutput);
    void WDT_Init(WDT_InitTypeDef * InitStruct);
    void WDT_Enable(void);
    void WDT_Disable(void);
    void WDT_WriteClearCode(void);

/** @} */
/* End of WDT_Exported_FunctionPrototypes */

/** @} */
/* End of group WDT */

/** @} */
/* End of group TX04_Periph_Driver */


#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* __TMPM475_WDT_H */
