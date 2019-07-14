#include "myconfig.h"
#include "encoder.h"


TIM_ICInitTypeDef  TIM1_ICInitStructure;
void TIM1_Cap_Config(u16 arr,u16 psc)//��ʱ��1ͨ��1\3���벶������
{	 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	
		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);	//ʹ��TIM1ʱ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIOE���ù����Լ�ʱ��
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM1,ENABLE);		//�ض���TIM1
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9|GPIO_Pin_13;  //PE9��PE13 ���֮ǰ����  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PE9��PE13 ����  
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_9|GPIO_Pin_13);						 //PE9��PE13 ����
	
	//��ʼ����ʱ��1 TIM1	 
	TIM_TimeBaseStructure.TIM_Period = arr; //�趨�������Զ���װֵ 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 	//Ԥ��Ƶ��   
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM1���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
  
	//��ʼ��TIM1ͨ��1���벶�����
	TIM1_ICInitStructure.TIM_Channel = TIM_Channel_1; // 	ѡ������� IC1ӳ�䵽TI1��
	TIM1_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
	TIM1_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
	TIM1_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
	TIM1_ICInitStructure.TIM_ICFilter = 0x0f;// ���������˲��� �˲�
	TIM_ICInit(TIM1, &TIM1_ICInitStructure);
	
	//��ʼ��TIM1ͨ��3���벶�����
	TIM1_ICInitStructure.TIM_Channel = TIM_Channel_3; //	ѡ������� IC3ӳ�䵽TI1��
	TIM1_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
	TIM1_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
	TIM1_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
	TIM1_ICInitStructure.TIM_ICFilter = 0x00;//���������˲��� �˲�
	TIM_ICInit(TIM1, &TIM1_ICInitStructure);
	
	
	//�жϷ����ʼ��
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;  //TIM1�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //�����ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ��� 
	
	TIM_ITConfig(TIM1,TIM_IT_CC1,ENABLE);//����CC1IE�����жϣ���Ϊ�ڸ����жϺ�����������
	TIM_ITConfig(TIM1, TIM_IT_CC3, ENABLE);//����CC3IE�����ж�
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);//��������ж�
	
  TIM_Cmd(TIM1,ENABLE ); 	//ʹ�ܶ�ʱ��1
}

/*

* �������ܣ�����������ʱ���ʼ����Ĭ��Ƶ��Ϊ1M
* �����������������time/1000����
* �����������
* ����ֵ  ����

*/
//void encoderTime_Init(u16 time)//4000-1��72-1��Ƶ��Ϊ1M���ϼ�����4000��Ϊ4ms
//{
//	TIM1_Cap_Config(time-1,720-1);
//	encoderStart(START);

//}

///*

//* �������ܣ���������/ֹͣ����
//* �����������ʼ��newState==START��ֹͣ��newState==STOP
//* �����������
//* ����ֵ  ����

//*/
//void encoderStart(SWITCHState newState)
//{
//	if(newState == START)
//			TIM_Cmd(TIM1, ENABLE);  	//ʹ��TIMx����
//	else if(newState == STOP)
//			TIM_Cmd(TIM1, DISABLE);  //��ʹ��TIMx����
//}

void TIM1_UP_IRQHandler(void)
{
	 if(TIM_GetITStatus(TIM1,TIM_IT_Update)!=RESET)
	 {
		 TIM_ClearITPendingBit(TIM1,TIM_IT_Update);//����жϱ�־λ
//		 TIM_ITConfig(TIM1,TIM_IT_CC1,ENABLE);//����CC1IE�����ж�
//		 TIM_ITConfig(TIM1, TIM_IT_CC3, ENABLE);//����CC3IE�����ж�
	 }
}


void TIM1_CC_IRQHandler(void)
{
	Encoder_get_val(encoder_value);
//	 encoder_value[0]=100;
}

void Encoder_get_val(u16 *data)
{
	static u8 CC1state=0;
	static u8 CC3state=0;
	static u16 CC1count1,CC1count2;
	static u16 CC3count1,CC3count2;
	if(TIM_GetITStatus(TIM1,TIM_IT_CC1)!=RESET)
   {
      TIM_ClearITPendingBit(TIM1, TIM_IT_CC1);    //����жϱ�־λ
      if(0==CC1state)	//ͨ��1��һ�β���������
			{
				CC1count1=TIM_GetCapture1(TIM1);
				CC1state=1;
			}
      else if(1==CC1state)
			{
				CC1count2=TIM_GetCapture1(TIM1);
				 if(CC1count1<CC1count2)
				 {
							 data[0]=CC1count2-CC1count1;           //���������صĲ�ֵ
				 }
				 else if(CC1count1>CC1count2)
				 {
							 data[0]=(4000-1-CC1count1)+CC1count2;  //���������صĲ�ֵ,ע�������ֵҪ��main������Ӧ
				 }
				 else
				 {
					 data[0]=0;
				 }
				CC1state=0;
//				TIM_ITConfig(TIM1,TIM_IT_CC1,DISABLE);//������CC1IE�����ж�
			}
			
   }
	if(TIM_GetITStatus(TIM1,TIM_IT_CC3)!=RESET)
   {
      TIM_ClearITPendingBit(TIM1, TIM_IT_CC3);    //����жϱ�־λ
      if(0==CC3state)	//ͨ��3��һ�β���������
			{
				CC3count1=TIM_GetCapture3(TIM1);
				CC3state=1;
			}
      else if(1==CC3state)
			{
				CC3count2=TIM_GetCapture3(TIM1);
			if(CC3count1<CC3count2)
			{
				data[1]=CC3count2-CC3count1;           //���������صĲ�ֵ
			}
			else if(CC3count1>CC3count2)
			{
				data[0]=(4000-1-CC3count1)+CC3count2;  //���������صĲ�ֵ,ע�������ֵҪ��main������Ӧ
			}
			else
			{
				data[0]=0;
			}
				CC3state=0;
//				TIM_ITConfig(TIM1,TIM_IT_CC3,DISABLE);//������CC1IE�����ж�
			}
			
   }
	
}



