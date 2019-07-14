#include "led.h"
#include "myconfig.h"

/*

* �������ܣ�LED��GPIO����
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void ledInit()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	/*����GPIOE*/
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //���ó���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);	
	
	/*Ĭ�ϲ���*/
	LED0=1;
	LED1=1;
	LED2=1;
}


/*

* �������ܣ�LED������N��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void led_light(u8 n)
{
	u8 i;
	for(i=0;i<n;i++)
	{
		LED0=0;
		LED1=0;
		LED2=0;
		delay_ms(500);
		LED0=1;
		LED1=1;
		LED2=1;
		delay_ms(500);	
	}
}

/*

* �������ܣ�LED0��˸һ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void led0_flash()
{
		LED0 = 0;
		delay_ms(50);
		LED0 = 1;
}

/*

* �������ܣ�LED1��˸һ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void led1_flash()
{
		LED1 = 0;
		delay_ms(50);
		LED1 = 1;
}




/*

* �������ܣ�������GPIO����
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void buzzerInit()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	/*����GPIOE*/
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //���ó���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);	
	
	/*Ĭ�ϲ���*/
	BEEP=1;
}


/*

* �������ܣ�����������1��
* ���������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void buzzer_beep()
{
	BEEP = 0;
	delay_ms(20);
	BEEP = 1;
}

















