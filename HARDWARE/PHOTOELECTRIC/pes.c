#include "pes.h"
#include "myconfig.h"

/*

* �������ܣ���紫������ʼ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/

void pesInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);	//ʹ��PORTCʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	//ʹ��PORTAʱ��
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	//ʹ��PORTBʱ��
	/*PC2��PC3*/
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 				//���ó���������
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
	/*PA15*/
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7|GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 				//���ó���������
 	GPIO_Init(GPIOE, &GPIO_InitStructure);
}



///*

//* �������ܣ���紫����IO������
//* �����������
//* �����������
//* ����ֵ  ����
//* ����    ��@����

//*/

//static void GPIOConfig(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);	//ʹ��PORTCʱ��
//	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	//ʹ��PORTAʱ��
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);	//ʹ��PORTEʱ��
//	/*PC2��PC3��PC4*/
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 				//���ó���������
// 	GPIO_Init(GPIOC, &GPIO_InitStructure);
//	/*PE7��PE8*/
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7|GPIO_Pin_8;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 				//���ó���������
// 	GPIO_Init(GPIOE, &GPIO_InitStructure);
//	
//}

///*

//* �������ܣ����ҹ���ⲿ�ж�����
//* �����������
//* �����������
//* ����ֵ  ����
//* ����    ��@����

//*/
//void pesInit(void)
//{
//	NVIC_InitTypeDef NVIC_InitStructure;
//	EXTI_InitTypeDef EXTI_InitStructure;
//	
//	GPIOConfig();
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
//	
//	/*PC2*/
//	EXTI_ClearITPendingBit(EXTI_Line2);  
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource2);//PC8
//  EXTI_InitStructure.EXTI_Line= EXTI_Line2; //PC2��Ϊ��EXTI_Line2 
//  EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;   
//  EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Falling;   //�жϷ�ʽΪ�½��ش���
//	EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
//  EXTI_Init(&EXTI_InitStructure);
//	
//	/*PC3*/
//	EXTI_ClearITPendingBit(EXTI_Line3);  
//  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource3);//PC3
//  EXTI_InitStructure.EXTI_Line= EXTI_Line3; //PC3��Ϊ��EXTI_Line3 
//  EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;   
//  EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Falling;   //�жϷ�ʽΪ�½��ش���
//	EXTI_InitStructure.EXTI_LineCmd=ENABLE;  
//  EXTI_Init(&EXTI_InitStructure);
//	
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;  
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 1;  //�������ȼ�
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority= 1;         //��Ӧ���ȼ�
//  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;     
//  NVIC_Init(&NVIC_InitStructure);
//	
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;  
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 1;  //�������ȼ�
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority= 1;         //��Ӧ���ȼ�
//  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;     
//  NVIC_Init(&NVIC_InitStructure);	
//}

///*PC3 �����ⲿ�ж�*/
//void EXTI3_IRQHandler(void)
//{
//		if(EXTI_GetITStatus(EXTI_Line3) != RESET)         //����Ϊ�ж���Ӧ���жϺ��Ƿ�����ж�
//	{
//		pes_R = 1;
//		
//		EXTI_ClearITPendingBit(EXTI_Line3);       			//���ж�  
//	}
//	
//}


///*PC2 �����ⲿ�ж�*/
//void EXTI2_IRQHandler(void)
//{
//		if(EXTI_GetITStatus(EXTI_Line2) != RESET)         //����Ϊ�ж���Ӧ���жϺ��Ƿ�����ж�
//	{
//		pes_L = 1;
//		
//		EXTI_ClearITPendingBit(EXTI_Line2);       			//���ж�  
//	}
//	
//}



///*

//* �������ܣ������ⲿ�жϿ���(PC2)
//* �����������ʼ��newState==START��ֹͣ��newState==STOP
//* �����������
//* ����ֵ  ����
//* ����    ��@����

//*/
//void pesLSwitch(SWITCHState newState)
//{
//	if(newState == START)
//	{
//		EXTI->IMR |=  0x04;
//		EXTI->PR=0;
//	}
//	else if(newState == STOP)
//			EXTI->IMR &= (~0x04);
//}

///*

//* �������ܣ��ҹ���ⲿ�жϿ���(PC3)
//* �����������ʼ��newState==START��ֹͣ��newState==STOP
//* �����������
//* ����ֵ  ����
//* ����    ��@����

//*/
//void pesRSwitch(SWITCHState newState)
//{
//	if(newState == START)
//	{
//		EXTI->IMR |=  0x08;
//		EXTI->PR=0;
//	}
//	else if(newState == STOP)
//			EXTI->IMR &= (~0x08);
//}












