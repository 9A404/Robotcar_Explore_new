#include "pwm.h"
#include "myconfig.h"

/*

* �������ܣ������·PWM��ʼ��
* ���������arr���Զ���װֵ����psc��ʱ��Ԥ��Ƶ����
* �����������
* ����ֵ  ����

*/
static void TIM4_PWM_Init(u16 arr,u16 psc)       
{    
	GPIO_InitTypeDef 				 GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  			 TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);     //ʹ��TIM4����ʱ��ʹ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);  // ʹ��GPIO����ʱ��ʹ��
	                                                                     	
	//���ã�PB6,PB7,PB8,PB9��Ϊ�����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;      
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	TIM_TimeBaseStructure.TIM_Period = arr; 												//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 											//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 									//����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 						//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 								//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 		//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; 																//���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 				//�������:TIM����Ƚϼ��Ը�
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  												//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  												//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);  												//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  												//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	
	TIM_CtrlPWMOutputs(TIM4,ENABLE);	//MOE �����ʹ��	

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��	 
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  	 
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM4, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM4, ENABLE);  
                            
}     

/*

* �������ܣ����PWM��ʼ��
* ���������arr���Զ���װֵ����psc��ʱ��Ԥ��Ƶ����
* �����������
* ����ֵ  ����

*/
static void TIM8_PWM_Init(u16 arr,u16 psc)       
{    
	GPIO_InitTypeDef 				 GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  			 TIM_OCInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);     //ʹ��TIM8����ʱ��ʹ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);  // ʹ��GPIO����ʱ��ʹ��
	                                                                     	
	//���ã�PC6,PC7,PC8,PC9��Ϊ�����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;      
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	
	TIM_TimeBaseStructure.TIM_Period = arr; 												//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 											//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 									//����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); 						//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 								//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 		//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; 																//���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 				//�������:TIM����Ƚϼ��Ը�
	
	TIM_OC1Init(TIM8, &TIM_OCInitStructure);  												//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC2Init(TIM8, &TIM_OCInitStructure);  												//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC3Init(TIM8, &TIM_OCInitStructure);  												//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC4Init(TIM8, &TIM_OCInitStructure);  												//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	
	TIM_CtrlPWMOutputs(TIM8,ENABLE);	//MOE �����ʹ��	

	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);  //CH1Ԥװ��ʹ��	 
	TIM_OC2PreloadConfig(TIM8,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);  	 
	TIM_OC4PreloadConfig(TIM8,TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM8, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM8, ENABLE);  
                            
}     


/*

* �������ܣ�����������������Ƕȿ���
* ���������num(����ƵĶ��)(������HEAD��L_ARM��R_ARM)��angle����ת���ĽǶȣ�(������L_90��L_45��MID ��R_45��R_90 )
* �����������
* ����ֵ  ����

*/
void sgAngleControl(SgNumber num,RotationAngle angle)
{
	switch(num)
	{
		case HEAD	:	TIM8->CCR3 = angle;break;
		case L_ARM: TIM8->CCR1 = angle;break;
		case R_ARM:	TIM8->CCR2 = angle;break;
		default 	: break;
	}
}

/*

* �������ܣ����PWMƵ�ʳ�ʼ����50����
* �����������
* �����������
* ����ֵ  ����

*/
void sg_PWM_Init(void)
{
	TIM8_PWM_Init(7200-1,200-1); //��ʼ��PWMƵ��Ϊ50hz
	sgAngleControl(HEAD,H_MID);
	sgAngleControl(L_ARM,L_DOWN);
	sgAngleControl(R_ARM,R_DOWN);
}




/*

* �������ܣ����PWMƵ�ʳ�ʼ����10k
* �����������
* �����������
* ����ֵ  ����

*/
void motor_PWM_Init(void)
{
	TIM4_PWM_Init(7200-1,0); //��ʼ��PWMƵ��Ϊ10k
	speedAdjustment(0,0);
}

/*

* �������ܣ����������ٶȵĵ���
* ���������lspeed�����ֵ�ռ�ձȣ�rspeed�����ֵ�ռ�ձȣ�
* �����������
* ����ֵ  ����

*/
void speedAdjustment(int lspeed,int rspeed)
{
	  if(rspeed>0)   
	{
		TIM4->CCR3 = 0;         // PB9
		TIM4->CCR4 = rspeed;	  // PB8          

	}
	else
	{ 
	  TIM4->CCR4 = 0;
		TIM4->CCR3 = -rspeed;              
	}
	
	if(lspeed>0)
 	{		
		TIM4->CCR1 = lspeed;	   			//PB7
		TIM4->CCR2 = 0;	  //PB6     
	}
		else
		{
	  TIM4->CCR2 = -lspeed;
		TIM4->CCR1 = 0;	         
		}
	
}

/*

* �������ܣ�(����ʽ)���նԵ��PWM�����
* ���������motorSpeedTypeDef(�������µ��ٶȲ���)��dSpeed��ƫ���ٶȣ�
* �����������
* ����ֵ  ����
* ����    ��ʵ����С���ܹ����趨���ٶ����ȶ���ֱ��
*/
void incrementalSpeedOut(motorSpeedTypeDef *p,int dSpeed)
{
	dSpeed=dSpeed/2;
	p->leftSpeed  -= dSpeed;
	p->rightSpeed += dSpeed;
  
	speedAdjustment(p->leftSpeed,p->rightSpeed);

}

/*

* �������ܣ�(����ʽ)���նԵ��PWM�����
* ���������leftSpeed(��ʼ�����ٶ�)��rightSpeed�����������ٶȣ���dSpeed��ƫ���ٶȣ�
* �����������
* ����ֵ  ����
* ����    ��ʵ����С���ܹ����趨���ٶ����ȶ���ֱ��
*/
void positionSpeedOut(int leftSpeed,int rightSpeed,int dSpeed)
{
	dSpeed=dSpeed/2;
	leftSpeed  -= dSpeed;
	rightSpeed += dSpeed;

	speedAdjustment(leftSpeed,rightSpeed);

}

/*

* �������ܣ��趨�ٶȼ�¼�����ṹ��motorSpeedTypeDef����ʼ����������
* ���������speedRegulator���ٶȼ�¼������leftSpeed�����ֳ�ʼֵ��rightSpeed�����ֳ�ʼֵ��
* �����������
* ����ֵ  ����
* ����		����
*/
void speedRec_Init(motorSpeedTypeDef *speedRegulator,int leftSpeed,int rightSpeed)
{
	speedRegulator->leftSpeed = leftSpeed;
	speedRegulator->rightSpeed = rightSpeed;
}




