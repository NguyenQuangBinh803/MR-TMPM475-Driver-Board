#ifndef __TMPM475_UART_INT_H
#define __TMPM475_UART_INT_H
#include "stdio.h"
#define     DEBUG_UART

void TestUart(void);
uint8_t Is_Uart_Ready_To_Send(void);
void Send_Data_To_PC(char * str);

void Uart0_initialization(void);
void Uart0_Transmit_Interrupt(void);
void Uart0_Receive_Interrupt(void);
void SendData(void);
unsigned char isReceiveEnoughData(void);
void ResetIdx(void);
#endif 
