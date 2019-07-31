#include "myconfig.h"
#include "encoder.h"

s16	hall_L_counter;	//储存编码器计数值，对应TIM2计数值
s16	hall_R_counter;//对应TIM3计数值
static s16 err_L_L,err_L_R,err_LL_L,err_LL_R,all_error_L,all_error_R;
static s16 PWM_Increase_L,PWM_Increase_R;
static s16 PWM_L = 0,PWM_R = 0;
float Kp = 0.3;
float Kd = 0.8;//3.5
float Ki =0.05 ;
/*

* 函数介绍：将TIM3配置为编码器接口模式
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：panshao

*/
void Encoder_Init_TIM3(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
  TIM_ICInitTypeDef TIM_ICInitStructure;  
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);   //使能定时器
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);  //使能GPIOB复用功能以及时钟
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);		//重定义TIM3,部分重映射

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;  //PB4、PB5 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_4|GPIO_Pin_5);
	
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure); 
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0; 							// No prescaling     //不分频
  TIM_TimeBaseStructure.TIM_Period = 0xffff;  //设定计数器自动重装值
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //选择时钟分频：不分频
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM向上计数    
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);  //初始化定时器
  
  TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使用编码器模式3，下降沿捕获，TI1和TI2同时
  TIM_ICStructInit(&TIM_ICInitStructure);		//
  TIM_ICInitStructure.TIM_ICFilter = 0;
  TIM_ICInit(TIM3, &TIM_ICInitStructure);
  
  TIM_ClearFlag(TIM3, TIM_FLAG_Update);//清除TIM的更新标志位
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
  TIM_SetCounter(TIM3,3000);
  TIM_Cmd(TIM3, ENABLE); 
}

/*

* 函数介绍：将TIM2配置为编码器接口模式
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：panshao

*/
void Encoder_Init_TIM2(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
  TIM_ICInitTypeDef TIM_ICInitStructure;  
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);   //使能定时器
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);  //使能GPIOA和B复用功能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);   //重映射必须要开AFIO时钟
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM2,ENABLE);		//重定义TIM2
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	//禁止JTAG功能，把PB3，PB4作为普通IO口使用

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;  //PA15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;;            //复用推挽输出
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;  //PB3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);
	GPIO_ResetBits(GPIOB,GPIO_Pin_3);
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
  TIM_DeInit(TIM2);	
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0; 							// No prescaling     //不分频
  TIM_TimeBaseStructure.TIM_Period = 0xffff;  //设定计数器自动重装值
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //选择时钟分频：不分频
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM向上计数    
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);  //初始化定时器
  
  //使用编码器模式3，双通道，跳变沿计时
	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12,TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
  TIM_ICStructInit(&TIM_ICInitStructure);		//
  TIM_ICInitStructure.TIM_ICFilter = 0;
  TIM_ICInit(TIM2, &TIM_ICInitStructure);
  
  TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除TIM的更新标志位
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);	
	TIM_SetCounter(TIM2,3000);//设定初值并使能编码器计数
  TIM_Cmd(TIM2, ENABLE); 
}

/*

* 函数介绍：单位时间读取编码器计数值
* 输入参数：定时器的对应数字
* 输出参数：无
* 返回值  ：当前计数值
* 作者    ：panshao

*/

u16 Read_Encoder(u8 TIMX)
{
   u16 Encoder_TIM;    
   switch(TIMX)
	 {
	   case 2:  Encoder_TIM= (u16)TIM2 -> CNT;  TIM2 -> CNT=0;break;   //读取编码器的数据并清零
		 case 3:  Encoder_TIM= (u16)TIM3 -> CNT;  TIM3 -> CNT=0;break;	 //读取编码器的数据并清零
		 default:  Encoder_TIM=0;
	 }
		return Encoder_TIM;
}


/*

* 函数介绍：用于定义读取编码器计数值的单位时间
* 输入参数：单位时间(毫秒)
* 输出参数：无
* 返回值  ：无
* 作者    ：panshao

*/
void TIM1_Read_Time(u16 msec)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);  ///使能TIM1时钟
	
	TIM_TimeBaseInitStructure.TIM_Period = 50000-1; 												//设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到500为500ms
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200-1; 											//设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; 									//设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM1,TIM_FLAG_Update);
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);
	
	
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE); 
	NVIC_InitStructure.NVIC_IRQChannel=TIM1_UP_IRQn; //定时器2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	TIM_Cmd(TIM1, ENABLE);
}



/*

* 函数介绍：电机速度闭环控制计算函数
* 输入参数：电机转速的设定值，与我们巡线函数的速度值之间是线性相关关系并不是相等
* 输出参数：无
* 返回值  ：无
* 作者    ：panshao

*/


void close_loop_PD_control(s16 V_set_L,s16 V_set_R)
{
		if(V_set_L>=0)
	{
		hall_L_counter = Read_Encoder(2);        //拿到测量返回值
		
	}
	if(V_set_L<0)
	{
		
		hall_L_counter = -Read_Encoder(2);        //拿到测量返回值	
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
	err_L_L = V_set_L - hall_L_counter;       //误差等于设定速度减去测量速度
	err_L_R = V_set_R - hall_R_counter;
	PWM_Increase_L  = Kp * err_L_L +Kd * (err_L_L - err_LL_L);         //计算PWM应该修改的量
	PWM_Increase_R  = Kp * err_L_R +Kd * (err_L_R - err_LL_R);
	PWM_L += PWM_Increase_L;                 //计算PWM应该输出的量
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
		}//根据计算值修改PWM占空比
	if(V_set_L<0)
	{	
		TIM_SetCompare2(TIM5, (uint16_t)PWM_L);
		TIM_SetCompare1(TIM5, 0);
		}//根据计算值修改PWM占空比
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
		err_LL_L = err_L_L;                      //把上一次采样时的误差保存
		err_LL_R = err_L_R;                      //把上一次采样时的误差保存
}






/*

* 函数介绍：TIM2的中断服务函数，清除中断标志位
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：panshao

*/
void TIM2_IRQHandler(void)
{ 		    		  			    
	if(TIM2->SR&0X0001)//溢出中断
	{    				   				     	    	
	}				   
	TIM2->SR&=~(1<<0);//清除中断标志位 	    
}
void TIM3_IRQHandler(void)
{ 		    		  			    
	if(TIM3->SR&0X0001)//溢出中断
	{    				   				     	    	
	}				   
	TIM3->SR&=~(1<<0);//清除中断标志位 	    
}
/*

* 函数介绍：TIM1的中断服务函数,闭环电机控制
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：panshao

*/


void TIM1_UP_IRQHandler(void)
{
	char buff[12];
	if(TIM_GetFlagStatus(TIM1, TIM_IT_Update) != RESET)
	{
  	TIM_Cmd(TIM1, DISABLE);
//******************显示左轮脉冲数*******************************************
		i= TIM_GetCounter(TIM2);		
		TIM2->CNT = 3000;		
		sprintf(buff,"%5d",i);
		Gui_DrawFont_GBK16(50,50,BLUE,WHITE,(const char*)buff);
//******************显示右轮脉冲数*******************************************
		i= TIM_GetCounter(TIM3);		
		TIM3->CNT = 3000;		
		sprintf(buff,"%5d",i);
		Gui_DrawFont_GBK16(50,80,BLUE,WHITE,(const char*)buff);
//***************************************************************************		
////		close_loop_PD_control(glmotorSpeed.leftSpeed-(gldSpeed/2),glmotorSpeed.rightSpeed+(gldSpeed/2));
//		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
		LED1=!LED1;

		TIM_Cmd(TIM1, ENABLE);
	}
}







