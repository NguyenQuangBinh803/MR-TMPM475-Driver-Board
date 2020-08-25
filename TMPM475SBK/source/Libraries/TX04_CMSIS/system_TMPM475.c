/**
 *******************************************************************************
 * @file    system_TMPM475.c
 * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer Source File for the
 *          TOSHIBA 'TMPM475' Device Series 
 * @version V2.0.2.2
 * @date    2015/03/05
 * 
 * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LISENCE AGREEMENT.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2015 All rights reserved
 *******************************************************************************
 */

#include "TMPM475.h"

/*-------- <<< Start of configuration section >>> ----------------------------*/

/* Watchdog Timer (WD) Configuration */
#define WD_SETUP                (1U)
#define WDMOD_Val               (0x00000000UL)
#define WDCR_Val                (0x000000B1UL)

/* Clock Generator (CG) Configuration */
#ifdef INTERNAL_OSCILLATION
#define CLOCK_SETUP             0U         /* Use the internal oscilation */
#else
#define CLOCK_SETUP             1U         /* Use the external oscilation */
#endif

#define OSCCR_Val               (0x000A0104UL) /* OSCCR<OSCSEL> = 1, OSCCR<XEN2> = 0, OSCCR<XEN1> = 1, OSCCR<PLLON> = 1, <WUPSEL2> = 1*/
#define STBYCR_Val              (0x00000103UL)

#define CG_SYSCR_GEAR_MASK      (0xFFFFFFF8UL)
#define CG_SYSCR_GEAR_0         (0x00000000UL)
#define CG_SYSCR_GEAR_2         (0x00000004UL)
#define CG_SYSCR_GEAR_4         (0x00000005UL)
#define CG_SYSCR_GEAR_8         (0x00000006UL)
#define CG_SYSCR_GEAR_16        (0x00000007UL)
#define CG_SYSCR_GEAR_SET        CG_SYSCR_GEAR_0
#define SYSCR_Val               (0x00010000UL)

#define CG_10M_MUL_8_FPLL       (0x0000591EUL<<1U)
#define CG_10M_MUL_10_FPLL      (0x00005926UL<<1U)
#define CG_10M_MUL_12_FPLL      (0x000059AEUL<<1U)
#define PLLSEL_MASK             (0xFFFFFFFEUL)
#define PLLSEL_Ready             CG_10M_MUL_12_FPLL
#define PLLSEL_Val              (PLLSEL_Ready | 1U)

/*-------- <<< End of configuration section >>> ------------------------------*/

/*-------- DEFINES -----------------------------------------------------------*/
/* Define clocks */
#define OSC_10M                 (10000000ULL)
#define EXTALH                  OSC_10M     /* External high-speed oscillator freq */
#define XTALH                   OSC_10M     /* Internal high-speed oscillator freq */

/* Configure Warm-up time */
#define HZ_1M                  (1000000UL)
#define WU_TIME_EXT            (5000ULL)          /* warm-up time for EXT is 5ms   */
#define WU_TIME_PLL_100        (100ULL)           /* warm-up time for PLL is 100us */
#define WU_TIME_PLL_200        (200ULL)           /* warm-up time for PLL is 200us */
#define OSCCR_WUODR_MASK       (0x000FFFFFUL)
#define OSCCR_WUODR_EXT        ((WU_TIME_EXT * EXTALH / HZ_1M / 16UL) << 20U)     /* OSCCR<WUPODR[11:0]> = warm-up time(us) * EXTALH(MHz) / 16 */
#define OSCCR_WUODR_PLL_100    ((WU_TIME_PLL_100 * EXTALH / HZ_1M / 16UL) << 20U)
#define OSCCR_WUODR_PLL_200    ((WU_TIME_PLL_200 * EXTALH / HZ_1M / 16UL) << 20U)

#if (CLOCK_SETUP)               /* Clock(external) Setup */
/* Determine core clock frequency according to settings */
/* System clock is high-speed clock*/
#if (OSCCR_Val & (1U<<17))
  #define CORE_TALH (EXTALH)
#else
  #define CORE_TALH (XTALH)
#endif

#if ((PLLSEL_Val & (1U<<0)) && (OSCCR_Val & (1U<<2))) /* If PLL selected and enabled */
  #if (CORE_TALH == OSC_10M)                             /* If input is 10MHz */
    #if ((PLLSEL_Val & PLLSEL_MASK) == (CG_10M_MUL_8_FPLL))
      #define __CORE_CLK   (CORE_TALH * 8U )            /* output clock is 80MHz */
    #elif ((PLLSEL_Val & PLLSEL_MASK) == (CG_10M_MUL_10_FPLL))
      #define __CORE_CLK   (CORE_TALH * 10U )           /* output clock is 100MHz */
    #elif ((PLLSEL_Val & PLLSEL_MASK) == (CG_10M_MUL_12_FPLL))
      #define __CORE_CLK   (CORE_TALH * 12U )           /* output clock is 120MHz */   
    #else                               /* Gear -> reserved                   */
      #define __CORE_CLK   (0U)
    #endif
  #else
    #define __CORE_CLK   (CORE_TALH)
  #endif
#endif

#if   ((SYSCR_Val & 7U) == 0U)      /* Gear -> fc                         */
  #define __CORE_SYS   (__CORE_CLK)
#elif ((SYSCR_Val & 7U) == 4U)      /* Gear -> fc/2                       */
  #define __CORE_SYS   (__CORE_CLK / 2U)
#elif ((SYSCR_Val & 7U) == 5U)      /* Gear -> fc/4                       */
  #define __CORE_SYS   (__CORE_CLK / 4U)
#elif ((SYSCR_Val & 7U) == 6U)      /* Gear -> fc/8                       */
  #define __CORE_SYS   (__CORE_CLK / 8U)
#elif ((SYSCR_Val & 7U) == 7U)      /* Gear -> fc/16                       */
  #define __CORE_SYS   (__CORE_CLK / 16U)
#else                               /* Gear -> reserved                   */
  #define __CORE_SYS   (0U)
#endif

#else
  #define __CORE_SYS   (XTALH)
  
#endif                                                  /* clock Setup */

/* Clock Variable definitions */
uint32_t SystemCoreClock = __CORE_SYS;  /*!< System Clock Frequency (Core Clock) */

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Update SystemCoreClock according register values.
 */
void SystemCoreClockUpdate(void)
{
    /* Get Core Clock Frequency */
    uint32_t CoreClock = 0U;
    uint32_t CoreClockInput = 0U;
    /* Determine clock frequency according to clock register values */
    /* System clock is high-speed clock */
    if (TSB_CG_OSCCR_OSCSEL) {  /* If system clock is External high-speed oscillator freq */
        CoreClock = EXTALH;
    } else {                    /* If system clock is Internal high-speed oscillator freq */
        CoreClock = XTALH;
    }
    if (TSB_CG_PLLSEL_PLLSEL && TSB_CG_OSCCR_PLLON) {   /* If PLL selected and enabled */

        if (CoreClock == OSC_10M) {                                          /* If input is 10MHz */
            if ((PLLSEL_Val & PLLSEL_MASK) == (CG_10M_MUL_8_FPLL)) {     
                CoreClockInput = CoreClock * 8U;                             /* output clock is 80MHz */
            } else if ((PLLSEL_Val & PLLSEL_MASK) == (CG_10M_MUL_10_FPLL)) {
                CoreClockInput = CoreClock * 10U;                            /* output clock is 100MHz */             
            } else if ((PLLSEL_Val & PLLSEL_MASK) == (CG_10M_MUL_12_FPLL)) {
                CoreClockInput = CoreClock * 12U;                            /* output clock is 120MHz */             
            } else {
                CoreClockInput = 0U;                                         /* fc -> reserved            */
            }
        } else {
            CoreClockInput = 0U;
        }
    } else {                                     /* If PLL not used      */
        CoreClockInput = CoreClock;
    }
    switch (TSB_CG->SYSCR & 7U) {
    case 0U:                                 /* Gear -> fc          */
      SystemCoreClock = CoreClockInput;
      break;
    case 1U:
    case 2U:
    case 3U:                                 /* Gear -> reserved    */
      SystemCoreClock = 0U;
      break;
    case 4U:                                 /* Gear -> fc/2        */
      SystemCoreClock = CoreClockInput / 2U;
      break;
    case 5U:                                 /* Gear -> fc/4        */
      SystemCoreClock = CoreClockInput / 4U;
      break;
    case 6U:                                 /* Gear -> fc/8        */
      SystemCoreClock = CoreClockInput / 8U;
      break;
    case 7U:                                 /* Gear -> fc/16     */
      SystemCoreClock = CoreClockInput / 16U;
      break;
    default:
      SystemCoreClock = 0U;
      break;
    }
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit(void)
{
#if (WD_SETUP)                  /* Watchdog Setup */
    TSB_WD->MOD = WDMOD_Val;
    if (!TSB_WD_MOD_WDTE) {     /* If watchdog is to be disabled */
        TSB_WD->CR = WDCR_Val;
    } else {
        /* Do nothing */
    }
#endif

#if (CLOCK_SETUP)               /* Clock(external) Setup */
	/* Switch over from the internal oscillator to the external oscillator. */
	TSB_CG->OSCCR           &= OSCCR_WUODR_MASK;		/* ウォーミングアップタイマ設定 */
	TSB_CG->OSCCR           |= OSCCR_WUODR_EXT;			/* 5ms */
	TSB_CG_OSCCR_HOSCON      = 1U;
	TSB_CG_OSCCR_XEN1        = 1U;						/* 外部高速発振 許可 */
	TSB_CG_OSCCR_WUPSEL2     = 1U;						/* 高速発振器用ウォーミングアップタイマのソースクロック  外部高速発振 */
	TSB_CG_OSCCR_WUEON       = 1U;						/* ウォーミングアップ開始 */
	while (TSB_CG_OSCCR_WUEF) {
	}													/* Warm-up */
	
	TSB_CG_OSCCR_OSCSEL      = 1U;
	while (TSB_CG_OSCCR_OSCSEL != 1U) {					/* 外部発振選択を確認 */
	}													/* Confirm CGOSCCR<OSCSEL> become "1" */
	
	TSB_CG_OSCCR_XEN2        = 0U;						/* 内部高速発振 禁止 */

	/* Set PLL and select PLL as fc source */
	TSB_CG->OSCCR           &= OSCCR_WUODR_MASK;		/* ウォーミングアップタイマ設定 */
	TSB_CG->OSCCR           |= OSCCR_WUODR_PLL_100;		/* 100us */
	TSB_CG->PLLSEL          &= PLLSEL_MASK;
	TSB_CG->PLLSEL          |= PLLSEL_Ready;			/* PLL逓倍数設定 */
	TSB_CG_OSCCR_WUEON       = 1U;						/* ウォーミングアップ開始 PLL初期化安定待ち */
	while (TSB_CG_OSCCR_WUEF) {
	}													/* wait 100us for the PLL initialization time */
	
	TSB_CG->OSCCR           &= OSCCR_WUODR_MASK;		/* ウォーミングアップタイマ設定 */
	TSB_CG->OSCCR           |= OSCCR_WUODR_PLL_200;		/* 200us */
	TSB_CG_OSCCR_PLLON       = 1U;						/* PLL enabled */
	TSB_CG_OSCCR_WUEON       = 1U;						/* ウォーミングアップ開始 PLL安定待ち */
	while (TSB_CG_OSCCR_WUEF) {
	}													/* wait 200us for the PLL to be stabilized */
	
	TSB_CG_PLLSEL_PLLSEL     = 1U;

	/* Set a division ratio of the clock gear. */
	TSB_CG->SYSCR            = SYSCR_Val;
	TSB_CG->SYSCR           &= CG_SYSCR_GEAR_MASK;
	TSB_CG->SYSCR           |= CG_SYSCR_GEAR_SET;

	/* Initiallize standby control register */
	TSB_CG->STBYCR = STBYCR_Val;
#endif

}
