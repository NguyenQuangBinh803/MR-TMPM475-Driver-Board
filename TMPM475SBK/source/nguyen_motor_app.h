#ifndef __TMPM475_MOTOR_APP_H
#define __TMPM475_MOTOR_APP_H

#include "TMPM475.h"

#define     MOTOR_RELEASE_STATE         0
#define     MOTOR_ENABLE_STATE          1

#define     SPEED_MODE_STATE            0
#define     POSITION_MODE_STATE         1

#define     RELATIVE_POSITION_STATE     0
#define     ABSOLUTE_POSITION_STATE     1

#define     CLOCK_WISE                  0
#define     COUNTER_CLOCK_WISE          1

void Motor_Action_Status_Bits_Initialization(void);
void Set_Position_Mode(uint32_t mode);
void Set_Motor_Mode(uint32_t mode);
void Set_Motor_Enable_Mode(uint32_t mode);

uint8_t Is_Motor_Enable(void);
uint8_t Get_Motor_Direction(void);

int32_t Get_Target_Speed(void);
void Set_Target_Speed(int32_t targetSpeed);

void Set_Max_Speed_For_Position_Mode(int32_t maxSpeed);
void Set_Distance_For_Position_Mode(int32_t distance);
#endif
