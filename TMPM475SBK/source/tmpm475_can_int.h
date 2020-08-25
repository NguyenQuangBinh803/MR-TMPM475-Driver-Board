/**
 *******************************************************************************
 * @file    tmpm475_can_int.h
 * @brief   All interrupt request functions prototypes of CAN
 *          for the TOSHIBA 'TMPM369' Device Series 
 * @version V0.101
 * @date    2014/05/20
 * 
 * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LICENSE AGREEMENT.
 * 
 * (C)Copyright TOSHIBA ELECTRONIC DEVICES & STORAGE CORPORATION 2017 All rights reserved
 *******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TMPM475_CAN_INT_H
#define __TMPM475_CAN_INT_H

/* Includes ------------------------------------------------------------------*/
#include "TMPM475.h"
#include "tmpm475_can.h"


#define     TRANSMIT_MAILBOX        CAN_MBX_1
#define     RECEIVE_MAILBOX         CAN_MBX_10


#define     RECEIVE_COMMAND                 0xDA
#define     RETURN_COMMAND                  0xDB

//register address
#define     MOTOR_ACTION                    0x0010
#define     SET_TARGET_SPEED                0x0011
#define     SET_MAX_SPEED_FOR_POSITION_MODE 0x0014
#define     SET_DISTANCE_FOR_POSITION_MODE  0x0016
#define     POSITION_OPERATION              0x0017
#define     WORKING_MODE                    0x0019


//payload
#define     RELEASE_MOTOR                   0x0000000F
#define     ENABLE_MOTOR                    0x0000001F
#define     SPEED_MODE                      0x0000002F
#define     POSITION_MODE                   0x0000003F
#define     ABSOLUTE_POSITION_MODE          0x0000004F
#define     RELATIVE_POSITION_MODE          0x0000005F


extern uint8_t fIntADC;
extern uint8_t fRcvCAN;
extern uint8_t fTranCAN;




typedef union {
    struct {
        int32_t payload;
        int32_t slave_function_address;
    }Words;
    struct {
        int16_t payload_2;
        int16_t payload_1;
        int16_t register_address;
        int16_t slave_function_code;
    }Half_words;
    struct {
        int8_t low_2;
        int8_t high_2;
        int8_t low_1;
        int8_t high_1;
        int8_t register_address_low;
        int8_t register_address_high;
        int8_t function_code;
        int8_t slave_number;
        
    } Bytes;
}CAN_PayloadDef;



void TestCan(void);
void CAN_Initialization(void);
void CAN_Data_Processing(void);

/* IRQ declaration	*/
void INTCANRX_IRQHandler(void);
void INTCANGB_IRQHandler(void);

#endif                          /* __TMPM475_CAN_INT_H */
