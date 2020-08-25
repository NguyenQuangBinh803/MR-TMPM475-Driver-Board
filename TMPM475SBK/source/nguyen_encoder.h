#ifndef __TMPM475_ENCODER_H
#define __TMPM475_ENCODER_H
#include "TMPM475.h"

#define     ENCODER_1

void Encoder_Initializaion(void);
int32_t Get_Encoder_Counter(void);
int32_t Get_Velocity(void);
void TestEncoder(void);
#endif
