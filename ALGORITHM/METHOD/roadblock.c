#include "roadblock.h"
#include "myconfig.h"



/************************************************��***********************************************************/
/*

* �������ܣ�ʶ���Ƿ�Ϊȫ0
* �����������
* �����������
* ����ֵ  ��1������·�ϣ�0��δ����·�ϣ�
* ����		��������ȫΪ0��ʱ��
* ����    ��@����

*/
u8 identifyALL_Zero()
{
		glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold); 
	if( 0x000==glsensor_dig_value)
		return 1;
	else
		return 0;
}

/*

* �������ܣ�����ͷ�ײ�ʶ�𷽷�
* �����������
* �����������
* ����ֵ  ��1������·�ϣ�0��δ����·�ϣ�
* ����		��������ȫΪ0��ʱ��
* ����    ��@����

*/
u8 identifyComingBrige_Bottom()
{
	static u8 flag=0;
	if( 0==flag && 0==PES_Platform) flag=1;
	else if(1==flag&&1==PES_Platform)
	{
		flag=0;
		return 1;
	}	
	return 0;
}


/*

* �������ܣ�����ͷ����ʶ�𷽷�
* �����������
* �����������
* ����ֵ  ��1������·�ϣ�0��δ����·�ϣ�
* ����		��������ȫΪ0��ʱ��
* ����    ��@����

*/
u8 identifyComingBrige_Top()
{
	static u8 flag=0;
//	if(1==identifyComingBrige_Bottom()) flag=1;
  if(0==flag && 0==PES_Platform)  flag=2;
	else if(2==flag && 1==PES_Platform) 
	{
		flag=0;
		return 1;
	}
		return 0;
}


/*

* �������ܣ�����β����ʶ�𷽷�
* �����������
* �����������
* ����ֵ  ��1��������β��0��δ������β��
* ����		��������ȫΪ1��ʱ��
* ����    ��@����

*/
u8 identifyCrossingBrige_Top()
{
	static u8 flag=0;
  if(0==flag && 0==PES_Platform)  flag=1;
	else if(1==flag && 1==PES_Platform) 
	{
		flag=0;
		return 1;
	}
		return 0;


}
/*

* �������ܣ�����β�ײ���ʶ�𷽷�
* �����������
* �����������
* ����ֵ  ��1��������β��0��δ������β��
* ����		��������ȫΪ1��ʱ��
* ����    ��@����

*/

u8 identifyCrossingBrige_Bottom()
{
	static u8 flag=0;
  if(0==flag && 0==PES_Platform)  flag=1;
	else if(1==flag && 1==PES_Platform) 
	{
		flag=0;
		return 1;
	}
		return 0;

}
/*

* �������ܣ���·�ϴ�����
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		����Ѳ�߷����л��ɹ��ŵ�Ѳ��
* ����    ��@����

*/
u8 BlockHandleMethod_Brige()
{
	static u8 flag=0;
	if(0==flag && 1==identifyComingBrige_Bottom())
	{
	//	save = glHello_control.linkInform.findLineWays;
		glHello_control.linkInform.findLineWays = FL_brigeup; 
		findLineFlag = 0;
		flag = 1;
	}
	if(1==flag && 1==identifyComingBrige_Top())
	{
		glHello_control.linkInform.findLineWays = FL_brige; 
		findLineFlag = 0;
		flag=2;
	}
	if(2==flag && 1==identifyCrossingBrige_Top())
	{
		glHello_control.linkInform.findLineWays = FL_brigedown
		;
	  findLineFlag = 0;
		flag=3;
	}
	if(3==flag && 1==identifyCrossingBrige_Bottom())
	{
		glHello_control.linkInform.findLineWays = FL_default;
	  findLineFlag = 0;
		flag=0;
		return 1;
	}
	
	return 0;
//static findLine save;
//	static u8 flag=0;
//     if(0 == flag)
//	 { 
//		 save = glHello_control.linkInform.findLineWays;
//		 Time3(START);
//		 gl_time = 0;
//      flag = 1;		 
//	 }
//	else if(1==flag && gl_time > 40)         //��?��???�����̡�2?
//	{   
////		speedAdjustment(0,0);
////		while(1);
//	//	delay_ms(500);
//		glHello_control.linkInform.findLineWays = FL_angle; 
//		findLineFlag = 0;
//		angle_flag = 0;
//		flag = 2;
//	}
//	else if(2==flag && gl_time > 140 )          //?��??����??��?
//	{
//		
////	k 
//		glHello_control.linkInform.findLineWays = FL_brige; 
//		findLineFlag = 0;
//		flag=3;
//	}
//	else if(3==flag && gl_time > 255)          //?��??����?��2?
//	{
////		speedAdjustment(0,0);
////     	while(1);
////		delay_ms(500);
//		flag=4;
//		Time3(STOP);
//	}
//	else if( 4 == flag )  
//	{
//     Time3(START);
//	 gl_time = 0;
//     glHello_control.linkInform.findLineWays = FL_angle;
//	 findLineFlag = 0; 
//     angle_flag = 0;
//	 flag = 5; 
//	}
//  	//?��??��?
//	else if(5==flag && gl_time > 105)             //?��???2?��2?
//	{
////	    speedAdjustment(0,0);
////     	while(1);
//		glHello_control.linkInform.findLineWays = save;
//	    findLineFlag = 0;
//		flag=0;
//		return 1;
//		
//	}
////	if(6==flag && 0==PES_Platform)  flag=6;
////	if(6==flag && 1==PES_Platform)        //?��???2�̡�2?
////	{
////		glHello_control.linkInform.findLineWays = save;
////	  findLineFlag = 0;
////		flag=0;
////		return 1;
////	}
////	
//	return 0;
}
/************************************************��***********************************************************/

/***************************************************��********************************************************/
/*

* �������ܣ����Ŵ�����
* �����������
* �����������
* ����ֵ  ��1(�ſ����߸�������·)0���Ź���û�и�����·��
* ����		��
* ����    ��@��

*/
u8 BlockHandleMethod_DOOR(void)
{
	static u8 flag=0;     //�ſ���־λ  

	DoorFlag=1;
	if(0==flag)
	{
		Time3(START);
		gl_time=0;
		flag=1;
	}
	if(1==flag && 0 == PES_H)
	{
		rotAngle_Right(180);
		runMethodUpdate(runMethod,0,runMethodTableDoorAuto);   //39�Źرս��е�һ�θ���·��
		DoorFlag_2=1;
		Control_Init(&glHello_control,runMethod);     //��ʼ������̨
		runStateInit(&glrunState,&glHello_control);		//���ݿ���̨��ʼ·�γ�ʼ������״̬
		flag=0;
		return 1;
	}
	if(1==flag && gl_time>Door_Time)
	{
		Time3(STOP);
		gl_time = 0;
		led1_flash();
		glHello_control.linkInform.findLineWays = FL_default;  //�л���ȱʡѲ��
		findLineFlag = 0;
		flag=0;
		return 1;
	}
	return 0;
}
/*

* �������ܣ����Ŵ�����
* �����������
* �����������
* ����ֵ  ��1(�ſ����߸�������·)0���Ź���û�и�����·��
* ����		��
* ����    ��@��

*/
u8 BlockHandleMethod_DOOR_2(void)
{
	static u8 flag1=0;     //�ſ���־λ  

	if(0==flag1)
	{
		Time3(START);
		gl_time=0;
		flag1=1;
	}
	if(1==flag1 && 0 == PES_H)
	{
		rotAngle_Right(180);
		runMethodUpdate(runMethod,1,runMethodTableDoorAuto);  //40�Źرս��еڶ��θ���·��
		DoorFlag_2=2;
		Control_Init(&glHello_control,runMethod);     //��ʼ������̨
		runStateInit(&glrunState,&glHello_control);		//���ݿ���̨��ʼ·�γ�ʼ������״̬
		flag1=0;
		return 1;

	}
	if(1==flag1 && gl_time>Door_Time_2)
	{
		Time3(STOP);
		gl_time = 0;
		led1_flash();
		glHello_control.linkInform.findLineWays = FL_default;  //�л���ȱʡѲ��
		findLineFlag = 0;
		flag1=0;
		return 1;
	}
	return 0;
}
/***************************************************��********************************************************/

/**************************************************ƽ̨********************************************************/
/*

* �������ܣ�����7��ƽ̨
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_down_27_26()
{
	static findLine save;
	static u8 flag=0;
	
	if(flag == 0)
	{
		glHello_control.linkInform.findLineWays =NFL;
		flag = 1;
	}
	else if(1==flag && 1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = FL_downPeak; 
		findLineFlag = 0;
		flag=2;
	}
	else if(2==flag && 0==PES_Platform) flag=3;
	else if(3==flag && 1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = FL_default; 
		findLineFlag = 0;
		flag=4;
	}
	else if(4==flag && 0==PES_Platform) flag=5;
	else if(5==flag && 1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = FL_slow; 
		findLineFlag = 0;
		Time3(START); //�򿪶�ʱ��
		gl_time=0;
		flag=6;
	}
	else if(6==flag && gl_time>200)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = save; 
		findLineFlag = 0;
		Time3(STOP); //�򿪶�ʱ��
		gl_time=0;
		flag=0;
		return 1;
	}
		return 0;

}
/*

* �������ܣ�����Ƿ�ͨ��б�£������ǣ�
* �����������
* �����������
* ����ֵ  ��������
* ����		��
* ����    ��@����

*/
float Monitor_ROLL()
{
	float temp;
	u8 i;
	#ifdef _NEW_MPU6050_
		MPU6050_Pose_usart();
		temp=glRoll;
	#else
		for(i=0;i<50;i++)
			MPU6050_Pose();				//����ŷ����
		temp=glPitch;
	#endif
	return temp;
}
/*

* ��������:·�϶��Ƕȷ���
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		����Ѳ�߷����л��ɹ��ŵ�Ѳ��
* ����    �����

*/
 u8 Angle_read()
{
  static u8 flag=0;
	if(flag == 0)
	{
	  Time3(START);
		gl_time = 0;
		flag = 1;
	}
	else if(flag == 1 && gl_time>80)
	{
		Time3(STOP);
//		speedAdjustment(0,0);
//		while(1);
		MPU6050_Pose_usart();
		angle_read = setYaw(glYaw,90);
		angle_read_back = setYaw(glYaw,-75);		
		flag = 0;  
		return 1;
	}
	return 0;
}


/*

* �������ܣ������ΰ�
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@��

*/
 u8 BlockHandleMethod_Seesaw()
{
//	static findLine save;
	static u8 flag=0,Turn_Flag=0;
	float temp;
	if(0==flag)                //���ҵ������н�����������ʱֱ��
	{	
//		speedAdjustment(2450,2200);
		Time3(START);
		gl_time=0;
		glHello_control.linkInform.findLineWays = FL_angle;
    angle_flag = 0; 		
		findLineFlag = 0;
//		led0_flash();
		flag=1;
	}
	else if(1==flag&&gl_time>100)         
	{
//		temp = Monitor_ROLL();
//		if( temp > -10)               //����������ΰ������һ�������ä�ߺ���flag=2
//		{
//			//flag++;
//			// ("glPitch%0.2f\r\n",temp);
//			speedAdjustment(2000,2000);

//			//glHello_control.linkInform.findLineWays = NFL; 
//			//led_flash();
//			flag=2;
//		}
//		else                         //�������û�е������ä��
//		{
//			speedAdjustment(2000,2120);
//		
//			delay_ms(1000);
//			delay_ms(200);
//			speedAdjustment(0,0);
//		
//			delay_ms(1000);

//			//u3_printf("glPitch%0.2f\r\n",glPitch);
//		}
		Time3(STOP);
		speedAdjustment(0,0);
		delay_ms(500);	
//		led0_flash();
//		while(1);
		temp = Monitor_ROLL();
		glHello_control.linkInform.findLineWays = FL_slow;
		findLineFlag = 0;
		if(temp>-10)
		{
			speedAdjustment(2000,2000);
			flag=2;
		}
			
		
	}
	else if(2 == flag)                //���������ΰ������һ�����ȼ�⴫������û���ڰ�����
	{
		glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������	
		if(calculateNum(glsensor_dig_value)<=1 && Turn_Flag<3) 
		{
			rotAngle_Left(20);             //������ڰ�������ת20�ȣ������������ǳ���ƫ�ң�����ת
			Turn_Flag++;
		}
		else                         //���򷵻�1����ϰ�����
		{
			flag=0;
			return 1;
		}
	}
		return 0;

}
/*

* �������ܣ���ƽ̨����������翪�أ�
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		������ƽ̨��Ѳ��
* ����    ��@����

*/
u8 BlockHandleMethod_Platform ()
{
	static findLine save;
	static u8 flag=0;
	
	if(flag == 0)
	{
		save = glHello_control.linkInform.findLineWays;
		glHello_control.linkInform.findLineWays =NFL;
		flag = 1;
	}
	else if(1==flag&&1==PES_Platform)
	{
		glHello_control.linkInform.findLineWays = FL_DownPlatform; 
		findLineFlag = 0;
		flag=2;
	}
	else if(2==flag&&0==PES_Platform)  flag=3;
	else if(3==flag&&1==PES_Platform)  flag=4;
	else if(0==PES_Platform && 4==flag)
	{
		glHello_control.linkInform.findLineWays = save; 
		findLineFlag = 0;
		flag = 0;
		return 1;
	}
		return 0;

}


u8  BlockHandleMethod_Platform_37_15 ()
{
		static findLine save;
	static u8 flag=0;
	
	if(flag == 0)
	{
		save = glHello_control.linkInform.findLineWays;
		glHello_control.linkInform.findLineWays =NFL;
		flag = 1;
	}
	else if(1==flag&&1==PES_Platform)
	{
		glHello_control.linkInform.findLineWays = FL_DownPlatform; 
		findLineFlag = 0;
		flag=2;
	}
	else if(2==flag&&0==PES_Platform)  flag=3;
	else if(3==flag&&1==PES_Platform)  flag=4;
	else if(0==PES_Platform && 4==flag)
	{
		glHello_control.linkInform.findLineWays = save; 
		findLineFlag = 0;
		Time3(START);
		gl_time=0;
		flag=5;
	}
	else if(5 == flag && gl_time > 20)
	{
		flag = 6;
		gl_time=0;
		glHello_control.linkInform.findLineWays = FL_quickest;  //�л���������Ѳ��
		findLineFlag = 0;
	}
	else if(6 == flag && gl_time > 70)
	{	
		speedAdjustment(0,0);
		delay_ms(500);
		Time3(STOP);
		flag = 0;
		gl_time = 0;
		glHello_control.linkInform.findLineWays = FL_default;  //�л���ȱʡѲ��
		findLineFlag = 0;
		return 1;
	}	
		return 0;

}
/*

* �������ܣ���ɽ�𷽷�
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		����
* ����    ��@��

*/
u8 BlockHandleMethod_Slope ()
{
	static u8 flag=0;
	static findLine save;
	if(flag == 0)
	{
		save=glHello_control.linkInform.findLineWays;
		flag=1;
	}
	else if(1 == flag&&1 == PES_Platform)          //ǰ�¹�翪�ز���������ɽ��ײ�
	{
			glHello_control.linkInform.findLineWays = FL_UpPlatform;   
			findLineFlag = 0;
			flag=2;	
	}
	else if(2==flag&&0==PES_Platform)         //ǰ�¹�翪����������ɽ�𶥲�
	{
		glHello_control.linkInform.findLineWays = FL_DownPlatform;   
		findLineFlag = 0;
		Time3(START); //�򿪶�ʱ��
		gl_time=0;
		flag=3;
	}
	else if(gl_time>260 && 3==flag)
	{
		Time3(STOP); //�رն�ʱ��
		gl_time = 0;
//		speedAdjustment(0,0);
//		delay_ms(1000);
		glHello_control.linkInform.findLineWays = FL_default;   
		findLineFlag = 0;
		flag = 0;
		return 1;
	}
		return 0;

}
/***********************************************ƽ̨********************************************************/

/**********************************************��㵲��*****************************************************/
/*

* �������ܣ������ж�
* �����������
* �����������
* ����ֵ  ��1������·�ϣ�0��δ����·�ϣ�
* ����		��ǰ�����û�м�⵽�ͳ���
* ����    ��@����

*/
static u8 BlockHandleMethod_Baffle()
{
	static u8 flag=0;
	if(flag == 0)
	{	
		speedAdjustment(0,0);	
				/*�������*/
		#ifdef _DJ_CONTROL_
	  sgAngleControl(HEAD,H_L);
	  delay_ms(400);
		sgAngleControl(HEAD,H_R);
		delay_ms(400);
		sgAngleControl(HEAD,H_L);
		delay_ms(400);
		sgAngleControl(HEAD,H_R);
		delay_ms(400);
		sgAngleControl(HEAD,H_MID);
		#endif
		
		#ifdef _LED_CONTROL_
		led_light(2);
		#endif
		
		flag = 1;
	 }	
	while(1==PES_H)  speedAdjustment(0,0);	
	while(0==PES_H)  speedAdjustment(0,0);	
	while(1==PES_H)  
	{
		flag=0;
		return 1;
	}
  return 0;
}

/*

* �������ܣ�����㴦����(���õ��¹�翪��+��⵲��)
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		������ƽ̨��Ѳ��
* ����    ��@����

*/
u8 BlockHandleMethod_Platform_1 ()
{
	static findLine save;
	static u8 flag=0;
	if(flag == 0&&1==BlockHandleMethod_Baffle())
	{
		//u3_printf("Baffle+NFL");
		save = glHello_control.linkInform.findLineWays;
		glHello_control.linkInform.findLineWays =NFL;
		flag = 1;
	}
	else if(1==flag&&1==PES_Platform)
	{
		//u3_printf("slow");
		glHello_control.linkInform.findLineWays = FL_DownPlatform; 
		findLineFlag = 0;
		flag=2;
	}
	else if(2==flag&&0==PES_Platform)  flag=3;
	else if(1==PES_Platform && 3==flag)
	{
		//u3_printf("finish");
		glHello_control.linkInform.findLineWays = save; 
		findLineFlag = 0;
		flag = 0;
		return 1;
	}
		return 0;
}
/**********************************************��㵲��*****************************************************/

/************************************************��ʱ********************************************************/
/*

* �������ܣ���ʱ(���ӽڵ㴦����)
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_TIME()
{
	static u8 flag=0;
	if(0==flag)
	{
		Time3(START); //�򿪶�ʱ��
		gl_time=0;
		flag=1;
	}
	if(gl_time > 50)
	{	
		Time3(STOP); //�رն�ʱ��
		gl_time = 0;
//		speedAdjustment(0,0);
//		delay_ms(500);
		flag=0;
		return 1;
	}
		
	return 0;

}

/*

* �������ܣ���ʱ(����2-5���ٰ�)
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_TIME_1()
{
	static u8 flag=0;
	if(0==flag)
	{
		Time3(START); //�򿪶�ʱ��
		gl_time=0;
		flag=1;
	}
	if(gl_time > 200)
	{	
		Time3(STOP); //�رն�ʱ��
		gl_time = 0;
		flag=0;
		return 1;
	}
		
	return 0;

}

/*

* �������ܣ���ʱ(����26-27���ٰ�)
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_TIME_2()
{
	static u8 flag=0;
	if(0==flag)
	{
		Time3(START); //�򿪶�ʱ��
		gl_time=0;
		flag=1;
	}
	if(1==flag && gl_time > 200)
	{	
		Time3(STOP); //�رն�ʱ��
		gl_time = 0;
		flag=2;
	}
	if(2==flag && 0==PES_Platform) 
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		flag=3;
	}
	if(3==flag &&1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays=FL_upPeak;
		findLineFlag = 0;
		flag=4;
	}
	if(4==flag && 0==PES_Platform) flag=5;
	if(5==flag && 1==PES_Platform) 
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		flag=0;
		return 1;
	}
		
	return 0;

}

/*

* �������ܣ���ʱ(����)
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_TIME_44_43()
{
	static u8 flag=0;
	if(0==flag)
	{
		Time3(START); //�򿪶�ʱ��
		gl_time=0;
		flag=1;
	}
	if(gl_time > 20)
	{	
		led1_flash();
		Time3(STOP); //�رն�ʱ��
		gl_time = 0;
		flag=0;
		return 1;
	}
		
	return 0;

}
/************************************************��ʱ********************************************************/

/**************************************************���ξ���**************************************************/
/*

* �������ܣ�01���ξ��㴦����
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_Trapezoid_1()
{
	static u8 flag=0;
	if(0==flag)
	{
		Time3(START);					 //�򿪶�ʱ��
		gl_time=0;
		flag = 1;
	}
	
	if(1==flag && gl_time>30)
	{
		flag = 2;
		gl_time = 0;
	}
	
	else if(2 == flag)
	{
		glHello_control.linkInform.findLineWays = FL_quickest; 
		findLineFlag = 0;
		flag = 3;
	}
	else if(3==flag && gl_time>S_TIME_6_8)  //����ʱ��
	{
		glHello_control.linkInform.findLineWays = FL_slow;
	  findLineFlag = 0;
		Time3(STOP); //�رն�ʱ��
		gl_time = 0;
		flag = 4;
	}
	else if(4==flag && 0==PES_H)
	{
		glHello_control.linkInform.findLineWays = FL_stop;
	  findLineFlag = 0;
		flag = 0;
		return 1;	
	}
	return 0;
}
	

/*

* �������ܣ�02���ξ��㴦����
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_Trapezoid_2(void)
{
	static u8 flag=0;
	if(0==flag)
	{
		Time3(START); //�򿪶�ʱ��
		gl_time=0;
		flag=1;
	}
	if(1==flag && gl_time>20)
	{
		flag = 2;
		gl_time = 0;
	}
	
	else if(2 == flag)
	{
		glHello_control.linkInform.findLineWays = FL_quickest; 
		findLineFlag = 0;
		flag = 3;	

	}
	else if(3==flag && gl_time>S_TIME_10_11)
	{
		glHello_control.linkInform.findLineWays = FL_slow;
	  findLineFlag = 0;
		Time3(STOP); //�رն�ʱ��
		gl_time = 0;
		flag = 4;
	}
	else if(4==flag && 0==PES_H)
	{
		glHello_control.linkInform.findLineWays = FL_stop;
	  findLineFlag = 0;
		flag = 0;
		return 1;	
	}
	return 0;
}


/*

* �������ܣ�05��06��07��08���ξ��㴦����
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_Trapezoid_3()
{
	static u8 flag=0;
	if(0==flag)
	{
		Time3(START); //�򿪶�ʱ��
		flag=1;
		gl_time=0;
	}
	if(gl_time > 50)
	{	
		Time3(STOP); //�رն�ʱ��
		gl_time = 0;
		flag=0;
		return 1;
	}		
	return 0;
}

/**************************************************���ξ���**************************************************/

/*****************************************************б��***************************************************/

/*

* �������ܣ�����Ƿ�ͨ��б�£������ǣ�
* �����������
* �����������
* ����ֵ  ��������
* ����		��
* ����    ��@����

*/
float CrossingTILT_ROLL()
{
	float temp;
	u8 i;
	 #ifdef _NEW_MPU6050_
	   MPU6050_Pose_usart();
	#else
	for(i=0;i<50;i++)	
		MPU6050_Pose();
	#endif				//����ŷ����
	temp=glPitch;
	return temp;
}

/*
* �������ܣ���ת��б·��·�ϴ�����
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@��| @��

*/

u8 BlockHandleMethod_GO_Tilt_R()
{
	static u8 flag=0,flag1=0;
	if(0==flag && 0==PES_Platform)  
	{
		if(0==flag1)
		{
			Time3(START);
			gl_time=0;
			flag1=1;
		}
		if(gl_time>30 &&1==flag1)
		{
			
			Time3(STOP);
			gl_time=0;
			flag=1;
			flag1=0;
		}
	}
	else if(1==flag && 1==PES_Platform)
	{	
		speedAdjustment(2000,1950);
		delay_ms(280);
		flag=2;
	}
	else if(2==flag && 0==PES_Platform)
	{
		speedAdjustment(0,0);
		delay_ms(50);
		rotAngle_UR(80);
		speedAdjustment(2000,1950);
		delay_ms(450);
		speedAdjustment(0,0);
		flag=3;
	}	
	else if(3==flag && 0==PES_Platform)
	{
		glHello_control.linkInform.findLineWays = FL_slow;
		findLineFlag = 0;
		flag=0;
		return 1;
	}
	return 0;
}
//	static u8 flag;
//	if(0==flag && 0==PES_Platform)  flag=1;
//	else if(1==flag && 1==PES_Platform)
//	{	
//		speedAdjustment(2000,2000);
//		delay_ms(280);
//		flag=2;
//	}
//	else if(2==flag && 0==PES_Platform)
//	{
//		speedAdjustment(0,0);
//		delay_ms(50);
//		rotAngle_UR(80);
//		speedAdjustment(2000,2000);
//		delay_ms(450);
//		speedAdjustment(0,0);
//		flag=3;
//	}	
//	else if(3==flag && 0==PES_Platform)
//	{
//		glHello_control.linkInform.findLineWays = FL_slow;
//		findLineFlag = 0;
//		flag=0;
//		return 1;
//	}
//	return 0;


/*
* �������ܣ���ת��б·��·�ϴ�����(ǰ��)
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@��| @��

*/
u8 BlockHandleMethod_GO_Tilt_L()
{
//	static u8 flag,flag1=0;
//	if(0==flag && 0==PES_Platform)  
//	{
//		if(0==flag1)
//		{
//			Time3(START);
//			gl_time=0;
//			flag1=1;
//		}
//		if(gl_time>30 &&1==flag1)
//		{
//			
//			Time3(STOP);
//			gl_time=0;
//			flag=1;
//			flag1=0;
//		}
//	}
//	else if(1==flag && 1==PES_Platform)
//	{	
//		speedAdjustment(2000,1950);
//		delay_ms(260);
//		flag=2;
//	}
//	else if(2==flag && 0==PES_Platform)
//	{
//		speedAdjustment(0,0);
//		delay_ms(50);
//		rotAngle_UL(90);
//		speedAdjustment(2000,2000);
//		delay_ms(450);
//		speedAdjustment(0,0);
//		flag=3;
//	}	
//	else if(3==flag && 0==PES_Platform)
//	{
//		glHello_control.linkInform.findLineWays = FL_default;
//		findLineFlag = 0;
//		flag=0;
//		return 1;
//	}
//	return 0;
	static u8 flag,flag1=0;
	if(0==flag && 0==PES_Platform)  
	{
		if(0==flag1)
		{
			Time3(START);
			gl_time=0;
			flag1=1;
		}
		if(gl_time>30 &&1==flag1)
		{
			
			Time3(STOP);
			gl_time=0;
			flag=1;
			flag1=0;
		}
	}
	else if(1==flag && 1==PES_Platform)
	{		
    Time3(START);
		gl_time=0;
		glHello_control.linkInform.findLineWays = FL_angle;
		findLineFlag = 0;
		angle_flag = 0;
		flag=2;
	}
	else if(2==flag && gl_time>12)
	{
		Time3(STOP);
		rotAngle_UL(80);
		speedAdjustment(2000,2000);
		delay_ms(450);
		speedAdjustment(0,0);
		glHello_control.linkInform.findLineWays = FL_default;
		findLineFlag = 0;
		flag=0;
		return 1;
	}	
	return 0;
}
/*
* �������ܣ���б·��·�ϴ��������أ�
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@��| @��

*/

u8 BlockHandleMethod_BACK_TILT_R()
{
  static u8 flag=0;
	if(0==flag && 0==PES_Platform)
	{		
		flag=1;
		Time3(START);
		gl_time = 0 ;
	}
	else if(1==flag && 1==PES_Platform && gl_time > 30)
	{
		Time3(STOP);
		gl_time = 0 ;
		speedAdjustment(2000,1950);
		delay_ms(580);
		//rotAngle_Right(70);
		rotAngle_UR(80);
		flag=0;
		return 1;
	}
 
	return 0;
}


/*
* �������ܣ������б·��·�ϴ��������أ�
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		����Ѳ�߷����л��ɹ��ŵ�Ѳ��
* ����    ��@��| @��

*/

u8 BlockHandleMethod_BACK_TILT_L()
{

  static u8 flag=0;
	if(0==flag && 0==PES_Platform)  flag=1;
	else if(1==flag && 1==PES_Platform)
	{
		speedAdjustment(2000,1950);
		delay_ms(600);
		//rotAngle_Right(70);
		rotAngle_UL(90);
		flag = 0 ;
		return 1;
	}
 
	return 0;
}

/*
* �������ܣ���������б��
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@��| @��

*/
u8 BlockHandleMethod_Crossing_All_TILT()
{
//	if(1 == PES_Platform)
//	{
//		speedAdjustment(2000,2000);
//		delay_ms(1000);
//		delay_ms(400);
//		return 1;
//	}
//		return 0;
//	static u8 flag;
//	if(0==flag && 0==PES_Platform)  flag=1;
//	else if(1==flag && 1==PES_Platform)
//	{	
////		speedAdjustment(0,0);
////		delay_ms(500);
//		speedAdjustment(2000,2000);
//		delay_ms(550);
//		flag=2;
//	}
//	else if(2==flag && 0==PES_Platform)
//	{
//		speedAdjustment(2000,2000);
//		delay_ms(1000);
//		flag=0;
//		return 1;
//	}
//	return 0;

	static u8 flag;
	if(0==flag && 0==PES_Platform)  
	{
    flag = 1;
	}     	
	else if(1==flag && 1==PES_Platform)
	{	
		Time3(START);	//�򿪶�ʱ��
		gl_time=0;
//		led0_flash();
//		Time3(STOP); 
		glHello_control.linkInform.findLineWays = FL_angle;
		findLineFlag = 0;
		angle_flag = 0;
 		flag = 2;
		
	}
	else if(2==flag && gl_time>120)
	{
//		led1_flash();
		glHello_control.linkInform.findLineWays = FL_slow;
		findLineFlag = 0; 
		Time3(STOP); //�رն�ʱ��

//		speedAdjustment(0,0);
//		while(1);

		flag=0;
		
		return 1;
	}
	return 0;
}
/*************************************************���**********************************************************/
/*

* �������ܣ������
* �����������
* �����������
* ����ֵ  ��1(��⵽)0��δ��⵽��
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_Peak()
{
	static u8 flag=0;
	//static findLine save;
	if(0==flag && 0==PES_Platform)
	{
	//	save=glHello_control.linkInform.findLineWays;
		flag=1;
	}
	if(1==flag && 1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays=FL_upPeak;
		findLineFlag = 0;
		flag=2;
	}
	
  if(2==flag && 0==PES_Platform) flag=3;
	if(3==flag && 1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays=NFL;
		findLineFlag = 0;
		flag=4;
	}
	if(4==flag && 0==PES_Platform) flag=5;
	if(5==flag && 1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays=FL_upPeak;
		findLineFlag = 0;
		flag=6;
	}
	if(6==flag && 0==PES_Platform) flag=7;
	if(7==flag && 1==PES_Platform)
	{
		glHello_control.linkInform.findLineWays = NFL;
		findLineFlag = 0;
		flag=0;
		return 1;
	}
	return 0;
	
	
}
/*
* �������ܣ�����巽��
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_downPlatform()
{
	static findLine save;
	static u8 flag=0;
	
	if(flag == 0)
	{
		speedAdjustment(0,0);
		delay_ms(200);
	//	DangerFlag=1;            //��Σ���źű�־λ��Ϊ1
		Time3(START);
		gl_time=0;
		save = glHello_control.linkInform.findLineWays;
		glHello_control.linkInform.findLineWays =NFL;
		flag = 1;
	}
	else if(1==flag && 1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = FL_downPeak; 
		findLineFlag = 0;
		flag=2;
	}
	else if(2==flag&&0==PES_Platform)  flag=3;
	else if(1==PES_Platform && 3==flag)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = NFL; 
		flag = 4;

	}
	else if(4==flag && 0==PES_Platform) flag=5;
	else if(5==flag && 1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = FL_downPeak; 
		findLineFlag = 0;
		flag=6;
	}
	else if(6==flag && 0==PES_Platform)	flag=7;
	else if(7==flag && 1==PES_Platform)
	{
		glHello_control.linkInform.findLineWays=save;
		findLineFlag = 0;
		flag=0;
		return 1;
	}
	else if(gl_time>600)
	{
		if(1==danger24_23())
		{
			Time3(STOP); //�رն�ʱ��
			gl_time = 0;
		}
	}
		return 0;


}

//***************************************************���ٰ�****************************************//
/*

* �������ܣ������ٰ�1(�õ��¹�翪��)
* �����������
* �����������
* ����ֵ  ��1(��⵽)0��δ��⵽��
* ����		��
* ����    ��@��

*/
u8 BlockHandleMethod_S_BOARD_1()
{
	static findLine save;
	static u8 flag=0;
	if(0==flag)
	{
		save = glHello_control.linkInform.findLineWays;
		flag = 1;
	}
	else if(1==flag&&1==PES_Platform) 
	{
		glHello_control.linkInform.findLineWays =FL_slowest;
		findLineFlag = 0;
//		speedAdjustment(0,0);
//		delay_ms(500);
		Time3(START);
		gl_time=0;
		flag=2;
	}
	else if(2==flag&&gl_time>150)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays =FL_slow;
		findLineFlag = 0;
		Time3(STOP);
		gl_time=0;
		flag=0;
		return 1;
	}
	return 0;
}

/*

* �������ܣ������ٰ�2(�õ��¹�翪��)
* �����������
* �����������
* ����ֵ  ��1(��⵽)0��δ��⵽��
* ����		��
* ����    ��@��

*/
u8 BlockHandleMethod_S_BOARD_2()
{
//	static findLine save;
	static u8 flag=0;
	if(0==flag)
	{
	//	save = glHello_control.linkInform.findLineWays;
		flag = 1;
	}
	if(1==flag&&0==PES_Platform) flag=2;
	if(2==flag&&1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays =FL_slow;
		findLineFlag = 0;
		Time3(START);
		gl_time=0;
		flag = 3;
	}
	if(3==flag&&gl_time>150)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays =FL_default;
		findLineFlag = 0;
		Time3(STOP);
		gl_time=0;
		flag=0;
		return 1;
	}
	return 0;
}

/*

* �������ܣ���˫�ؼ��ٰ�(�õ��¹�翪��)
* �����������
* �����������
* ����ֵ  ��1(��⵽)0��δ��⵽��
* ����		��
* ����    ��@��

*/
u8 BlockHandleMethod_S_BOARD_Double()
{
	static findLine save;
	static u8 flag=0;
	if(0==flag)
	{
		save = glHello_control.linkInform.findLineWays;
		flag = 1;
	}
	else if(1==flag&&1==PES_Platform) 
	{
		glHello_control.linkInform.findLineWays =FL_slowest;
		findLineFlag = 0;
//		speedAdjustment(0,0);
//		delay_ms(500);
		Time3(START);
		gl_time=0;
		flag=2;
	}
	else if(2==flag&&gl_time>280)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays =save;
		findLineFlag = 0;
		Time3(STOP);
		gl_time=0;
		flag=0;
		return 1;
	}
	return 0;
}






/*

* �������ܣ���26��27(�õ��¹�翪��)
* �����������
* �����������
* ����ֵ  ��1(��⵽)0��δ��⵽��
* ����		��
* ����    ��@��

*/
u8 BlockHandleMethod_26_27()
{
	static findLine save;
	static u8 flag=0;
	if(0==flag)
	{
		Time3(START);
		gl_time = 0;
		save = glHello_control.linkInform.findLineWays;
		flag = 1;
	}
	if(1==flag&&0==PES_Platform) flag=2;
	if(2==flag && 1==PES_Platform && gl_time > 30)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		Time3(STOP);
		gl_time = 0;
		glHello_control.linkInform.findLineWays =FL_slowest;
		findLineFlag = 0;
		Time3(START);
		gl_time=0;
		flag = 3;
	}
	if(3==flag && gl_time>150)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
//		led0_flash();
		glHello_control.linkInform.findLineWays =FL_slowest;
		findLineFlag = 0;
		Time3(STOP);
		gl_time=0;
		flag=4;
	}
	if(4==flag && 0==PES_Platform) flag=5;
	if(5==flag && 1==PES_Platform)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = FL_upPeak;
		findLineFlag = 0;
		flag=6;
	}
	if(6==flag && 0==PES_Platform) flag=7;
	if(7==flag && 1==PES_Platform) 
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		flag=0;
		return 1;
	}
	return 0;
}
/*
* �������ܣ�������43-44����ط����ұߴ������ҵ�
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@��hzihaio

*/
u8 BlockHandleMethod_PESR(void)
	{
//		static u8 flag=0;
//	if(0 == flag)
//	{
//		pes_R=0;
//	//	pesRSwitch(START);//���ж�
//		//glHello_control.linkInform.findLineWays = FL_stop;
//		flag = 1;
//	}
//	if(1==pes_R && 1==flag)
//	{	
//	//	pesRSwitch(STOP);//���ж�
//		//speedAdjustment(0,0);
//		pes_R=0;
//		flag = 0;	
//		return 1;
//	}
//		
//	return 0;
		if(1==PES_R)	return 1;
		return 0;
}

/*

* �������ܣ���ʱ(����)
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		��
* ����    ��@����

*/
u8 BlockHandleMethod_TIME_45_46()
{
	static u8 flag=0;
	if(0==flag)
	{
		Time3(START); //�򿪶�ʱ��
		gl_time=0;
		flag=1;
	}
	if(gl_time > 80)
	{	
		Time3(STOP); //�رն�ʱ��
		gl_time = 0;
		flag=0;
		#ifdef LED_Debug
		led_flash();
		#endif
		return 1;
	}
		
	return 0;

}




