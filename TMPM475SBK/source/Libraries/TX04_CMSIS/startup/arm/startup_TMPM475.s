;/**
; *******************************************************************************
; * @file    startup_TMPM475.s
; * @brief   CMSIS Cortex-M4 Core Device Startup File for the
; *          TOSHIBA 'TMPM475' Device Series
; * @version V2.0.2.5 (Tentative)
; * @date    2015/03/06
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; * 
; * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LISENCE AGREEMENT.
; * 
; * (C)Copyright TOSHIBA CORPORATION 2015 All rights reserved
; *******************************************************************************
; */

; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     INT0_IRQHandler           ; 0:	Interrupt pin (PH0/AINA0/INT0)
                DCD     INT1_IRQHandler           ; 1:	Interrupt pin (PH1/AINA1/INT1)
                DCD     INT2_IRQHandler           ; 2:	Interrupt pin (PH2/AINA2/INT2)
                DCD     INT3_IRQHandler           ; 3:	Interrupt pin (PA0/TB0IN/INT3)
                DCD     INT4_IRQHandler           ; 4:	Interrupt pin (PA2/TB1IN/INT4)
                DCD     INT5_IRQHandler           ; 5:	Interrupt pin (PE4/TB2IN/INT5)
                DCD     INTRX0_IRQHandler         ; 6:	Serial reception (channel 0)
                DCD     INTTX0_IRQHandler         ; 7:	Serial transmit (channel 0)
                DCD     INTRX1_IRQHandler         ; 8:	Serial reception (channel 1)
                DCD     INTTX1_IRQHandler         ; 9:	Serial transmit (channel 1)
                DCD     INTVCN0_IRQHandler        ; 10:	Vector Engine interrupt 0
                DCD     INTVCN1_IRQHandler        ; 11:	Vector Engine interrupt 1
                DCD     INTEMG0_IRQHandler        ; 12:	PMD0 EMG interrupt
                DCD     INTEMG1_IRQHandler        ; 13:	PMD1 EMG interrupt
                DCD     INTOVV0_IRQHandler        ; 14:	PMD0 OVV interrupt
                DCD     INTOVV1_IRQHandler        ; 15:	PMD1 OVV interrupt
                DCD     INTADAPDA_IRQHandler      ; 16:	ADC unit A conversion triggered by PMD0 is finished
                DCD     INTADBPDA_IRQHandler      ; 17:	ADC unit B conversion triggered by PMD0 is finished
                DCD     INTADAPDB_IRQHandler      ; 18:	ADC unit A conversion triggered by PMD1 is finished
                DCD     INTADBPDB_IRQHandler      ; 19:	ADC unit B conversion triggered by PMD1 is finished
                DCD     INTTB00_IRQHandler        ; 20:	16bit TMRB0 compare match detection 0 / Over flow
                DCD     INTTB01_IRQHandler        ; 21:	16bit TMRB0 compare match detection 1
                DCD     INTTB10_IRQHandler        ; 22:	16bit TMRB1 compare match detection 0 / Over flow
                DCD     INTTB11_IRQHandler        ; 23:	16bit TMRB1 compare match detection 1
                DCD     INTTB40_IRQHandler        ; 24:	16bit TMRB4 compare match detection 0 / Over flow
                DCD     INTTB41_IRQHandler        ; 25:	16bit TMRB4 compare match detection 1
                DCD     INTTB50_IRQHandler        ; 26:	16bit TMRB5 compare match detection 0 / Over flow
                DCD     INTTB51_IRQHandler        ; 27:	16bit TMRB5 compare match detection 1
                DCD     INTPMD0_IRQHandler        ; 28:	PMD0 PWM interrupt
                DCD     INTPMD1_IRQHandler        ; 29:	PMD1 PWM interrupt
                DCD     INTCAP00_IRQHandler       ; 30:	16bit TMRB0 input capture 0
                DCD     INTCAP01_IRQHandler       ; 31:	16bit TMRB0 input capture 1
                DCD     INTCAP10_IRQHandler       ; 32:	16bit TMRB1 input capture 0
                DCD     INTCAP11_IRQHandler       ; 33:	16bit TMRB1 input capture 1
                DCD     INTCAP40_IRQHandler       ; 34:	16bit TMRB4 input capture 0
                DCD     INTCAP41_IRQHandler       ; 35:	16bit TMRB4 input capture 1
                DCD     INTCAP50_IRQHandler       ; 36:	16bit TMRB5 input capture 0
                DCD     INTCAP51_IRQHandler       ; 37:	16bit TMRB5 input capture 1
                DCD     INT6_IRQHandler           ; 38:	Interrupt pin (PE6/TB3IN/INT6)
                DCD     INT7_IRQHandler           ; 39:	Interrupt pin (PE7/TB3OUT/INT7)
                DCD     INTRX2_IRQHandler         ; 40:	Serial reception (channel 2)
                DCD     INTTX2_IRQHandler         ; 41:	Serial transmit (channel 2)
                DCD     INTADACPA_IRQHandler      ; 42:	ADCA conversion monitoring function interrupt A
                DCD     INTADBCPA_IRQHandler      ; 43:	ADCB conversion monitoring function interrupt A
                DCD     INTADACPB_IRQHandler      ; 44:	ADCA conversion monitoring function interrupt B
                DCD     INTADBCPB_IRQHandler      ; 45:	ADCB conversion monitoring function interrupt B
                DCD     INTTB20_IRQHandler        ; 46:	16bit TMRB2 compare match detection 0 / Over flow
                DCD     INTTB21_IRQHandler        ; 47:	16bit TMRB2 compare match detection 1
                DCD     INTTB30_IRQHandler        ; 48:	16bit TMRB3 compare match detection 0 / Over flow
                DCD     INTTB31_IRQHandler        ; 49:	16bit TMRB3 compare match detection 1
                DCD     INTCAP20_IRQHandler       ; 50:	16bit TMRB2 input capture 0
                DCD     INTCAP21_IRQHandler       ; 51:	16bit TMRB2 input capture 1
                DCD     INTCAP30_IRQHandler       ; 52:	16bit TMRB3 input capture 0
                DCD     INTCAP31_IRQHandler       ; 53:	16bit TMRB3 input capture 1
                DCD     INTADASFT_IRQHandler      ; 54:	ADC unit A conversion started by software is finished
                DCD     INTADBSFT_IRQHandler      ; 55:	ADC unit B conversion started by software is finished
                DCD     INTADATMR_IRQHandler      ; 56:	ADC unit A conversion triggered by timer is finished
                DCD     INTADBTMR_IRQHandler      ; 57:	ADC unit B conversion triggered by timer is finished
                DCD     INT8_IRQHandler           ; 58:	Interrupt pin (PA7/TB4IN/INT8)
                DCD     INT9_IRQHandler           ; 59:	Interrupt pin (PD3/INT9)
                DCD     INTA_IRQHandler           ; 60:	Interrupt pin (PL1/CA_RX/INTA)
                DCD     INTB_IRQHandler           ; 61:	Interrupt pin (PL0/CA_TX/INTB)
                DCD     INTENC00_IRQHandler       ; 62:	Encoder 0 interrupt 0
                DCD     INTENC01_IRQHandler       ; 63:	Encoder 0 interrupt 1
                DCD     INTRX3_IRQHandler         ; 64:	Serial reception (channel 3)
                DCD     INTTX3_IRQHandler         ; 65:	Serial transmit (channel 3)
                DCD     INTTB60_IRQHandler        ; 66:	16bit TMRB6 compare match detection 0 / Over flow
                DCD     INTTB61_IRQHandler        ; 67:	16bit TMRB6 compare match detection 1
                DCD     INTTB70_IRQHandler        ; 68:	16bit TMRB7 compare match detection 0 / Over flow
                DCD     INTTB71_IRQHandler        ; 69:	16bit TMRB7 compare match detection 1
                DCD     INTCAP60_IRQHandler       ; 70:	16bit TMRB6 input capture 0
                DCD     INTCAP61_IRQHandler       ; 71:	16bit TMRB6 input capture 1
                DCD     INTCAP70_IRQHandler       ; 72:	16bit TMRB7 input capture 0
                DCD     INTCAP71_IRQHandler       ; 73:	16bit TMRB7 input capture 1
                DCD     INTC_IRQHandler           ; 74:	Interrupt pin (PJ6/AINB9/INTC)
                DCD     INTD_IRQHandler           ; 75:	Interrupt pin (PJ7/AINB10/INTD)
                DCD     INTE_IRQHandler           ; 76:	Interrupt pin (PK0/TRACEDATA3/INTE)
                DCD     INTF_IRQHandler           ; 77:	Interrupt pin (PK1/TRACEDATA2/INTF)
                DCD     INTVCT0_IRQHandler        ; 78:	Vector Engine 0 task is finished
                DCD     INTVCT1_IRQHandler        ; 79:	Vector Engine 1 task is finished
                DCD     INTSBI0_IRQHandler        ; 80:	Serial bus interface
                DCD     INTCANRX_IRQHandler       ; 81:	CAN transmit completion interrupt
                DCD     INTCANTX_IRQHandler       ; 82:	CAN receive completion interrupt
                DCD     INTCANGB_IRQHandler       ; 83:	CAN Global status interrupt
                DCD     INTTB80_IRQHandler        ; 84:	16bit TMRB8 compare match detection 0 / Over flow
                DCD     INTTB81_IRQHandler        ; 85:	16bit TMRB8 compare match detection 1
                DCD     INTTB90_IRQHandler        ; 86:	16bit TMRB9 compare match detection 0 / Over flow
                DCD     INTTB91_IRQHandler        ; 87:	16bit TMRB9 compare match detection 1
                DCD     INTCAP80_IRQHandler       ; 88:	16bit TMRB8 input capture 0
                DCD     INTCAP81_IRQHandler       ; 89:	16bit TMRB8 input capture 1
                DCD     INTCAP90_IRQHandler       ; 90:	16bit TMRB9 input capture 0
                DCD     INTCAP91_IRQHandler       ; 91:	16bit TMRB9 input capture 1
                DCD     INTDMACATC_IRQHandler     ; 92:	DMA end of transfer
                DCD     INTDMACAERR_IRQHandler    ; 93:	DMA transfer error
                DCD     INTENC10_IRQHandler       ; 94:	Encoder 1 interrupt 0
                DCD     INTENC11_IRQHandler       ; 95:	Encoder 1 interrupt 1



                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  INT0_IRQHandler           [WEAK]
                EXPORT  INT1_IRQHandler           [WEAK]
                EXPORT  INT2_IRQHandler           [WEAK]
                EXPORT  INT3_IRQHandler           [WEAK]
                EXPORT  INT4_IRQHandler           [WEAK]
                EXPORT  INT5_IRQHandler           [WEAK]
                EXPORT  INTRX0_IRQHandler         [WEAK]
                EXPORT  INTTX0_IRQHandler         [WEAK]
                EXPORT  INTRX1_IRQHandler         [WEAK]
                EXPORT  INTTX1_IRQHandler         [WEAK]
                EXPORT  INTVCN0_IRQHandler        [WEAK]
                EXPORT  INTVCN1_IRQHandler        [WEAK]
                EXPORT  INTEMG0_IRQHandler        [WEAK]
                EXPORT  INTEMG1_IRQHandler        [WEAK]
                EXPORT  INTOVV0_IRQHandler        [WEAK]
                EXPORT  INTOVV1_IRQHandler        [WEAK]
                EXPORT  INTADAPDA_IRQHandler      [WEAK]
                EXPORT  INTADBPDA_IRQHandler      [WEAK]
                EXPORT  INTADAPDB_IRQHandler      [WEAK]
                EXPORT  INTADBPDB_IRQHandler      [WEAK]
                EXPORT  INTTB00_IRQHandler        [WEAK]
                EXPORT  INTTB01_IRQHandler        [WEAK]
                EXPORT  INTTB10_IRQHandler        [WEAK]
                EXPORT  INTTB11_IRQHandler        [WEAK]
                EXPORT  INTTB40_IRQHandler        [WEAK]
                EXPORT  INTTB41_IRQHandler        [WEAK]
                EXPORT  INTTB50_IRQHandler        [WEAK]
                EXPORT  INTTB51_IRQHandler        [WEAK]
                EXPORT  INTPMD0_IRQHandler        [WEAK]
                EXPORT  INTPMD1_IRQHandler        [WEAK]
                EXPORT  INTCAP00_IRQHandler       [WEAK]
                EXPORT  INTCAP01_IRQHandler       [WEAK]
                EXPORT  INTCAP10_IRQHandler       [WEAK]
                EXPORT  INTCAP11_IRQHandler       [WEAK]
                EXPORT  INTCAP40_IRQHandler       [WEAK]
                EXPORT  INTCAP41_IRQHandler       [WEAK]
                EXPORT  INTCAP50_IRQHandler       [WEAK]
                EXPORT  INTCAP51_IRQHandler       [WEAK]
                EXPORT  INT6_IRQHandler           [WEAK]
                EXPORT  INT7_IRQHandler           [WEAK]
                EXPORT  INTRX2_IRQHandler         [WEAK]
                EXPORT  INTTX2_IRQHandler         [WEAK]
                EXPORT  INTADACPA_IRQHandler      [WEAK]
                EXPORT  INTADBCPA_IRQHandler      [WEAK]
                EXPORT  INTADACPB_IRQHandler      [WEAK]
                EXPORT  INTADBCPB_IRQHandler      [WEAK]
                EXPORT  INTTB20_IRQHandler        [WEAK]
                EXPORT  INTTB21_IRQHandler        [WEAK]
                EXPORT  INTTB30_IRQHandler        [WEAK]
                EXPORT  INTTB31_IRQHandler        [WEAK]
                EXPORT  INTCAP20_IRQHandler       [WEAK]
                EXPORT  INTCAP21_IRQHandler       [WEAK]
                EXPORT  INTCAP30_IRQHandler       [WEAK]
                EXPORT  INTCAP31_IRQHandler       [WEAK]
                EXPORT  INTADASFT_IRQHandler      [WEAK]
                EXPORT  INTADBSFT_IRQHandler      [WEAK]
                EXPORT  INTADATMR_IRQHandler      [WEAK]
                EXPORT  INTADBTMR_IRQHandler      [WEAK]
                EXPORT  INT8_IRQHandler           [WEAK]
                EXPORT  INT9_IRQHandler           [WEAK]
                EXPORT  INTA_IRQHandler           [WEAK]
                EXPORT  INTB_IRQHandler           [WEAK]
                EXPORT  INTENC00_IRQHandler       [WEAK]
                EXPORT  INTENC01_IRQHandler       [WEAK]
                EXPORT  INTRX3_IRQHandler         [WEAK]
                EXPORT  INTTX3_IRQHandler         [WEAK]
                EXPORT  INTTB60_IRQHandler        [WEAK]
                EXPORT  INTTB61_IRQHandler        [WEAK]
                EXPORT  INTTB70_IRQHandler        [WEAK]
                EXPORT  INTTB71_IRQHandler        [WEAK]
                EXPORT  INTCAP60_IRQHandler       [WEAK]
                EXPORT  INTCAP61_IRQHandler       [WEAK]
                EXPORT  INTCAP70_IRQHandler       [WEAK]
                EXPORT  INTCAP71_IRQHandler       [WEAK]
                EXPORT  INTC_IRQHandler           [WEAK]
                EXPORT  INTD_IRQHandler           [WEAK]
                EXPORT  INTE_IRQHandler           [WEAK]
                EXPORT  INTF_IRQHandler           [WEAK]
                EXPORT  INTVCT0_IRQHandler        [WEAK]
                EXPORT  INTVCT1_IRQHandler        [WEAK]
                EXPORT  INTSBI0_IRQHandler        [WEAK]
                EXPORT  INTCANRX_IRQHandler       [WEAK]
                EXPORT  INTCANTX_IRQHandler       [WEAK]
                EXPORT  INTCANGB_IRQHandler       [WEAK]
                EXPORT  INTTB80_IRQHandler        [WEAK]
                EXPORT  INTTB81_IRQHandler        [WEAK]
                EXPORT  INTTB90_IRQHandler        [WEAK]
                EXPORT  INTTB91_IRQHandler        [WEAK]
                EXPORT  INTCAP80_IRQHandler       [WEAK]
                EXPORT  INTCAP81_IRQHandler       [WEAK]
                EXPORT  INTCAP90_IRQHandler       [WEAK]
                EXPORT  INTCAP91_IRQHandler       [WEAK]
                EXPORT  INTDMACATC_IRQHandler     [WEAK]
                EXPORT  INTDMACAERR_IRQHandler    [WEAK]
                EXPORT  INTENC10_IRQHandler       [WEAK]
                EXPORT  INTENC11_IRQHandler       [WEAK]

INT0_IRQHandler
INT1_IRQHandler
INT2_IRQHandler
INT3_IRQHandler
INT4_IRQHandler
INT5_IRQHandler
INTRX0_IRQHandler
INTTX0_IRQHandler
INTRX1_IRQHandler
INTTX1_IRQHandler
INTVCN0_IRQHandler
INTVCN1_IRQHandler
INTEMG0_IRQHandler
INTEMG1_IRQHandler
INTOVV0_IRQHandler
INTOVV1_IRQHandler
INTADAPDA_IRQHandler
INTADBPDA_IRQHandler
INTADAPDB_IRQHandler
INTADBPDB_IRQHandler
INTTB00_IRQHandler
INTTB01_IRQHandler
INTTB10_IRQHandler
INTTB11_IRQHandler
INTTB40_IRQHandler
INTTB41_IRQHandler
INTTB50_IRQHandler
INTTB51_IRQHandler
INTPMD0_IRQHandler
INTPMD1_IRQHandler
INTCAP00_IRQHandler
INTCAP01_IRQHandler
INTCAP10_IRQHandler
INTCAP11_IRQHandler
INTCAP40_IRQHandler
INTCAP41_IRQHandler
INTCAP50_IRQHandler
INTCAP51_IRQHandler
INT6_IRQHandler
INT7_IRQHandler
INTRX2_IRQHandler
INTTX2_IRQHandler
INTADACPA_IRQHandler
INTADBCPA_IRQHandler
INTADACPB_IRQHandler
INTADBCPB_IRQHandler
INTTB20_IRQHandler
INTTB21_IRQHandler
INTTB30_IRQHandler
INTTB31_IRQHandler
INTCAP20_IRQHandler
INTCAP21_IRQHandler
INTCAP30_IRQHandler
INTCAP31_IRQHandler
INTADASFT_IRQHandler
INTADBSFT_IRQHandler
INTADATMR_IRQHandler
INTADBTMR_IRQHandler
INT8_IRQHandler
INT9_IRQHandler
INTA_IRQHandler
INTB_IRQHandler
INTENC00_IRQHandler
INTENC01_IRQHandler
INTRX3_IRQHandler
INTTX3_IRQHandler
INTTB60_IRQHandler
INTTB61_IRQHandler
INTTB70_IRQHandler
INTTB71_IRQHandler
INTCAP60_IRQHandler
INTCAP61_IRQHandler
INTCAP70_IRQHandler
INTCAP71_IRQHandler
INTC_IRQHandler
INTD_IRQHandler
INTE_IRQHandler
INTF_IRQHandler
INTVCT0_IRQHandler
INTVCT1_IRQHandler
INTSBI0_IRQHandler
INTCANRX_IRQHandler
INTCANTX_IRQHandler
INTCANGB_IRQHandler
INTTB80_IRQHandler
INTTB81_IRQHandler
INTTB90_IRQHandler
INTTB91_IRQHandler
INTCAP80_IRQHandler
INTCAP81_IRQHandler
INTCAP90_IRQHandler
INTCAP91_IRQHandler
INTDMACATC_IRQHandler
INTDMACAERR_IRQHandler
INTENC10_IRQHandler
INTENC11_IRQHandler

                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END

