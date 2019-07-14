#ifndef __TIMER_H
#define __TIMER_H	

#include "sys.h"

typedef enum {STOP = 0, START = !DISABLE} SWITCHState;

void sampingTime_Init(u16 time);				  //adc��������
void sampingStart(SWITCHState newState);  //adc�������غ���

void mpu6050_sampingTime_Init(u16 time);  	//mpu6050��������
void mpu6050_samping(SWITCHState newState); // mpu6050��������

void TIM3_Config(u16 arr,u16 psc);   //��ʱ��3��ʼ��
void Time3(SWITCHState newState);    //��ʱ��3����



#endif
