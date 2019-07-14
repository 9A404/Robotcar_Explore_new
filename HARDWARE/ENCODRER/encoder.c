#include "myconfig.h"
#include "encoder.h"


TIM_ICInitTypeDef  TIM1_ICInitStructure;
void TIM1_Cap_Config(u16 arr,u16 psc)//定时器1通道1\3输入捕获配置
{	 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	
		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);	//使能TIM1时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO, ENABLE);  //使能GPIOE复用功能以及时钟
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM1,ENABLE);		//重定义TIM1
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9|GPIO_Pin_13;  //PE9、PE13 清除之前设置  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PE9、PE13 输入  
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_9|GPIO_Pin_13);						 //PE9、PE13 下拉
	
	//初始化定时器1 TIM1	 
	TIM_TimeBaseStructure.TIM_Period = arr; //设定计数器自动重装值 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 	//预分频器   
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM1向上计数模式
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
  
	//初始化TIM1通道1输入捕获参数
	TIM1_ICInitStructure.TIM_Channel = TIM_Channel_1; // 	选择输入端 IC1映射到TI1上
	TIM1_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
	TIM1_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
	TIM1_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
	TIM1_ICInitStructure.TIM_ICFilter = 0x0f;// 配置输入滤波器 滤波
	TIM_ICInit(TIM1, &TIM1_ICInitStructure);
	
	//初始化TIM1通道3输入捕获参数
	TIM1_ICInitStructure.TIM_Channel = TIM_Channel_3; //	选择输入端 IC3映射到TI1上
	TIM1_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
	TIM1_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
	TIM1_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
	TIM1_ICInitStructure.TIM_ICFilter = 0x00;//配置输入滤波器 滤波
	TIM_ICInit(TIM1, &TIM1_ICInitStructure);
	
	
	//中断分组初始化
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_CC_IRQn;  //TIM1中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器 
	
	TIM_ITConfig(TIM1,TIM_IT_CC1,ENABLE);//允许CC1IE捕获中断，改为在更新中断函数里面允许
	TIM_ITConfig(TIM1, TIM_IT_CC3, ENABLE);//允许CC3IE捕获中断
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);//允许更新中断
	
  TIM_Cmd(TIM1,ENABLE ); 	//使能定时器1
}

/*

* 函数介绍：编码器采样时间初始化，默认频率为1M
* 输入参数：采样周期time/1000毫秒
* 输出参数：无
* 返回值  ：无

*/
//void encoderTime_Init(u16 time)//4000-1，72-1，频率为1M向上计数到4000，为4ms
//{
//	TIM1_Cap_Config(time-1,720-1);
//	encoderStart(START);

//}

///*

//* 函数介绍：采样启动/停止控制
//* 输入参数：开始：newState==START，停止：newState==STOP
//* 输出参数：无
//* 返回值  ：无

//*/
//void encoderStart(SWITCHState newState)
//{
//	if(newState == START)
//			TIM_Cmd(TIM1, ENABLE);  	//使能TIMx外设
//	else if(newState == STOP)
//			TIM_Cmd(TIM1, DISABLE);  //不使能TIMx外设
//}

void TIM1_UP_IRQHandler(void)
{
	 if(TIM_GetITStatus(TIM1,TIM_IT_Update)!=RESET)
	 {
		 TIM_ClearITPendingBit(TIM1,TIM_IT_Update);//清除中断标志位
//		 TIM_ITConfig(TIM1,TIM_IT_CC1,ENABLE);//允许CC1IE捕获中断
//		 TIM_ITConfig(TIM1, TIM_IT_CC3, ENABLE);//允许CC3IE捕获中断
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
      TIM_ClearITPendingBit(TIM1, TIM_IT_CC1);    //清除中断标志位
      if(0==CC1state)	//通道1第一次捕获到上升沿
			{
				CC1count1=TIM_GetCapture1(TIM1);
				CC1state=1;
			}
      else if(1==CC1state)
			{
				CC1count2=TIM_GetCapture1(TIM1);
				 if(CC1count1<CC1count2)
				 {
							 data[0]=CC1count2-CC1count1;           //两次上升沿的差值
				 }
				 else if(CC1count1>CC1count2)
				 {
							 data[0]=(4000-1-CC1count1)+CC1count2;  //两次上升沿的差值,注意计数总值要跟main函数对应
				 }
				 else
				 {
					 data[0]=0;
				 }
				CC1state=0;
//				TIM_ITConfig(TIM1,TIM_IT_CC1,DISABLE);//不允许CC1IE捕获中断
			}
			
   }
	if(TIM_GetITStatus(TIM1,TIM_IT_CC3)!=RESET)
   {
      TIM_ClearITPendingBit(TIM1, TIM_IT_CC3);    //清除中断标志位
      if(0==CC3state)	//通道3第一次捕获到上升沿
			{
				CC3count1=TIM_GetCapture3(TIM1);
				CC3state=1;
			}
      else if(1==CC3state)
			{
				CC3count2=TIM_GetCapture3(TIM1);
			if(CC3count1<CC3count2)
			{
				data[1]=CC3count2-CC3count1;           //两次上升沿的差值
			}
			else if(CC3count1>CC3count2)
			{
				data[0]=(4000-1-CC3count1)+CC3count2;  //两次上升沿的差值,注意计数总值要跟main函数对应
			}
			else
			{
				data[0]=0;
			}
				CC3state=0;
//				TIM_ITConfig(TIM1,TIM_IT_CC3,DISABLE);//不允许CC1IE捕获中断
			}
			
   }
	
}



