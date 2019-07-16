#ifndef __TIMER_H
#define __TIMER_H	

#include "sys.h"

typedef enum {STOP = 0, START = !DISABLE} SWITCHState;

void sampingTime_Init(u16 time);				  //adc采样周期
void sampingStart(SWITCHState newState);  //adc采样开关函数

void mpu6050_sampingTime_Init(u16 time);  	//mpu6050采样周期
void mpu6050_samping(SWITCHState newState); // mpu6050采样开关

void TIM7_Config(u16 arr,u16 psc);   //定时器7初始化
void Time7(SWITCHState newState);    //定时器7开关



#endif
