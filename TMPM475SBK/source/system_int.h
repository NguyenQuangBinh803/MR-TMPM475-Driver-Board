/**
 ****************************************************************************
 * @file	 system_int.h
 * @brief	 System Interrupt Definitions
 * @version	 V1.0
 *****************************************************************************
 */
#ifndef _SYSTEM_IT_H
#define _SYSTEM_IT_H


void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

void INT0_IRQHandler(void);
void INT1_IRQHandler(void);
void INT2_IRQHandler(void);
void INT3_IRQHandler(void);
void INT4_IRQHandler(void);
void INT5_IRQHandler(void);
void INTRX0_IRQHandler(void);
void INTTX0_IRQHandler(void);
void INTRX1_IRQHandler(void);
void INTTX1_IRQHandler(void);
void INTVCNA_IRQHandler(void);
void INTVCNB_IRQHandler(void);
void INTEMG0_IRQHandler(void);
void INTEMG1_IRQHandler(void);
void INTOVV0_IRQHandler(void);
void INTOVV1_IRQHandler(void);
void INTADAPDA_IRQHandler(void);
void INTADBPDA_IRQHandler(void);
void INTADAPDB_IRQHandler(void);
void INTADBPDB_IRQHandler(void);
void INTTB00_IRQHandler(void);
void INTTB01_IRQHandler(void);
void INTTB10_IRQHandler(void);
void INTTB11_IRQHandler(void);
void INTTB40_IRQHandler(void);
void INTTB41_IRQHandler(void);
void INTTB50_IRQHandler(void);
void INTTB51_IRQHandler(void);
void INTPMD0_IRQHandler(void);
void INTPMD1_IRQHandler(void);
void INTCAP00_IRQHandler(void);
void INTCAP01_IRQHandler(void);
void INTCAP10_IRQHandler(void);
void INTCAP11_IRQHandler(void);
void INTCAP40_IRQHandler(void);
void INTCAP41_IRQHandler(void);
void INTCAP50_IRQHandler(void);
void INTCAP51_IRQHandler(void);
void INT6_IRQHandler(void);
void INT7_IRQHandler(void);
void INTRX2_IRQHandler(void);
void INTTX2_IRQHandler(void);
void INTADACPA_IRQHandler(void);
void INTADBCPA_IRQHandler(void);
void INTADACPB_IRQHandler(void);
void INTADBCPB_IRQHandler(void);
void INTTB20_IRQHandler(void);
void INTTB21_IRQHandler(void);
void INTTB30_IRQHandler(void);
void INTTB31_IRQHandler(void);
void INTCAP20_IRQHandler(void);
void INTCAP21_IRQHandler(void);
void INTCAP30_IRQHandler(void);
void INTCAP31_IRQHandler(void);
void INTADASFT_IRQHandler(void);
void INTADBSFT_IRQHandler(void);
void INTADATMR_IRQHandler(void);
void INTADBTMR_IRQHandler(void);
void INT8_IRQHandler(void);
void INT9_IRQHandler(void);
void INTA_IRQHandler(void);
void INTB_IRQHandler(void);
void INTENC0_IRQHandler(void);
void INTENC1_IRQHandler(void);
void INTRX3_IRQHandler(void);
void INTTX3_IRQHandler(void);
void INTTB60_IRQHandler(void);
void INTTB61_IRQHandler(void);
void INTTB70_IRQHandler(void);
void INTTB71_IRQHandler(void);
void INTCAP60_IRQHandler(void);
void INTCAP61_IRQHandler(void);
void INTCAP70_IRQHandler(void);
void INTCAP71_IRQHandler(void);
void INTC_IRQHandler(void);
void INTD_IRQHandler(void);
void INTE_IRQHandler(void);
void INTF_IRQHandler(void);


#endif /* _SYSTEM_IT_H */


/******************************** END OF FILE *********************************/
