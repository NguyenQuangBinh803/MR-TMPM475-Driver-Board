#include <stdlib.h>
#include <stdio.h>

#include "ipdefine.h"
#include "mcuip_drv_ave.h"
#include "D_Para.h"

#include "tmpm475_gpio.h"
#include "tmpm475_enc.h"

#include "tmpm475_can_int.h"
#include "nguyen_uart.h"
#include "nguyen_encoder.h"
#include "nguyen_motor_app.h"

#define   PROPORTION_DISTANCE_PREPARE_TO_STOP       8/10
#define   SPEED_PREPARE_TO_STOP                     0x10
typedef union {
    uint32_t All;
    struct {
        uint32_t reserve: 27;
        uint32_t motor_direction:1;                 // 0: CW, 1: CCW
        uint32_t position_mode: 1;                  // 0: relative position; 1: absolute position
        uint32_t motor_mode: 1;                     // 0: speed_mode; 1: potition_mode 
        uint32_t motor_enable_mode: 1;              // 0: release; 1: enable
        
    } Bits;
} MOTOR_Action_Status;

typedef enum{
    WAIT_FOR_START_COMMAND = 0,
    START_RUNNING,
    PREPARE_TO_STOP,
    STOP_MOTOR
}ROBOT_POSITION_RUNNING_STATE;

ROBOT_POSITION_RUNNING_STATE robotRunningState = WAIT_FOR_START_COMMAND;

//////////////////////////////////////////////////////////////////////////////////
static MOTOR_Action_Status motorActionStatusBits;
static int32_t current_target_speed = 0;
//static int32_t previous_target_speed = 0;
static int32_t max_speed_for_position_mode = 0;
static int32_t distance_to_run = 0;
/////////////////////////////////////////////////////////////////////////////////
static int32_t Position_Mode_Running_FSM(void);
static int32_t Motor_FSM_Application(void);
/////////////////////////////////////////////////////////////////////////////////
//CAN commands to send
//RELEASE MOTOR:                00 DA 00 10 00 00 00 0F       
//SPEED MODE   :                00 DA 00 19 00 00 00 2F
//SET TARGET SPEED:             00 DA 00 11 00 00 00 XX
//ENABLE MOTOR :                00 DA 00 10 00 00 00 1F

//POSITION MODE:                00 DA 00 19 00 00 00 3F
//SET MAX SPEED:                00 DA 00 14 00 00 00 XX
//RELATIVE POSITION MODE:       00 DA 00 17 00 00 00 5F
//ABSOLUTE POTITION MODE:       00 DA 00 17 00 00 00 4F
//SET DISTANCE:                 00 DA 00 16 XX XX XX XX  //number of pulses of encoder

//ENABLE MOTOR :                00 DA 00 10 00 00 00 1F

void Motor_Action_Status_Bits_Initialization(void){
    motorActionStatusBits.All = 0;
}
void Set_Position_Mode(uint32_t mode){
    if(mode == ABSOLUTE_POSITION_MODE){
        motorActionStatusBits.Bits.position_mode = ABSOLUTE_POSITION_STATE;
    } else if(mode == RELATIVE_POSITION_STATE){
        motorActionStatusBits.Bits.position_mode = RELATIVE_POSITION_STATE;
    }
}

void Set_Motor_Mode(uint32_t mode){
    if(mode == SPEED_MODE){
        motorActionStatusBits.Bits.motor_mode = SPEED_MODE_STATE;
    } else if(mode == POSITION_MODE){
        motorActionStatusBits.Bits.motor_mode = POSITION_MODE_STATE;
    }
}

void Set_Motor_Enable_Mode(uint32_t mode){
    if(mode == RELEASE_MOTOR){
        motorActionStatusBits.Bits.motor_enable_mode = MOTOR_RELEASE_STATE;
    } else if(mode == ENABLE_MOTOR){
        motorActionStatusBits.Bits.motor_enable_mode = MOTOR_ENABLE_STATE;
    }
}

uint8_t Get_Motor_Direction(void){
    return motorActionStatusBits.Bits.motor_direction;
}
uint8_t Is_Motor_Enable(void){
    return (motorActionStatusBits.Bits.motor_enable_mode == MOTOR_ENABLE_STATE);
}


/////////////////////////////////////////////////////////////////////////////////
//For speed mode
/////////////////////////////////////////////////////////////////////////////////
int32_t Get_Target_Speed(void){
    int32_t tempTargetSpeed = 0;
    tempTargetSpeed = Motor_FSM_Application();
    if(motorActionStatusBits.Bits.motor_enable_mode == MOTOR_RELEASE_STATE){
        tempTargetSpeed = 0;
        //current_target_speed = 0;
    } else if(motorActionStatusBits.Bits.motor_enable_mode == MOTOR_ENABLE_STATE){
        
    }
    return tempTargetSpeed;
}

void Set_Target_Speed(int32_t targetSpeed){
    if(motorActionStatusBits.Bits.motor_mode == SPEED_MODE_STATE){
        if(targetSpeed >= 0){
            current_target_speed = targetSpeed;
            motorActionStatusBits.Bits.motor_direction = CLOCK_WISE;
        } else {
            current_target_speed = -targetSpeed;
            motorActionStatusBits.Bits.motor_direction = COUNTER_CLOCK_WISE;
        }
    } else {
        current_target_speed = 0;
        motorActionStatusBits.Bits.motor_direction = CLOCK_WISE;
    }
}
/////////////////////////////////////////////////////////////////////////////////
//For position mode
/////////////////////////////////////////////////////////////////////////////////
void Set_Max_Speed_For_Position_Mode(int32_t maxSpeed){
    if(motorActionStatusBits.Bits.motor_mode == POSITION_MODE_STATE){
        if(maxSpeed >= 0)
            max_speed_for_position_mode = maxSpeed;
        else 
            max_speed_for_position_mode = -maxSpeed;
    } else {
        max_speed_for_position_mode = 0;
    }
}

void Set_Distance_For_Position_Mode(int32_t distance){
    if(motorActionStatusBits.Bits.motor_mode == POSITION_MODE_STATE){
        if(distance >= 0){
            distance_to_run = distance;
            motorActionStatusBits.Bits.motor_direction = CLOCK_WISE;
        } else {
            distance_to_run = -distance;
            motorActionStatusBits.Bits.motor_direction = COUNTER_CLOCK_WISE;
        }
    } else {
        distance_to_run = 0;
        motorActionStatusBits.Bits.motor_direction = CLOCK_WISE;
    }
    
}
/////////////////////////////////////////////////////////////////////////////////

static int32_t Motor_FSM_Application(void){
    static int32_t tempTargetSpeedFSM = 0;
    //if(motorActionStatusBits.Bits.motor_enable_mode == MOTOR_ENABLE_STATE)
    {
        if(motorActionStatusBits.Bits.motor_mode == SPEED_MODE_STATE){
            tempTargetSpeedFSM = current_target_speed;
        } else if(motorActionStatusBits.Bits.motor_mode == POSITION_MODE_STATE){
            tempTargetSpeedFSM = Position_Mode_Running_FSM();
        }
    } 
    return tempTargetSpeedFSM;
}

static int32_t Position_Mode_Running_FSM(void){
    static int32_t tempTargetSpeedPM = 0;
    static uint32_t countForPrepareStop =  0;
    static int32_t counterEncoderStart, currentCounterEncoder;
#ifdef DEBUG_UART
    char strtmp[] = "                                                                               ";
    static int32_t tempDistance = 0;
#endif
    countForPrepareStop = distance_to_run * PROPORTION_DISTANCE_PREPARE_TO_STOP;
    switch(robotRunningState){
        case WAIT_FOR_START_COMMAND:
            if(max_speed_for_position_mode > 0 && distance_to_run > 0){
                counterEncoderStart = Get_Encoder_Counter();
                tempTargetSpeedPM = max_speed_for_position_mode;
                robotRunningState = START_RUNNING;
#ifdef DEBUG_UART
                sprintf((char*) strtmp, "START_RUNNING\r\n");
                Send_Data_To_PC(strtmp);
#endif
            }
            break;
        case START_RUNNING:
            tempTargetSpeedPM = max_speed_for_position_mode;
            currentCounterEncoder = Get_Encoder_Counter();
#ifdef DEBUG_UART
            if(abs(currentCounterEncoder - counterEncoderStart) > 0 && abs(abs(currentCounterEncoder - counterEncoderStart) - tempDistance) > 0){
                tempDistance = abs(currentCounterEncoder - counterEncoderStart);
                sprintf((char*) strtmp, "d = %d\r\n", abs(currentCounterEncoder - counterEncoderStart));
                Send_Data_To_PC(strtmp);
            }
#endif
            if(abs(currentCounterEncoder - counterEncoderStart) >= countForPrepareStop){
                robotRunningState = PREPARE_TO_STOP;
                tempTargetSpeedPM = SPEED_PREPARE_TO_STOP;
#ifdef DEBUG_UART
                sprintf((char*) strtmp, "PREPARE_TO_STOP\r\n");
                Send_Data_To_PC(strtmp);
                sprintf((char*) strtmp, "ts = %d\r\n", tempTargetSpeedPM);
                Send_Data_To_PC(strtmp);
#endif
            }
            break;
        case PREPARE_TO_STOP:
            currentCounterEncoder = Get_Encoder_Counter();
#ifdef DEBUG_UART
            if(abs(currentCounterEncoder - counterEncoderStart) > 0 && abs(abs(currentCounterEncoder - counterEncoderStart) - tempDistance) > 0){
                tempDistance = abs(currentCounterEncoder - counterEncoderStart);
                sprintf((char*) strtmp, "ad = %d\r\n", abs(currentCounterEncoder - counterEncoderStart));
                Send_Data_To_PC(strtmp);
            }
#endif
            if(abs(currentCounterEncoder - counterEncoderStart) >= distance_to_run){
                
                robotRunningState = STOP_MOTOR;
                tempTargetSpeedPM = 0;
                distance_to_run = 0;
                Set_Motor_Enable_Mode(RELEASE_MOTOR);
#ifdef DEBUG_UART
                sprintf((char*) strtmp, "STOP_MOTOR\r\n");
                Send_Data_To_PC(strtmp);
                sprintf((char*) strtmp, "ts = %d\r\n", tempTargetSpeedPM);
                Send_Data_To_PC(strtmp);
#endif
      
            }
            break;
        case STOP_MOTOR:
            distance_to_run = 0;
            max_speed_for_position_mode = 0;
            Set_Motor_Enable_Mode(ENABLE_MOTOR);
            robotRunningState = WAIT_FOR_START_COMMAND;
#ifdef DEBUG_UART
            currentCounterEncoder = Get_Encoder_Counter();
            if(abs(currentCounterEncoder - counterEncoderStart) > 0 && abs(abs(currentCounterEncoder - counterEncoderStart) - tempDistance) > 0){
                tempDistance = abs(currentCounterEncoder - counterEncoderStart);
                sprintf((char*) strtmp, "asd = %d\r\n", abs(currentCounterEncoder - counterEncoderStart));
                Send_Data_To_PC(strtmp);
            }
#endif
            break;
        default:
        break;
    }
    return tempTargetSpeedPM;
}

