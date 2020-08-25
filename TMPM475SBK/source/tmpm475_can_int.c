/**
 *******************************************************************************
 * @file    tmpm369_can_int.c
 * @brief   All interrupt request functions definition of CAN
 *          for the TOSHIBA 'TMPM369' Device Series 
 * @version V0.101
 * @date    2014/05/20
 * 
 * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LICENSE AGREEMENT.
 * 
 * (C)Copyright TOSHIBA ELECTRONIC DEVICES & STORAGE CORPORATION 2017 All rights reserved
 *******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"

#include "tmpm475_can_int.h"
#include "tmpm475_uart.h"
#include "tmpm475_gpio.h"

#include "tmpm475_can.h"
#include "nguyen_uart.h"
#include "nguyen_motor_app.h"

/* Const define --------------------------------------------------------------------*/
#define MSG_ID                      (0x00000001U)
#define BAUDRATE_PRESCALER          (0x00000003U)

void CAN_Clock_Enable(void);
void CAN_PortInit(void);
void nENCAN_Pin_Configuration(void);
void Can_Update_Payload_Buffer(void);
void Command_Parsing(void);
void Send_Command_Back(void);

uint8_t fIntADC = 1U;
uint8_t fRcvCAN = 0U;
uint8_t fTranCAN = 0U;



CAN_MsgTypeDef canMessageTransmit = { 0U };
CAN_MsgTypeDef canMessageReceive = { 0U };

CAN_PayloadDef canPayloadProcessingBuffer = {0U};

#ifdef DEBUG_UART
void Uart_Display_State(void);

#endif

void TestCan(void){
    uint32_t counter  = 0;
    while (1) {
//        counter = (counter + 1) % 3000000;
//        if(counter == 0) fIntADC = 1;
        
        if (fIntADC == 1U) {
             fIntADC = 0U;
            //adc_value = adc_value + 1; //ADC_GetConvertResult(TSB_ADB,ADC_REG_00);
            canMessageTransmit.MsgData[0] = 0x11; //(uint8_t) adc_value.Bit.ADResult;
            canMessageTransmit.MsgData[1] = 0x22; //(uint8_t) (adc_value.Bit.ADResult >> 8U);
            canMessageTransmit.MsgData[2] = 0x11; //(uint8_t) adc_value.Bit.ADResult;
            canMessageTransmit.MsgData[3] = 0x22; //(uint8_t) (adc_value.Bit.ADResult >> 8U);
            canMessageTransmit.MsgData[4] = 0x11; //(uint8_t) adc_value.Bit.ADResult;
            canMessageTransmit.MsgData[5] = 0x22; //(uint8_t) (adc_value.Bit.ADResult >> 8U);
            canMessageTransmit.MsgData[6] = 0x11; //(uint8_t) adc_value.Bit.ADResult;
            canMessageTransmit.MsgData[7] =  canMessageTransmit.MsgData[7] + 1; //(uint8_t) (adc_value.Bit.ADResult >> 8U);
            
            
            CAN_SetMbxMsg(TRANSMIT_MAILBOX, &canMessageTransmit);   /* Put the ADC result into mailbox0 */
			CAN_SetTxReq(TRANSMIT_MAILBOX, ENABLE);    /* Start to send */
        } else {
            /* Do nothing */
        }

        if (fRcvCAN == 1U) {
             fRcvCAN = 0U;
        }
    }
}


void CAN_Clock_Enable(void){
    TSB_CG->CKSTP = 0x00;
}
void CAN_Initialization(void){
    
    
    CAN_GlobalState globalstate;
    CAN_INTFactor intmask;
	
    CAN_BitTimingTypeDef bittiming = { 
			BAUDRATE_PRESCALER, 
			CAN_TIMING_TSEG1_6TQ, 
			CAN_TIMING_TSEG2_3TQ, 
			CAN_SINGLE_SAMPLING,
            CAN_TIMING_SJW_1TQ
    };
    
    CAN_Clock_Enable();
    nENCAN_Pin_Configuration();
    CAN_PortInit();
	CAN_ConfigBitTiming(&bittiming);
	
 	
    CAN_SetMbxDirection(TRANSMIT_MAILBOX, CAN_MBX_TX); /* mailbox0: Tx */
    /* CAN Tx mailbox0 setting */
    canMessageTransmit.MsgID = MSG_ID;
    canMessageTransmit.MsgDataLen = 8U;      /* data length: 8 byte */
    //msgtx.MsgFormat = CAN_EXT_FORMAT;  
    
    CAN_SetMbxMsg(TRANSMIT_MAILBOX, &canMessageTransmit);
		
		
    /* CAN Rx mailbox10 setting */
    canMessageReceive.MsgID = canMessageTransmit.MsgID;  /* ID of mailbox10 = ID of mailbox0 */
    CAN_SetMbxMsg(RECEIVE_MAILBOX, &canMessageReceive);
    CAN_SetMbxDirection(RECEIVE_MAILBOX, CAN_MBX_RX);        /* mailbox10: Rx */

    
	globalstate.All = 0U;
	
    /* Enter suspend mode */
    
    CAN_SetMode(CAN_SUSPEND_MODE);
    while (globalstate.Bit.SuspendModeAck == 0) {
        globalstate = CAN_GetGlobalState();
    }

//    /* Set test loop back mode */
//    CAN_SetTestMode(CAN_TEST_LOOP_BACK_MODE, ENABLE);
	
    CAN_SetMode(CAN_NORMAL_MODE);
    while (globalstate.Bit.SuspendModeAck == 1U) {
        globalstate = CAN_GetGlobalState();
    }
		
	CAN_SetTxOrder(CAN_TX_ORDER_MBX_NUM);       /* Tx order: by mailbox number */  
		
	intmask.MbxBit.Mbx1 = 1U;
    CAN_SetINTMask(CAN_INT_MBX_MASK, &intmask);
	CAN_EnableMbx(TRANSMIT_MAILBOX);  
		
	NVIC_EnableIRQ(INTCANTX_IRQn); 
		

    /* Enable mailbox10 Rx interrupt */
    intmask.MbxBit.Mbx10 = 1U;
    CAN_SetINTMask(CAN_INT_MBX_MASK, &intmask);
	CAN_EnableMbx(RECEIVE_MAILBOX);   		
    
    NVIC_EnableIRQ(INTCANRX_IRQn); 		
}

void nENCAN_Pin_Configuration(void){
	GPIO_InitTypeDef nENCanPin;
	
	nENCanPin.IOMode = GPIO_OUTPUT_MODE;
	nENCanPin.OpenDrain = GPIO_OPEN_DRAIN_DISABLE;
	nENCanPin.PullUp = GPIO_PULLUP_DISABLE;
	nENCanPin.PullDown = GPIO_PULLDOWN_DISABLE;
	
	GPIO_Init(GPIO_PD, GPIO_BIT_3, &nENCanPin);
	
	GPIO_WriteDataBit(GPIO_PD, GPIO_BIT_3, GPIO_BIT_VALUE_0);
}
/**
  * @brief  CAN port initialization
  * @param  None.
  * @retval None.
  */
void CAN_PortInit(void)
{

    GPIO_SetOutput(GPIO_PL, GPIO_BIT_0);        /* Set TX pin as output */
    GPIO_SetInput(GPIO_PL, GPIO_BIT_1); /* Set RX pin as input */
    GPIO_EnableFuncReg(GPIO_PL, GPIO_FUNC_REG_1, (uint8_t) (GPIO_BIT_0));  /* Enable TX and RX pin functions */
	
    GPIO_EnableFuncReg(GPIO_PL, GPIO_FUNC_REG_1, (uint8_t) (GPIO_BIT_1));  /* Enable TX and RX pin functions */
    GPIO_SetOpenDrain(GPIO_PL, GPIO_BIT_0, DISABLE);    /* Set TX pin as CMOS output */
    GPIO_SetPullUp(GPIO_PL, (uint8_t) (GPIO_BIT_0 | GPIO_BIT_1), DISABLE);      /* Disable pull-ups for CAN pins */
}
/**
  * @brief  CAN mailbox Rx interrupt.
  * @param  None
  * @retval None
  */
void INTCANRX_IRQHandler(void)
{
    CAN_MbxState mbxstate = { 0U };

    mbxstate = CAN_GetMbxTRxState(CAN_STATE_ID_RX_ACK); /* Read Rx state */
    if (mbxstate.Bit.Mbx10 == 1U) {     /* If mailbox10 has received a message */
          fRcvCAN=1U;        
    } else {
        /* Do nothing */
    }
    CAN_ClearMbxTRxState(CAN_STATE_ID_RX_ACK);  /* Clear the Rx state */
    CAN_ClearINTFlag(CAN_INT_TYPE_RX);  /* Clear the Rx interrupt flag */
}

/**
  * @brief  CAN mailbox Rx interrupt.
  * @param  None
  * @retval None
  */
void INTCANTX_IRQHandler(void)
{
    CAN_MbxState mbxstate = { 0U };

    mbxstate = CAN_GetMbxTRxState(CAN_STATE_ID_TX_ACK); /* Read Tx state */
    if(mbxstate.Bit.Mbx1 == 1U){
        fTranCAN=1U;
    }
    CAN_ClearMbxTRxState(CAN_STATE_ID_TX_ACK);		
    CAN_ClearINTFlag(CAN_INT_TYPE_TX);  /* Clear the Tx interrupt flag */
}
void INTCANGB_IRQHandler(void)
{
    
    CAN_ClearINTFlag(CAN_INT_TYPE_GLOBAL);  /* Clear the Rx interrupt flag */
}
/**
  * @brief  ADC interrupt.
  * @param  None
  * @retval None
  */
void INTADB_IRQHandler(void)
{
    fIntADC = 1U;
}



void CAN_Data_Processing(void){
    if (fRcvCAN == 1U) {
        fRcvCAN = 0U;
        CAN_GetMbxMsg(RECEIVE_MAILBOX, &canMessageReceive);     /* Read mailbox10 */
        Can_Update_Payload_Buffer();
        Send_Command_Back();
        Command_Parsing();
#ifdef     DEBUG_UART
      Uart_Display_State();  
#endif
    }
}

void Can_Update_Payload_Buffer(void){
    canPayloadProcessingBuffer.Bytes.slave_number = canMessageReceive.MsgData[0]; 
    canPayloadProcessingBuffer.Bytes.function_code = canMessageReceive.MsgData[1]; 
    canPayloadProcessingBuffer.Bytes.register_address_high = canMessageReceive.MsgData[2]; 
    canPayloadProcessingBuffer.Bytes.register_address_low = canMessageReceive.MsgData[3]; 
    canPayloadProcessingBuffer.Bytes.high_1 = canMessageReceive.MsgData[4]; 
    canPayloadProcessingBuffer.Bytes.low_1 = canMessageReceive.MsgData[5]; 
    canPayloadProcessingBuffer.Bytes.high_2 = canMessageReceive.MsgData[6]; 
    canPayloadProcessingBuffer.Bytes.low_2 = canMessageReceive.MsgData[7];
   
}
void Send_Command_Back(void){
    if(canMessageReceive.MsgData[0] == 0x00 && canMessageReceive.MsgData[1] == RECEIVE_COMMAND){
        
        canMessageTransmit.MsgData[0] = canMessageReceive.MsgData[0]; 
        canMessageTransmit.MsgData[1] = RETURN_COMMAND; 
        canMessageTransmit.MsgData[2] = canMessageReceive.MsgData[2]; 
        canMessageTransmit.MsgData[3] = canMessageReceive.MsgData[3]; 
        canMessageTransmit.MsgData[4] = canMessageReceive.MsgData[4]; 
        canMessageTransmit.MsgData[5] = canMessageReceive.MsgData[5]; 
        canMessageTransmit.MsgData[6] = canMessageReceive.MsgData[6]; 
        canMessageTransmit.MsgData[7] = canMessageReceive.MsgData[7]; 

        CAN_SetMbxMsg(TRANSMIT_MAILBOX, &canMessageTransmit);   /* Put the return command into mailbox0 */
        CAN_SetTxReq(TRANSMIT_MAILBOX, ENABLE);    /* Start to send */
    }
}


void Command_Parsing(void){
    if(canPayloadProcessingBuffer.Half_words.slave_function_code == (int16_t)RECEIVE_COMMAND){
        switch(canPayloadProcessingBuffer.Half_words.register_address){
            case MOTOR_ACTION:
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)RELEASE_MOTOR){
                    Set_Motor_Enable_Mode(RELEASE_MOTOR);
                }
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)ENABLE_MOTOR){
                    Set_Motor_Enable_Mode(ENABLE_MOTOR);
                }
                break;
            case WORKING_MODE:
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)SPEED_MODE){
                    Set_Motor_Mode(SPEED_MODE);
                }
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)POSITION_MODE){
                    Set_Motor_Mode(POSITION_MODE);
                }
                break;
            case POSITION_OPERATION:
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)ABSOLUTE_POSITION_MODE){
                    Set_Position_Mode(ABSOLUTE_POSITION_MODE);
                }
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)RELATIVE_POSITION_MODE){
                    Set_Position_Mode(RELATIVE_POSITION_MODE);
                }
            break;
            case SET_DISTANCE_FOR_POSITION_MODE:
                Set_Distance_For_Position_Mode(canPayloadProcessingBuffer.Words.payload);
                break;
            case SET_MAX_SPEED_FOR_POSITION_MODE:
                Set_Max_Speed_For_Position_Mode(canPayloadProcessingBuffer.Words.payload);
            break;
            case SET_TARGET_SPEED:
                Set_Target_Speed(canPayloadProcessingBuffer.Words.payload);
            break;
        }
    }        
}

#ifdef     DEBUG_UART
void Uart_Display_State(void){
    char strtmp[] = "                                                                               ";
    if(canPayloadProcessingBuffer.Half_words.slave_function_code == (int16_t)RECEIVE_COMMAND){
        switch(canPayloadProcessingBuffer.Half_words.register_address){
            case MOTOR_ACTION:
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)RELEASE_MOTOR){
                    sprintf((char*) strtmp, "RELEASE_MOTOR\r\n");
                    Send_Data_To_PC(strtmp);
                }
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)ENABLE_MOTOR){
                    sprintf((char*) strtmp, "ENABLE_MOTOR\r\n");
                    Send_Data_To_PC(strtmp);
                }
                break;
            case WORKING_MODE:
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)SPEED_MODE){
                    sprintf((char*) strtmp, "SPEED_MODE\r\n");
                    Send_Data_To_PC(strtmp);
                }
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)POSITION_MODE){
                    sprintf((char*) strtmp, "POSITION_MODE\r\n");
                    Send_Data_To_PC(strtmp);
                }
                break;
            case POSITION_OPERATION:
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)ABSOLUTE_POSITION_MODE){
                    sprintf((char*) strtmp, "ABSOLUTE_POSITION_MODE\r\n");
                    Send_Data_To_PC(strtmp);
                }
                if(canPayloadProcessingBuffer.Words.payload == (int32_t)RELATIVE_POSITION_MODE){
                    sprintf((char*) strtmp, "RELATIVE_POSITION_MODE\r\n");
                    Send_Data_To_PC(strtmp);
                }
            break;
            case SET_DISTANCE_FOR_POSITION_MODE:
                sprintf((char*) strtmp, "SET_DISTANCE_FOR_POSITION_MODE = %x\r\n", canPayloadProcessingBuffer.Words.payload);
                Send_Data_To_PC(strtmp);
                break;
            case SET_MAX_SPEED_FOR_POSITION_MODE:
                sprintf((char*) strtmp, "SET_MAX_SPEED_FOR_POSITION_MODE = %x\r\n", canPayloadProcessingBuffer.Words.payload);
                Send_Data_To_PC(strtmp);
            break;
            case SET_TARGET_SPEED:
            sprintf((char*) strtmp, "SET_TARGET_SPEED = %x\r\n", canPayloadProcessingBuffer.Words.payload);
                Send_Data_To_PC(strtmp);
            break;
        }
    }  
}
#endif
