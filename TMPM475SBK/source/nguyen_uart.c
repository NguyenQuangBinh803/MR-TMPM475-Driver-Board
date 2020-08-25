
#include "tmpm475_uart.h"
#include "tmpm475_gpio.h"
#include "nguyen_uart.h"
#define TX_BUFFER_SIZE  100
#define BufSize (sizeof(TxBuffer) / sizeof(*(TxBuffer)))

uint8_t TxBuffer[TX_BUFFER_SIZE];
uint8_t RxBuffer[BufSize] = { 0U };

const uint8_t NumToBeTx = BufSize - 1U;

uint8_t TxCounter = 0U;
uint8_t RxCounter = 0U;


UART_InitTypeDef myUART;
GPIO_InitTypeDef uartPin;

void ResetIdx(void);

void TestUart(void){
    while (1) {
       
      SendData();
      while (isReceiveEnoughData()) {
            /* Do nothing */
      } 
#ifdef DEBUG
     printf("%s\n", RxBuffer1);
     printf("%s\n", RxBuffer);
#endif
        ResetIdx();
    }
}


void Uart0_initialization(void){
	
	/* Initialize system */

    //SIO_Configuration(UART0);

    myUART.BaudRate = (uint32_t)115200;
    myUART.DataBits = UART_DATA_BITS_8;
    myUART.StopBits = UART_STOP_BITS_1;
    myUART.Parity = UART_NO_PARITY;
    myUART.Mode =  UART_ENABLE_TX|UART_ENABLE_RX;
    myUART.FlowCtrl = UART_NONE_FLOW_CTRL;

    UART_Enable(UART0);
    UART_Init(UART0, &myUART);

		
    uartPin.IOMode = GPIO_OUTPUT_MODE;
    uartPin.OpenDrain = GPIO_OPEN_DRAIN_NONE;
    uartPin.PullUp = GPIO_PULLUP_ENABLE;
    uartPin.PullDown = GPIO_PULLDOWN_NONE;

    GPIO_Init(GPIO_PE, GPIO_BIT_0, &uartPin);

    uartPin.IOMode = GPIO_INPUT_MODE;

    GPIO_Init(GPIO_PE, GPIO_BIT_1, &uartPin);
    GPIO_EnableFuncReg(GPIO_PE,GPIO_FUNC_REG_1,GPIO_BIT_0);
    GPIO_EnableFuncReg(GPIO_PE,GPIO_FUNC_REG_1,GPIO_BIT_1);

    UART_RxFIFOByteSel(UART0,UART_RXFIFO_RXFLEVEL);

    UART_TxFIFOINTCtrl(UART0,ENABLE);
    UART_RxFIFOINTCtrl(UART0,ENABLE);

    UART_TRxAutoDisable(UART0,UART_RXTXCNT_AUTODISABLE);

    UART_FIFOConfig(UART0,ENABLE); 

    UART_RxFIFOFillLevel(UART0,UART_RXFIFO4B_FLEVLE_4_2B);

    UART_RxFIFOINTSel(UART0,UART_RFIS_REACH_EXCEED_FLEVEL);

    UART_RxFIFOClear(UART0);

    UART_TxFIFOFillLevel(UART0,UART_TXFIFO4B_FLEVLE_0_0B);

    UART_TxFIFOINTSel(UART0,UART_TFIS_REACH_NOREACH_FLEVEL);

    UART_TxFIFOClear(UART0); 
    NVIC_EnableIRQ(INTTX0_IRQn);
		
    NVIC_EnableIRQ(INTRX0_IRQn);
}


void Uart0_Transmit_Interrupt(void){
	
	volatile UART_Err err;

    if (TxBuffer[TxCounter] != 0 && TxCounter < TX_BUFFER_SIZE) {
        UART_SetTxData(UART0, TxBuffer[TxCounter++]);
    } else {
        err = UART_GetErrState(UART0);
    }
}

void Uart0_Receive_Interrupt(void){
		volatile UART_Err err;

    err = UART_GetErrState(UART0);
    if (UART_NO_ERR == err) {
        RxBuffer[RxCounter++] = (uint8_t) UART_GetRxData(UART0);
    }
}

unsigned char isReceiveEnoughData(void){
	if(RxCounter < NumToBeTx)
		return 1;
	else 
		return 0;
}

uint8_t Is_Uart_Ready_To_Send(void){
    return (TxBuffer[TxCounter] == 0);
}

void Send_Data_To_PC(char * str){
    if(Is_Uart_Ready_To_Send()){
        uint8_t index = 0;
        while(str[index] != 0){
            TxBuffer[index] = str[index];
            index ++;
        }
        TxBuffer[index] = 0;
        TxCounter = 0;
        SendData();
    }
}

void SendData(void){
    
	UART_SetTxData(UART0, (uint32_t) (TxBuffer[TxCounter++]));
}



void ResetIdx(void)
{
    uint8_t i = 0U;

    for (i = 0U; i <= RxCounter; i++) {
        RxBuffer[i] = 0U;
    }
        
    TxCounter = 0U;
    RxCounter = 0U;
}
