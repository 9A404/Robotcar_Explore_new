#include "myconfig.h"
#include "encoder.h"

s16	hall_L_counter;	//�������������ֵ����ӦTIM2����ֵ
s16	hall_R_counter;//��ӦTIM3����ֵ
static s16 err_L_L,err_L_R,err_LL_L,err_LL_R,all_error_L,all_error_R;
static s16 PWM_Increase_L,PWM_Increase_R;
static s16 PWM_L = 0,PWM_R = 0;
float Kp = 0.3;
float Kd = 0.8;//3.5
float Ki =0.05 ;
/*

* �������ܣ���TIM3����Ϊ�������ӿ�ģʽ
* �����������
* �����������
* ����ֵ  ����
* ����    ��panshao

*/
void Encoder_Init_TIM3(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
  TIM_ICInitTypeDef TIM_ICInitStructure;  
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);   //ʹ�ܶ�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIOB���ù����Լ�ʱ��
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);		//�ض���TIM3

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;  //PB4��PB5 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_4|GPIO_Pin_5);						 
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
  
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0; 							// No prescaling     //����Ƶ
  TIM_TimeBaseStructure.TIM_Period = 0xffff;  //�趨�������Զ���װֵ
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ѡ��ʱ�ӷ�Ƶ������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ���    
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);  //��ʼ����ʱ��
  
  TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//ʹ�ñ�����ģʽ3���½��ز���TI1��TI2ͬʱ
  TIM_ICStructInit(&TIM_ICInitStructure);		//
  TIM_ICInitStructure.TIM_ICFilter = 0;
  TIM_ICInit(TIM3, &TIM_ICInitStructure);
  
  TIM_ClearFlag(TIM3, TIM_FLAG_Update);//���TIM�ĸ��±�־λ
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM3, ENABLE); 
}

/*

* �������ܣ���TIM2����Ϊ�������ӿ�ģʽ
* �����������
* �����������
* ����ֵ  ����
* ����    ��panshao

*/
void Encoder_Init_TIM2(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
  TIM_ICInitTypeDef TIM_ICInitStructure;  
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);   //ʹ�ܶ�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIOA��B���ù���ʱ��
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM2,ENABLE);		//�ض���TIM2

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;  //PA15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;  //PB3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);
	GPIO_ResetBits(GPIOB,GPIO_Pin_3);
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
  
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0; 							// No prescaling     //����Ƶ
  TIM_TimeBaseStructure.TIM_Period = 0xffff;  //�趨�������Զ���װֵ
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ѡ��ʱ�ӷ�Ƶ������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ���    
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);  //��ʼ����ʱ��
  
  TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//ʹ�ñ�����ģʽ3���½��ز���TI1��TI2ͬʱ
  TIM_ICStructInit(&TIM_ICInitStructure);		//
  TIM_ICInitStructure.TIM_ICFilter = 0;
  TIM_ICInit(TIM2, &TIM_ICInitStructure);
  
  TIM_ClearFlag(TIM2, TIM_FLAG_Update);//���TIM�ĸ��±�־λ
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM2, ENABLE); 
}

/*

* �������ܣ���λʱ���ȡ����������ֵ
* �����������ʱ���Ķ�Ӧ����
* �����������
* ����ֵ  ����ǰ����ֵ
* ����    ��panshao

*/

s16 Read_Encoder(u8 TIMX)
{
   s16 Encoder_TIM;    
   switch(TIMX)
	 {
	   case 2:  Encoder_TIM= (short)TIM2 -> CNT;  TIM2 -> CNT=0;break;   //��ȡ�����������ݲ�����
		 case 3:  Encoder_TIM= (short)TIM3 -> CNT;  TIM3 -> CNT=0;break;	 //��ȡ�����������ݲ�����
		 default:  Encoder_TIM=0;
	 }
		return Encoder_TIM;
}


/*

* �������ܣ����ڶ����ȡ����������ֵ�ĵ�λʱ��
* �����������λʱ��(����)
* �����������
* ����ֵ  ����
* ����    ��panshao

*/
void TIM1_Read_Time(u16 msec)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);  ///ʹ��TIM1ʱ��
	
	TIM_TimeBaseInitStructure.TIM_Period = 10 * msec; 												//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 ������500Ϊ500ms
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200-1; 											//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  10Khz�ļ���Ƶ��  
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0; 									//����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE); 
	NVIC_InitStructure.NVIC_IRQChannel=TIM1_UP_IRQn; //��ʱ��2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	TIM_Cmd(TIM1, ENABLE);
}



/*

* �������ܣ�����ٶȱջ����Ƽ��㺯��
* ������������ת�ٵ��趨ֵ��������Ѳ�ߺ������ٶ�ֵ֮����������ع�ϵ���������
* �����������
* ����ֵ  ����
* ����    ��panshao

*/


void close_loop_PD_control(s16 V_set_L,s16 V_set_R)
{
		if(V_set_L>=0)
	{
		hall_L_counter = Read_Encoder(2);        //�õ���������ֵ
		
	}
	if(V_set_L<0)
	{
		
		hall_L_counter = -Read_Encoder(2);        //�õ���������ֵ	
		V_set_L = -V_set_L;
	}
	if(V_set_R>=0)
	{
		hall_R_counter = Read_Encoder(3); 
	}
	if(V_set_R<0)
	{
		hall_R_counter = -Read_Encoder(3); 
		V_set_R=-V_set_R;
	}
	err_L_L = V_set_L - hall_L_counter;       //�������趨�ٶȼ�ȥ�����ٶ�
	err_L_R = V_set_R - hall_R_counter;
	PWM_Increase_L  = Kp * err_L_L +Kd * (err_L_L - err_LL_L);         //����PWMӦ���޸ĵ���
	PWM_Increase_R  = Kp * err_L_R +Kd * (err_L_R - err_LL_R);
	PWM_L += PWM_Increase_L;                 //����PWMӦ���������
	PWM_R += PWM_Increase_R; 
if(PWM_L>200)
	{
		PWM_L=200;
	}
		if(PWM_R>200)
	{
		PWM_R=200;
	}
	if(V_set_L>=0)
	{	
		TIM_SetCompare1(TIM5, (uint16_t)PWM_L);
		TIM_SetCompare2(TIM5, 0);
		}//���ݼ���ֵ�޸�PWMռ�ձ�
	if(V_set_L<0)
	{	
		TIM_SetCompare2(TIM5, (uint16_t)PWM_L);
		TIM_SetCompare1(TIM5, 0);
		}//���ݼ���ֵ�޸�PWMռ�ձ�
		if(V_set_R>=0)
	{
		TIM_SetCompare3(TIM5, (uint16_t)PWM_R);
		TIM_SetCompare4(TIM5, 0);
	}
	if(V_set_R<0)
	{
		TIM_SetCompare4(TIM5, (uint16_t)PWM_R);
		TIM_SetCompare3(TIM5, 0);
	}
		err_LL_L = err_L_L;                      //����һ�β���ʱ������
		err_LL_R = err_L_R;                      //����һ�β���ʱ������
}






/*

* �������ܣ�TIM2���жϷ�����������жϱ�־λ
* �����������
* �����������
* ����ֵ  ����
* ����    ��panshao

*/
void TIM2_IRQHandler(void)
{ 		    		  			    
	if(TIM2->SR&0X0001)//����ж�
	{    				   				     	    	
	}				   
	TIM2->SR&=~(1<<0);//����жϱ�־λ 	    
}

/*

* �������ܣ�TIM1���жϷ�����,�ջ��������
* �����������
* �����������
* ����ֵ  ����
* ����    ��panshao

*/
void TIM3_IRQHandler(void)
{ 		    		  			    
	if(TIM3->SR&0X0001)//����ж�
	{    				   				     	    	
	}				   
	TIM3->SR&=~(1<<0);//����жϱ�־λ 	    
}

void TIM1_IRQHandler(void)
{
	if(TIM_GetFlagStatus(TIM1, TIM_FLAG_Update) != RESET)
	{
		TIM_Cmd(TIM1, DISABLE);
		
		close_loop_PD_control(glmotorSpeed.leftSpeed-(gldSpeed/2),glmotorSpeed.rightSpeed+(gldSpeed/2));
		
		TIM_ClearITPendingBit(TIM1, TIM_FLAG_Update);
		TIM_Cmd(TIM1, ENABLE);
	}
}










