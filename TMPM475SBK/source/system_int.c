/**
 ****************************************************************************
 * @file	 system_int.c
 * @brief	 System Interrupt Functions
 * @version	 V1.0
 *****************************************************************************
 */
#include "ipdefine.h"
#include "D_Para.h"
#include "interrupt.h"
#include "B_User.h"
#include "dac_drv.h"

#include "system_int.h"

#include "nguyen_uart.h"

#define	LED_VE0_ON
#define	LED_VE0_OFF
#define	LED_VE1_ON			TSB_PA_DATA_PA1 = 1
#define	LED_VE1_OFF			TSB_PA_DATA_PA1 = 0


void NMI_Handler(void)
{}

void HardFault_Handler(void)
{}

void MemManage_Handler(void)
{}

void BusFault_Handler(void)
{}

void UsageFault_Handler(void)
{}

void SVC_Handler(void)
{}

void DebugMon_Handler(void)
{}

void PendSV_Handler(void)
{}

void SysTick_Handler(void)
{}

void INT0_IRQHandler(void)
{}

void INT1_IRQHandler(void)
{}

void INT2_IRQHandler(void)
{}

void INT3_IRQHandler(void)
{}

void INT4_IRQHandler(void)
{}

void INT5_IRQHandler(void)
{}

void INTRX0_IRQHandler(void)
{
	Uart0_Receive_Interrupt();
}

void INTTX0_IRQHandler(void)
{
    Uart0_Transmit_Interrupt();

}
void INTRX1_IRQHandler(void)
{}

void INTTX1_IRQHandler(void)
{
#if defined(__USE_DAC)
	DacWriteContinue(DAC_SIO_CH);
	__DSB();				/* for ARM processor errata 838469 */
#endif /* __USE_DAC */
}

void INTVCN0_IRQHandler(void)
{
#if defined(__CONTROL_MOTOR_CH0)
	LED_VE0_ON;
	INTVCN0();
	LED_VE0_OFF;
	__DSB();				/* for ARM processor errata 838469 */
#endif /* __CONTROL_MOTOR_CH0 */
}

void INTVCN1_IRQHandler(void)
{
#if defined(__CONTROL_MOTOR_CH1)
	LED_VE1_ON;
	INTVCN1();
	LED_VE1_OFF;
	__DSB();				/* for ARM processor errata 838469 */
#endif /* __CONTROL_MOTOR_CH1 */
}

void INTEMG0_IRQHandler(void)
{}

void INTEMG1_IRQHandler(void)
{}

void INTOVV0_IRQHandler(void)
{}

void INTOVV1_IRQHandler(void)
{}

void INTADAPDA_IRQHandler(void)
{}

void INTADBPDA_IRQHandler(void)
{}

void INTADAPDB_IRQHandler(void)
{}

void INTADBPDB_IRQHandler(void)
{}

void INTTB00_IRQHandler(void)
{
	INT_interval_4kHz();
	__DSB();				/* for ARM processor errata 838469 */
}

void INTTB01_IRQHandler(void)
{}

void INTTB10_IRQHandler(void)
{}

void INTTB11_IRQHandler(void)
{}

void INTTB40_IRQHandler(void)
{}

void INTTB41_IRQHandler(void)
{}

void INTTB50_IRQHandler(void)
{}

void INTTB51_IRQHandler(void)
{}

void INTPMD0_IRQHandler(void)
{}

void INTPMD1_IRQHandler(void)
{}

void INTCAP00_IRQHandler(void)
{}

void INTCAP01_IRQHandler(void)
{}

void INTCAP10_IRQHandler(void)
{}

void INTCAP11_IRQHandler(void)
{}

void INTCAP40_IRQHandler(void)
{}

void INTCAP41_IRQHandler(void)
{}

void INTCAP50_IRQHandler(void)
{}

void INTCAP51_IRQHandler(void)
{}

void INT6_IRQHandler(void)
{}

void INT7_IRQHandler(void)
{}

void INTRX2_IRQHandler(void)
{}

void INTTX2_IRQHandler(void)
{}

void INTADACPA_IRQHandler(void)
{}

void INTADBCPA_IRQHandler(void)
{}

void INTADACPB_IRQHandler(void)
{}

void INTADBCPB_IRQHandler(void)
{}

void INTTB20_IRQHandler(void)
{}

void INTTB21_IRQHandler(void)
{}

void INTTB30_IRQHandler(void)
{}

void INTTB31_IRQHandler(void)
{}

void INTCAP20_IRQHandler(void)
{}

void INTCAP21_IRQHandler(void)
{}

void INTCAP30_IRQHandler(void)
{}

void INTCAP31_IRQHandler(void)
{}

void INTADASFT_IRQHandler(void)
{}

void INTADBSFT_IRQHandler(void)
{}

void INTADATMR_IRQHandler(void)
{}

void INTADBTMR_IRQHandler(void)
{}

void INT8_IRQHandler(void)
{}

void INT9_IRQHandler(void)
{}

void INTA_IRQHandler(void)
{}

void INTB_IRQHandler(void)
{}

void INTENC00_IRQHandler(void)
{}

void INTENC01_IRQHandler(void)
{}

void INTENC0_IRQHandler(void)
{}

void INTENC1_IRQHandler(void)
{}

void INTRX3_IRQHandler(void)
{}

void INTTX3_IRQHandler(void)
{}

void INTTB60_IRQHandler(void)
{}

void INTTB61_IRQHandler(void)
{}

void INTTB70_IRQHandler(void)
{}

void INTTB71_IRQHandler(void)
{}

void INTCAP60_IRQHandler(void)
{}

void INTCAP61_IRQHandler(void)
{}

void INTCAP70_IRQHandler(void)
{}

void INTCAP71_IRQHandler(void)
{}

void INTC_IRQHandler(void)
{}

void INTD_IRQHandler(void)
{}

void INTE_IRQHandler(void)
{}

void INTF_IRQHandler(void)
{}

void INTVCT0_IRQHandler(void)
{}

void INTVCT1_IRQHandler(void)
{}

void INTSBI0_IRQHandler(void)
{}

void INTTB80_IRQHandler(void)
{}

void INTTB81_IRQHandler(void)
{}

void INTTB90_IRQHandler(void)
{}

void INTTB91_IRQHandler(void)
{}

void INTCAP80_IRQHandler(void)
{}

void INTCAP81_IRQHandler(void)
{}

void INTCAP90_IRQHandler(void)
{}

void INTCAP91_IRQHandler(void)
{}

void INTDMACATC_IRQHandler(void)
{}

void INTDMACAERR_IRQHandler(void)
{}

//void INTENC10_IRQHandler(void)
//{}

void INTENC11_IRQHandler(void)
{}

/*********************************** END OF FILE ******************************/
