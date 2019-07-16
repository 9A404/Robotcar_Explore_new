#ifndef __TIMER_H
#define __TIMER_H	

#include "sys.h"

typedef enum {STOP = 0, START = !DISABLE} SWITCHState;

void sampingTime_Init(u16 time);				  //adc��������
void sampingStart(SWITCHState newState);  //adc�������غ���

void mpu6050_sampingTime_Init(u16 time);  	//mpu6050��������
void mpu6050_samping(SWITCHState newState); // mpu6050��������

void TIM7_Config(u16 arr,u16 psc);   //��ʱ��7��ʼ��
void Time7(SWITCHState newState);    //��ʱ��7����



#endif
