#ifndef _ENCODER_H_
#define _ENCODER_H_
#endif
#include "sys.h"

void Encoder_Init_TIM3(void);
void Encoder_Init_TIM2(void);
s16 Read_Encoder(u8 TIMX);
void TIM1_Read_Time(u16 msec);
void close_loop_PD_control(s16 V_set_L,s16 V_set_R);