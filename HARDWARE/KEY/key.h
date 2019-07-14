#ifndef _KEY_H_
#define _KEY_H_
#include "myconfig.h"


#define KEY0  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_0)		//��ȡ����0
#define KEY1  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)	//��ȡ����1
#define KEY2  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)	//��ȡ����2 
#define KEY3  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_11)	//��ȡ����3
#define KEY4  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_10)	//��ȡ����4

#define KEY0_UP			1			//�� 
#define KEY1_DOWN		2		  //�� 
#define KEY2_ENTER	3		  //ȷ��  
#define KEY3_MENU		4		  //�˵�  
#define KEY4_ESC		5		  //���� 

#define Collision   GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_15)

void keyInit(void); 
u8 keyScan(u8 mode);

#endif



