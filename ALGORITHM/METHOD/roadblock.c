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
}
/************************************************��***********************************************************/

/***************************************************��********************************************************/
/*

* �������ܣ����Ŵ�����������״̬����Ҫײ��
* �����������
* �����������
* ����ֵ  ��1(�ſ����߸�������·)0���Ź���û�и�����·��
* ����		��
* ����    ��@��

*/
u8 BlockHandleMethod_DOOR(void)
{
	static u8 flag=0;     

	DoorFlag=1;
	if(0==flag)
	{
		Time7(START);
		gl_time=0;
		flag=1;
	}
	if(1==flag && 0 == PES_H)
	{
		rotAngle_Right(180);
		runMethodUpdate(runMethod,DoorFlag_2,runMethodTableDoorAuto);   
		if(1 == DoorFlag_2)
		{
			DoorFlag_2=2;
		}
		if(0 == DoorFlag_2)
		{
			DoorFlag_2=1;
		}
		Control_Init(&glHello_control,runMethod);     //��ʼ������̨
		runStateInit(&glrunState,&glHello_control);		//���ݿ���̨��ʼ·�γ�ʼ������״̬
		flag=0;
		return 1;
	}
	if(1==flag && gl_time>Door_Time)
	{
		Time7(STOP);
		gl_time = 0;
//		led1_flash();
		glHello_control.linkInform.findLineWays = FL_default;  //�л���ȱʡѲ��
		findLineFlag = 0;
		flag=0;
		return 1;
	}
	return 0;
}

/*

* �������ܣ����Ŵ�����������״̬��Ҫײ��
* �����������
* �����������
* ����ֵ  ��1(�ſ����߸�������·)0���Ź���û�и�����·��
* ����		��
* ����    ��@panshao

*/
u8 BlockHandleMethod_DOOR_Click(void)
{
	static u8 flag =0;
	DoorFlag = 1;
	if(0==flag && 0 == PES_H)
	{
		glHello_control.linkInform.findLineWays = FL_stop;
		findLineFlag = 0;
		flag = 1;
	}
	if(1==flag && 1==Collision)
	{
		speedAdjustment(-1500,-1500);
		delay_ms(200);
		speedAdjustment(0,0);
		delay_ms(1000);
//		Time7(START);
//		gl_time = 0;
		flag = 2;
	}
	if(2==flag && 0==PES_H)	//��δ��ײ��
	{
//		Time7(STOP);
//		gl_time = 0;
//		speedAdjustment(-1500,-1500);
//		
//		delay_ms(200);
		rotAngle_Right(180);
		runMethodUpdate(runMethod,DoorFlag_2,runMethodTableDoorAuto); 
		if(1 == DoorFlag_2)
		{
			DoorFlag_2=2;
		}
		if(0 == DoorFlag_2)
		{
			DoorFlag_2=1;
		}
		Control_Init(&glHello_control,runMethod);     //��ʼ������̨
		runStateInit(&glrunState,&glHello_control);		//���ݿ���̨��ʼ·�γ�ʼ������״̬
		flag=0;
		return 1;
	}
	if(2==flag && 1==PES_H)	//�ű�ײ��
	{
//		Time7(STOP);
//		gl_time = 0;
//		led1_flash();
		glHello_control.linkInform.findLineWays = FL_default;  //�л���ȱʡѲ��
		findLineFlag = 0;
		flag=0;
		return 1;
	}
	return 0;
}





/***************************************************��********************************************************/

/**************************************************ƽ̨********************************************************/
/*

* �������ܣ���27��26
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
		findLineFlag = 0;
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
		Time7(START); //�򿪶�ʱ��
		gl_time=0;
		flag=6;
	}
	else if(6==flag && gl_time>200)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = save; 
		findLineFlag = 0;
		Time7(STOP); //�򿪶�ʱ��
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
	  Time7(START);
		gl_time = 0;
		flag = 1;
	}
	else if(flag == 1 && gl_time>80)
	{
		Time7(STOP);
//		speedAdjustment(0,0);
//		while(1);
		MPU6050_Pose_usart();
		angle_read = setYaw(glYaw,94);
		angle_read_back = setYaw(glYaw,-78);		
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
		Time7(START);
		gl_time=0;
		glHello_control.linkInform.findLineWays = FL_angle;
    angle_flag = 0; 		
		findLineFlag = 0;
//		led0_flash();
		flag=1;
	}
	else if(1==flag&&gl_time>80)         
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
		Time7(STOP);
		speedAdjustment(0,0);
		delay_ms(500);	
//		led0_flash();
//		while(1);
		temp = Monitor_ROLL();
		glHello_control.linkInform.findLineWays = FL_slow;
		findLineFlag = 0;
		if(temp>-10)
		{
			speedAdjustment(1690,1800);
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
		findLineFlag = 0;
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



/*

* �������ܣ�����ɽ����
* �����������
* �����������
* ����ֵ  ��1(·�Ͻ��)0��·��δ�����
* ����		����
* ����    ��panshao

*/
u8 BlockHandleMethod_Sword ()
{
	if(calculateNum(glsensor_dig_value) == 0)
	{
		speedAdjustment(1310,2500);
		delay_ms(300);
		glHello_control.linkInform.findLineWays = FL_default;   
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
		Time7(START); //�򿪶�ʱ��
		gl_time=0;
		flag=3;
	}
	else if(gl_time>260 && 3==flag)
	{
		Time7(STOP); //�رն�ʱ��
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
		findLineFlag = 0;
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
			Time7(START);
			gl_time=0;
			flag1=1;
		}
		if(gl_time>30 &&1==flag1)
		{
			
			Time7(STOP);
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

	static u8 flag,flag1=0;
	if(0==flag && 0==PES_Platform)  
	{
		if(0==flag1)
		{
			Time7(START);
			gl_time=0;
			flag1=1;
		}
		if(gl_time>30 &&1==flag1)
		{
			
			Time7(STOP);
			gl_time=0;
			flag=1;
			flag1=0;
		}
	}
	else if(1==flag && 1==PES_Platform)
	{		
    Time7(START);
		gl_time=0;
		glHello_control.linkInform.findLineWays = FL_angle;
		findLineFlag = 0;
		angle_flag = 0;
		flag=2;
	}
	else if(2==flag && gl_time>12)
	{
		Time7(STOP);
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
		Time7(START);
		gl_time = 0 ;
	}
	else if(1==flag && 1==PES_Platform && gl_time > 30)
	{
		Time7(STOP);
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
	static u8 flag;
	if(0==flag && 0==PES_Platform)  
	{
    flag = 1;
	}     	
	else if(1==flag && 1==PES_Platform)
	{	
		Time7(START);	//�򿪶�ʱ��
		gl_time=0;
//		led0_flash();
//		Time7(STOP); 
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
		Time7(STOP); //�رն�ʱ��

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
		Time7(START);
		gl_time=0;
		save = glHello_control.linkInform.findLineWays;
		glHello_control.linkInform.findLineWays =NFL;
		findLineFlag = 0;
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
		findLineFlag = 0;
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
			Time7(STOP); //�رն�ʱ��
			gl_time = 0;
		}
	}
		return 0;


}

//***************************************************���ٰ�****************************************//
/*

* �������ܣ������ٰ�1��(�õ��¹�翪��)
* �����������
* �����������
* ����ֵ  ��1(��⵽)0��δ��⵽��
* ����		��
* ����    ��@��

*/
u8 BlockHandleMethod_S_BOARD()
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
		Time7(START);
		gl_time=0;
		flag=2;
	}
	else if(2==flag&&gl_time>150)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays =FL_slow;
		findLineFlag = 0;
		Time7(STOP);
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
* ����    ��panshao

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
		Time7(START);
		gl_time=0;
		flag=2;
	}
	else if(2==flag&&gl_time>280)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays =save;
		findLineFlag = 0;
		Time7(STOP);
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
		Time7(START);
		gl_time = 0;
		save = glHello_control.linkInform.findLineWays;
		flag = 1;
	}
	if(1==flag&&0==PES_Platform) flag=2;
	if(2==flag && 1==PES_Platform && gl_time > 30)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		Time7(STOP);
		gl_time = 0;
		glHello_control.linkInform.findLineWays =FL_slowest;
		findLineFlag = 0;
		Time7(START);
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
		Time7(STOP);
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
		glHello_control.linkInform.findLineWays =save;
		findLineFlag = 0;
		flag=0;
		return 1;
	}
	return 0;
}



