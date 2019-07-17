#include "seeknodeway.h"

/*

* �������ܣ�������������1����
* ���������digital�����������������
* �����������
* ����ֵ  ��1�ĸ���
* ����    ��@����

*/

static u8 calculateNum(u16 digital)
{
	u8 i;
	u8 temp=0;
	for(i=0;i<NUM_OF_SENSOR;i++)
	{
		if(digital & (0x001<<i) )
			temp++;
	}
	return temp;
}

/*

* �������ܣ�ȱʡ�ҵ㷽��
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·����1���ĸ���Ϊ4ʱ��flag��1��
													��һ�μ�⵽��1���ĸ���Ϊ5ʱ���ж�Ϊ�˴�Ϊ�ڵ� 
* ����    ��@����

*/

u8 seekNodeMethod_default()
{
	 if(3 < calculateNum(glsensor_dig_value))
	 {
		return 1;
	 }
	 return 0;
			
}

/*

* �������ܣ���߹���ҵ㷽��(һ��Ҫ���жϣ���Ȼ�м���©��)
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·��������߹�紫�����жϽڵ�
* ����    ��@����

*/

u8 seekNodeMethod_pesL()
{
//	static u8 flag=0;
//	if(0 == flag)
//	{
//		pes_L=0;
//		//pesLSwitch(START);//���ж�
//		//glHello_control.linkInform.findLineWays = FL_stop;
//		flag = 1;
//	}
//	if(1==pes_L && 1==flag)
//	{	
//		//pesLSwitch(STOP);//���ж�
//		//speedAdjustment(0,0);
//		pes_L=0;
//		flag = 0;	
//		return 1;
//	}
//		
//	return 0;
		if(0==PES_L)
	{	
			return 1;
	}
		
	return 0;
}

/*

* �������ܣ��ұ߹���ҵ㷽��(һ��Ҫ���жϣ���Ȼ�м���©��)
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·�������ұ߹�紫�����жϽڵ�
* ����    ��@����

*/

u8 seekNodeMethod_pesR()
{
//	static u8 flag=0;
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
		if(0==PES_R)
	{	
			return 1;
	}
		
	return 0;
	
}

/*

* �������ܣ�4�ڵ��ҵ㷽��(��̨)
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·������ϵ�ƽ̨��Ϊ����ڵ�
* ����    ��@����

*/

u8 seekNodeMethod_4()
{
	static u8 flag=0;
	if(mpu6050_flag == 0 && 0==flag)
	{	
		U_Dswitch = 1;//��־�ж�������̨����
		mpu6050_samping(START);
		flag=1;
		//u3_printf("1\n");
	
	}
	
	if(mpu6050_flag == 1&&1==flag)
	{
		flag=2;
		//u3_printf("2\n");
		//sgAngleControl(R_ARM,DOWM);//���¶��	
		glHello_control.linkInform.findLineWays = NFL;
	}
	if(mpu6050_flag == 2&&flag==2)
	{
		flag=0;
		//u3_printf("3\n");
		mpu6050_flag = 0;
		U_Dswitch = 0;//����̨��������
		mpu6050_samping(STOP);
		//u3_printf ("\na %0.2f\n",glPitch-glPitchbuff[0]);
		
		//delay_ms(10);  //��֤������̨��
		return 1;
	}
	return 0;
	
}

/*

* �������ܣ��ҵ㷽��(��̨):���ù�翪����̨
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·������ϵ�ƽ̨��Ϊ����ڵ�
* ����    ��@����

*/

u8 seekNodeMethod_pesPlatform()
{
  static u8 flag=0;	
	if(flag==0)
	{
		Time7(START);
		gl_time=0;
		flag=1;
	}	
	if (1==flag&&PES_Platform==0) flag = 2;
	else if (2==flag&&1==PES_Platform&&gl_time>10) 
	{
		Time7(STOP);
		gl_time=0;
		glHello_control.linkInform.findLineWays = FL_UpPlatform;
	  findLineFlag = 0;
		flag=3;
	}
	else if(3==flag&&0==PES_Platform) 
	{
		flag=4;

	}
	else if(4==flag&&1==PES_Platform)
	{
		glHello_control.linkInform.findLineWays = NFL;
		flag=0;
		delay_ms(200);
		return 1;
	}		
	return 0;
	
}


/*

* �������ܣ�10�ڵ��ҵ㷽��
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·������ϵ�ƽ̨��Ϊ����ڵ�
* ����    ��@����

*/

u8 seekNodeMethod_10()
{
	if(calculateNum(glsensor_dig_value) > 4)
	{	
			return 1;
	}
		
	return 0;
	
}


/*

* �������ܣ�	���ξ����ҵ㷽����������ײ���⣩
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·������ϵ�ƽ̨��Ϊ����ڵ�
* ����    ��@����

*/

u8 seekNodeMethod_Collision()
{
//	if(1==Collision) return 1;
//	return 0;
  
  static u8 flag=0;
	if(0==flag && 0==PES_H)
	{
//    speedAdjustment(-0,-0);
//		delay_ms(200);
    glHello_control.linkInform.findLineWays = FL_stop;
	  findLineFlag = 0;
    
		flag = 1;
	}
	
	if(1==flag && 1==Collision)
	{
		glHello_control.linkInform.findLineWays = BACK_NFL;
	  findLineFlag = 0;
		delay_ms(200);
    flag=0;
		return 1;	
	}

	return 0;

}

/*

* �������ܣ�	���ξ����ҵ㷽����������ײ���⣩
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·������ϵ�ƽ̨��Ϊ����ڵ�
* ����    ��@����

*/

u8 seekNodeMethod_H()
{
//	if(1==Collision) return 1;
//	return 0;
	if(0==PES_H) 
	{
		speedAdjustment(-1400,-1400);
		delay_ms(200);
		return 1;	
	}
	return 0;

}
/*

* �������ܣ����ΰ��ҵ㣨���������翪�⣩
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·������ϵ�ƽ̨��Ϊ����ڵ�
* ����    ��@��

*/

u8 seekNodeMethod_SeeSaw()
{
  int err,speed;
	static u8 flag=0;
	if(flag==0)
	{
	    Time7(START);
      gl_time=0;
		  glHello_control.linkInform.findLineWays =FL_left; 
		  findLineFlag = 0;
		flag=1;
	}
	
	if(flag==1 && gl_time>25)
	{
	    glHello_control.linkInform.findLineWays =FL_16_44; 
		  findLineFlag = 0;
		  flag=2; 
	}
	if(1==PES_Platform && flag==2) 
	 {
			speedAdjustment(0,0);
			delay_ms(200);
			PID_Init(&glrotAnglePID,0,0,0,0,0);//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
			err=errCalculation(glYaw,angle_read);
			if(err<0)err=-err;
			while(err > 2)
			{
				MPU6050_Pose_usart();
				err = errCalculation(glYaw,angle_read);
				if(err<0)err=-err;
				speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
				speedAdjustment(0,speed+2500);
			}
			angle_read = 0;
			flag = 0;
	//		speedAdjustment(0,0);
	//		while(1);
			return 1;
		}
		
	return 0;
}

/*

* �������ܣ�������������ҵ�
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·�����������ҵ�Ϊ1ʱΪ�ҵ���
* ����    ��@Ԭ����

*/

u8 seekNodeMethod_digL()
{
	if(glsensor_dig_value&0x800)
	{
		return 1;
	}
	return 0;		
}

/*

* �������ܣ����������ұ��ҵ�
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·�����������ҵ�Ϊ1ʱΪ�ҵ���
* ����    ��@Ԭ����

*/

u8 seekNodeMethod_digR()
{
	if(glsensor_dig_value&0x001)
	{
		return 1;
	}
	return 0;	
}

/*

* �������ܣ����ΰ��ȥ�ҵ㣨���������翪�⣩
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·������ϵ�ƽ̨��Ϊ����ڵ�
* ����    ��@Ԭ����

*/

u8 seekNodeMethod_SeeSaw_back()
{

//	if(1==PES_Platform) 
//	{
//		speedAdjustment(0,0);	
//		delay_ms(200);
//		speedAdjustment(0,1900);
//		delay_ms(350);
//		return 1;
//	}
//		
//	return 0;
	    int err,speed;
		if(1==PES_Platform) 
	   {
		speedAdjustment(0,0);
		delay_ms(200);
		PID_Init(&glrotAnglePID,0,0,0,0,0);//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
		err=errCalculation(glYaw,angle_read_back);
		if(err<0)err=-err;
		while(err > 2)
		{
			#ifdef _NEW_MPU6050_
			MPU6050_Pose_usart();
			#else 
			for(int i=0;i<50;i++) MPU6050_Pose();
			#endif
		    err = errCalculation(glYaw,angle_read_back);
		    if(err<0)err=-err;
		
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(0,speed+2500);
		}
//		speedAdjustment(0,0);
//		while(1);
		return 1;
	}
		
	return 0;
}


/*

* �������ܣ����ΰ��ҵ㣨���������翪�⣩
* ���������
* ���������
* ����ֵ  ��1(�ҵ��ڵ�)0��û���ҵ��ڵ㣩
* ����		���ҵ㷽��˼·������ϵ�ƽ̨��Ϊ����ڵ�
* ����    ��@��

*/

u8 seekNodeMethod_SeeSaw_2019()
{

//	if(1==PES_Platform) 
//	{
//		speedAdjustment(0,0);	
//		delay_ms(200);
//		speedAdjustment(0,1900);
//		delay_ms(350);
//		return 1;
//	}
//		
//	return 0;
	    int err,speed;
		if(1==PES_Platform) 
	   {
		speedAdjustment(0,0);
		delay_ms(200);
		PID_Init(&glrotAnglePID,0,0,0,0,0);//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
		err=errCalculation(glYaw,angle_read);
		if(err<0)err=-err;
		while(err > 2)
		{
			#ifdef _NEW_MPU6050_
			MPU6050_Pose_usart();
			#else 
			for(int i=0;i<50;i++) MPU6050_Pose();
			#endif
		    err = errCalculation(glYaw,angle_read);
		    if(err<0)err=-err;
		
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(0,speed+2500);
		}
//		speedAdjustment(0,0);
//		while(1);
		return 1;
	}
		
	return 0;
}





