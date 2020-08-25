/**
 *******************************************************************************
 * @file    TMPM475.h
 * @brief   CMSIS Cortex-M4 Core Peripheral Access Layer Header File for the
 *          TOSHIBA 'TMPM475' Device Series
 * @version V2.0.2.5 (Tentative)
 * @date    2015/03/06
 * 
 * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LISENCE AGREEMENT.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2015 All rights reserved
 *******************************************************************************
 */

/** @addtogroup TOSHIBA_TX04_MICROCONTROLLER
  * @{
  */
  
/** @addtogroup TMPM475
  * @{
  */

#ifndef __TMPM475_H__
#define __TMPM475_H__

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Configuration_of_CMSIS
  * @{
  */

/** Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M4 Processor Exceptions Numbers ***************************************************************/
  NonMaskableInt_IRQn           = -14,       /*!< 2 Non Maskable Interrupt                                    */
  HardFault_IRQn                = -13,       /*!< 3 Cortex-M4 Hard Fault Interrupt                            */
  MemoryManagement_IRQn         = -12,       /*!< 4 Cortex-M4 Memory Management Interrupt                     */
  BusFault_IRQn                 = -11,       /*!< 5 Cortex-M4 Bus Fault Interrupt                             */
  UsageFault_IRQn               = -10,       /*!< 6 Cortex-M4 Usage Fault Interrupt                           */
  SVCall_IRQn                   = -5,        /*!< 11 Cortex-M4 SV Call Interrupt                              */
  DebugMonitor_IRQn             = -4,        /*!< 12 Cortex-M4 Debug Monitor Interrupt                        */
  PendSV_IRQn                   = -2,        /*!< 14 Cortex-M4 Pend SV Interrupt                              */
  SysTick_IRQn                  = -1,        /*!< 15 Cortex-M4 System Tick Interrupt                          */

/******  TMPM475 Specific Interrupt Numbers *******************************************************************/
  INT0_IRQn                     = 0,         /*!< Interrupt pin (PH0/AINA0/INT0)                              */
  INT1_IRQn                     = 1,         /*!< Interrupt pin (PH1/AINA1/INT1)                              */
  INT2_IRQn                     = 2,         /*!< Interrupt pin (PH2/AINA2/INT2)                              */
  INT3_IRQn                     = 3,         /*!< Interrupt pin (PA0/TB0IN/INT3)                              */
  INT4_IRQn                     = 4,         /*!< Interrupt pin (PA2/TB1IN/INT4)                              */
  INT5_IRQn                     = 5,         /*!< Interrupt pin (PE4/TB2IN/INT5)                              */
  INTRX0_IRQn                   = 6,         /*!< Serial reception (channel 0)                                */
  INTTX0_IRQn                   = 7,         /*!< Serial transmit (channel 0)                                 */
  INTRX1_IRQn                   = 8,         /*!< Serial reception (channel 1)                                */
  INTTX1_IRQn                   = 9,         /*!< Serial transmit (channel 1)                                 */
  INTVCN0_IRQn                  = 10,        /*!< Vector Engine interrupt 0                                   */
  INTVCN1_IRQn                  = 11,        /*!< Vector Engine interrupt 1                                   */
  INTEMG0_IRQn                  = 12,        /*!< PMD0 EMG interrupt                                          */
  INTEMG1_IRQn                  = 13,        /*!< PMD1 EMG interrupt                                          */
  INTOVV0_IRQn                  = 14,        /*!< PMD0 OVV interrupt                                          */
  INTOVV1_IRQn                  = 15,        /*!< PMD1 OVV interrupt                                          */
  INTADAPDA_IRQn                = 16,        /*!< ADC unit A conversion triggered by PMD0 is finished         */
  INTADBPDA_IRQn                = 17,        /*!< ADC unit B conversion triggered by PMD0 is finished         */
  INTADAPDB_IRQn                = 18,        /*!< ADC unit A conversion triggered by PMD1 is finished         */
  INTADBPDB_IRQn                = 19,        /*!< ADC unit B conversion triggered by PMD1 is finished         */
  INTTB00_IRQn                  = 20,        /*!< 16bit TMRB0 compare match detection 0 / Over flow           */
  INTTB01_IRQn                  = 21,        /*!< 16bit TMRB0 compare match detection 1                       */
  INTTB10_IRQn                  = 22,        /*!< 16bit TMRB1 compare match detection 0 / Over flow           */
  INTTB11_IRQn                  = 23,        /*!< 16bit TMRB1 compare match detection 1                       */
  INTTB40_IRQn                  = 24,        /*!< 16bit TMRB4 compare match detection 0 / Over flow           */
  INTTB41_IRQn                  = 25,        /*!< 16bit TMRB4 compare match detection 1                       */
  INTTB50_IRQn                  = 26,        /*!< 16bit TMRB5 compare match detection 0 / Over flow           */
  INTTB51_IRQn                  = 27,        /*!< 16bit TMRB5 compare match detection 1                       */
  INTPMD0_IRQn                  = 28,        /*!< PMD0 PWM interrupt                                          */
  INTPMD1_IRQn                  = 29,        /*!< PMD1 PWM interrupt                                          */
  INTCAP00_IRQn                 = 30,        /*!< 16bit TMRB0 input capture 0                                 */
  INTCAP01_IRQn                 = 31,        /*!< 16bit TMRB0 input capture 1                                 */
  INTCAP10_IRQn                 = 32,        /*!< 16bit TMRB1 input capture 0                                 */
  INTCAP11_IRQn                 = 33,        /*!< 16bit TMRB1 input capture 1                                 */
  INTCAP40_IRQn                 = 34,        /*!< 16bit TMRB4 input capture 0                                 */
  INTCAP41_IRQn                 = 35,        /*!< 16bit TMRB4 input capture 1                                 */
  INTCAP50_IRQn                 = 36,        /*!< 16bit TMRB5 input capture 0                                 */
  INTCAP51_IRQn                 = 37,        /*!< 16bit TMRB5 input capture 1                                 */
  INT6_IRQn                     = 38,        /*!< Interrupt pin (PE6/TB3IN/INT6)                              */
  INT7_IRQn                     = 39,        /*!< Interrupt pin (PE7/TB3OUT/INT7)                             */
  INTRX2_IRQn                   = 40,        /*!< Serial reception (channel 2)                                */
  INTTX2_IRQn                   = 41,        /*!< Serial transmit (channel 2)                                 */
  INTADACPA_IRQn                = 42,        /*!< ADCA conversion monitoring function interrupt A             */
  INTADBCPA_IRQn                = 43,        /*!< ADCB conversion monitoring function interrupt A             */
  INTADACPB_IRQn                = 44,        /*!< ADCA conversion monitoring function interrupt B             */
  INTADBCPB_IRQn                = 45,        /*!< ADCB conversion monitoring function interrupt B             */
  INTTB20_IRQn                  = 46,        /*!< 16bit TMRB2 compare match detection 0 / Over flow           */
  INTTB21_IRQn                  = 47,        /*!< 16bit TMRB2 compare match detection 1                       */
  INTTB30_IRQn                  = 48,        /*!< 16bit TMRB3 compare match detection 0 / Over flow           */
  INTTB31_IRQn                  = 49,        /*!< 16bit TMRB3 compare match detection 1                       */
  INTCAP20_IRQn                 = 50,        /*!< 16bit TMRB2 input capture 0                                 */
  INTCAP21_IRQn                 = 51,        /*!< 16bit TMRB2 input capture 1                                 */
  INTCAP30_IRQn                 = 52,        /*!< 16bit TMRB3 input capture 0                                 */
  INTCAP31_IRQn                 = 53,        /*!< 16bit TMRB3 input capture 1                                 */
  INTADASFT_IRQn                = 54,        /*!< ADC unit A conversion started by software is finished       */
  INTADBSFT_IRQn                = 55,        /*!< ADC unit B conversion started by software is finished       */
  INTADATMR_IRQn                = 56,        /*!< ADC unit A conversion triggered by timer is finished        */
  INTADBTMR_IRQn                = 57,        /*!< ADC unit B conversion triggered by timer is finished        */
  INT8_IRQn                     = 58,        /*!< Interrupt pin (PA7/TB4IN/INT8)                              */
  INT9_IRQn                     = 59,        /*!< Interrupt pin (PD3/INT9)                                    */
  INTA_IRQn                     = 60,        /*!< Interrupt pin (PL1/CA_RX/INTA)                              */
  INTB_IRQn                     = 61,        /*!< Interrupt pin (PL0/CA_TX/INTB)                              */
  INTENC00_IRQn                 = 62,        /*!< Encoder 0 interrupt 0                                       */
  INTENC01_IRQn                 = 63,        /*!< Encoder 0 interrupt 1                                       */
  INTRX3_IRQn                   = 64,        /*!< Serial reception (channel 3)                                */
  INTTX3_IRQn                   = 65,        /*!< Serial transmit (channel 3)                                 */
  INTTB60_IRQn                  = 66,        /*!< 16bit TMRB6 compare match detection 0 / Over flow           */
  INTTB61_IRQn                  = 67,        /*!< 16bit TMRB6 compare match detection 1                       */
  INTTB70_IRQn                  = 68,        /*!< 16bit TMRB7 compare match detection 0 / Over flow           */
  INTTB71_IRQn                  = 69,        /*!< 16bit TMRB7 compare match detection 1                       */
  INTCAP60_IRQn                 = 70,        /*!< 16bit TMRB6 input capture 0                                 */
  INTCAP61_IRQn                 = 71,        /*!< 16bit TMRB6 input capture 1                                 */
  INTCAP70_IRQn                 = 72,        /*!< 16bit TMRB7 input capture 0                                 */
  INTCAP71_IRQn                 = 73,        /*!< 16bit TMRB7 input capture 1                                 */
  INTC_IRQn                     = 74,        /*!< Interrupt pin (PJ6/AINB9/INTC)                              */
  INTD_IRQn                     = 75,        /*!< Interrupt pin (PJ7/AINB10/INTD)                             */
  INTE_IRQn                     = 76,        /*!< Interrupt pin (PK0/TRACEDATA3/INTE)                         */
  INTF_IRQn                     = 77,        /*!< Interrupt pin (PK1/TRACEDATA2/INTF)                         */
  INTVCT0_IRQn                  = 78,        /*!< Vector Engine 0 task is finished                            */
  INTVCT1_IRQn                  = 79,        /*!< Vector Engine 1 task is finished                            */
  INTSBI0_IRQn                  = 80,        /*!< Serial bus interface                                        */
  INTCANRX_IRQn                 = 81,        /*!< CAN transmit completion interrupt                           */
  INTCANTX_IRQn                 = 82,        /*!< CAN receive completion interrupt                            */
  INTCANGB_IRQn                 = 83,        /*!< CAN Global status interrupt                                 */
  INTTB80_IRQn                  = 84,        /*!< 16bit TMRB8 compare match detection 0 / Over flow           */
  INTTB81_IRQn                  = 85,        /*!< 16bit TMRB8 compare match detection 1                       */
  INTTB90_IRQn                  = 86,        /*!< 16bit TMRB9 compare match detection 0 / Over flow           */
  INTTB91_IRQn                  = 87,        /*!< 16bit TMRB9 compare match detection 1                       */
  INTCAP80_IRQn                 = 88,        /*!< 16bit TMRB8 input capture 0                                 */
  INTCAP81_IRQn                 = 89,        /*!< 16bit TMRB8 input capture 1                                 */
  INTCAP90_IRQn                 = 90,        /*!< 16bit TMRB9 input capture 0                                 */
  INTCAP91_IRQn                 = 91,        /*!< 16bit TMRB9 input capture 1                                 */
  INTDMACATC_IRQn               = 92,        /*!< DMA end of transfer                                         */
  INTDMACAERR_IRQn              = 93,        /*!< DMA transfer error                                          */
  INTENC10_IRQn                 = 94,        /*!< Encoder 1 interrupt 0                                       */
  INTENC11_IRQn                 = 95         /*!< Encoder 1 interrupt 1                                       */
} IRQn_Type;

/** Processor and Core Peripheral Section */

/* Configuration of the Cortex-M4 Processor and Core Peripherals */
#define __CM4_REV              0x0001       /*!< Cortex-M4 Core Revision                           */
#define __MPU_PRESENT             0         /*!< MPU present or not                                */
#define __FPU_PRESENT             1         /*!< FPU present or not                                */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels           */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used      */

/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm4.h"                       /* Cortex-M4 processor and core peripherals            */
#include "system_TMPM475.h"                 /* TMPM475 System                                      */

/** @addtogroup Device_Peripheral_registers
  * @{
  */

/** Device Specific Peripheral registers structures */

/**
  * @brief CAN Controller (TXCAN) Mailbox RAM
  */
typedef struct
{
  __IO uint32_t ID;                /*!< CAN Mailbox ID                               */
       uint32_t RESERVED0;
  __IO uint32_t TSVMCF;            /*!< CAN Mailbox Time Stamp Value and Message Control Field*/
       uint32_t RESERVED1;
  __IO uint32_t DL;                /*!< CAN Mailbox Lower Data Field (D3-D0)         */
       uint32_t RESERVED2;
  __IO uint32_t DH;                /*!< CAN Mailbox Upper Data Field (D7-D4)         */
} TSB_CANMB_TypeDef;

/**
  * @brief CAN Controller (TXCAN)
  */
typedef struct
{
  __IO uint32_t MC;                /*!< CAN Mailbox Configuration Register           */
       uint32_t RESERVED0;
  __IO uint32_t MD;                /*!< CAN Mailbox Direction Register               */
       uint32_t RESERVED1;
  __IO uint32_t TRS;               /*!< CAN Transmit Request Set Register            */
       uint32_t RESERVED2;
  __IO uint32_t TRR;               /*!< CAN Transmit Request Reset Register          */
       uint32_t RESERVED3;
  __IO uint32_t TA;                /*!< CAN Transmission Acknowledge Register        */
       uint32_t RESERVED4;
  __IO uint32_t AA;                /*!< CAN Abort Acknowledge Register               */
       uint32_t RESERVED5;
  __IO uint32_t RMP;               /*!< CAN Receive Message Pending Register         */
       uint32_t RESERVED6;
  __IO uint32_t RML;               /*!< CAN Receive Message Lost Register            */
       uint32_t RESERVED7;
  __IO uint32_t LAM;               /*!< CAN Local Acceptance Mask Register           */
       uint32_t RESERVED8;
  __IO uint32_t GAM;               /*!< CAN Global Acceptance Mask Register          */
       uint32_t RESERVED9;
  __IO uint32_t MCR;               /*!< CAN Master Control Register                  */
       uint32_t RESERVED10;
  __I  uint32_t GSR;               /*!< CAN Global Status Register                   */
       uint32_t RESERVED11;
  __IO uint32_t BCR1;              /*!< CAN Bit Configuration Register 1             */
       uint32_t RESERVED12;
  __IO uint32_t BCR2;              /*!< CAN Bit Configuration Register 2             */
       uint32_t RESERVED13;
  __IO uint32_t GIF;               /*!< CAN Global Interrupt Flag Register           */
       uint32_t RESERVED14;
  __IO uint32_t GIM;               /*!< CAN Global Interrupt Mask Register           */
       uint32_t RESERVED15;
  __IO uint32_t MBTIF;             /*!< CAN Mailbox Transmit Interrupt Flag Register */
       uint32_t RESERVED16;
  __IO uint32_t MBRIF;             /*!< CAN Mailbox Receive Interrupt Flag Register  */
       uint32_t RESERVED17;
  __IO uint32_t MBIM;              /*!< CAN Mailbox Interrupt Mask Register          */
       uint32_t RESERVED18;
  __IO uint32_t CDR;               /*!< CAN Change Data Request                      */
       uint32_t RESERVED19;
  __IO uint32_t RFP;               /*!< CAN Remote Frame Pending Register            */
       uint32_t RESERVED20;
  __IO uint32_t CEC;               /*!< CAN Error Counter Register                   */
       uint32_t RESERVED21;
  __IO uint32_t TSP;               /*!< CAN Time Stamp Counter Prescaler Register    */
       uint32_t RESERVED22;
  __IO uint32_t TSC;               /*!< CAN Time Stamp Counter Register              */
} TSB_CAN_TypeDef;

/**
  * @brief DMA Controller
  */
typedef struct
{
  __I  uint32_t STATUS;            /*!< DMA Status Register                          */
  __O  uint32_t CFG;               /*!< DMA Configuration Register                   */
  __IO uint32_t CTRLBASEPTR;       /*!< DMA Control Data Base Pointer Register       */
  __I  uint32_t ALTCTRLBASEPTR;    /*!< DMA Channel Alternate Control Data Base Pointer Register*/
       uint32_t RESERVED0;
  __O  uint32_t CHNLSWREQUEST;     /*!< DMA Channel Software Request Register        */
  __IO uint32_t CHNLUSEBURSTSET;   /*!< DMA Channel Useburst Set Register            */
  __O  uint32_t CHNLUSEBURSTCLR;   /*!< DMA Channel Useburst Clear Register          */
  __IO uint32_t CHNLREQMASKSET;    /*!< DMA Channel Request Mask Set Register        */
  __O  uint32_t CHNLREQMASKCLR;    /*!< DMA Channel Request Mask Clear Register      */
  __IO uint32_t CHNLENABLESET;     /*!< DMA Channel Enable Set Register              */
  __O  uint32_t CHNLENABLECLR;     /*!< DMA Channel Enable Clear Register            */
  __IO uint32_t CHNLPRIALTSET;     /*!< DMA Channel Primary-Alternate Set Register   */
  __O  uint32_t CHNLPRIALTCLR;     /*!< DMA Channel Primary-Alternate Clear Register */
  __IO uint32_t CHNLPRIORITYSET;   /*!< DMA Channel Priority Set Register            */
  __O  uint32_t CHNLPRIORITYCLR;   /*!< DMA Channel Priority Clear Register          */
       uint32_t RESERVED1[3];
  __IO uint32_t ERRCLR;            /*!< DMA Bus Error Clear Register                 */
} TSB_DMA_TypeDef;

/**
  * @brief DMA Interrupt Flag
  */
typedef struct
{
  __I  uint32_t FLGA;              /*!< DMA Flag Register A                          */
} TSB_DMAIF_TypeDef;

/**
  * @brief Port A
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port A Data Register                         */
  __IO uint32_t CR;                /*!< Port A Output Control Register               */
  __IO uint32_t FR1;               /*!< Port A Function Register 1                   */
  __IO uint32_t FR2;               /*!< Port A Function Register 2                   */
       uint32_t RESERVED0[6];
  __IO uint32_t OD;                /*!< Port A Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port A Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port A Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port A Input Control Register                */
} TSB_PA_TypeDef;

/**
  * @brief Port B
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port B Data Register                         */
  __IO uint32_t CR;                /*!< Port B Output Control Register               */
  __IO uint32_t FR1;               /*!< Port B Function Register 1                   */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< Port B Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port B Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port B Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port B Input Control Register                */
} TSB_PB_TypeDef;

/**
  * @brief Port C
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port C Data Register                         */
  __IO uint32_t CR;                /*!< Port C Output Control Register               */
  __IO uint32_t FR1;               /*!< Port C Function Register 1                   */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< Port C Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port C Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port C Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port C Input Control Register                */
} TSB_PC_TypeDef;

/**
  * @brief Port D
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port D Data Register                         */
  __IO uint32_t CR;                /*!< Port D Output Control Register               */
  __IO uint32_t FR1;               /*!< Port D Function Register 1                   */
  __IO uint32_t FR2;               /*!< Port D Function Register 2                   */
       uint32_t RESERVED0[6];
  __IO uint32_t OD;                /*!< Port D Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port D Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port D Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port D Input Control Register                */
} TSB_PD_TypeDef;

/**
  * @brief Port E
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port E Data Register                         */
  __IO uint32_t CR;                /*!< Port E Output Control Register               */
  __IO uint32_t FR1;               /*!< Port E Function Register 1                   */
  __IO uint32_t FR2;               /*!< Port E Function Register 2                   */
       uint32_t RESERVED0[6];
  __IO uint32_t OD;                /*!< Port E Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port E Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port E Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port E Input Control Register                */
} TSB_PE_TypeDef;

/**
  * @brief Port F
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port F Data Register                         */
  __IO uint32_t CR;                /*!< Port F Output Control Register               */
  __IO uint32_t FR1;               /*!< Port F Function Register 1                   */
  __IO uint32_t FR2;               /*!< Port F Function Register 2                   */
  __IO uint32_t FR3;               /*!< Port F Function Register 3                   */
       uint32_t RESERVED0[5];
  __IO uint32_t OD;                /*!< Port F Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port F Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port F Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port F Input Control Register                */
} TSB_PF_TypeDef;

/**
  * @brief Port G
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port G Data Register                         */
  __IO uint32_t CR;                /*!< Port G Output Control Register               */
  __IO uint32_t FR1;               /*!< Port G Function Register 1                   */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< Port G Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port G Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port G Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port G Input Control Register                */
} TSB_PG_TypeDef;

/**
  * @brief Port H
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port H Data Register                         */
  __IO uint32_t CR;                /*!< Port H Output Control Register               */
       uint32_t RESERVED0[8];
  __IO uint32_t OD;                /*!< Port H Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port H Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port H Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port H Input Control Register                */
} TSB_PH_TypeDef;

/**
  * @brief Port J
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port J Data Register                         */
  __IO uint32_t CR;                /*!< Port J Output Control Register               */
       uint32_t RESERVED0[8];
  __IO uint32_t OD;                /*!< Port J Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port J Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port J Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port J Input Control Register                */
} TSB_PJ_TypeDef;

/**
  * @brief Port K
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port K Data Register                         */
  __IO uint32_t CR;                /*!< Port K Output Control Register               */
  __IO uint32_t FR1;               /*!< Port K Function Register 1                   */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< Port K Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port K Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port K Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port K Input Control Register                */
} TSB_PK_TypeDef;

/**
  * @brief Port L
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port L Data Register                         */
  __IO uint32_t CR;                /*!< Port L Output Control Register               */
  __IO uint32_t FR1;               /*!< Port L Function Register 1                   */
       uint32_t RESERVED0[7];
  __IO uint32_t OD;                /*!< Port L Open Drain Control Register           */
  __IO uint32_t PUP;               /*!< Port L Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port L Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port L Input Control Register                */
} TSB_PL_TypeDef;

/**
  * @brief Port N
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port N Data Register                         */
  __IO uint32_t CR;                /*!< Port N Output Control Register               */
  __IO uint32_t FR1;               /*!< Port N Function Register 1                   */
  __IO uint32_t FR2;               /*!< Port N Function Register 2                   */
       uint32_t RESERVED0[6];
  __IO uint32_t OD;                /*!< Port N Open Drain Register                   */
  __IO uint32_t PUP;               /*!< Port N Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port N Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port N Input Control Register                */
} TSB_PN_TypeDef;

/**
  * @brief Port P
  */
typedef struct
{
  __IO uint32_t DATA;              /*!< Port P Data Register                         */
  __IO uint32_t CR;                /*!< Port P Output Control Register               */
       uint32_t RESERVED0[8];
  __IO uint32_t OD;                /*!< Port P Open Drain Register                   */
  __IO uint32_t PUP;               /*!< Port P Pull-up Control Register              */
  __IO uint32_t PDN;               /*!< Port P Pull-down Control Register            */
       uint32_t RESERVED1;
  __IO uint32_t IE;                /*!< Port P Input Control Register                */
} TSB_PP_TypeDef;

/**
  * @brief 16-bit Timer / Event Counters (TMRB)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< TB Enable Register                           */
  __IO uint32_t RUN;               /*!< TB RUN Register                              */
  __IO uint32_t CR;                /*!< TB Control Register                          */
  __IO uint32_t MOD;               /*!< TB Mode Register                             */
  __IO uint32_t FFCR;              /*!< TB Flip-Flop Control Register                */
  __I  uint32_t ST;                /*!< TB Status Register                           */
  __IO uint32_t IM;                /*!< TB Interrupt Mask Register                   */
  __I  uint32_t UC;                /*!< TB Up-counter Capture Register               */
  __IO uint32_t RG0;               /*!< TB RG0 Timer Register                        */
  __IO uint32_t RG1;               /*!< TB RG1 Timer Register                        */
  __I  uint32_t CP0;               /*!< TB CP0 Capture Register                      */
  __I  uint32_t CP1;               /*!< TB CP1 Capture Register                      */
} TSB_TB_TypeDef;

#if defined ( __CC_ARM   )           /* RealView Compiler */
#pragma anon_unions
#elif (defined (__ICCARM__))         /*  ICC Compiler     */
#pragma language=extended
#endif

/**
  * @brief Serial Bus Interface(SBI)
  */
typedef struct
{
  __IO uint32_t CR0;               /*!< SBI Control Register 0                       */
  __IO uint32_t CR1;               /*!< SBI Control Register 1 (I2C Mode)            */
  __IO uint32_t DBR;               /*!< SBI Data Buffer Register                     */
  __IO uint32_t I2CAR;             /*!< SBI I2C Bus Address Register                 */
union {
  __O  uint32_t CR2;               /*!< SBI Control Register 2 (I2C Mode)            */
  __I  uint32_t SR;                /*!< SBI Status Register (I2C Mode)               */
  };
  __IO uint32_t BR0;               /*!< SBI Baud Rate Register 0                     */
} TSB_SBI_TypeDef;

/**
  * @brief Serial Channel (SC)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< SC Enable Register                           */
  __IO uint32_t BUF;               /*!< SC Buffer Register                           */
  __IO uint32_t CR;                /*!< SC Control Register                          */
  __IO uint32_t MOD0;              /*!< SC Mode Control Register 0                   */
  __IO uint32_t BRCR;              /*!< SC Baud Rate Generator Control Register      */
  __IO uint32_t BRADD;             /*!< SC Baud Rate Generator Control Register 2    */
  __IO uint32_t MOD1;              /*!< SC Mode Control Register 1                   */
  __IO uint32_t MOD2;              /*!< SC Mode Control Register 2                   */
  __IO uint32_t RFC;               /*!< SC RX FIFO Configuration Register            */
  __IO uint32_t TFC;               /*!< SC TX FIFO Configuration Register            */
  __I  uint32_t RST;               /*!< SC RX FIFO Status Register                   */
  __I  uint32_t TST;               /*!< SC TX FIFO Status Register                   */
  __IO uint32_t FCNF;              /*!< SC FIFO Configuration Register               */
} TSB_SC_TypeDef;

/**
  * @brief Oscillation Frequency Detector (OFD)
  */
typedef struct
{
  __IO uint32_t CR1;               /*!< OFD Control Register 1                       */
  __IO uint32_t CR2;               /*!< OFD Control Register 2                       */
  __IO uint32_t MNPLLOFF;          /*!< OFD Lower Detection Frequency Setting Register*/
  __IO uint32_t MNPLLON;           /*!< OFD Lower Detection Frequency Setting Register*/
  __IO uint32_t MXPLLOFF;          /*!< OFD Higher Detection Frequency Setting Register*/
  __IO uint32_t MXPLLON;           /*!< OFD Higher Detection Frequency Setting Register*/
} TSB_OFD_TypeDef;

/**
  * @brief Watchdog Timer (WD)
  */
typedef struct
{
  __IO uint32_t MOD;               /*!< WD Mode Register                             */
  __O  uint32_t CR;                /*!< WD Control Register                          */
} TSB_WD_TypeDef;

/**
  * @brief Clock Generator (CG)
  */
typedef struct
{
  __IO uint32_t SYSCR;             /*!< System Control Register                      */
  __IO uint32_t OSCCR;             /*!< Oscillation Control Register                 */
  __IO uint32_t STBYCR;            /*!< Standby Control Register                     */
  __IO uint32_t PLLSEL;            /*!< PLL Selection Register                       */
       uint32_t RESERVED0;
  __O  uint32_t ICRCG;             /*!< CG Interrupt Request Clear Register          */
       uint32_t RESERVED1;
  __IO uint32_t RSTFLG;            /*!< Reset Flag Register                          */
  __IO uint32_t IMCGA;             /*!< CG Interrupt Mode Control Register A         */
  __IO uint32_t IMCGB;             /*!< CG Interrupt Mode Control Register B         */
  __IO uint32_t IMCGC;             /*!< CG Interrupt Mode Control Register C         */
  __IO uint32_t IMCGD;             /*!< CG Interrupt Mode Control Register D         */
       uint32_t RESERVED2[4];
  __IO uint32_t CKSTP;             /*!< Clock stop regiser for peripheral            */
} TSB_CG_TypeDef;

/**
  * @brief Internal High-speed Oscillation Adjustment
  */
typedef struct
{
  __IO uint32_t PRO;               /*!< Protect Register                             */
  __IO uint32_t EN;                /*!< Enable Register                              */
  __I  uint32_t INIT;              /*!< Initial Trimming Value Monitor Register      */
  __IO uint32_t SET;               /*!< Timming Value Setting Register               */
} TSB_TRMOSC_TypeDef;

/**
  * @brief Digital Noize FilterClock Control
  */
typedef struct
{
  __IO uint32_t CKCR;              /*!< Clcok Control                                */
  __IO uint32_t ENCR;              /*!< Enable Control                               */
} TSB_NF_TypeDef;

/**
  * @brief Voltage Detection Control Circuit
  */
typedef struct
{
  __IO uint32_t CR;                /*!< VD Control Register                          */
} TSB_VD_TypeDef;

/**
  * @brief Programmable Motor Driver (PMD)
  */
typedef struct
{
  __IO uint32_t MDEN;              /*!< PMD Enable Register                          */
  __IO uint32_t PORTMD;            /*!< Port Output Mode Register                    */
  __IO uint32_t MDCR;              /*!< PMD Control Register                         */
  __I  uint32_t CNTSTA;            /*!< PWM Counter Status Register                  */
  __I  uint32_t MDCNT;             /*!< PWM Counter Register                         */
  __IO uint32_t MDPRD;             /*!< PWM Period Register                          */
  __IO uint32_t CMPU;              /*!< PWM Compare U Register                       */
  __IO uint32_t CMPV;              /*!< PWM Compare V Register                       */
  __IO uint32_t CMPW;              /*!< PWM Compare W Register                       */
  __IO uint32_t MODESEL;           /*!< Mode Select Register                         */
  __IO uint32_t MDOUT;             /*!< PMD Conduction Control Register              */
  __IO uint32_t MDPOT;             /*!< PMD Output Setting Register                  */
  __O  uint32_t EMGREL;            /*!< EMG Release Register                         */
  __IO uint32_t EMGCR;             /*!< EMG Control Register                         */
  __I  uint32_t EMGSTA;            /*!< EMG Status Register                          */
  __IO uint32_t OVVCR;             /*!< OVV Control Register                         */
  __I  uint32_t OVVSTA;            /*!< OVV Status Register                          */
  __IO uint32_t DTR;               /*!< Dead Time Register                           */
  __IO uint32_t TRGCMP0;           /*!< Trigger Compare Register 0                   */
  __IO uint32_t TRGCMP1;           /*!< Trigger Compare Register 1                   */
  __IO uint32_t TRGCMP2;           /*!< Trigger Compare Register 2                   */
  __IO uint32_t TRGCMP3;           /*!< Trigger Compare Register 3                   */
  __IO uint32_t TRGCR;             /*!< Trigger Control Register                     */
  __IO uint32_t TRGMD;             /*!< Trigger Output Mode Setting Register         */
  __IO uint32_t TRGSEL;            /*!< Trigger Output Select Register               */
  __IO uint32_t TRGSYNCR;          /*!< Trigger Update Timing Setting Register       */
} TSB_PMD_TypeDef;

/**
  * @brief Encoder Input (ENC)
  */
typedef struct
{
  __IO uint32_t TNCR;              /*!< Encoder Control Register                     */
  __IO uint32_t RELOAD;            /*!< Reload Compare Register                      */
  __IO uint32_t INT;               /*!< INT Compare Register                         */
  __IO uint32_t CNT;               /*!< Counter/Capture Register                     */
  __IO uint32_t MCMP;              /*!< MCMP Compare Register                        */
  __IO uint32_t RATE;              /*!< Phase Count Rate Register                    */
  __I  uint32_t STS;               /*!< Status Register                              */
  __IO uint32_t INPCR;             /*!< Input Process Cntrol Register                */
  __IO uint32_t SMPDLY;            /*!< Sample Delay Register                        */
  __I  uint32_t INPMON;            /*!< Input Moniter Register                       */
  __IO uint32_t CLKCR;             /*!< Sample Clock Control Register                */
  __IO uint32_t INTCR;             /*!< Interrupt Reqyest Control Register           */
  __I  uint32_t INTF;              /*!< Interrupt Event Flag Register                */
} TSB_EN_TypeDef;

/**
  * @brief Vector Engine (VE)
  */
typedef struct
{
  __IO uint32_t EN;                /*!< VE enable/disable                            */
  __O  uint32_t CPURUNTRG;         /*!< CPU start trigger selection                  */
  __IO uint32_t TASKAPP;           /*!< Task selection                               */
  __IO uint32_t ACTSCH;            /*!< Operation schedule selection                 */
  __IO uint32_t REPTIME;           /*!< Schedule repeat count                        */
  __IO uint32_t TRGMODE;           /*!< Start trigger mode                           */
  __IO uint32_t ERRINTEN;          /*!< Error interrupt enable/disable               */
  __O  uint32_t COMPEND;           /*!< VE forced termination                        */
  __I  uint32_t ERRDET;            /*!< Error detection                              */
  __I  uint32_t SCHTASKRUN;        /*!< Schedule executing flag/executing task       */
       uint32_t RESERVED0;
  __IO uint32_t TMPREG0;           /*!< Temporary register                           */
  __IO uint32_t TMPREG1;           /*!< Temporary register                           */
  __IO uint32_t TMPREG2;           /*!< Temporary register                           */
  __IO uint32_t TMPREG3;           /*!< Temporary register                           */
  __IO uint32_t TMPREG4;           /*!< Temporary register                           */
  __IO uint32_t TMPREG5;           /*!< Temporary register                           */
  __IO uint32_t MCTLF;             /*!< Status flags                                 */
  __IO uint32_t MODE;              /*!< Task control mode                            */
  __IO uint32_t FMODE;             /*!< Flow control                                 */
  __IO uint32_t TPWM;              /*!< PWM period rate (PWM period [s] * maximum speed * 2^16) setting*/
  __IO uint32_t OMEGA;             /*!< Rotation speed (speed [Hz] / maximum speed * 2^15) setting*/
  __IO uint32_t THETA;             /*!< Motor phase (motor phase [deg] / 360 * 2^16) setting*/
  __IO uint32_t IDREF;             /*!< d-axis reference value (current [A] / maximum current * 2^15)*/
  __IO uint32_t IQREF;             /*!< q-axis reference value (current [A] / maximum current * 2^15)*/
  __IO uint32_t VD;                /*!< d-axis voltage (voltage [V] / maximum voltage * 2^31)*/
  __IO uint32_t VQ;                /*!< q-axis voltage (voltage [V] / maximum voltage * 2^31)*/
  __IO uint32_t CIDKI;             /*!< Integral coefficient for PI control of d-axis*/
  __IO uint32_t CIDKP;             /*!< Proportional coefficient for PI control of d-axis*/
  __IO uint32_t CIQKI;             /*!< Integral coefficient for PI control of q-axis*/
  __IO uint32_t CIQKP;             /*!< Proportional coefficient for PI control of q-axis*/
  __IO uint32_t VDIH;              /*!< Upper 32 bits of integral term (VDI ) of d-axis voltage*/
  __IO uint32_t VDILH;             /*!< Lower 32 bits of integral term (VDI) of d-axis voltage*/
  __IO uint32_t VQIH;              /*!< Upper 32 bits of integral term (VQI) of q-axis voltage*/
  __IO uint32_t VQILH;             /*!< Lower 32 bits of integral term (VQI) of q-axis voltage*/
  __IO uint32_t FPWMCHG;           /*!< Switching speed (for 2-phase modulation and shift PWM)*/
  __IO uint32_t MDPRD;             /*!< PWM period (to be set identically with PMD's PWM period)*/
  __IO uint32_t MINPLS;            /*!< Minimum pulse width                          */
  __IO uint32_t TRGCRC;            /*!< Synchronizing trigger correction value       */
  __IO uint32_t VDCL;              /*!< Cosine value at THETA for output conversion (Q15 data)*/
  __IO uint32_t COS;               /*!< Cosine value at THETA for output conversion (Q15 data)*/
  __IO uint32_t SIN;               /*!< Sine value at THETA for output conversion (Q15 data)*/
  __IO uint32_t COSM;              /*!< Previous cosine value for input processing (Q15 data)*/
  __IO uint32_t SINM;              /*!< Previous sine value for input processing (Q15 data)*/
  __IO uint32_t SECTOR;            /*!< Sector information (0-11)                    */
  __IO uint32_t SECTORM;           /*!< Previous sector information for input processing (0-11)*/
  __IO uint32_t IAO;               /*!< AD conversion result of a-phase zero-current */
  __IO uint32_t IBO;               /*!< AD conversion result of b-phase zero-current */
  __IO uint32_t ICO;               /*!< AD conversion result of c-phase zero-current */
  __IO uint32_t IAADC;             /*!< AD conversion result of a-phase current      */
  __IO uint32_t IBADC;             /*!< AD conversion result of b-phase current      */
  __IO uint32_t ICADC;             /*!< AD conversion result of c-phase current      */
  __IO uint32_t VDC;               /*!< DC supply voltage (voltage [V] / maximum voltage * 2^15)*/
  __IO uint32_t ID;                /*!< d-axis current (current [A] / maximum current * 2^31)*/
  __IO uint32_t IQ;                /*!< q-axis current (current [A] / maximum current * 2^31)*/
       uint32_t RESERVED1[39];
  __IO uint32_t TADC;              /*!< ADC start wait setting                       */
  __IO uint32_t CMPU;              /*!< PMD control: CMPU setting                    */
  __IO uint32_t CMPV;              /*!< PMD control: CMPV setting                    */
  __IO uint32_t CMPW;              /*!< PMD control: CMPW setting                    */
  __IO uint32_t OUTCR;             /*!< PMD control: Output control (MDOUT)          */
  __IO uint32_t TRGCMP0;           /*!< PMD control: TRGCMP0 setting                 */
  __IO uint32_t TRGCMP1;           /*!< PMD control: TRGCMP1 setting                 */
  __IO uint32_t TRGSEL;            /*!< PMD control: Trigger selection               */
  __IO uint32_t EMGRS;             /*!< PMD control: EMG return (EMGCR[EMGRS])       */
       uint32_t RESERVED2[8];
  __IO uint32_t PIOLIM;            /*!< PI controled output limit value setting      */
  __IO uint32_t CIDKG;             /*!< PI controled d-axis coefficient range setting*/
  __IO uint32_t CIQKG;             /*!< PI controled q-axis coefficient range setting*/
  __IO uint32_t VSLIM;             /*!< Voltage scalar limits                        */
  __IO uint32_t VDQ;               /*!< Voltage scalar                               */
  __IO uint32_t DELTA;             /*!< Declination angle                            */
  __IO uint32_t CPHI;              /*!< Motor interlinkage magnetic flux             */
  __IO uint32_t CLD;               /*!< Motor q-axis inductance                      */
  __IO uint32_t CLQ;               /*!< Motor d-axis inductance                      */
  __IO uint32_t CR;                /*!< Motor resistance value                       */
  __IO uint32_t CPHIG;             /*!< Motor magnetic flux range setting            */
  __IO uint32_t CLG;               /*!< Motor inductance range setting               */
  __IO uint32_t CRG;               /*!< Motor resistance range setting               */
  __IO uint32_t VDE;               /*!< Non-interference controled d-axis voltage    */
  __IO uint32_t VQE;               /*!< Non-interference controled q-axis voltage    */
  __IO uint32_t DTC;               /*!< Dead time compensation                       */
  __IO uint32_t HYS;               /*!< Hysteresis width for current discrimination  */
  __IO uint32_t DTCS;              /*!< Dead time compensation control / status      */
  __IO uint32_t PWMMAX;            /*!< PWM upper limit setting                      */
  __IO uint32_t PWMMIN;            /*!< PWM lower limit setting                      */
  __IO uint32_t THTCLP;            /*!< Clipped phase value setting                  */
} TSB_VE_TypeDef;

/**
  * @brief Analog-to-Digital Converter (AD)
  */
typedef struct
{
  __IO uint32_t CLK;               /*!< AD Conversion Clock Setting Register         */
  __IO uint32_t MOD0;              /*!< AD Mode Setting Register 0                   */
  __IO uint32_t MOD1;              /*!< AD Mode Setting Register 1                   */
  __I  uint32_t MOD2;              /*!< AD Mode Setting Register 2                   */
  __IO uint32_t CMPCR0;            /*!< AD Monitoring Setting Register 0             */
  __IO uint32_t CMPCR1;            /*!< AD Monitoring Setting Register 1             */
  __IO uint32_t CMP0;              /*!< AD Conversion Result Compare Register 0      */
  __IO uint32_t CMP1;              /*!< AD Conversion Result Compare Register 1      */
  __I  uint32_t REG0;              /*!< AD Conversion Result Register 0              */
  __I  uint32_t REG1;              /*!< AD Conversion Result Register 1              */
  __I  uint32_t REG2;              /*!< AD Conversion Result Register 2              */
  __I  uint32_t REG3;              /*!< AD Conversion Result Register 3              */
  __I  uint32_t REG4;              /*!< AD Conversion Result Register 4              */
  __I  uint32_t REG5;              /*!< AD Conversion Result Register 5              */
  __I  uint32_t REG6;              /*!< AD Conversion Result Register 6              */
  __I  uint32_t REG7;              /*!< AD Conversion Result Register 7              */
  __I  uint32_t REG8;              /*!< AD Conversion Result Register 8              */
  __I  uint32_t REG9;              /*!< AD Conversion Result Register 9              */
  __I  uint32_t REG10;             /*!< AD Conversion Result Register 10             */
  __I  uint32_t REG11;             /*!< AD Conversion Result Register 11             */
  __IO uint32_t PSEL0;             /*!< PMD Trigger Program Number Select Register 0 */
  __IO uint32_t PSEL1;             /*!< PMD Trigger Program Number Select Register 1 */
  __IO uint32_t PSEL2;             /*!< PMD Trigger Program Number Select Register 2 */
  __IO uint32_t PSEL3;             /*!< PMD Trigger Program Number Select Register 3 */
  __IO uint32_t PSEL4;             /*!< PMD Trigger Program Number Select Register 4 */
  __IO uint32_t PSEL5;             /*!< PMD Trigger Program Number Select Register 5 */
  __IO uint32_t PSEL6;             /*!< PMD Trigger Program Number Select Register 6 */
  __IO uint32_t PSEL7;             /*!< PMD Trigger Program Number Select Register 7 */
  __IO uint32_t PSEL8;             /*!< PMD Trigger Program Number Select Register 8 */
  __IO uint32_t PSEL9;             /*!< PMD Trigger Program Number Select Register 9 */
  __IO uint32_t PSEL10;            /*!< PMD Trigger Program Number Select Register 10*/
  __IO uint32_t PSEL11;            /*!< PMD Trigger Program Number Select Register 11*/
  __IO uint32_t PINTS0;            /*!< PMD Trigger Interrupt Select Register 0      */
  __IO uint32_t PINTS1;            /*!< PMD Trigger Interrupt Select Register 1      */
  __IO uint32_t PINTS2;            /*!< PMD Trigger Interrupt Select Register 2      */
  __IO uint32_t PINTS3;            /*!< PMD Trigger Interrupt Select Register 3      */
  __IO uint32_t PINTS4;            /*!< PMD Trigger Interrupt Select Register 4      */
  __IO uint32_t PINTS5;            /*!< PMD Trigger Interrupt Select Register 5      */
  __IO uint32_t PSET0;             /*!< PMD Trigger Program Register 0               */
  __IO uint32_t PSET1;             /*!< PMD Trigger Program Register 1               */
  __IO uint32_t PSET2;             /*!< PMD Trigger Program Register 2               */
  __IO uint32_t PSET3;             /*!< PMD Trigger Program Register 3               */
  __IO uint32_t PSET4;             /*!< PMD Trigger Program Register 4               */
  __IO uint32_t PSET5;             /*!< PMD Trigger Program Register 5               */
  __IO uint32_t TSET03;            /*!< Timer Trigger Program Register 03            */
  __IO uint32_t TSET47;            /*!< Timer Trigger Program Register 47            */
  __IO uint32_t TSET811;           /*!< Timer Trigger Program Register 811           */
  __IO uint32_t SSET03;            /*!< Software Trigger Program Register 03         */
  __IO uint32_t SSET47;            /*!< Software Trigger Program Register 47         */
  __IO uint32_t SSET811;           /*!< Software Trigger Program Register 811        */
  __IO uint32_t ASET03;            /*!< Constant Conversion Program Register 03      */
  __IO uint32_t ASET47;            /*!< Constant Conversion Program Register 47      */
  __IO uint32_t ASET811;           /*!< Constant Conversion Program Register 811     */
  __IO uint32_t MOD3;              /*!< Mode setting Register 3                      */
  __IO uint32_t MOD4;              /*!< Mode setting Register 4                      */
  __IO uint32_t MOD5;              /*!< Mode setting Register 5                      */
} TSB_AD_TypeDef;

/**
  * @brief Flash Control (FC)
  */
typedef struct
{
       uint32_t RESERVED0[4];
  __IO uint32_t SECBIT;            /*!< Security Bit Register                        */
       uint32_t RESERVED1[3];
  __I  uint32_t PSR0;              /*!< Protect Status Register 0                    */
       uint32_t RESERVED2[55];
  __I  uint32_t SR;                /*!< Status Register                              */
  __I  uint32_t SWPSR;             /*!< Swap Status Register                         */
       uint32_t RESERVED3[14];
  __IO uint32_t AREASEL;           /*!< Area Selection Register                      */
       uint32_t RESERVED4;
  __IO uint32_t CR;                /*!< Control Register                             */
  __IO uint32_t STSCLR;            /*!< Status Clear Register                        */
  __IO uint32_t WCLKCR;            /*!< WCLK Configuration Register                  */
  __IO uint32_t PROGCR;            /*!< Program Counter Configuration Register       */
  __IO uint32_t ERASECR;           /*!< Erase Counter Configuration Register         */
} TSB_FC_TypeDef;


/* Memory map */
#define FLASH_BASE            (0x00000000UL)
#define RAM_BASE              (0x20000000UL)
#define PERI_BASE             (0x40000000UL)


#define TSB_CANMB0_BASE            (PERI_BASE  + 0x0005000UL)
#define TSB_CANMB1_BASE            (PERI_BASE  + 0x0005020UL)
#define TSB_CANMB2_BASE            (PERI_BASE  + 0x0005040UL)
#define TSB_CANMB3_BASE            (PERI_BASE  + 0x0005060UL)
#define TSB_CANMB4_BASE            (PERI_BASE  + 0x0005080UL)
#define TSB_CANMB5_BASE            (PERI_BASE  + 0x00050A0UL)
#define TSB_CANMB6_BASE            (PERI_BASE  + 0x00050C0UL)
#define TSB_CANMB7_BASE            (PERI_BASE  + 0x00050E0UL)
#define TSB_CANMB8_BASE            (PERI_BASE  + 0x0005100UL)
#define TSB_CANMB9_BASE            (PERI_BASE  + 0x0005120UL)
#define TSB_CANMB10_BASE           (PERI_BASE  + 0x0005140UL)
#define TSB_CANMB11_BASE           (PERI_BASE  + 0x0005160UL)
#define TSB_CANMB12_BASE           (PERI_BASE  + 0x0005180UL)
#define TSB_CANMB13_BASE           (PERI_BASE  + 0x00051A0UL)
#define TSB_CANMB14_BASE           (PERI_BASE  + 0x00051C0UL)
#define TSB_CANMB15_BASE           (PERI_BASE  + 0x00051E0UL)
#define TSB_CANMB16_BASE           (PERI_BASE  + 0x0005200UL)
#define TSB_CANMB17_BASE           (PERI_BASE  + 0x0005220UL)
#define TSB_CANMB18_BASE           (PERI_BASE  + 0x0005240UL)
#define TSB_CANMB19_BASE           (PERI_BASE  + 0x0005260UL)
#define TSB_CANMB20_BASE           (PERI_BASE  + 0x0005280UL)
#define TSB_CANMB21_BASE           (PERI_BASE  + 0x00052A0UL)
#define TSB_CANMB22_BASE           (PERI_BASE  + 0x00052C0UL)
#define TSB_CANMB23_BASE           (PERI_BASE  + 0x00052E0UL)
#define TSB_CANMB24_BASE           (PERI_BASE  + 0x0005300UL)
#define TSB_CANMB25_BASE           (PERI_BASE  + 0x0005320UL)
#define TSB_CANMB26_BASE           (PERI_BASE  + 0x0005340UL)
#define TSB_CANMB27_BASE           (PERI_BASE  + 0x0005360UL)
#define TSB_CANMB28_BASE           (PERI_BASE  + 0x0005380UL)
#define TSB_CANMB29_BASE           (PERI_BASE  + 0x00053A0UL)
#define TSB_CANMB30_BASE           (PERI_BASE  + 0x00053C0UL)
#define TSB_CANMB31_BASE           (PERI_BASE  + 0x00053E0UL)
#define TSB_CAN_BASE               (PERI_BASE  + 0x0005400UL)
#define TSB_DMA_BASE               (PERI_BASE  + 0x004C000UL)
#define TSB_DMAIF_BASE             (PERI_BASE  + 0x005F000UL)
#define TSB_PA_BASE                (PERI_BASE  + 0x00C0000UL)
#define TSB_PB_BASE                (PERI_BASE  + 0x00C0100UL)
#define TSB_PC_BASE                (PERI_BASE  + 0x00C0200UL)
#define TSB_PD_BASE                (PERI_BASE  + 0x00C0300UL)
#define TSB_PE_BASE                (PERI_BASE  + 0x00C0400UL)
#define TSB_PF_BASE                (PERI_BASE  + 0x00C0500UL)
#define TSB_PG_BASE                (PERI_BASE  + 0x00C0600UL)
#define TSB_PH_BASE                (PERI_BASE  + 0x00C0700UL)
#define TSB_PJ_BASE                (PERI_BASE  + 0x00C0800UL)
#define TSB_PK_BASE                (PERI_BASE  + 0x00C0900UL)
#define TSB_PL_BASE                (PERI_BASE  + 0x00C0A00UL)
#define TSB_PN_BASE                (PERI_BASE  + 0x00C0C00UL)
#define TSB_PP_BASE                (PERI_BASE  + 0x00C0D00UL)
#define TSB_TB0_BASE               (PERI_BASE  + 0x00C4000UL)
#define TSB_TB1_BASE               (PERI_BASE  + 0x00C4100UL)
#define TSB_TB2_BASE               (PERI_BASE  + 0x00C4200UL)
#define TSB_TB3_BASE               (PERI_BASE  + 0x00C4300UL)
#define TSB_TB4_BASE               (PERI_BASE  + 0x00C4400UL)
#define TSB_TB5_BASE               (PERI_BASE  + 0x00C4500UL)
#define TSB_TB6_BASE               (PERI_BASE  + 0x00C4600UL)
#define TSB_TB7_BASE               (PERI_BASE  + 0x00C4700UL)
#define TSB_TB8_BASE               (PERI_BASE  + 0x00C4800UL)
#define TSB_TB9_BASE               (PERI_BASE  + 0x00C4900UL)
#define TSB_SBI_BASE               (PERI_BASE  + 0x00E0000UL)
#define TSB_SC0_BASE               (PERI_BASE  + 0x00E1000UL)
#define TSB_SC1_BASE               (PERI_BASE  + 0x00E1100UL)
#define TSB_SC2_BASE               (PERI_BASE  + 0x00E1200UL)
#define TSB_SC3_BASE               (PERI_BASE  + 0x00E1300UL)
#define TSB_OFD_BASE               (PERI_BASE  + 0x00F1000UL)
#define TSB_WD_BASE                (PERI_BASE  + 0x00F2000UL)
#define TSB_CG_BASE                (PERI_BASE  + 0x00F3000UL)
#define TSB_TRMOSC_BASE            (PERI_BASE  + 0x00F3200UL)
#define TSB_NF_BASE                (PERI_BASE  + 0x00F3400UL)
#define TSB_VD_BASE                (PERI_BASE  + 0x00F4000UL)
#define TSB_PMD0_BASE              (PERI_BASE  + 0x00F6000UL)
#define TSB_PMD1_BASE              (PERI_BASE  + 0x00F6100UL)
#define TSB_EN0_BASE               (PERI_BASE  + 0x00F7000UL)
#define TSB_EN1_BASE               (PERI_BASE  + 0x00F7100UL)
#define TSB_VE0_BASE               (PERI_BASE  + 0x00F8000UL)
#define TSB_VE1_BASE               (PERI_BASE  + 0x00F8400UL)
#define TSB_ADA_BASE               (PERI_BASE  + 0x00FD000UL)
#define TSB_ADB_BASE               (PERI_BASE  + 0x00FD100UL)
#define TSB_FC_BASE                (PERI_BASE  + 0x1DFF0000UL)


/* Peripheral declaration */
#define TSB_CANMB0                 ((  TSB_CANMB_TypeDef *)TSB_CANMB0_BASE)
#define TSB_CANMB1                 ((  TSB_CANMB_TypeDef *)TSB_CANMB1_BASE)
#define TSB_CANMB2                 ((  TSB_CANMB_TypeDef *)TSB_CANMB2_BASE)
#define TSB_CANMB3                 ((  TSB_CANMB_TypeDef *)TSB_CANMB3_BASE)
#define TSB_CANMB4                 ((  TSB_CANMB_TypeDef *)TSB_CANMB4_BASE)
#define TSB_CANMB5                 ((  TSB_CANMB_TypeDef *)TSB_CANMB5_BASE)
#define TSB_CANMB6                 ((  TSB_CANMB_TypeDef *)TSB_CANMB6_BASE)
#define TSB_CANMB7                 ((  TSB_CANMB_TypeDef *)TSB_CANMB7_BASE)
#define TSB_CANMB8                 ((  TSB_CANMB_TypeDef *)TSB_CANMB8_BASE)
#define TSB_CANMB9                 ((  TSB_CANMB_TypeDef *)TSB_CANMB9_BASE)
#define TSB_CANMB10                ((  TSB_CANMB_TypeDef *)TSB_CANMB10_BASE)
#define TSB_CANMB11                ((  TSB_CANMB_TypeDef *)TSB_CANMB11_BASE)
#define TSB_CANMB12                ((  TSB_CANMB_TypeDef *)TSB_CANMB12_BASE)
#define TSB_CANMB13                ((  TSB_CANMB_TypeDef *)TSB_CANMB13_BASE)
#define TSB_CANMB14                ((  TSB_CANMB_TypeDef *)TSB_CANMB14_BASE)
#define TSB_CANMB15                ((  TSB_CANMB_TypeDef *)TSB_CANMB15_BASE)
#define TSB_CANMB16                ((  TSB_CANMB_TypeDef *)TSB_CANMB16_BASE)
#define TSB_CANMB17                ((  TSB_CANMB_TypeDef *)TSB_CANMB17_BASE)
#define TSB_CANMB18                ((  TSB_CANMB_TypeDef *)TSB_CANMB18_BASE)
#define TSB_CANMB19                ((  TSB_CANMB_TypeDef *)TSB_CANMB19_BASE)
#define TSB_CANMB20                ((  TSB_CANMB_TypeDef *)TSB_CANMB20_BASE)
#define TSB_CANMB21                ((  TSB_CANMB_TypeDef *)TSB_CANMB21_BASE)
#define TSB_CANMB22                ((  TSB_CANMB_TypeDef *)TSB_CANMB22_BASE)
#define TSB_CANMB23                ((  TSB_CANMB_TypeDef *)TSB_CANMB23_BASE)
#define TSB_CANMB24                ((  TSB_CANMB_TypeDef *)TSB_CANMB24_BASE)
#define TSB_CANMB25                ((  TSB_CANMB_TypeDef *)TSB_CANMB25_BASE)
#define TSB_CANMB26                ((  TSB_CANMB_TypeDef *)TSB_CANMB26_BASE)
#define TSB_CANMB27                ((  TSB_CANMB_TypeDef *)TSB_CANMB27_BASE)
#define TSB_CANMB28                ((  TSB_CANMB_TypeDef *)TSB_CANMB28_BASE)
#define TSB_CANMB29                ((  TSB_CANMB_TypeDef *)TSB_CANMB29_BASE)
#define TSB_CANMB30                ((  TSB_CANMB_TypeDef *)TSB_CANMB30_BASE)
#define TSB_CANMB31                ((  TSB_CANMB_TypeDef *)TSB_CANMB31_BASE)
#define TSB_CAN                    ((    TSB_CAN_TypeDef *)   TSB_CAN_BASE)
#define TSB_DMA                    ((    TSB_DMA_TypeDef *)   TSB_DMA_BASE)
#define TSB_DMAIF                  ((  TSB_DMAIF_TypeDef *) TSB_DMAIF_BASE)
#define TSB_PA                     ((     TSB_PA_TypeDef *)    TSB_PA_BASE)
#define TSB_PB                     ((     TSB_PB_TypeDef *)    TSB_PB_BASE)
#define TSB_PC                     ((     TSB_PC_TypeDef *)    TSB_PC_BASE)
#define TSB_PD                     ((     TSB_PD_TypeDef *)    TSB_PD_BASE)
#define TSB_PE                     ((     TSB_PE_TypeDef *)    TSB_PE_BASE)
#define TSB_PF                     ((     TSB_PF_TypeDef *)    TSB_PF_BASE)
#define TSB_PG                     ((     TSB_PG_TypeDef *)    TSB_PG_BASE)
#define TSB_PH                     ((     TSB_PH_TypeDef *)    TSB_PH_BASE)
#define TSB_PJ                     ((     TSB_PJ_TypeDef *)    TSB_PJ_BASE)
#define TSB_PK                     ((     TSB_PK_TypeDef *)    TSB_PK_BASE)
#define TSB_PL                     ((     TSB_PL_TypeDef *)    TSB_PL_BASE)
#define TSB_PN                     ((     TSB_PN_TypeDef *)    TSB_PN_BASE)
#define TSB_PP                     ((     TSB_PP_TypeDef *)    TSB_PP_BASE)
#define TSB_TB0                    ((     TSB_TB_TypeDef *)   TSB_TB0_BASE)
#define TSB_TB1                    ((     TSB_TB_TypeDef *)   TSB_TB1_BASE)
#define TSB_TB2                    ((     TSB_TB_TypeDef *)   TSB_TB2_BASE)
#define TSB_TB3                    ((     TSB_TB_TypeDef *)   TSB_TB3_BASE)
#define TSB_TB4                    ((     TSB_TB_TypeDef *)   TSB_TB4_BASE)
#define TSB_TB5                    ((     TSB_TB_TypeDef *)   TSB_TB5_BASE)
#define TSB_TB6                    ((     TSB_TB_TypeDef *)   TSB_TB6_BASE)
#define TSB_TB7                    ((     TSB_TB_TypeDef *)   TSB_TB7_BASE)
#define TSB_TB8                    ((     TSB_TB_TypeDef *)   TSB_TB8_BASE)
#define TSB_TB9                    ((     TSB_TB_TypeDef *)   TSB_TB9_BASE)
#define TSB_SBI                    ((    TSB_SBI_TypeDef *)   TSB_SBI_BASE)
#define TSB_SC0                    ((     TSB_SC_TypeDef *)   TSB_SC0_BASE)
#define TSB_SC1                    ((     TSB_SC_TypeDef *)   TSB_SC1_BASE)
#define TSB_SC2                    ((     TSB_SC_TypeDef *)   TSB_SC2_BASE)
#define TSB_SC3                    ((     TSB_SC_TypeDef *)   TSB_SC3_BASE)
#define TSB_OFD                    ((    TSB_OFD_TypeDef *)   TSB_OFD_BASE)
#define TSB_WD                     ((     TSB_WD_TypeDef *)    TSB_WD_BASE)
#define TSB_CG                     ((     TSB_CG_TypeDef *)    TSB_CG_BASE)
#define TSB_TRMOSC                 (( TSB_TRMOSC_TypeDef *)TSB_TRMOSC_BASE)
#define TSB_NF                     ((     TSB_NF_TypeDef *)    TSB_NF_BASE)
#define TSB_VD                     ((     TSB_VD_TypeDef *)    TSB_VD_BASE)
#define TSB_PMD0                   ((    TSB_PMD_TypeDef *)  TSB_PMD0_BASE)
#define TSB_PMD1                   ((    TSB_PMD_TypeDef *)  TSB_PMD1_BASE)
#define TSB_EN0                    ((     TSB_EN_TypeDef *)   TSB_EN0_BASE)
#define TSB_EN1                    ((     TSB_EN_TypeDef *)   TSB_EN1_BASE)
#define TSB_VE0                    ((     TSB_VE_TypeDef *)   TSB_VE0_BASE)
#define TSB_VE1                    ((     TSB_VE_TypeDef *)   TSB_VE1_BASE)
#define TSB_ADA                    ((     TSB_AD_TypeDef *)   TSB_ADA_BASE)
#define TSB_ADB                    ((     TSB_AD_TypeDef *)   TSB_ADB_BASE)
#define TSB_FC                     ((     TSB_FC_TypeDef *)    TSB_FC_BASE)


/* Bit-Band for Device Specific Peripheral Registers */
#define BITBAND_OFFSET (0x02000000UL)
#define BITBAND_PERI_BASE (PERI_BASE + BITBAND_OFFSET)
#define BITBAND_PERI(addr, bitnum) (BITBAND_PERI_BASE + (((uint32_t)(addr) - PERI_BASE) << 5) + ((uint32_t)(bitnum) << 2))



/* CAN Controller (TXCAN) Mailbox RAM */
#define TSB_CANMB0_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB0->ID,29)))
#define TSB_CANMB0_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB0->ID,30)))
#define TSB_CANMB0_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB0->ID,31)))
#define TSB_CANMB0_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB0->TSVMCF,4)))

#define TSB_CANMB1_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB1->ID,29)))
#define TSB_CANMB1_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB1->ID,30)))
#define TSB_CANMB1_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB1->ID,31)))
#define TSB_CANMB1_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB1->TSVMCF,4)))

#define TSB_CANMB2_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB2->ID,29)))
#define TSB_CANMB2_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB2->ID,30)))
#define TSB_CANMB2_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB2->ID,31)))
#define TSB_CANMB2_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB2->TSVMCF,4)))

#define TSB_CANMB3_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB3->ID,29)))
#define TSB_CANMB3_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB3->ID,30)))
#define TSB_CANMB3_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB3->ID,31)))
#define TSB_CANMB3_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB3->TSVMCF,4)))

#define TSB_CANMB4_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB4->ID,29)))
#define TSB_CANMB4_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB4->ID,30)))
#define TSB_CANMB4_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB4->ID,31)))
#define TSB_CANMB4_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB4->TSVMCF,4)))

#define TSB_CANMB5_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB5->ID,29)))
#define TSB_CANMB5_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB5->ID,30)))
#define TSB_CANMB5_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB5->ID,31)))
#define TSB_CANMB5_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB5->TSVMCF,4)))

#define TSB_CANMB6_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB6->ID,29)))
#define TSB_CANMB6_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB6->ID,30)))
#define TSB_CANMB6_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB6->ID,31)))
#define TSB_CANMB6_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB6->TSVMCF,4)))

#define TSB_CANMB7_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB7->ID,29)))
#define TSB_CANMB7_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB7->ID,30)))
#define TSB_CANMB7_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB7->ID,31)))
#define TSB_CANMB7_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB7->TSVMCF,4)))

#define TSB_CANMB8_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB8->ID,29)))
#define TSB_CANMB8_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB8->ID,30)))
#define TSB_CANMB8_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB8->ID,31)))
#define TSB_CANMB8_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB8->TSVMCF,4)))

#define TSB_CANMB9_ID_RFH                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB9->ID,29)))
#define TSB_CANMB9_ID_GAME_LAME                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB9->ID,30)))
#define TSB_CANMB9_ID_IDE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB9->ID,31)))
#define TSB_CANMB9_TSVMCF_RTR                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB9->TSVMCF,4)))

#define TSB_CANMB10_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB10->ID,29)))
#define TSB_CANMB10_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB10->ID,30)))
#define TSB_CANMB10_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB10->ID,31)))
#define TSB_CANMB10_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB10->TSVMCF,4)))

#define TSB_CANMB11_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB11->ID,29)))
#define TSB_CANMB11_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB11->ID,30)))
#define TSB_CANMB11_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB11->ID,31)))
#define TSB_CANMB11_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB11->TSVMCF,4)))

#define TSB_CANMB12_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB12->ID,29)))
#define TSB_CANMB12_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB12->ID,30)))
#define TSB_CANMB12_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB12->ID,31)))
#define TSB_CANMB12_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB12->TSVMCF,4)))

#define TSB_CANMB13_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB13->ID,29)))
#define TSB_CANMB13_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB13->ID,30)))
#define TSB_CANMB13_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB13->ID,31)))
#define TSB_CANMB13_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB13->TSVMCF,4)))

#define TSB_CANMB14_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB14->ID,29)))
#define TSB_CANMB14_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB14->ID,30)))
#define TSB_CANMB14_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB14->ID,31)))
#define TSB_CANMB14_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB14->TSVMCF,4)))

#define TSB_CANMB15_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB15->ID,29)))
#define TSB_CANMB15_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB15->ID,30)))
#define TSB_CANMB15_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB15->ID,31)))
#define TSB_CANMB15_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB15->TSVMCF,4)))

#define TSB_CANMB16_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB16->ID,29)))
#define TSB_CANMB16_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB16->ID,30)))
#define TSB_CANMB16_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB16->ID,31)))
#define TSB_CANMB16_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB16->TSVMCF,4)))

#define TSB_CANMB17_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB17->ID,29)))
#define TSB_CANMB17_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB17->ID,30)))
#define TSB_CANMB17_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB17->ID,31)))
#define TSB_CANMB17_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB17->TSVMCF,4)))

#define TSB_CANMB18_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB18->ID,29)))
#define TSB_CANMB18_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB18->ID,30)))
#define TSB_CANMB18_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB18->ID,31)))
#define TSB_CANMB18_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB18->TSVMCF,4)))

#define TSB_CANMB19_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB19->ID,29)))
#define TSB_CANMB19_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB19->ID,30)))
#define TSB_CANMB19_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB19->ID,31)))
#define TSB_CANMB19_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB19->TSVMCF,4)))

#define TSB_CANMB20_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB20->ID,29)))
#define TSB_CANMB20_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB20->ID,30)))
#define TSB_CANMB20_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB20->ID,31)))
#define TSB_CANMB20_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB20->TSVMCF,4)))

#define TSB_CANMB21_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB21->ID,29)))
#define TSB_CANMB21_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB21->ID,30)))
#define TSB_CANMB21_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB21->ID,31)))
#define TSB_CANMB21_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB21->TSVMCF,4)))

#define TSB_CANMB22_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB22->ID,29)))
#define TSB_CANMB22_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB22->ID,30)))
#define TSB_CANMB22_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB22->ID,31)))
#define TSB_CANMB22_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB22->TSVMCF,4)))

#define TSB_CANMB23_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB23->ID,29)))
#define TSB_CANMB23_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB23->ID,30)))
#define TSB_CANMB23_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB23->ID,31)))
#define TSB_CANMB23_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB23->TSVMCF,4)))

#define TSB_CANMB24_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB24->ID,29)))
#define TSB_CANMB24_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB24->ID,30)))
#define TSB_CANMB24_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB24->ID,31)))
#define TSB_CANMB24_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB24->TSVMCF,4)))

#define TSB_CANMB25_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB25->ID,29)))
#define TSB_CANMB25_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB25->ID,30)))
#define TSB_CANMB25_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB25->ID,31)))
#define TSB_CANMB25_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB25->TSVMCF,4)))

#define TSB_CANMB26_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB26->ID,29)))
#define TSB_CANMB26_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB26->ID,30)))
#define TSB_CANMB26_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB26->ID,31)))
#define TSB_CANMB26_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB26->TSVMCF,4)))

#define TSB_CANMB27_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB27->ID,29)))
#define TSB_CANMB27_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB27->ID,30)))
#define TSB_CANMB27_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB27->ID,31)))
#define TSB_CANMB27_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB27->TSVMCF,4)))

#define TSB_CANMB28_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB28->ID,29)))
#define TSB_CANMB28_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB28->ID,30)))
#define TSB_CANMB28_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB28->ID,31)))
#define TSB_CANMB28_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB28->TSVMCF,4)))

#define TSB_CANMB29_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB29->ID,29)))
#define TSB_CANMB29_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB29->ID,30)))
#define TSB_CANMB29_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB29->ID,31)))
#define TSB_CANMB29_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB29->TSVMCF,4)))

#define TSB_CANMB30_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB30->ID,29)))
#define TSB_CANMB30_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB30->ID,30)))
#define TSB_CANMB30_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB30->ID,31)))
#define TSB_CANMB30_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB30->TSVMCF,4)))

#define TSB_CANMB31_ID_RFH                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB31->ID,29)))
#define TSB_CANMB31_ID_GAME_LAME                  (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB31->ID,30)))
#define TSB_CANMB31_ID_IDE                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB31->ID,31)))
#define TSB_CANMB31_TSVMCF_RTR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CANMB31->TSVMCF,4)))


/* CAN Controller (TXCAN) */
#define TSB_CAN_MC_MC0                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,0)))
#define TSB_CAN_MC_MC1                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,1)))
#define TSB_CAN_MC_MC2                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,2)))
#define TSB_CAN_MC_MC3                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,3)))
#define TSB_CAN_MC_MC4                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,4)))
#define TSB_CAN_MC_MC5                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,5)))
#define TSB_CAN_MC_MC6                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,6)))
#define TSB_CAN_MC_MC7                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,7)))
#define TSB_CAN_MC_MC8                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,8)))
#define TSB_CAN_MC_MC9                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,9)))
#define TSB_CAN_MC_MC10                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,10)))
#define TSB_CAN_MC_MC11                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,11)))
#define TSB_CAN_MC_MC12                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,12)))
#define TSB_CAN_MC_MC13                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,13)))
#define TSB_CAN_MC_MC14                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,14)))
#define TSB_CAN_MC_MC15                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,15)))
#define TSB_CAN_MC_MC16                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,16)))
#define TSB_CAN_MC_MC17                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,17)))
#define TSB_CAN_MC_MC18                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,18)))
#define TSB_CAN_MC_MC19                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,19)))
#define TSB_CAN_MC_MC20                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,20)))
#define TSB_CAN_MC_MC21                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,21)))
#define TSB_CAN_MC_MC22                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,22)))
#define TSB_CAN_MC_MC23                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,23)))
#define TSB_CAN_MC_MC24                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,24)))
#define TSB_CAN_MC_MC25                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,25)))
#define TSB_CAN_MC_MC26                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,26)))
#define TSB_CAN_MC_MC27                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,27)))
#define TSB_CAN_MC_MC28                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,28)))
#define TSB_CAN_MC_MC29                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,29)))
#define TSB_CAN_MC_MC30                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,30)))
#define TSB_CAN_MC_MC31                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MC,31)))
#define TSB_CAN_MD_MD0                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,0)))
#define TSB_CAN_MD_MD1                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,1)))
#define TSB_CAN_MD_MD2                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,2)))
#define TSB_CAN_MD_MD3                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,3)))
#define TSB_CAN_MD_MD4                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,4)))
#define TSB_CAN_MD_MD5                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,5)))
#define TSB_CAN_MD_MD6                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,6)))
#define TSB_CAN_MD_MD7                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,7)))
#define TSB_CAN_MD_MD8                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,8)))
#define TSB_CAN_MD_MD9                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,9)))
#define TSB_CAN_MD_MD10                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,10)))
#define TSB_CAN_MD_MD11                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,11)))
#define TSB_CAN_MD_MD12                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,12)))
#define TSB_CAN_MD_MD13                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,13)))
#define TSB_CAN_MD_MD14                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,14)))
#define TSB_CAN_MD_MD15                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,15)))
#define TSB_CAN_MD_MD16                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,16)))
#define TSB_CAN_MD_MD17                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,17)))
#define TSB_CAN_MD_MD18                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,18)))
#define TSB_CAN_MD_MD19                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,19)))
#define TSB_CAN_MD_MD20                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,20)))
#define TSB_CAN_MD_MD21                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,21)))
#define TSB_CAN_MD_MD22                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,22)))
#define TSB_CAN_MD_MD23                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,23)))
#define TSB_CAN_MD_MD24                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,24)))
#define TSB_CAN_MD_MD25                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,25)))
#define TSB_CAN_MD_MD26                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,26)))
#define TSB_CAN_MD_MD27                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,27)))
#define TSB_CAN_MD_MD28                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,28)))
#define TSB_CAN_MD_MD29                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,29)))
#define TSB_CAN_MD_MD30                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MD,30)))
#define TSB_CAN_MD_MD31                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->MD,31)))
#define TSB_CAN_TRS_TRS0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,0)))
#define TSB_CAN_TRS_TRS1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,1)))
#define TSB_CAN_TRS_TRS2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,2)))
#define TSB_CAN_TRS_TRS3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,3)))
#define TSB_CAN_TRS_TRS4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,4)))
#define TSB_CAN_TRS_TRS5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,5)))
#define TSB_CAN_TRS_TRS6                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,6)))
#define TSB_CAN_TRS_TRS7                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,7)))
#define TSB_CAN_TRS_TRS8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,8)))
#define TSB_CAN_TRS_TRS9                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,9)))
#define TSB_CAN_TRS_TRS10                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,10)))
#define TSB_CAN_TRS_TRS11                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,11)))
#define TSB_CAN_TRS_TRS12                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,12)))
#define TSB_CAN_TRS_TRS13                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,13)))
#define TSB_CAN_TRS_TRS14                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,14)))
#define TSB_CAN_TRS_TRS15                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,15)))
#define TSB_CAN_TRS_TRS16                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,16)))
#define TSB_CAN_TRS_TRS17                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,17)))
#define TSB_CAN_TRS_TRS18                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,18)))
#define TSB_CAN_TRS_TRS19                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,19)))
#define TSB_CAN_TRS_TRS20                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,20)))
#define TSB_CAN_TRS_TRS21                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,21)))
#define TSB_CAN_TRS_TRS22                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,22)))
#define TSB_CAN_TRS_TRS23                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,23)))
#define TSB_CAN_TRS_TRS24                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,24)))
#define TSB_CAN_TRS_TRS25                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,25)))
#define TSB_CAN_TRS_TRS26                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,26)))
#define TSB_CAN_TRS_TRS27                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,27)))
#define TSB_CAN_TRS_TRS28                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,28)))
#define TSB_CAN_TRS_TRS29                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,29)))
#define TSB_CAN_TRS_TRS30                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRS,30)))
#define TSB_CAN_TRR_TRR0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,0)))
#define TSB_CAN_TRR_TRR1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,1)))
#define TSB_CAN_TRR_TRR2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,2)))
#define TSB_CAN_TRR_TRR3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,3)))
#define TSB_CAN_TRR_TRR4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,4)))
#define TSB_CAN_TRR_TRR5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,5)))
#define TSB_CAN_TRR_TRR6                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,6)))
#define TSB_CAN_TRR_TRR7                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,7)))
#define TSB_CAN_TRR_TRR8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,8)))
#define TSB_CAN_TRR_TRR9                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,9)))
#define TSB_CAN_TRR_TRR10                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,10)))
#define TSB_CAN_TRR_TRR11                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,11)))
#define TSB_CAN_TRR_TRR12                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,12)))
#define TSB_CAN_TRR_TRR13                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,13)))
#define TSB_CAN_TRR_TRR14                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,14)))
#define TSB_CAN_TRR_TRR15                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,15)))
#define TSB_CAN_TRR_TRR16                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,16)))
#define TSB_CAN_TRR_TRR17                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,17)))
#define TSB_CAN_TRR_TRR18                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,18)))
#define TSB_CAN_TRR_TRR19                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,19)))
#define TSB_CAN_TRR_TRR20                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,20)))
#define TSB_CAN_TRR_TRR21                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,21)))
#define TSB_CAN_TRR_TRR22                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,22)))
#define TSB_CAN_TRR_TRR23                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,23)))
#define TSB_CAN_TRR_TRR24                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,24)))
#define TSB_CAN_TRR_TRR25                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,25)))
#define TSB_CAN_TRR_TRR26                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,26)))
#define TSB_CAN_TRR_TRR27                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,27)))
#define TSB_CAN_TRR_TRR28                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,28)))
#define TSB_CAN_TRR_TRR29                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,29)))
#define TSB_CAN_TRR_TRR30                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TRR,30)))
#define TSB_CAN_TA_TA0                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,0)))
#define TSB_CAN_TA_TA1                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,1)))
#define TSB_CAN_TA_TA2                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,2)))
#define TSB_CAN_TA_TA3                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,3)))
#define TSB_CAN_TA_TA4                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,4)))
#define TSB_CAN_TA_TA5                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,5)))
#define TSB_CAN_TA_TA6                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,6)))
#define TSB_CAN_TA_TA7                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,7)))
#define TSB_CAN_TA_TA8                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,8)))
#define TSB_CAN_TA_TA9                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,9)))
#define TSB_CAN_TA_TA10                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,10)))
#define TSB_CAN_TA_TA11                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,11)))
#define TSB_CAN_TA_TA12                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,12)))
#define TSB_CAN_TA_TA13                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,13)))
#define TSB_CAN_TA_TA14                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,14)))
#define TSB_CAN_TA_TA15                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,15)))
#define TSB_CAN_TA_TA16                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,16)))
#define TSB_CAN_TA_TA17                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,17)))
#define TSB_CAN_TA_TA18                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,18)))
#define TSB_CAN_TA_TA19                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,19)))
#define TSB_CAN_TA_TA20                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,20)))
#define TSB_CAN_TA_TA21                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,21)))
#define TSB_CAN_TA_TA22                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,22)))
#define TSB_CAN_TA_TA23                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,23)))
#define TSB_CAN_TA_TA24                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,24)))
#define TSB_CAN_TA_TA25                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,25)))
#define TSB_CAN_TA_TA26                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,26)))
#define TSB_CAN_TA_TA27                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,27)))
#define TSB_CAN_TA_TA28                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,28)))
#define TSB_CAN_TA_TA29                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,29)))
#define TSB_CAN_TA_TA30                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->TA,30)))
#define TSB_CAN_AA_AA0                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,0)))
#define TSB_CAN_AA_AA1                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,1)))
#define TSB_CAN_AA_AA2                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,2)))
#define TSB_CAN_AA_AA3                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,3)))
#define TSB_CAN_AA_AA4                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,4)))
#define TSB_CAN_AA_AA5                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,5)))
#define TSB_CAN_AA_AA6                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,6)))
#define TSB_CAN_AA_AA7                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,7)))
#define TSB_CAN_AA_AA8                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,8)))
#define TSB_CAN_AA_AA9                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,9)))
#define TSB_CAN_AA_AA10                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,10)))
#define TSB_CAN_AA_AA11                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,11)))
#define TSB_CAN_AA_AA12                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,12)))
#define TSB_CAN_AA_AA13                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,13)))
#define TSB_CAN_AA_AA14                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,14)))
#define TSB_CAN_AA_AA15                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,15)))
#define TSB_CAN_AA_AA16                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,16)))
#define TSB_CAN_AA_AA17                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,17)))
#define TSB_CAN_AA_AA18                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,18)))
#define TSB_CAN_AA_AA19                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,19)))
#define TSB_CAN_AA_AA20                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,20)))
#define TSB_CAN_AA_AA21                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,21)))
#define TSB_CAN_AA_AA22                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,22)))
#define TSB_CAN_AA_AA23                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,23)))
#define TSB_CAN_AA_AA24                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,24)))
#define TSB_CAN_AA_AA25                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,25)))
#define TSB_CAN_AA_AA26                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,26)))
#define TSB_CAN_AA_AA27                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,27)))
#define TSB_CAN_AA_AA28                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,28)))
#define TSB_CAN_AA_AA29                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,29)))
#define TSB_CAN_AA_AA30                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->AA,30)))
#define TSB_CAN_RMP_RMP0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,0)))
#define TSB_CAN_RMP_RMP1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,1)))
#define TSB_CAN_RMP_RMP2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,2)))
#define TSB_CAN_RMP_RMP3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,3)))
#define TSB_CAN_RMP_RMP4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,4)))
#define TSB_CAN_RMP_RMP5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,5)))
#define TSB_CAN_RMP_RMP6                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,6)))
#define TSB_CAN_RMP_RMP7                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,7)))
#define TSB_CAN_RMP_RMP8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,8)))
#define TSB_CAN_RMP_RMP9                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,9)))
#define TSB_CAN_RMP_RMP10                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,10)))
#define TSB_CAN_RMP_RMP11                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,11)))
#define TSB_CAN_RMP_RMP12                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,12)))
#define TSB_CAN_RMP_RMP13                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,13)))
#define TSB_CAN_RMP_RMP14                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,14)))
#define TSB_CAN_RMP_RMP15                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,15)))
#define TSB_CAN_RMP_RMP16                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,16)))
#define TSB_CAN_RMP_RMP17                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,17)))
#define TSB_CAN_RMP_RMP18                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,18)))
#define TSB_CAN_RMP_RMP19                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,19)))
#define TSB_CAN_RMP_RMP20                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,20)))
#define TSB_CAN_RMP_RMP21                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,21)))
#define TSB_CAN_RMP_RMP22                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,22)))
#define TSB_CAN_RMP_RMP23                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,23)))
#define TSB_CAN_RMP_RMP24                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,24)))
#define TSB_CAN_RMP_RMP25                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,25)))
#define TSB_CAN_RMP_RMP26                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,26)))
#define TSB_CAN_RMP_RMP27                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,27)))
#define TSB_CAN_RMP_RMP28                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,28)))
#define TSB_CAN_RMP_RMP29                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,29)))
#define TSB_CAN_RMP_RMP30                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,30)))
#define TSB_CAN_RMP_RMP31                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RMP,31)))
#define TSB_CAN_RML_RML0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,0)))
#define TSB_CAN_RML_RML1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,1)))
#define TSB_CAN_RML_RML2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,2)))
#define TSB_CAN_RML_RML3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,3)))
#define TSB_CAN_RML_RML4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,4)))
#define TSB_CAN_RML_RML5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,5)))
#define TSB_CAN_RML_RML6                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,6)))
#define TSB_CAN_RML_RML7                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,7)))
#define TSB_CAN_RML_RML8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,8)))
#define TSB_CAN_RML_RML9                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,9)))
#define TSB_CAN_RML_RML10                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,10)))
#define TSB_CAN_RML_RML11                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,11)))
#define TSB_CAN_RML_RML12                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,12)))
#define TSB_CAN_RML_RML13                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,13)))
#define TSB_CAN_RML_RML14                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,14)))
#define TSB_CAN_RML_RML15                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,15)))
#define TSB_CAN_RML_RML16                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,16)))
#define TSB_CAN_RML_RML17                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,17)))
#define TSB_CAN_RML_RML18                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,18)))
#define TSB_CAN_RML_RML19                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,19)))
#define TSB_CAN_RML_RML20                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,20)))
#define TSB_CAN_RML_RML21                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,21)))
#define TSB_CAN_RML_RML22                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,22)))
#define TSB_CAN_RML_RML23                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,23)))
#define TSB_CAN_RML_RML24                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,24)))
#define TSB_CAN_RML_RML25                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,25)))
#define TSB_CAN_RML_RML26                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,26)))
#define TSB_CAN_RML_RML27                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,27)))
#define TSB_CAN_RML_RML28                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,28)))
#define TSB_CAN_RML_RML29                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,29)))
#define TSB_CAN_RML_RML30                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,30)))
#define TSB_CAN_RML_RML31                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RML,31)))
#define TSB_CAN_LAM_LAMI                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->LAM,31)))
#define TSB_CAN_GAM_GAMI                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GAM,31)))
#define TSB_CAN_MCR_SRES                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,0)))
#define TSB_CAN_MCR_TSCC                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,1)))
#define TSB_CAN_MCR_MTOS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,3)))
#define TSB_CAN_MCR_WUBA                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,4)))
#define TSB_CAN_MCR_SMR                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,6)))
#define TSB_CAN_MCR_CCR                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,7)))
#define TSB_CAN_MCR_TSTERR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,8)))
#define TSB_CAN_MCR_TSTLB                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,9)))
#define TSB_CAN_MCR_SUR                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MCR,11)))
#define TSB_CAN_GSR_EW                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,0)))
#define TSB_CAN_GSR_EP                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,1)))
#define TSB_CAN_GSR_BO                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,2)))
#define TSB_CAN_GSR_TSO                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,3)))
#define TSB_CAN_GSR_SMA                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,6)))
#define TSB_CAN_GSR_CCE                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,7)))
#define TSB_CAN_GSR_SUA                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,8)))
#define TSB_CAN_GSR_TM                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,10)))
#define TSB_CAN_GSR_RM                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_CAN->GSR,11)))
#define TSB_CAN_BCR2_SAM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->BCR2,7)))
#define TSB_CAN_GIF_WLIF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIF,0)))
#define TSB_CAN_GIF_EPIF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIF,1)))
#define TSB_CAN_GIF_BOIF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIF,2)))
#define TSB_CAN_GIF_TSOIF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIF,3)))
#define TSB_CAN_GIF_TRMABF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIF,4)))
#define TSB_CAN_GIF_RMLIF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIF,5)))
#define TSB_CAN_GIF_WUIF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIF,6)))
#define TSB_CAN_GIF_RFPF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIF,7)))
#define TSB_CAN_GIM_WLIM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,0)))
#define TSB_CAN_GIM_EPIM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,1)))
#define TSB_CAN_GIM_BOIM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,2)))
#define TSB_CAN_GIM_TSOIM                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,3)))
#define TSB_CAN_GIM_TRMABF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,4)))
#define TSB_CAN_GIM_RMLIM                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,5)))
#define TSB_CAN_GIM_WUIM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,6)))
#define TSB_CAN_GIM_RFPM                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->GIM,7)))
#define TSB_CAN_MBTIF_MBTIF0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,0)))
#define TSB_CAN_MBTIF_MBTIF1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,1)))
#define TSB_CAN_MBTIF_MBTIF2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,2)))
#define TSB_CAN_MBTIF_MBTIF3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,3)))
#define TSB_CAN_MBTIF_MBTIF4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,4)))
#define TSB_CAN_MBTIF_MBTIF5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,5)))
#define TSB_CAN_MBTIF_MBTIF6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,6)))
#define TSB_CAN_MBTIF_MBTIF7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,7)))
#define TSB_CAN_MBTIF_MBTIF8                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,8)))
#define TSB_CAN_MBTIF_MBTIF9                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,9)))
#define TSB_CAN_MBTIF_MBTIF10                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,10)))
#define TSB_CAN_MBTIF_MBTIF11                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,11)))
#define TSB_CAN_MBTIF_MBTIF12                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,12)))
#define TSB_CAN_MBTIF_MBTIF13                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,13)))
#define TSB_CAN_MBTIF_MBTIF14                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,14)))
#define TSB_CAN_MBTIF_MBTIF15                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,15)))
#define TSB_CAN_MBTIF_MBTIF16                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,16)))
#define TSB_CAN_MBTIF_MBTIF17                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,17)))
#define TSB_CAN_MBTIF_MBTIF18                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,18)))
#define TSB_CAN_MBTIF_MBTIF19                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,19)))
#define TSB_CAN_MBTIF_MBTIF20                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,20)))
#define TSB_CAN_MBTIF_MBTIF21                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,21)))
#define TSB_CAN_MBTIF_MBTIF22                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,22)))
#define TSB_CAN_MBTIF_MBTIF23                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,23)))
#define TSB_CAN_MBTIF_MBTIF24                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,24)))
#define TSB_CAN_MBTIF_MBTIF25                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,25)))
#define TSB_CAN_MBTIF_MBTIF26                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,26)))
#define TSB_CAN_MBTIF_MBTIF27                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,27)))
#define TSB_CAN_MBTIF_MBTIF28                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,28)))
#define TSB_CAN_MBTIF_MBTIF29                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,29)))
#define TSB_CAN_MBTIF_MBTIF30                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBTIF,30)))
#define TSB_CAN_MBRIF_MBRIF0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,0)))
#define TSB_CAN_MBRIF_MBRIF1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,1)))
#define TSB_CAN_MBRIF_MBRIF2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,2)))
#define TSB_CAN_MBRIF_MBRIF3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,3)))
#define TSB_CAN_MBRIF_MBRIF4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,4)))
#define TSB_CAN_MBRIF_MBRIF5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,5)))
#define TSB_CAN_MBRIF_MBRIF6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,6)))
#define TSB_CAN_MBRIF_MBRIF7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,7)))
#define TSB_CAN_MBRIF_MBRIF8                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,8)))
#define TSB_CAN_MBRIF_MBRIF9                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,9)))
#define TSB_CAN_MBRIF_MBRIF10                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,10)))
#define TSB_CAN_MBRIF_MBRIF11                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,11)))
#define TSB_CAN_MBRIF_MBRIF12                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,12)))
#define TSB_CAN_MBRIF_MBRIF13                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,13)))
#define TSB_CAN_MBRIF_MBRIF14                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,14)))
#define TSB_CAN_MBRIF_MBRIF15                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,15)))
#define TSB_CAN_MBRIF_MBRIF16                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,16)))
#define TSB_CAN_MBRIF_MBRIF17                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,17)))
#define TSB_CAN_MBRIF_MBRIF18                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,18)))
#define TSB_CAN_MBRIF_MBRIF19                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,19)))
#define TSB_CAN_MBRIF_MBRIF20                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,20)))
#define TSB_CAN_MBRIF_MBRIF21                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,21)))
#define TSB_CAN_MBRIF_MBRIF22                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,22)))
#define TSB_CAN_MBRIF_MBRIF23                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,23)))
#define TSB_CAN_MBRIF_MBRIF24                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,24)))
#define TSB_CAN_MBRIF_MBRIF25                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,25)))
#define TSB_CAN_MBRIF_MBRIF26                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,26)))
#define TSB_CAN_MBRIF_MBRIF27                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,27)))
#define TSB_CAN_MBRIF_MBRIF28                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,28)))
#define TSB_CAN_MBRIF_MBRIF29                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,29)))
#define TSB_CAN_MBRIF_MBRIF30                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBRIF,30)))
#define TSB_CAN_MBIM_MBIM0                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,0)))
#define TSB_CAN_MBIM_MBIM1                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,1)))
#define TSB_CAN_MBIM_MBIM2                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,2)))
#define TSB_CAN_MBIM_MBIM3                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,3)))
#define TSB_CAN_MBIM_MBIM4                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,4)))
#define TSB_CAN_MBIM_MBIM5                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,5)))
#define TSB_CAN_MBIM_MBIM6                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,6)))
#define TSB_CAN_MBIM_MBIM7                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,7)))
#define TSB_CAN_MBIM_MBIM8                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,8)))
#define TSB_CAN_MBIM_MBIM9                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,9)))
#define TSB_CAN_MBIM_MBIM10                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,10)))
#define TSB_CAN_MBIM_MBIM11                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,11)))
#define TSB_CAN_MBIM_MBIM12                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,12)))
#define TSB_CAN_MBIM_MBIM13                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,13)))
#define TSB_CAN_MBIM_MBIM14                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,14)))
#define TSB_CAN_MBIM_MBIM15                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,15)))
#define TSB_CAN_MBIM_MBIM16                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,16)))
#define TSB_CAN_MBIM_MBIM17                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,17)))
#define TSB_CAN_MBIM_MBIM18                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,18)))
#define TSB_CAN_MBIM_MBIM19                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,19)))
#define TSB_CAN_MBIM_MBIM20                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,20)))
#define TSB_CAN_MBIM_MBIM21                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,21)))
#define TSB_CAN_MBIM_MBIM22                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,22)))
#define TSB_CAN_MBIM_MBIM23                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,23)))
#define TSB_CAN_MBIM_MBIM24                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,24)))
#define TSB_CAN_MBIM_MBIM25                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,25)))
#define TSB_CAN_MBIM_MBIM26                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,26)))
#define TSB_CAN_MBIM_MBIM27                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,27)))
#define TSB_CAN_MBIM_MBIM28                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,28)))
#define TSB_CAN_MBIM_MBIM29                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,29)))
#define TSB_CAN_MBIM_MBIM30                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,30)))
#define TSB_CAN_MBIM_MBIM31                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->MBIM,31)))
#define TSB_CAN_CDR_CDR0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,0)))
#define TSB_CAN_CDR_CDR1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,1)))
#define TSB_CAN_CDR_CDR2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,2)))
#define TSB_CAN_CDR_CDR3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,3)))
#define TSB_CAN_CDR_CDR4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,4)))
#define TSB_CAN_CDR_CDR5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,5)))
#define TSB_CAN_CDR_CDR6                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,6)))
#define TSB_CAN_CDR_CDR7                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,7)))
#define TSB_CAN_CDR_CDR8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,8)))
#define TSB_CAN_CDR_CDR9                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,9)))
#define TSB_CAN_CDR_CDR10                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,10)))
#define TSB_CAN_CDR_CDR11                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,11)))
#define TSB_CAN_CDR_CDR12                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,12)))
#define TSB_CAN_CDR_CDR13                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,13)))
#define TSB_CAN_CDR_CDR14                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,14)))
#define TSB_CAN_CDR_CDR15                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,15)))
#define TSB_CAN_CDR_CDR16                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,16)))
#define TSB_CAN_CDR_CDR17                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,17)))
#define TSB_CAN_CDR_CDR18                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,18)))
#define TSB_CAN_CDR_CDR19                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,19)))
#define TSB_CAN_CDR_CDR20                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,20)))
#define TSB_CAN_CDR_CDR21                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,21)))
#define TSB_CAN_CDR_CDR22                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,22)))
#define TSB_CAN_CDR_CDR23                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,23)))
#define TSB_CAN_CDR_CDR24                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,24)))
#define TSB_CAN_CDR_CDR25                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,25)))
#define TSB_CAN_CDR_CDR26                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,26)))
#define TSB_CAN_CDR_CDR27                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,27)))
#define TSB_CAN_CDR_CDR28                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,28)))
#define TSB_CAN_CDR_CDR29                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,29)))
#define TSB_CAN_CDR_CDR30                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->CDR,30)))
#define TSB_CAN_RFP_RFP0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,0)))
#define TSB_CAN_RFP_RFP1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,1)))
#define TSB_CAN_RFP_RFP2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,2)))
#define TSB_CAN_RFP_RFP3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,3)))
#define TSB_CAN_RFP_RFP4                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,4)))
#define TSB_CAN_RFP_RFP5                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,5)))
#define TSB_CAN_RFP_RFP6                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,6)))
#define TSB_CAN_RFP_RFP7                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,7)))
#define TSB_CAN_RFP_RFP8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,8)))
#define TSB_CAN_RFP_RFP9                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,9)))
#define TSB_CAN_RFP_RFP10                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,10)))
#define TSB_CAN_RFP_RFP11                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,11)))
#define TSB_CAN_RFP_RFP12                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,12)))
#define TSB_CAN_RFP_RFP13                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,13)))
#define TSB_CAN_RFP_RFP14                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,14)))
#define TSB_CAN_RFP_RFP15                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,15)))
#define TSB_CAN_RFP_RFP16                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,16)))
#define TSB_CAN_RFP_RFP17                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,17)))
#define TSB_CAN_RFP_RFP18                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,18)))
#define TSB_CAN_RFP_RFP19                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,19)))
#define TSB_CAN_RFP_RFP20                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,20)))
#define TSB_CAN_RFP_RFP21                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,21)))
#define TSB_CAN_RFP_RFP22                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,22)))
#define TSB_CAN_RFP_RFP23                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,23)))
#define TSB_CAN_RFP_RFP24                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,24)))
#define TSB_CAN_RFP_RFP25                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,25)))
#define TSB_CAN_RFP_RFP26                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,26)))
#define TSB_CAN_RFP_RFP27                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,27)))
#define TSB_CAN_RFP_RFP28                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,28)))
#define TSB_CAN_RFP_RFP29                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,29)))
#define TSB_CAN_RFP_RFP30                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,30)))
#define TSB_CAN_RFP_RFP31                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CAN->RFP,31)))


/* DMA Controller */
#define TSB_DMA_STATUS_MASTER_ENABLE              (*((__I  uint32_t *)BITBAND_PERI(&TSB_DMA->STATUS,0)))
#define TSB_DMA_CFG_MASTER_ENABLE                 (*((__O  uint32_t *)BITBAND_PERI(&TSB_DMA->CFG,0)))
#define TSB_DMA_ERRCLR_ERR_CLR                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_DMA->ERRCLR,0)))



/* Port A */
#define TSB_PA_DATA_PA0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,0)))
#define TSB_PA_DATA_PA1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,1)))
#define TSB_PA_DATA_PA2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,2)))
#define TSB_PA_DATA_PA3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,3)))
#define TSB_PA_DATA_PA4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,4)))
#define TSB_PA_DATA_PA5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,5)))
#define TSB_PA_DATA_PA6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,6)))
#define TSB_PA_DATA_PA7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->DATA,7)))
#define TSB_PA_CR_PA0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,0)))
#define TSB_PA_CR_PA1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,1)))
#define TSB_PA_CR_PA2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,2)))
#define TSB_PA_CR_PA3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,3)))
#define TSB_PA_CR_PA4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,4)))
#define TSB_PA_CR_PA5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,5)))
#define TSB_PA_CR_PA6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,6)))
#define TSB_PA_CR_PA7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->CR,7)))
#define TSB_PA_FR1_PA0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,0)))
#define TSB_PA_FR1_PA1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,1)))
#define TSB_PA_FR1_PA2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,2)))
#define TSB_PA_FR1_PA3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,3)))
#define TSB_PA_FR1_PA4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,4)))
#define TSB_PA_FR1_PA5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,5)))
#define TSB_PA_FR1_PA6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,6)))
#define TSB_PA_FR1_PA7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR1,7)))
#define TSB_PA_FR2_PA4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,4)))
#define TSB_PA_FR2_PA5F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,5)))
#define TSB_PA_FR2_PA6F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->FR2,6)))
#define TSB_PA_OD_PA0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,0)))
#define TSB_PA_OD_PA1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,1)))
#define TSB_PA_OD_PA2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,2)))
#define TSB_PA_OD_PA3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,3)))
#define TSB_PA_OD_PA4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,4)))
#define TSB_PA_OD_PA5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,5)))
#define TSB_PA_OD_PA6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,6)))
#define TSB_PA_OD_PA7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->OD,7)))
#define TSB_PA_PUP_PA0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,0)))
#define TSB_PA_PUP_PA1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,1)))
#define TSB_PA_PUP_PA2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,2)))
#define TSB_PA_PUP_PA3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,3)))
#define TSB_PA_PUP_PA4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,4)))
#define TSB_PA_PUP_PA5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,5)))
#define TSB_PA_PUP_PA6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,6)))
#define TSB_PA_PUP_PA7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PUP,7)))
#define TSB_PA_PDN_PA0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,0)))
#define TSB_PA_PDN_PA1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,1)))
#define TSB_PA_PDN_PA2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,2)))
#define TSB_PA_PDN_PA3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,3)))
#define TSB_PA_PDN_PA4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,4)))
#define TSB_PA_PDN_PA5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,5)))
#define TSB_PA_PDN_PA6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,6)))
#define TSB_PA_PDN_PA7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->PDN,7)))
#define TSB_PA_IE_PA0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,0)))
#define TSB_PA_IE_PA1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,1)))
#define TSB_PA_IE_PA2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,2)))
#define TSB_PA_IE_PA3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,3)))
#define TSB_PA_IE_PA4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,4)))
#define TSB_PA_IE_PA5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,5)))
#define TSB_PA_IE_PA6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,6)))
#define TSB_PA_IE_PA7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PA->IE,7)))


/* Port B */
#define TSB_PB_DATA_PB0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,0)))
#define TSB_PB_DATA_PB1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,1)))
#define TSB_PB_DATA_PB2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,2)))
#define TSB_PB_DATA_PB3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,3)))
#define TSB_PB_DATA_PB4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,4)))
#define TSB_PB_DATA_PB5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,5)))
#define TSB_PB_DATA_PB6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,6)))
#define TSB_PB_DATA_PB7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->DATA,7)))
#define TSB_PB_CR_PB0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,0)))
#define TSB_PB_CR_PB1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,1)))
#define TSB_PB_CR_PB2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,2)))
#define TSB_PB_CR_PB3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,3)))
#define TSB_PB_CR_PB4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,4)))
#define TSB_PB_CR_PB5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,5)))
#define TSB_PB_CR_PB6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,6)))
#define TSB_PB_CR_PB7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->CR,7)))
#define TSB_PB_FR1_PB0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,0)))
#define TSB_PB_FR1_PB1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,1)))
#define TSB_PB_FR1_PB2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,2)))
#define TSB_PB_FR1_PB3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,3)))
#define TSB_PB_FR1_PB4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,4)))
#define TSB_PB_FR1_PB5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,5)))
#define TSB_PB_FR1_PB6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,6)))
#define TSB_PB_FR1_PB7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->FR1,7)))
#define TSB_PB_OD_PB0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,0)))
#define TSB_PB_OD_PB1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,1)))
#define TSB_PB_OD_PB2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,2)))
#define TSB_PB_OD_PB3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,3)))
#define TSB_PB_OD_PB4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,4)))
#define TSB_PB_OD_PB5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,5)))
#define TSB_PB_OD_PB6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,6)))
#define TSB_PB_OD_PB7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->OD,7)))
#define TSB_PB_PUP_PB0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,0)))
#define TSB_PB_PUP_PB1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,1)))
#define TSB_PB_PUP_PB2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,2)))
#define TSB_PB_PUP_PB3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,3)))
#define TSB_PB_PUP_PB4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,4)))
#define TSB_PB_PUP_PB5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,5)))
#define TSB_PB_PUP_PB6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,6)))
#define TSB_PB_PUP_PB7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PUP,7)))
#define TSB_PB_PDN_PB0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,0)))
#define TSB_PB_PDN_PB1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,1)))
#define TSB_PB_PDN_PB2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,2)))
#define TSB_PB_PDN_PB3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,3)))
#define TSB_PB_PDN_PB4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,4)))
#define TSB_PB_PDN_PB5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,5)))
#define TSB_PB_PDN_PB6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,6)))
#define TSB_PB_PDN_PB7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->PDN,7)))
#define TSB_PB_IE_PB0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,0)))
#define TSB_PB_IE_PB1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,1)))
#define TSB_PB_IE_PB2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,2)))
#define TSB_PB_IE_PB3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,3)))
#define TSB_PB_IE_PB4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,4)))
#define TSB_PB_IE_PB5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,5)))
#define TSB_PB_IE_PB6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,6)))
#define TSB_PB_IE_PB7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PB->IE,7)))


/* Port C */
#define TSB_PC_DATA_PC0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,0)))
#define TSB_PC_DATA_PC1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,1)))
#define TSB_PC_DATA_PC2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,2)))
#define TSB_PC_DATA_PC3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,3)))
#define TSB_PC_DATA_PC4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,4)))
#define TSB_PC_DATA_PC5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,5)))
#define TSB_PC_DATA_PC6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,6)))
#define TSB_PC_DATA_PC7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->DATA,7)))
#define TSB_PC_CR_PC0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,0)))
#define TSB_PC_CR_PC1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,1)))
#define TSB_PC_CR_PC2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,2)))
#define TSB_PC_CR_PC3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,3)))
#define TSB_PC_CR_PC4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,4)))
#define TSB_PC_CR_PC5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,5)))
#define TSB_PC_CR_PC6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,6)))
#define TSB_PC_CR_PC7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->CR,7)))
#define TSB_PC_FR1_PC0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,0)))
#define TSB_PC_FR1_PC1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,1)))
#define TSB_PC_FR1_PC2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,2)))
#define TSB_PC_FR1_PC3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,3)))
#define TSB_PC_FR1_PC4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,4)))
#define TSB_PC_FR1_PC5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,5)))
#define TSB_PC_FR1_PC6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,6)))
#define TSB_PC_FR1_PC7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->FR1,7)))
#define TSB_PC_OD_PC0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,0)))
#define TSB_PC_OD_PC1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,1)))
#define TSB_PC_OD_PC2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,2)))
#define TSB_PC_OD_PC3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,3)))
#define TSB_PC_OD_PC4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,4)))
#define TSB_PC_OD_PC5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,5)))
#define TSB_PC_OD_PC6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,6)))
#define TSB_PC_OD_PC7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->OD,7)))
#define TSB_PC_PUP_PC0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,0)))
#define TSB_PC_PUP_PC1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,1)))
#define TSB_PC_PUP_PC2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,2)))
#define TSB_PC_PUP_PC3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,3)))
#define TSB_PC_PUP_PC4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,4)))
#define TSB_PC_PUP_PC5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,5)))
#define TSB_PC_PUP_PC6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,6)))
#define TSB_PC_PUP_PC7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PUP,7)))
#define TSB_PC_PDN_PC0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,0)))
#define TSB_PC_PDN_PC1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,1)))
#define TSB_PC_PDN_PC2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,2)))
#define TSB_PC_PDN_PC3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,3)))
#define TSB_PC_PDN_PC4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,4)))
#define TSB_PC_PDN_PC5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,5)))
#define TSB_PC_PDN_PC6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,6)))
#define TSB_PC_PDN_PC7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->PDN,7)))
#define TSB_PC_IE_PC0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,0)))
#define TSB_PC_IE_PC1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,1)))
#define TSB_PC_IE_PC2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,2)))
#define TSB_PC_IE_PC3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,3)))
#define TSB_PC_IE_PC4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,4)))
#define TSB_PC_IE_PC5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,5)))
#define TSB_PC_IE_PC6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,6)))
#define TSB_PC_IE_PC7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PC->IE,7)))


/* Port D */
#define TSB_PD_DATA_PD0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,0)))
#define TSB_PD_DATA_PD1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,1)))
#define TSB_PD_DATA_PD2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,2)))
#define TSB_PD_DATA_PD3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,3)))
#define TSB_PD_DATA_PD4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,4)))
#define TSB_PD_DATA_PD5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,5)))
#define TSB_PD_DATA_PD6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->DATA,6)))
#define TSB_PD_CR_PD0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,0)))
#define TSB_PD_CR_PD1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,1)))
#define TSB_PD_CR_PD2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,2)))
#define TSB_PD_CR_PD3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,3)))
#define TSB_PD_CR_PD4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,4)))
#define TSB_PD_CR_PD5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,5)))
#define TSB_PD_CR_PD6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->CR,6)))
#define TSB_PD_FR1_PD0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,0)))
#define TSB_PD_FR1_PD1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,1)))
#define TSB_PD_FR1_PD2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,2)))
#define TSB_PD_FR1_PD4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,4)))
#define TSB_PD_FR1_PD5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,5)))
#define TSB_PD_FR1_PD6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR1,6)))
#define TSB_PD_FR2_PD0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR2,0)))
#define TSB_PD_FR2_PD1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR2,1)))
#define TSB_PD_FR2_PD4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->FR2,4)))
#define TSB_PD_OD_PD0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,0)))
#define TSB_PD_OD_PD1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,1)))
#define TSB_PD_OD_PD2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,2)))
#define TSB_PD_OD_PD3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,3)))
#define TSB_PD_OD_PD4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,4)))
#define TSB_PD_OD_PD5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,5)))
#define TSB_PD_OD_PD6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->OD,6)))
#define TSB_PD_PUP_PD0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,0)))
#define TSB_PD_PUP_PD1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,1)))
#define TSB_PD_PUP_PD2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,2)))
#define TSB_PD_PUP_PD3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,3)))
#define TSB_PD_PUP_PD4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,4)))
#define TSB_PD_PUP_PD5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,5)))
#define TSB_PD_PUP_PD6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PUP,6)))
#define TSB_PD_PDN_PD0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,0)))
#define TSB_PD_PDN_PD1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,1)))
#define TSB_PD_PDN_PD2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,2)))
#define TSB_PD_PDN_PD3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,3)))
#define TSB_PD_PDN_PD4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,4)))
#define TSB_PD_PDN_PD5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,5)))
#define TSB_PD_PDN_PD6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->PDN,6)))
#define TSB_PD_IE_PD0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,0)))
#define TSB_PD_IE_PD1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,1)))
#define TSB_PD_IE_PD2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,2)))
#define TSB_PD_IE_PD3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,3)))
#define TSB_PD_IE_PD4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,4)))
#define TSB_PD_IE_PD5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,5)))
#define TSB_PD_IE_PD6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PD->IE,6)))


/* Port E */
#define TSB_PE_DATA_PE0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,0)))
#define TSB_PE_DATA_PE1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,1)))
#define TSB_PE_DATA_PE2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,2)))
#define TSB_PE_DATA_PE3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,3)))
#define TSB_PE_DATA_PE4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,4)))
#define TSB_PE_DATA_PE5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,5)))
#define TSB_PE_DATA_PE6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,6)))
#define TSB_PE_DATA_PE7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->DATA,7)))
#define TSB_PE_CR_PE0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,0)))
#define TSB_PE_CR_PE1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,1)))
#define TSB_PE_CR_PE2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,2)))
#define TSB_PE_CR_PE3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,3)))
#define TSB_PE_CR_PE4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,4)))
#define TSB_PE_CR_PE5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,5)))
#define TSB_PE_CR_PE6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,6)))
#define TSB_PE_CR_PE7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->CR,7)))
#define TSB_PE_FR1_PE0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,0)))
#define TSB_PE_FR1_PE1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,1)))
#define TSB_PE_FR1_PE2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,2)))
#define TSB_PE_FR1_PE3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,3)))
#define TSB_PE_FR1_PE4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,4)))
#define TSB_PE_FR1_PE5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,5)))
#define TSB_PE_FR1_PE6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,6)))
#define TSB_PE_FR1_PE7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR1,7)))
#define TSB_PE_FR2_PE0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,0)))
#define TSB_PE_FR2_PE1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,1)))
#define TSB_PE_FR2_PE2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->FR2,2)))
#define TSB_PE_OD_PE0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,0)))
#define TSB_PE_OD_PE1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,1)))
#define TSB_PE_OD_PE2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,2)))
#define TSB_PE_OD_PE3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,3)))
#define TSB_PE_OD_PE4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,4)))
#define TSB_PE_OD_PE5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,5)))
#define TSB_PE_OD_PE6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,6)))
#define TSB_PE_OD_PE7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->OD,7)))
#define TSB_PE_PUP_PE0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,0)))
#define TSB_PE_PUP_PE1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,1)))
#define TSB_PE_PUP_PE2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,2)))
#define TSB_PE_PUP_PE3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,3)))
#define TSB_PE_PUP_PE4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,4)))
#define TSB_PE_PUP_PE5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,5)))
#define TSB_PE_PUP_PE6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,6)))
#define TSB_PE_PUP_PE7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PUP,7)))
#define TSB_PE_PDN_PE0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,0)))
#define TSB_PE_PDN_PE1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,1)))
#define TSB_PE_PDN_PE2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,2)))
#define TSB_PE_PDN_PE3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,3)))
#define TSB_PE_PDN_PE4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,4)))
#define TSB_PE_PDN_PE5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,5)))
#define TSB_PE_PDN_PE6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,6)))
#define TSB_PE_PDN_PE7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->PDN,7)))
#define TSB_PE_IE_PE0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,0)))
#define TSB_PE_IE_PE1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,1)))
#define TSB_PE_IE_PE2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,2)))
#define TSB_PE_IE_PE3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,3)))
#define TSB_PE_IE_PE4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,4)))
#define TSB_PE_IE_PE5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,5)))
#define TSB_PE_IE_PE6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,6)))
#define TSB_PE_IE_PE7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PE->IE,7)))


/* Port F */
#define TSB_PF_DATA_PF0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,0)))
#define TSB_PF_DATA_PF1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,1)))
#define TSB_PF_DATA_PF2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,2)))
#define TSB_PF_DATA_PF3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,3)))
#define TSB_PF_DATA_PF4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->DATA,4)))
#define TSB_PF_CR_PF0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,0)))
#define TSB_PF_CR_PF1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,1)))
#define TSB_PF_CR_PF2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,2)))
#define TSB_PF_CR_PF3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,3)))
#define TSB_PF_CR_PF4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->CR,4)))
#define TSB_PF_FR1_PF0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,0)))
#define TSB_PF_FR1_PF1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,1)))
#define TSB_PF_FR1_PF2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,2)))
#define TSB_PF_FR1_PF3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,3)))
#define TSB_PF_FR1_PF4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR1,4)))
#define TSB_PF_FR2_PF2F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,2)))
#define TSB_PF_FR2_PF3F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,3)))
#define TSB_PF_FR2_PF4F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR2,4)))
#define TSB_PF_FR3_PF2F3                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->FR3,2)))
#define TSB_PF_OD_PF0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,0)))
#define TSB_PF_OD_PF1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,1)))
#define TSB_PF_OD_PF2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,2)))
#define TSB_PF_OD_PF3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,3)))
#define TSB_PF_OD_PF4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->OD,4)))
#define TSB_PF_PUP_PF0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,0)))
#define TSB_PF_PUP_PF1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,1)))
#define TSB_PF_PUP_PF2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,2)))
#define TSB_PF_PUP_PF3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,3)))
#define TSB_PF_PUP_PF4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PUP,4)))
#define TSB_PF_PDN_PF0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,0)))
#define TSB_PF_PDN_PF1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,1)))
#define TSB_PF_PDN_PF2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,2)))
#define TSB_PF_PDN_PF3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,3)))
#define TSB_PF_PDN_PF4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->PDN,4)))
#define TSB_PF_IE_PF0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,0)))
#define TSB_PF_IE_PF1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,1)))
#define TSB_PF_IE_PF2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,2)))
#define TSB_PF_IE_PF3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,3)))
#define TSB_PF_IE_PF4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PF->IE,4)))


/* Port G */
#define TSB_PG_DATA_PG0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,0)))
#define TSB_PG_DATA_PG1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,1)))
#define TSB_PG_DATA_PG2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,2)))
#define TSB_PG_DATA_PG3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,3)))
#define TSB_PG_DATA_PG4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,4)))
#define TSB_PG_DATA_PG5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,5)))
#define TSB_PG_DATA_PG6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,6)))
#define TSB_PG_DATA_PG7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->DATA,7)))
#define TSB_PG_CR_PG0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,0)))
#define TSB_PG_CR_PG1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,1)))
#define TSB_PG_CR_PG2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,2)))
#define TSB_PG_CR_PG3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,3)))
#define TSB_PG_CR_PG4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,4)))
#define TSB_PG_CR_PG5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,5)))
#define TSB_PG_CR_PG6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,6)))
#define TSB_PG_CR_PG7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->CR,7)))
#define TSB_PG_FR1_PG0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,0)))
#define TSB_PG_FR1_PG1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,1)))
#define TSB_PG_FR1_PG2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,2)))
#define TSB_PG_FR1_PG3F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,3)))
#define TSB_PG_FR1_PG4F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,4)))
#define TSB_PG_FR1_PG5F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,5)))
#define TSB_PG_FR1_PG6F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,6)))
#define TSB_PG_FR1_PG7F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->FR1,7)))
#define TSB_PG_OD_PG0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,0)))
#define TSB_PG_OD_PG1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,1)))
#define TSB_PG_OD_PG2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,2)))
#define TSB_PG_OD_PG3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,3)))
#define TSB_PG_OD_PG4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,4)))
#define TSB_PG_OD_PG5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,5)))
#define TSB_PG_OD_PG6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,6)))
#define TSB_PG_OD_PG7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->OD,7)))
#define TSB_PG_PUP_PG0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,0)))
#define TSB_PG_PUP_PG1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,1)))
#define TSB_PG_PUP_PG2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,2)))
#define TSB_PG_PUP_PG3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,3)))
#define TSB_PG_PUP_PG4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,4)))
#define TSB_PG_PUP_PG5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,5)))
#define TSB_PG_PUP_PG6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,6)))
#define TSB_PG_PUP_PG7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PUP,7)))
#define TSB_PG_PDN_PG0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,0)))
#define TSB_PG_PDN_PG1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,1)))
#define TSB_PG_PDN_PG2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,2)))
#define TSB_PG_PDN_PG3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,3)))
#define TSB_PG_PDN_PG4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,4)))
#define TSB_PG_PDN_PG5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,5)))
#define TSB_PG_PDN_PG6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,6)))
#define TSB_PG_PDN_PG7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->PDN,7)))
#define TSB_PG_IE_PG0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,0)))
#define TSB_PG_IE_PG1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,1)))
#define TSB_PG_IE_PG2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,2)))
#define TSB_PG_IE_PG3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,3)))
#define TSB_PG_IE_PG4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,4)))
#define TSB_PG_IE_PG5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,5)))
#define TSB_PG_IE_PG6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,6)))
#define TSB_PG_IE_PG7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PG->IE,7)))


/* Port H */
#define TSB_PH_DATA_PH0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,0)))
#define TSB_PH_DATA_PH1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,1)))
#define TSB_PH_DATA_PH2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,2)))
#define TSB_PH_DATA_PH3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,3)))
#define TSB_PH_DATA_PH4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,4)))
#define TSB_PH_DATA_PH5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,5)))
#define TSB_PH_DATA_PH6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,6)))
#define TSB_PH_DATA_PH7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->DATA,7)))
#define TSB_PH_CR_PH0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,0)))
#define TSB_PH_CR_PH1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,1)))
#define TSB_PH_CR_PH2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,2)))
#define TSB_PH_CR_PH3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,3)))
#define TSB_PH_CR_PH4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,4)))
#define TSB_PH_CR_PH5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,5)))
#define TSB_PH_CR_PH6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,6)))
#define TSB_PH_CR_PH7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->CR,7)))
#define TSB_PH_OD_PH0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,0)))
#define TSB_PH_OD_PH1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,1)))
#define TSB_PH_OD_PH2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,2)))
#define TSB_PH_OD_PH3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,3)))
#define TSB_PH_OD_PH4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,4)))
#define TSB_PH_OD_PH5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,5)))
#define TSB_PH_OD_PH6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,6)))
#define TSB_PH_OD_PH7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->OD,7)))
#define TSB_PH_PUP_PH0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,0)))
#define TSB_PH_PUP_PH1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,1)))
#define TSB_PH_PUP_PH2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,2)))
#define TSB_PH_PUP_PH3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,3)))
#define TSB_PH_PUP_PH4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,4)))
#define TSB_PH_PUP_PH5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,5)))
#define TSB_PH_PUP_PH6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,6)))
#define TSB_PH_PUP_PH7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PUP,7)))
#define TSB_PH_PDN_PH0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,0)))
#define TSB_PH_PDN_PH1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,1)))
#define TSB_PH_PDN_PH2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,2)))
#define TSB_PH_PDN_PH3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,3)))
#define TSB_PH_PDN_PH4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,4)))
#define TSB_PH_PDN_PH5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,5)))
#define TSB_PH_PDN_PH6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,6)))
#define TSB_PH_PDN_PH7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->PDN,7)))
#define TSB_PH_IE_PH0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,0)))
#define TSB_PH_IE_PH1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,1)))
#define TSB_PH_IE_PH2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,2)))
#define TSB_PH_IE_PH3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,3)))
#define TSB_PH_IE_PH4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,4)))
#define TSB_PH_IE_PH5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,5)))
#define TSB_PH_IE_PH6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,6)))
#define TSB_PH_IE_PH7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PH->IE,7)))


/* Port J */
#define TSB_PJ_DATA_PJ0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,0)))
#define TSB_PJ_DATA_PJ1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,1)))
#define TSB_PJ_DATA_PJ2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,2)))
#define TSB_PJ_DATA_PJ3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,3)))
#define TSB_PJ_DATA_PJ4                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,4)))
#define TSB_PJ_DATA_PJ5                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,5)))
#define TSB_PJ_DATA_PJ6                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,6)))
#define TSB_PJ_DATA_PJ7                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->DATA,7)))
#define TSB_PJ_CR_PJ0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,0)))
#define TSB_PJ_CR_PJ1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,1)))
#define TSB_PJ_CR_PJ2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,2)))
#define TSB_PJ_CR_PJ3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,3)))
#define TSB_PJ_CR_PJ4C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,4)))
#define TSB_PJ_CR_PJ5C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,5)))
#define TSB_PJ_CR_PJ6C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,6)))
#define TSB_PJ_CR_PJ7C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->CR,7)))
#define TSB_PJ_OD_PJ0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,0)))
#define TSB_PJ_OD_PJ1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,1)))
#define TSB_PJ_OD_PJ2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,2)))
#define TSB_PJ_OD_PJ3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,3)))
#define TSB_PJ_OD_PJ4OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,4)))
#define TSB_PJ_OD_PJ5OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,5)))
#define TSB_PJ_OD_PJ6OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,6)))
#define TSB_PJ_OD_PJ7OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->OD,7)))
#define TSB_PJ_PUP_PJ0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,0)))
#define TSB_PJ_PUP_PJ1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,1)))
#define TSB_PJ_PUP_PJ2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,2)))
#define TSB_PJ_PUP_PJ3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,3)))
#define TSB_PJ_PUP_PJ4UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,4)))
#define TSB_PJ_PUP_PJ5UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,5)))
#define TSB_PJ_PUP_PJ6UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,6)))
#define TSB_PJ_PUP_PJ7UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PUP,7)))
#define TSB_PJ_PDN_PJ0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,0)))
#define TSB_PJ_PDN_PJ1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,1)))
#define TSB_PJ_PDN_PJ2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,2)))
#define TSB_PJ_PDN_PJ3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,3)))
#define TSB_PJ_PDN_PJ4DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,4)))
#define TSB_PJ_PDN_PJ5DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,5)))
#define TSB_PJ_PDN_PJ6DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,6)))
#define TSB_PJ_PDN_PJ7DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->PDN,7)))
#define TSB_PJ_IE_PJ0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,0)))
#define TSB_PJ_IE_PJ1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,1)))
#define TSB_PJ_IE_PJ2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,2)))
#define TSB_PJ_IE_PJ3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,3)))
#define TSB_PJ_IE_PJ4IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,4)))
#define TSB_PJ_IE_PJ5IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,5)))
#define TSB_PJ_IE_PJ6IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,6)))
#define TSB_PJ_IE_PJ7IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PJ->IE,7)))


/* Port K */
#define TSB_PK_DATA_PK0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,0)))
#define TSB_PK_DATA_PK1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->DATA,1)))
#define TSB_PK_CR_PK0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,0)))
#define TSB_PK_CR_PK1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->CR,1)))
#define TSB_PK_FR1_PK0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,0)))
#define TSB_PK_FR1_PK1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->FR1,1)))
#define TSB_PK_OD_PK0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,0)))
#define TSB_PK_OD_PK1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->OD,1)))
#define TSB_PK_PUP_PK0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,0)))
#define TSB_PK_PUP_PK1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PUP,1)))
#define TSB_PK_PDN_PK0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,0)))
#define TSB_PK_PDN_PK1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->PDN,1)))
#define TSB_PK_IE_PK0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,0)))
#define TSB_PK_IE_PK1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PK->IE,1)))


/* Port L */
#define TSB_PL_DATA_PL0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,0)))
#define TSB_PL_DATA_PL1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->DATA,1)))
#define TSB_PL_CR_PL0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,0)))
#define TSB_PL_CR_PL1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->CR,1)))
#define TSB_PL_FR1_PL0F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,0)))
#define TSB_PL_FR1_PL1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->FR1,1)))
#define TSB_PL_OD_PL0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,0)))
#define TSB_PL_OD_PL1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->OD,1)))
#define TSB_PL_PUP_PL0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,0)))
#define TSB_PL_PUP_PL1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PUP,1)))
#define TSB_PL_PDN_PL0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,0)))
#define TSB_PL_PDN_PL1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->PDN,1)))
#define TSB_PL_IE_PL0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,0)))
#define TSB_PL_IE_PL1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PL->IE,1)))


/* Port N */
#define TSB_PN_DATA_PN0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,0)))
#define TSB_PN_DATA_PN1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,1)))
#define TSB_PN_DATA_PN2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->DATA,2)))
#define TSB_PN_CR_PN0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,0)))
#define TSB_PN_CR_PN1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,1)))
#define TSB_PN_CR_PN2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->CR,2)))
#define TSB_PN_FR1_PN1F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,1)))
#define TSB_PN_FR1_PN2F1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR1,2)))
#define TSB_PN_FR2_PN0F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR2,0)))
#define TSB_PN_FR2_PN1F2                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->FR2,1)))
#define TSB_PN_OD_PN0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,0)))
#define TSB_PN_OD_PN1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->OD,1)))
#define TSB_PN_PUP_PN0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,0)))
#define TSB_PN_PUP_PN1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PUP,1)))
#define TSB_PN_PDN_PN0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PDN,0)))
#define TSB_PN_PDN_PN1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->PDN,1)))
#define TSB_PN_IE_PN0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,0)))
#define TSB_PN_IE_PN1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PN->IE,1)))


/* Port P */
#define TSB_PP_DATA_PP0                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,0)))
#define TSB_PP_DATA_PP1                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,1)))
#define TSB_PP_DATA_PP2                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,2)))
#define TSB_PP_DATA_PP3                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->DATA,3)))
#define TSB_PP_CR_PP0C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,0)))
#define TSB_PP_CR_PP1C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,1)))
#define TSB_PP_CR_PP2C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,2)))
#define TSB_PP_CR_PP3C                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->CR,3)))
#define TSB_PP_OD_PP0OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,0)))
#define TSB_PP_OD_PP1OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,1)))
#define TSB_PP_OD_PP2OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,2)))
#define TSB_PP_OD_PP3OD                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->OD,3)))
#define TSB_PP_PUP_PP0UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,0)))
#define TSB_PP_PUP_PP1UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,1)))
#define TSB_PP_PUP_PP2UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,2)))
#define TSB_PP_PUP_PP3UP                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PUP,3)))
#define TSB_PP_PDN_PP0DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PDN,0)))
#define TSB_PP_PDN_PP1DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PDN,1)))
#define TSB_PP_PDN_PP2DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PDN,2)))
#define TSB_PP_PDN_PP3DN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->PDN,3)))
#define TSB_PP_IE_PP0IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,0)))
#define TSB_PP_IE_PP1IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,1)))
#define TSB_PP_IE_PP2IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,2)))
#define TSB_PP_IE_PP3IE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_PP->IE,3)))


/* 16-bit Timer / Event Counters (TMRB) */
#define TSB_TB0_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,6)))
#define TSB_TB0_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->EN,7)))
#define TSB_TB0_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,0)))
#define TSB_TB0_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->RUN,2)))
#define TSB_TB0_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,0)))
#define TSB_TB0_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,1)))
#define TSB_TB0_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,3)))
#define TSB_TB0_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,5)))
#define TSB_TB0_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->CR,7)))
#define TSB_TB0_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,3)))
#define TSB_TB0_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,6)))
#define TSB_TB0_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->MOD,7)))
#define TSB_TB0_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,2)))
#define TSB_TB0_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,3)))
#define TSB_TB0_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,4)))
#define TSB_TB0_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->FFCR,5)))
#define TSB_TB0_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->IM,0)))
#define TSB_TB0_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->IM,1)))
#define TSB_TB0_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB0->IM,2)))

#define TSB_TB1_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->EN,6)))
#define TSB_TB1_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->EN,7)))
#define TSB_TB1_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->RUN,0)))
#define TSB_TB1_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->RUN,2)))
#define TSB_TB1_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,0)))
#define TSB_TB1_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,1)))
#define TSB_TB1_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,3)))
#define TSB_TB1_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,5)))
#define TSB_TB1_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->CR,7)))
#define TSB_TB1_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,3)))
#define TSB_TB1_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,6)))
#define TSB_TB1_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->MOD,7)))
#define TSB_TB1_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,2)))
#define TSB_TB1_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,3)))
#define TSB_TB1_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,4)))
#define TSB_TB1_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->FFCR,5)))
#define TSB_TB1_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,0)))
#define TSB_TB1_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,1)))
#define TSB_TB1_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB1->IM,2)))

#define TSB_TB2_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->EN,6)))
#define TSB_TB2_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->EN,7)))
#define TSB_TB2_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->RUN,0)))
#define TSB_TB2_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->RUN,2)))
#define TSB_TB2_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,0)))
#define TSB_TB2_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,1)))
#define TSB_TB2_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,3)))
#define TSB_TB2_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,5)))
#define TSB_TB2_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->CR,7)))
#define TSB_TB2_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,3)))
#define TSB_TB2_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,6)))
#define TSB_TB2_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->MOD,7)))
#define TSB_TB2_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,2)))
#define TSB_TB2_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,3)))
#define TSB_TB2_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,4)))
#define TSB_TB2_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->FFCR,5)))
#define TSB_TB2_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,0)))
#define TSB_TB2_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,1)))
#define TSB_TB2_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB2->IM,2)))

#define TSB_TB3_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->EN,6)))
#define TSB_TB3_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->EN,7)))
#define TSB_TB3_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->RUN,0)))
#define TSB_TB3_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->RUN,2)))
#define TSB_TB3_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,0)))
#define TSB_TB3_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,1)))
#define TSB_TB3_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,3)))
#define TSB_TB3_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,5)))
#define TSB_TB3_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->CR,7)))
#define TSB_TB3_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,3)))
#define TSB_TB3_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,6)))
#define TSB_TB3_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->MOD,7)))
#define TSB_TB3_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,2)))
#define TSB_TB3_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,3)))
#define TSB_TB3_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,4)))
#define TSB_TB3_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->FFCR,5)))
#define TSB_TB3_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,0)))
#define TSB_TB3_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,1)))
#define TSB_TB3_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB3->IM,2)))

#define TSB_TB4_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->EN,6)))
#define TSB_TB4_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->EN,7)))
#define TSB_TB4_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->RUN,0)))
#define TSB_TB4_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->RUN,2)))
#define TSB_TB4_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,0)))
#define TSB_TB4_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,1)))
#define TSB_TB4_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,3)))
#define TSB_TB4_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,5)))
#define TSB_TB4_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->CR,7)))
#define TSB_TB4_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,3)))
#define TSB_TB4_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,6)))
#define TSB_TB4_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->MOD,7)))
#define TSB_TB4_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,2)))
#define TSB_TB4_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,3)))
#define TSB_TB4_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,4)))
#define TSB_TB4_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->FFCR,5)))
#define TSB_TB4_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,0)))
#define TSB_TB4_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,1)))
#define TSB_TB4_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB4->IM,2)))

#define TSB_TB5_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->EN,6)))
#define TSB_TB5_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->EN,7)))
#define TSB_TB5_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->RUN,0)))
#define TSB_TB5_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->RUN,2)))
#define TSB_TB5_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,0)))
#define TSB_TB5_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,1)))
#define TSB_TB5_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,3)))
#define TSB_TB5_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,5)))
#define TSB_TB5_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->CR,7)))
#define TSB_TB5_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,3)))
#define TSB_TB5_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,6)))
#define TSB_TB5_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->MOD,7)))
#define TSB_TB5_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,2)))
#define TSB_TB5_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,3)))
#define TSB_TB5_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,4)))
#define TSB_TB5_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->FFCR,5)))
#define TSB_TB5_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,0)))
#define TSB_TB5_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,1)))
#define TSB_TB5_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB5->IM,2)))

#define TSB_TB6_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->EN,6)))
#define TSB_TB6_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->EN,7)))
#define TSB_TB6_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->RUN,0)))
#define TSB_TB6_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->RUN,2)))
#define TSB_TB6_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,0)))
#define TSB_TB6_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,1)))
#define TSB_TB6_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,3)))
#define TSB_TB6_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,5)))
#define TSB_TB6_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->CR,7)))
#define TSB_TB6_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,3)))
#define TSB_TB6_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,6)))
#define TSB_TB6_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->MOD,7)))
#define TSB_TB6_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,2)))
#define TSB_TB6_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,3)))
#define TSB_TB6_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,4)))
#define TSB_TB6_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->FFCR,5)))
#define TSB_TB6_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,0)))
#define TSB_TB6_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,1)))
#define TSB_TB6_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB6->IM,2)))

#define TSB_TB7_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->EN,6)))
#define TSB_TB7_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->EN,7)))
#define TSB_TB7_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->RUN,0)))
#define TSB_TB7_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->RUN,2)))
#define TSB_TB7_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,0)))
#define TSB_TB7_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,1)))
#define TSB_TB7_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,3)))
#define TSB_TB7_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,5)))
#define TSB_TB7_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->CR,7)))
#define TSB_TB7_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,3)))
#define TSB_TB7_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,6)))
#define TSB_TB7_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->MOD,7)))
#define TSB_TB7_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,2)))
#define TSB_TB7_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,3)))
#define TSB_TB7_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,4)))
#define TSB_TB7_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->FFCR,5)))
#define TSB_TB7_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,0)))
#define TSB_TB7_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,1)))
#define TSB_TB7_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB7->IM,2)))

#define TSB_TB8_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->EN,6)))
#define TSB_TB8_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->EN,7)))
#define TSB_TB8_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->RUN,0)))
#define TSB_TB8_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->RUN,2)))
#define TSB_TB8_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,0)))
#define TSB_TB8_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,1)))
#define TSB_TB8_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,3)))
#define TSB_TB8_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,5)))
#define TSB_TB8_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->CR,7)))
#define TSB_TB8_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->MOD,3)))
#define TSB_TB8_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB8->MOD,6)))
#define TSB_TB8_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->MOD,7)))
#define TSB_TB8_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,2)))
#define TSB_TB8_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,3)))
#define TSB_TB8_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,4)))
#define TSB_TB8_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->FFCR,5)))
#define TSB_TB8_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->IM,0)))
#define TSB_TB8_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->IM,1)))
#define TSB_TB8_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB8->IM,2)))

#define TSB_TB9_EN_TBHALT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->EN,6)))
#define TSB_TB9_EN_TBEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->EN,7)))
#define TSB_TB9_RUN_TBRUN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->RUN,0)))
#define TSB_TB9_RUN_TBPRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->RUN,2)))
#define TSB_TB9_CR_CSSEL                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,0)))
#define TSB_TB9_CR_TRGSEL                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,1)))
#define TSB_TB9_CR_I2TB                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,3)))
#define TSB_TB9_CR_TBSYNC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,5)))
#define TSB_TB9_CR_TBWBF                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->CR,7)))
#define TSB_TB9_MOD_TBCLE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->MOD,3)))
#define TSB_TB9_MOD_TBCP                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_TB9->MOD,6)))
#define TSB_TB9_MOD_TBRSWR                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->MOD,7)))
#define TSB_TB9_FFCR_TBE0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,2)))
#define TSB_TB9_FFCR_TBE1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,3)))
#define TSB_TB9_FFCR_TBC0T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,4)))
#define TSB_TB9_FFCR_TBC1T1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->FFCR,5)))
#define TSB_TB9_IM_TBIM0                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->IM,0)))
#define TSB_TB9_IM_TBIM1                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->IM,1)))
#define TSB_TB9_IM_TBIMOF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_TB9->IM,2)))


/* Serial Bus Interface(SBI) */
#define TSB_SBI_CR0_SBIEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI->CR0,7)))
#define TSB_SBI_CR1_SWRMON                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->CR1,0)))
#define TSB_SBI_CR1_ACK                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI->CR1,4)))
#define TSB_SBI_I2CAR_ALS                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI->I2CAR,0)))
#define TSB_SBI_CR2_PIN                           (*((__O  uint32_t *)BITBAND_PERI(&TSB_SBI->CR2,4)))
#define TSB_SBI_CR2_BB                            (*((__O  uint32_t *)BITBAND_PERI(&TSB_SBI->CR2,5)))
#define TSB_SBI_CR2_TRX                           (*((__O  uint32_t *)BITBAND_PERI(&TSB_SBI->CR2,6)))
#define TSB_SBI_CR2_MST                           (*((__O  uint32_t *)BITBAND_PERI(&TSB_SBI->CR2,7)))
#define TSB_SBI_SR_LRB                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,0)))
#define TSB_SBI_SR_ADO                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,1)))
#define TSB_SBI_SR_AAS                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,2)))
#define TSB_SBI_SR_AL                             (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,3)))
#define TSB_SBI_SR_PIN                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,4)))
#define TSB_SBI_SR_BB                             (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,5)))
#define TSB_SBI_SR_TRX                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,6)))
#define TSB_SBI_SR_MST                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_SBI->SR,7)))
#define TSB_SBI_BR0_I2SBI                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SBI->BR0,6)))


/* Serial Channel (SC) */
#define TSB_SC0_EN_SIOE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->EN,0)))
#define TSB_SC0_EN_BRCKSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->EN,1)))
#define TSB_SC0_CR_TXDEMP                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->CR,10)))
#define TSB_SC0_MOD0_WU                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,4)))
#define TSB_SC0_MOD0_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,5)))
#define TSB_SC0_MOD0_CTSE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,6)))
#define TSB_SC0_MOD0_TB8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD0,7)))
#define TSB_SC0_BRCR_BRADDE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->BRCR,6)))
#define TSB_SC0_MOD1_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD1,4)))
#define TSB_SC0_MOD1_I2SC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD1,7)))
#define TSB_SC0_MOD2_WBUF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,2)))
#define TSB_SC0_MOD2_DRCHG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,3)))
#define TSB_SC0_MOD2_SBLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,4)))
#define TSB_SC0_MOD2_TXRUN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,5)))
#define TSB_SC0_MOD2_RBFLL                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,6)))
#define TSB_SC0_MOD2_TBEMP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->MOD2,7)))
#define TSB_SC0_RFC_RFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->RFC,6)))
#define TSB_SC0_RFC_RFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC0->RFC,7)))
#define TSB_SC0_TFC_TFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->TFC,6)))
#define TSB_SC0_TFC_TFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC0->TFC,7)))
#define TSB_SC0_TFC_TBCLR                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC0->TFC,8)))
#define TSB_SC0_RST_ROR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->RST,7)))
#define TSB_SC0_TST_TUR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC0->TST,7)))
#define TSB_SC0_FCNF_CNFG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,0)))
#define TSB_SC0_FCNF_RXTXCNT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,1)))
#define TSB_SC0_FCNF_RFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,2)))
#define TSB_SC0_FCNF_TFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,3)))
#define TSB_SC0_FCNF_RFST                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC0->FCNF,4)))

#define TSB_SC1_EN_SIOE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->EN,0)))
#define TSB_SC1_EN_BRCKSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->EN,1)))
#define TSB_SC1_CR_TXDEMP                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->CR,10)))
#define TSB_SC1_MOD0_WU                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,4)))
#define TSB_SC1_MOD0_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,5)))
#define TSB_SC1_MOD0_CTSE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,6)))
#define TSB_SC1_MOD0_TB8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD0,7)))
#define TSB_SC1_BRCR_BRADDE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->BRCR,6)))
#define TSB_SC1_MOD1_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD1,4)))
#define TSB_SC1_MOD1_I2SC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD1,7)))
#define TSB_SC1_MOD2_WBUF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,2)))
#define TSB_SC1_MOD2_DRCHG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,3)))
#define TSB_SC1_MOD2_SBLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,4)))
#define TSB_SC1_MOD2_TXRUN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,5)))
#define TSB_SC1_MOD2_RBFLL                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,6)))
#define TSB_SC1_MOD2_TBEMP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->MOD2,7)))
#define TSB_SC1_RFC_RFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->RFC,6)))
#define TSB_SC1_RFC_RFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC1->RFC,7)))
#define TSB_SC1_TFC_TFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->TFC,6)))
#define TSB_SC1_TFC_TFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC1->TFC,7)))
#define TSB_SC1_TFC_TBCLR                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC1->TFC,8)))
#define TSB_SC1_RST_ROR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->RST,7)))
#define TSB_SC1_TST_TUR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC1->TST,7)))
#define TSB_SC1_FCNF_CNFG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,0)))
#define TSB_SC1_FCNF_RXTXCNT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,1)))
#define TSB_SC1_FCNF_RFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,2)))
#define TSB_SC1_FCNF_TFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,3)))
#define TSB_SC1_FCNF_RFST                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC1->FCNF,4)))

#define TSB_SC2_EN_SIOE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->EN,0)))
#define TSB_SC2_EN_BRCKSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->EN,1)))
#define TSB_SC2_CR_TXDEMP                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->CR,10)))
#define TSB_SC2_MOD0_WU                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,4)))
#define TSB_SC2_MOD0_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,5)))
#define TSB_SC2_MOD0_CTSE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,6)))
#define TSB_SC2_MOD0_TB8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD0,7)))
#define TSB_SC2_BRCR_BRADDE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->BRCR,6)))
#define TSB_SC2_MOD1_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD1,4)))
#define TSB_SC2_MOD1_I2SC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD1,7)))
#define TSB_SC2_MOD2_WBUF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,2)))
#define TSB_SC2_MOD2_DRCHG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,3)))
#define TSB_SC2_MOD2_SBLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,4)))
#define TSB_SC2_MOD2_TXRUN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,5)))
#define TSB_SC2_MOD2_RBFLL                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,6)))
#define TSB_SC2_MOD2_TBEMP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->MOD2,7)))
#define TSB_SC2_RFC_RFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->RFC,6)))
#define TSB_SC2_RFC_RFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC2->RFC,7)))
#define TSB_SC2_TFC_TFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->TFC,6)))
#define TSB_SC2_TFC_TFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC2->TFC,7)))
#define TSB_SC2_TFC_TBCLR                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC2->TFC,8)))
#define TSB_SC2_RST_ROR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->RST,7)))
#define TSB_SC2_TST_TUR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC2->TST,7)))
#define TSB_SC2_FCNF_CNFG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,0)))
#define TSB_SC2_FCNF_RXTXCNT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,1)))
#define TSB_SC2_FCNF_RFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,2)))
#define TSB_SC2_FCNF_TFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,3)))
#define TSB_SC2_FCNF_RFST                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC2->FCNF,4)))

#define TSB_SC3_EN_SIOE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->EN,0)))
#define TSB_SC3_EN_BRCKSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->EN,1)))
#define TSB_SC3_CR_TXDEMP                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->CR,10)))
#define TSB_SC3_MOD0_WU                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD0,4)))
#define TSB_SC3_MOD0_RXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD0,5)))
#define TSB_SC3_MOD0_CTSE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD0,6)))
#define TSB_SC3_MOD0_TB8                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD0,7)))
#define TSB_SC3_BRCR_BRADDE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->BRCR,6)))
#define TSB_SC3_MOD1_TXE                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD1,4)))
#define TSB_SC3_MOD1_I2SC                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD1,7)))
#define TSB_SC3_MOD2_WBUF                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,2)))
#define TSB_SC3_MOD2_DRCHG                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,3)))
#define TSB_SC3_MOD2_SBLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,4)))
#define TSB_SC3_MOD2_TXRUN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,5)))
#define TSB_SC3_MOD2_RBFLL                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,6)))
#define TSB_SC3_MOD2_TBEMP                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->MOD2,7)))
#define TSB_SC3_RFC_RFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->RFC,6)))
#define TSB_SC3_RFC_RFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC3->RFC,7)))
#define TSB_SC3_TFC_TFIS                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->TFC,6)))
#define TSB_SC3_TFC_TFCS                          (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC3->TFC,7)))
#define TSB_SC3_TFC_TBCLR                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_SC3->TFC,8)))
#define TSB_SC3_RST_ROR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->RST,7)))
#define TSB_SC3_TST_TUR                           (*((__I  uint32_t *)BITBAND_PERI(&TSB_SC3->TST,7)))
#define TSB_SC3_FCNF_CNFG                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,0)))
#define TSB_SC3_FCNF_RXTXCNT                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,1)))
#define TSB_SC3_FCNF_RFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,2)))
#define TSB_SC3_FCNF_TFIE                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,3)))
#define TSB_SC3_FCNF_RFST                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_SC3->FCNF,4)))



/* Watchdog Timer (WD) */
#define TSB_WD_MOD_RESCR                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,1)))
#define TSB_WD_MOD_WDTE                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_WD->MOD,7)))


/* Clock Generator (CG) */
#define TSB_CG_SYSCR_FPSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->SYSCR,12)))
#define TSB_CG_OSCCR_WUEON                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,0)))
#define TSB_CG_OSCCR_WUEF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,1)))
#define TSB_CG_OSCCR_PLLON                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,2)))
#define TSB_CG_OSCCR_WUPSEL1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,3)))
#define TSB_CG_OSCCR_XEN1                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,8)))
#define TSB_CG_OSCCR_XEN2                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,16)))
#define TSB_CG_OSCCR_OSCSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,17)))
#define TSB_CG_OSCCR_HOSCON                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,18)))
#define TSB_CG_OSCCR_WUPSEL2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->OSCCR,19)))
#define TSB_CG_STBYCR_RXEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->STBYCR,8)))
#define TSB_CG_PLLSEL_PLLSEL                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->PLLSEL,0)))
#define TSB_CG_RSTFLG_PONRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,0)))
#define TSB_CG_RSTFLG_PINRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,1)))
#define TSB_CG_RSTFLG_WDTRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,2)))
#define TSB_CG_RSTFLG_VLTDRSTF                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,3)))
#define TSB_CG_RSTFLG_DBGRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,4)))
#define TSB_CG_RSTFLG_OFDRSTF                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->RSTFLG,5)))
#define TSB_CG_IMCGA_INT0EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,0)))
#define TSB_CG_IMCGA_INT1EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,8)))
#define TSB_CG_IMCGA_INT2EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,16)))
#define TSB_CG_IMCGA_INT3EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGA,24)))
#define TSB_CG_IMCGB_INT4EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,0)))
#define TSB_CG_IMCGB_INT5EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,8)))
#define TSB_CG_IMCGB_INT6EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,16)))
#define TSB_CG_IMCGB_INT7EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGB,24)))
#define TSB_CG_IMCGC_INT8EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,0)))
#define TSB_CG_IMCGC_INT9EN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,8)))
#define TSB_CG_IMCGC_INTAEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,16)))
#define TSB_CG_IMCGC_INTBEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGC,24)))
#define TSB_CG_IMCGD_INTCEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,0)))
#define TSB_CG_IMCGD_INTDEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,8)))
#define TSB_CG_IMCGD_INTEEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,16)))
#define TSB_CG_IMCGD_INTFEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->IMCGD,24)))
#define TSB_CG_CKSTP_CANSTP                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_CG->CKSTP,2)))


/* Internal High-speed Oscillation Adjustment */
#define TSB_TRMOSC_EN_TRIMEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_TRMOSC->EN,0)))


/* Digital Noize FilterClock Control */
#define TSB_NF_ENCR_NFEN0                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,0)))
#define TSB_NF_ENCR_NFEN1                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,1)))
#define TSB_NF_ENCR_NFEN2                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,2)))
#define TSB_NF_ENCR_NFEN3                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,3)))
#define TSB_NF_ENCR_NFEN4                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,4)))
#define TSB_NF_ENCR_NFEN5                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,5)))
#define TSB_NF_ENCR_NFEN6                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,6)))
#define TSB_NF_ENCR_NFEN7                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,7)))
#define TSB_NF_ENCR_NFEN8                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,8)))
#define TSB_NF_ENCR_NFEN9                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_NF->ENCR,9)))


/* Voltage Detection Control Circuit */
#define TSB_VD_CR_VDEN                            (*((__IO uint32_t *)BITBAND_PERI(&TSB_VD->CR,0)))


/* Programmable Motor Driver (PMD) */
#define TSB_PMD0_MDEN_PWMEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDEN,0)))
#define TSB_PMD0_MDCR_PWMMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,0)))
#define TSB_PMD0_MDCR_PINT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,3)))
#define TSB_PMD0_MDCR_DTYMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,4)))
#define TSB_PMD0_MDCR_SYNTMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,5)))
#define TSB_PMD0_MDCR_PWMCK                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,6)))
#define TSB_PMD0_MDCR_DTCREN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDCR,7)))
#define TSB_PMD0_CNTSTA_UPDWN                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->CNTSTA,0)))
#define TSB_PMD0_MODESEL_MDSEL0                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MODESEL,0)))
#define TSB_PMD0_MODESEL_MDSEL1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MODESEL,1)))
#define TSB_PMD0_MODESEL_MDSEL2                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MODESEL,2)))
#define TSB_PMD0_MODESEL_MDSEL3                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MODESEL,3)))
#define TSB_PMD0_MODESEL_DCMPEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MODESEL,7)))
#define TSB_PMD0_MDOUT_UPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDOUT,8)))
#define TSB_PMD0_MDOUT_VPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDOUT,9)))
#define TSB_PMD0_MDOUT_WPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDOUT,10)))
#define TSB_PMD0_MDPOT_POLL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDPOT,2)))
#define TSB_PMD0_MDPOT_POLH                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->MDPOT,3)))
#define TSB_PMD0_EMGCR_EMGEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGCR,0)))
#define TSB_PMD0_EMGCR_EMGRS                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGCR,1)))
#define TSB_PMD0_EMGCR_INHEN                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGCR,5)))
#define TSB_PMD0_EMGSTA_EMGST                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGSTA,0)))
#define TSB_PMD0_EMGSTA_EMGI                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->EMGSTA,1)))
#define TSB_PMD0_OVVCR_OVVEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,0)))
#define TSB_PMD0_OVVCR_OVVRS                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,1)))
#define TSB_PMD0_OVVCR_OVVISEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,2)))
#define TSB_PMD0_OVVCR_ADIN0EN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,5)))
#define TSB_PMD0_OVVCR_ADIN1EN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVCR,6)))
#define TSB_PMD0_OVVSTA_OVVST                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVSTA,0)))
#define TSB_PMD0_OVVSTA_OVVI                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD0->OVVSTA,1)))
#define TSB_PMD0_TRGCR_TRG0BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGCR,3)))
#define TSB_PMD0_TRGCR_TRG1BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGCR,7)))
#define TSB_PMD0_TRGCR_TRG2BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGCR,11)))
#define TSB_PMD0_TRGCR_TRG3BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGCR,15)))
#define TSB_PMD0_TRGMD_EMGTGE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGMD,0)))
#define TSB_PMD0_TRGMD_TRGOUT                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD0->TRGMD,1)))

#define TSB_PMD1_MDEN_PWMEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDEN,0)))
#define TSB_PMD1_MDCR_PWMMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,0)))
#define TSB_PMD1_MDCR_PINT                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,3)))
#define TSB_PMD1_MDCR_DTYMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,4)))
#define TSB_PMD1_MDCR_SYNTMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,5)))
#define TSB_PMD1_MDCR_PWMCK                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,6)))
#define TSB_PMD1_MDCR_DTCREN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDCR,7)))
#define TSB_PMD1_CNTSTA_UPDWN                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->CNTSTA,0)))
#define TSB_PMD1_MODESEL_MDSEL0                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MODESEL,0)))
#define TSB_PMD1_MODESEL_MDSEL1                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MODESEL,1)))
#define TSB_PMD1_MODESEL_MDSEL2                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MODESEL,2)))
#define TSB_PMD1_MODESEL_MDSEL3                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MODESEL,3)))
#define TSB_PMD1_MODESEL_DCMPEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MODESEL,7)))
#define TSB_PMD1_MDOUT_UPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDOUT,8)))
#define TSB_PMD1_MDOUT_VPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDOUT,9)))
#define TSB_PMD1_MDOUT_WPWM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDOUT,10)))
#define TSB_PMD1_MDPOT_POLL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDPOT,2)))
#define TSB_PMD1_MDPOT_POLH                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->MDPOT,3)))
#define TSB_PMD1_EMGCR_EMGEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGCR,0)))
#define TSB_PMD1_EMGCR_EMGRS                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGCR,1)))
#define TSB_PMD1_EMGCR_INHEN                      (*((__O  uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGCR,5)))
#define TSB_PMD1_EMGSTA_EMGST                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGSTA,0)))
#define TSB_PMD1_EMGSTA_EMGI                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->EMGSTA,1)))
#define TSB_PMD1_OVVCR_OVVEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,0)))
#define TSB_PMD1_OVVCR_OVVRS                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,1)))
#define TSB_PMD1_OVVCR_OVVISEL                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,2)))
#define TSB_PMD1_OVVCR_ADIN0EN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,5)))
#define TSB_PMD1_OVVCR_ADIN1EN                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVCR,6)))
#define TSB_PMD1_OVVSTA_OVVST                     (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVSTA,0)))
#define TSB_PMD1_OVVSTA_OVVI                      (*((__I  uint32_t *)BITBAND_PERI(&TSB_PMD1->OVVSTA,1)))
#define TSB_PMD1_TRGCR_TRG0BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGCR,3)))
#define TSB_PMD1_TRGCR_TRG1BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGCR,7)))
#define TSB_PMD1_TRGCR_TRG2BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGCR,11)))
#define TSB_PMD1_TRGCR_TRG3BE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGCR,15)))
#define TSB_PMD1_TRGMD_EMGTGE                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGMD,0)))
#define TSB_PMD1_TRGMD_TRGOUT                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_PMD1->TRGMD,1)))


/* Encoder Input (ENC) */
#define TSB_EN0_TNCR_ENRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,6)))
#define TSB_EN0_TNCR_ZEN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,7)))
#define TSB_EN0_TNCR_ENCLR                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,10)))
#define TSB_EN0_TNCR_SFTCAP                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,11)))
#define TSB_EN0_TNCR_TRGCAPMD                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,12)))
#define TSB_EN0_TNCR_P3EN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,16)))
#define TSB_EN0_TNCR_SDTEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,21)))
#define TSB_EN0_TNCR_MCMPMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,24)))
#define TSB_EN0_TNCR_TOVMD                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,25)))
#define TSB_EN0_TNCR_CMPSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->TNCR,28)))
#define TSB_EN0_STS_INERR                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->STS,0)))
#define TSB_EN0_STS_PDERR                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->STS,1)))
#define TSB_EN0_STS_SKPDT                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->STS,2)))
#define TSB_EN0_STS_ZDET                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->STS,12)))
#define TSB_EN0_STS_UD                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->STS,13)))
#define TSB_EN0_STS_REVERR                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->STS,14)))
#define TSB_EN0_INPCR_SYNCSPLEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->INPCR,0)))
#define TSB_EN0_INPCR_SYNCSPLND                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->INPCR,1)))
#define TSB_EN0_INPCR_SYNCNCZEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->INPCR,2)))
#define TSB_EN0_INPCR_PDSTT                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN0->INPCR,6)))
#define TSB_EN0_INPCR_PDSTP                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN0->INPCR,7)))
#define TSB_EN0_INPMON_SPLMONA                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INPMON,0)))
#define TSB_EN0_INPMON_SPLMONB                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INPMON,1)))
#define TSB_EN0_INPMON_SPLMONZ                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INPMON,2)))
#define TSB_EN0_INPMON_DETMONA                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INPMON,4)))
#define TSB_EN0_INPMON_DETMONB                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INPMON,5)))
#define TSB_EN0_INPMON_DETMONZ                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INPMON,6)))
#define TSB_EN0_INTCR_TPLSIE                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->INTCR,0)))
#define TSB_EN0_INTCR_CAPIE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->INTCR,1)))
#define TSB_EN0_INTCR_ERRIN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->INTCR,2)))
#define TSB_EN0_INTCR_CMPIE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->INTCR,3)))
#define TSB_EN0_INTCR_RLDIE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->INTCR,4)))
#define TSB_EN0_INTCR_MCMPIE                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN0->INTCR,5)))
#define TSB_EN0_INTF_TPLSF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INTF,0)))
#define TSB_EN0_INTF_CAPF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INTF,1)))
#define TSB_EN0_INTF_ERRF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INTF,2)))
#define TSB_EN0_INTF_INTCPF                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INTF,3)))
#define TSB_EN0_INTF_RLDCPF                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INTF,4)))
#define TSB_EN0_INTF_MCMPF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN0->INTF,5)))

#define TSB_EN1_TNCR_ENRUN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,6)))
#define TSB_EN1_TNCR_ZEN                          (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,7)))
#define TSB_EN1_TNCR_ENCLR                        (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,10)))
#define TSB_EN1_TNCR_SFTCAP                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,11)))
#define TSB_EN1_TNCR_TRGCAPMD                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,12)))
#define TSB_EN1_TNCR_P3EN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,16)))
#define TSB_EN1_TNCR_SDTEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,21)))
#define TSB_EN1_TNCR_MCMPMD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,24)))
#define TSB_EN1_TNCR_TOVMD                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,25)))
#define TSB_EN1_TNCR_CMPSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->TNCR,28)))
#define TSB_EN1_STS_INERR                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->STS,0)))
#define TSB_EN1_STS_PDERR                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->STS,1)))
#define TSB_EN1_STS_SKPDT                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->STS,2)))
#define TSB_EN1_STS_ZDET                          (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->STS,12)))
#define TSB_EN1_STS_UD                            (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->STS,13)))
#define TSB_EN1_STS_REVERR                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->STS,14)))
#define TSB_EN1_INPCR_SYNCSPLEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->INPCR,0)))
#define TSB_EN1_INPCR_SYNCSPLND                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->INPCR,1)))
#define TSB_EN1_INPCR_SYNCNCZEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->INPCR,2)))
#define TSB_EN1_INPCR_PDSTT                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN1->INPCR,6)))
#define TSB_EN1_INPCR_PDSTP                       (*((__O  uint32_t *)BITBAND_PERI(&TSB_EN1->INPCR,7)))
#define TSB_EN1_INPMON_SPLMONA                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INPMON,0)))
#define TSB_EN1_INPMON_SPLMONB                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INPMON,1)))
#define TSB_EN1_INPMON_SPLMONZ                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INPMON,2)))
#define TSB_EN1_INPMON_DETMONA                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INPMON,4)))
#define TSB_EN1_INPMON_DETMONB                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INPMON,5)))
#define TSB_EN1_INPMON_DETMONZ                    (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INPMON,6)))
#define TSB_EN1_INTCR_TPLSIE                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->INTCR,0)))
#define TSB_EN1_INTCR_CAPIE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->INTCR,1)))
#define TSB_EN1_INTCR_ERRIN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->INTCR,2)))
#define TSB_EN1_INTCR_CMPIE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->INTCR,3)))
#define TSB_EN1_INTCR_RLDIE                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->INTCR,4)))
#define TSB_EN1_INTCR_MCMPIE                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_EN1->INTCR,5)))
#define TSB_EN1_INTF_TPLSF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INTF,0)))
#define TSB_EN1_INTF_CAPF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INTF,1)))
#define TSB_EN1_INTF_ERRF                         (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INTF,2)))
#define TSB_EN1_INTF_INTCPF                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INTF,3)))
#define TSB_EN1_INTF_RLDCPF                       (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INTF,4)))
#define TSB_EN1_INTF_MCMPF                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_EN1->INTF,5)))


/* Vector Engine (VE) */
#define TSB_VE0_EN_VEEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->EN,0)))
#define TSB_VE0_EN_VEIDLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->EN,1)))
#define TSB_VE0_ERRINTEN_VERREN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->ERRINTEN,0)))
#define TSB_VE0_ERRINTEN_INTTEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->ERRINTEN,2)))
#define TSB_VE0_SCHTASKRUN_VRSCH                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_VE0->SCHTASKRUN,0)))
#define TSB_VE0_MCTLF_LAVF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MCTLF,0)))
#define TSB_VE0_MCTLF_LAVFM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MCTLF,1)))
#define TSB_VE0_MCTLF_LVTF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MCTLF,2)))
#define TSB_VE0_MCTLF_PLSLF                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MCTLF,4)))
#define TSB_VE0_MCTLF_PLSLFM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MCTLF,5)))
#define TSB_VE0_MCTLF_PIDOVF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MCTLF,8)))
#define TSB_VE0_MCTLF_PIQOVF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MCTLF,9)))
#define TSB_VE0_MCTLF_VSOVF                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MCTLF,10)))
#define TSB_VE0_MCTLF_PWMOVF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MCTLF,11)))
#define TSB_VE0_MODE_PVIEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,0)))
#define TSB_VE0_MODE_ZIEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,1)))
#define TSB_VE0_MODE_VDCSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,4)))
#define TSB_VE0_MODE_CLPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,7)))
#define TSB_VE0_MODE_T5ECEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,10)))
#define TSB_VE0_MODE_NICEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,11)))
#define TSB_VE0_MODE_PWMBLEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,12)))
#define TSB_VE0_MODE_PWMFLEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,13)))
#define TSB_VE0_MODE_PMDDTCEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,14)))
#define TSB_VE0_MODE_IPDEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->MODE,15)))
#define TSB_VE0_FMODE_C2PEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->FMODE,0)))
#define TSB_VE0_FMODE_SPWMEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->FMODE,1)))
#define TSB_VE0_FMODE_IAPLMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->FMODE,5)))
#define TSB_VE0_FMODE_IBPLMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->FMODE,6)))
#define TSB_VE0_FMODE_ICPLMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->FMODE,7)))
#define TSB_VE0_FMODE_CRCEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->FMODE,8)))
#define TSB_VE0_FMODE_MREGDIS                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->FMODE,9)))
#define TSB_VE0_FMODE_PHCVDIS                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->FMODE,12)))
#define TSB_VE0_FMODE_SADCEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->FMODE,13)))
#define TSB_VE0_OUTCR_UPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->OUTCR,6)))
#define TSB_VE0_OUTCR_VPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->OUTCR,7)))
#define TSB_VE0_OUTCR_WPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->OUTCR,8)))
#define TSB_VE0_EMGRS_EMGRS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE0->EMGRS,0)))

#define TSB_VE1_EN_VEEN                           (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->EN,0)))
#define TSB_VE1_EN_VEIDLEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->EN,1)))
#define TSB_VE1_ERRINTEN_VERREN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->ERRINTEN,0)))
#define TSB_VE1_ERRINTEN_INTTEN                   (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->ERRINTEN,2)))
#define TSB_VE1_SCHTASKRUN_VRSCH                  (*((__I  uint32_t *)BITBAND_PERI(&TSB_VE1->SCHTASKRUN,0)))
#define TSB_VE1_MCTLF_LAVF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MCTLF,0)))
#define TSB_VE1_MCTLF_LAVFM                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MCTLF,1)))
#define TSB_VE1_MCTLF_LVTF                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MCTLF,2)))
#define TSB_VE1_MCTLF_PLSLF                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MCTLF,4)))
#define TSB_VE1_MCTLF_PLSLFM                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MCTLF,5)))
#define TSB_VE1_MCTLF_PIDOVF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MCTLF,8)))
#define TSB_VE1_MCTLF_PIQOVF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MCTLF,9)))
#define TSB_VE1_MCTLF_VSOVF                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MCTLF,10)))
#define TSB_VE1_MCTLF_PWMOVF                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MCTLF,11)))
#define TSB_VE1_MODE_PVIEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,0)))
#define TSB_VE1_MODE_ZIEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,1)))
#define TSB_VE1_MODE_VDCSEL                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,4)))
#define TSB_VE1_MODE_CLPEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,7)))
#define TSB_VE1_MODE_T5ECEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,10)))
#define TSB_VE1_MODE_NICEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,11)))
#define TSB_VE1_MODE_PWMBLEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,12)))
#define TSB_VE1_MODE_PWMFLEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,13)))
#define TSB_VE1_MODE_PMDDTCEN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,14)))
#define TSB_VE1_MODE_IPDEN                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->MODE,15)))
#define TSB_VE1_FMODE_C2PEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->FMODE,0)))
#define TSB_VE1_FMODE_SPWMEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->FMODE,1)))
#define TSB_VE1_FMODE_IAPLMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->FMODE,5)))
#define TSB_VE1_FMODE_IBPLMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->FMODE,6)))
#define TSB_VE1_FMODE_ICPLMD                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->FMODE,7)))
#define TSB_VE1_FMODE_CRCEN                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->FMODE,8)))
#define TSB_VE1_FMODE_MREGDIS                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->FMODE,9)))
#define TSB_VE1_FMODE_PHCVDIS                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->FMODE,12)))
#define TSB_VE1_FMODE_SADCEN                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->FMODE,13)))
#define TSB_VE1_OUTCR_UPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->OUTCR,6)))
#define TSB_VE1_OUTCR_VPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->OUTCR,7)))
#define TSB_VE1_OUTCR_WPWM                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->OUTCR,8)))
#define TSB_VE1_EMGRS_EMGRS                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_VE1->EMGRS,0)))


/* Analog-to-Digital Converter (AD) */
#define TSB_ADA_MOD0_ADSS                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADA->MOD0,0)))
#define TSB_ADA_MOD1_ADAS                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,0)))
#define TSB_ADA_MOD1_ADEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD1,7)))
#define TSB_ADA_MOD2_ADBFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADA->MOD2,0)))
#define TSB_ADA_MOD2_ADSFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADA->MOD2,1)))
#define TSB_ADA_CMPCR0_ADBIG0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR0,4)))
#define TSB_ADA_CMPCR0_CMP0EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR0,7)))
#define TSB_ADA_CMPCR1_ADBIG1                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR1,4)))
#define TSB_ADA_CMPCR1_CMP1EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->CMPCR1,7)))
#define TSB_ADA_PSEL0_PENS0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL0,7)))
#define TSB_ADA_PSEL1_PENS1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL1,7)))
#define TSB_ADA_PSEL2_PENS2                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL2,7)))
#define TSB_ADA_PSEL3_PENS3                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL3,7)))
#define TSB_ADA_PSEL4_PENS4                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL4,7)))
#define TSB_ADA_PSEL5_PENS5                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL5,7)))
#define TSB_ADA_PSEL6_PENS6                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL6,7)))
#define TSB_ADA_PSEL7_PENS7                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL7,7)))
#define TSB_ADA_PSEL8_PENS8                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL8,7)))
#define TSB_ADA_PSEL9_PENS9                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL9,7)))
#define TSB_ADA_PSEL10_PENS10                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL10,7)))
#define TSB_ADA_PSEL11_PENS11                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSEL11,7)))
#define TSB_ADA_PSET0_ENSP00                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET0,7)))
#define TSB_ADA_PSET0_ENSP01                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET0,15)))
#define TSB_ADA_PSET0_ENSP02                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET0,23)))
#define TSB_ADA_PSET0_ENSP03                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET0,31)))
#define TSB_ADA_PSET1_ENSP10                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET1,7)))
#define TSB_ADA_PSET1_ENSP11                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET1,15)))
#define TSB_ADA_PSET1_ENSP12                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET1,23)))
#define TSB_ADA_PSET1_ENSP13                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET1,31)))
#define TSB_ADA_PSET2_ENSP20                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET2,7)))
#define TSB_ADA_PSET2_ENSP21                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET2,15)))
#define TSB_ADA_PSET2_ENSP22                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET2,23)))
#define TSB_ADA_PSET2_ENSP23                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET2,31)))
#define TSB_ADA_PSET3_ENSP30                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET3,7)))
#define TSB_ADA_PSET3_ENSP31                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET3,15)))
#define TSB_ADA_PSET3_ENSP32                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET3,23)))
#define TSB_ADA_PSET3_ENSP33                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET3,31)))
#define TSB_ADA_PSET4_ENSP40                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET4,7)))
#define TSB_ADA_PSET4_ENSP41                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET4,15)))
#define TSB_ADA_PSET4_ENSP42                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET4,23)))
#define TSB_ADA_PSET4_ENSP43                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET4,31)))
#define TSB_ADA_PSET5_ENSP50                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET5,7)))
#define TSB_ADA_PSET5_ENSP51                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET5,15)))
#define TSB_ADA_PSET5_ENSP52                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET5,23)))
#define TSB_ADA_PSET5_ENSP53                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->PSET5,31)))
#define TSB_ADA_TSET03_ENST0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET03,7)))
#define TSB_ADA_TSET03_ENST1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET03,15)))
#define TSB_ADA_TSET03_ENST2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET03,23)))
#define TSB_ADA_TSET03_ENST3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET03,31)))
#define TSB_ADA_TSET47_ENST4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET47,7)))
#define TSB_ADA_TSET47_ENST5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET47,15)))
#define TSB_ADA_TSET47_ENST6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET47,23)))
#define TSB_ADA_TSET47_ENST7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET47,31)))
#define TSB_ADA_TSET811_ENST8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET811,7)))
#define TSB_ADA_TSET811_ENST9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET811,15)))
#define TSB_ADA_TSET811_ENST10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET811,23)))
#define TSB_ADA_TSET811_ENST11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->TSET811,31)))
#define TSB_ADA_SSET03_ENSS0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET03,7)))
#define TSB_ADA_SSET03_ENSS1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET03,15)))
#define TSB_ADA_SSET03_ENSS2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET03,23)))
#define TSB_ADA_SSET03_ENSS3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET03,31)))
#define TSB_ADA_SSET47_ENSS4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET47,7)))
#define TSB_ADA_SSET47_ENSS5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET47,15)))
#define TSB_ADA_SSET47_ENSS6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET47,23)))
#define TSB_ADA_SSET47_ENSS7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET47,31)))
#define TSB_ADA_SSET811_ENSS8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET811,7)))
#define TSB_ADA_SSET811_ENSS9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET811,15)))
#define TSB_ADA_SSET811_ENSS10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET811,23)))
#define TSB_ADA_SSET811_ENSS11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->SSET811,31)))
#define TSB_ADA_ASET03_ENSA0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET03,7)))
#define TSB_ADA_ASET03_ENSA1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET03,15)))
#define TSB_ADA_ASET03_ENSA2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET03,23)))
#define TSB_ADA_ASET03_ENSA3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET03,31)))
#define TSB_ADA_ASET47_ENSA4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET47,7)))
#define TSB_ADA_ASET47_ENSA5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET47,15)))
#define TSB_ADA_ASET47_ENSA6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET47,23)))
#define TSB_ADA_ASET47_ENSA7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET47,31)))
#define TSB_ADA_ASET811_ENSA8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET811,7)))
#define TSB_ADA_ASET811_ENSA9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET811,15)))
#define TSB_ADA_ASET811_ENSA10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET811,23)))
#define TSB_ADA_ASET811_ENSA11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->ASET811,31)))
#define TSB_ADA_MOD3_RCUT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD3,8)))
#define TSB_ADA_MOD3_BINMOD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD3,12)))
#define TSB_ADA_MOD3_PBSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADA->MOD3,14)))

#define TSB_ADB_MOD0_ADSS                         (*((__O  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD0,0)))
#define TSB_ADB_MOD1_ADAS                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,0)))
#define TSB_ADB_MOD1_ADEN                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD1,7)))
#define TSB_ADB_MOD2_ADBFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD2,0)))
#define TSB_ADB_MOD2_ADSFN                        (*((__I  uint32_t *)BITBAND_PERI(&TSB_ADB->MOD2,1)))
#define TSB_ADB_CMPCR0_ADBIG0                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR0,4)))
#define TSB_ADB_CMPCR0_CMP0EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR0,7)))
#define TSB_ADB_CMPCR1_ADBIG1                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR1,4)))
#define TSB_ADB_CMPCR1_CMP1EN                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->CMPCR1,7)))
#define TSB_ADB_PSEL0_PENS0                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL0,7)))
#define TSB_ADB_PSEL1_PENS1                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL1,7)))
#define TSB_ADB_PSEL2_PENS2                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL2,7)))
#define TSB_ADB_PSEL3_PENS3                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL3,7)))
#define TSB_ADB_PSEL4_PENS4                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL4,7)))
#define TSB_ADB_PSEL5_PENS5                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL5,7)))
#define TSB_ADB_PSEL6_PENS6                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL6,7)))
#define TSB_ADB_PSEL7_PENS7                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL7,7)))
#define TSB_ADB_PSEL8_PENS8                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL8,7)))
#define TSB_ADB_PSEL9_PENS9                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL9,7)))
#define TSB_ADB_PSEL10_PENS10                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL10,7)))
#define TSB_ADB_PSEL11_PENS11                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSEL11,7)))
#define TSB_ADB_PSET0_ENSP00                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET0,7)))
#define TSB_ADB_PSET0_ENSP01                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET0,15)))
#define TSB_ADB_PSET0_ENSP02                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET0,23)))
#define TSB_ADB_PSET0_ENSP03                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET0,31)))
#define TSB_ADB_PSET1_ENSP10                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET1,7)))
#define TSB_ADB_PSET1_ENSP11                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET1,15)))
#define TSB_ADB_PSET1_ENSP12                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET1,23)))
#define TSB_ADB_PSET1_ENSP13                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET1,31)))
#define TSB_ADB_PSET2_ENSP20                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET2,7)))
#define TSB_ADB_PSET2_ENSP21                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET2,15)))
#define TSB_ADB_PSET2_ENSP22                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET2,23)))
#define TSB_ADB_PSET2_ENSP23                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET2,31)))
#define TSB_ADB_PSET3_ENSP30                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET3,7)))
#define TSB_ADB_PSET3_ENSP31                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET3,15)))
#define TSB_ADB_PSET3_ENSP32                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET3,23)))
#define TSB_ADB_PSET3_ENSP33                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET3,31)))
#define TSB_ADB_PSET4_ENSP40                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET4,7)))
#define TSB_ADB_PSET4_ENSP41                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET4,15)))
#define TSB_ADB_PSET4_ENSP42                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET4,23)))
#define TSB_ADB_PSET4_ENSP43                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET4,31)))
#define TSB_ADB_PSET5_ENSP50                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET5,7)))
#define TSB_ADB_PSET5_ENSP51                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET5,15)))
#define TSB_ADB_PSET5_ENSP52                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET5,23)))
#define TSB_ADB_PSET5_ENSP53                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->PSET5,31)))
#define TSB_ADB_TSET03_ENST0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET03,7)))
#define TSB_ADB_TSET03_ENST1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET03,15)))
#define TSB_ADB_TSET03_ENST2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET03,23)))
#define TSB_ADB_TSET03_ENST3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET03,31)))
#define TSB_ADB_TSET47_ENST4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET47,7)))
#define TSB_ADB_TSET47_ENST5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET47,15)))
#define TSB_ADB_TSET47_ENST6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET47,23)))
#define TSB_ADB_TSET47_ENST7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET47,31)))
#define TSB_ADB_TSET811_ENST8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET811,7)))
#define TSB_ADB_TSET811_ENST9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET811,15)))
#define TSB_ADB_TSET811_ENST10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET811,23)))
#define TSB_ADB_TSET811_ENST11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->TSET811,31)))
#define TSB_ADB_SSET03_ENSS0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET03,7)))
#define TSB_ADB_SSET03_ENSS1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET03,15)))
#define TSB_ADB_SSET03_ENSS2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET03,23)))
#define TSB_ADB_SSET03_ENSS3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET03,31)))
#define TSB_ADB_SSET47_ENSS4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET47,7)))
#define TSB_ADB_SSET47_ENSS5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET47,15)))
#define TSB_ADB_SSET47_ENSS6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET47,23)))
#define TSB_ADB_SSET47_ENSS7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET47,31)))
#define TSB_ADB_SSET811_ENSS8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET811,7)))
#define TSB_ADB_SSET811_ENSS9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET811,15)))
#define TSB_ADB_SSET811_ENSS10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET811,23)))
#define TSB_ADB_SSET811_ENSS11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->SSET811,31)))
#define TSB_ADB_ASET03_ENSA0                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET03,7)))
#define TSB_ADB_ASET03_ENSA1                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET03,15)))
#define TSB_ADB_ASET03_ENSA2                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET03,23)))
#define TSB_ADB_ASET03_ENSA3                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET03,31)))
#define TSB_ADB_ASET47_ENSA4                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET47,7)))
#define TSB_ADB_ASET47_ENSA5                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET47,15)))
#define TSB_ADB_ASET47_ENSA6                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET47,23)))
#define TSB_ADB_ASET47_ENSA7                      (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET47,31)))
#define TSB_ADB_ASET811_ENSA8                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET811,7)))
#define TSB_ADB_ASET811_ENSA9                     (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET811,15)))
#define TSB_ADB_ASET811_ENSA10                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET811,23)))
#define TSB_ADB_ASET811_ENSA11                    (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->ASET811,31)))
#define TSB_ADB_MOD3_RCUT                         (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD3,8)))
#define TSB_ADB_MOD3_BINMOD                       (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD3,12)))
#define TSB_ADB_MOD3_PBSEL                        (*((__IO uint32_t *)BITBAND_PERI(&TSB_ADB->MOD3,14)))

/** @} */ /* End of group Device_Peripheral_registers */

#ifdef __cplusplus
}
#endif

#endif  /* __TMPM475_H__ */

/** @} */ /* End of group TMPM475 */
/** @} */ /* End of group TOSHIBA_TX04_MICROCONTROLLER */
