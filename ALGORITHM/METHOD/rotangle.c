#include "rotangle.h"


/*

* �������ܣ������ƫ�����趨ֵ
* ���������curYaw(��ǰƫ����) rad��ת���ǶȲ(+)������ת����-��������ת
* ����������趨ֵ
* ����ֵ  ��
* ����    ��@λʤ

*/
float setYaw(float curYaw,float rad)
{
	float temp;
	rad = -rad;
	if(curYaw + rad < -180)
			temp = 180+rad+(180+curYaw);
	else if(curYaw + rad > 180)
			temp = -180+rad-(180-curYaw);
	else
			temp = curYaw + rad;
//	/*��ת���趨ֵ������������(rad>0.0) && (temp>0.0)*/
//	if((temp>0)&&(rad<0))		
//		temp= temp - 360;	
//	/*��ת���趨ֵ���ڸ�������*/
//	else if((temp<0) && (rad>0))  
//		temp = temp+360;
	
	return(temp);
}

/*

* �������ܣ���ǰֵ���趨ֵ��������
* ���������curYaw����ǰ��ƫ���ǣ�setYaw���趨��ƫ���ǣ�
* �����������
* ����ֵ  ��err(��ǰֵ���趨ֵ��ƫ��)
* ����    ������ת��ƫ����㷽����ͬ
* ����    ��@����

*/

float  errCalculation(float curYaw,float setYaw)
{
	float err;
	err = setYaw - curYaw;
	if(err>180)err = err-360; 
  else if(err<-180)err =err+360;
  
	return err;
			
}


/*

* �������ܣ�������ת����ǶȺ�����0-180��
* ���������angle����ת�Ƕȣ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��@����

*/
u8 rotAngle_Right(float angle)
{
	int err,speed;
	float set;
	u8 i;
	//sgAngleControl(R_ARM,UP);//������
	speedAdjustment(0,0);
	#ifdef _NEW_MPU6050_
	MPU6050_Pose_usart();
	#else
	for(i=0;i<50;i++)	
		MPU6050_Pose();
	#endif
	set = setYaw(glYaw,angle);

	err=errCalculation(glYaw,set);
	if(err<0)err=-err;
	#ifdef _NEW_MPU6050_
	PID_Init(&glrotAnglePID,0,4000,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{
		MPU6050_Pose_usart();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(speed+1000,-speed-1000);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#else
	PID_Init(&glrotAnglePID,0,4200,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{ 
		for(i=0;i<50;i++)
		MPU6050_Pose();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(speed+1000,-speed-1000);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#endif
	speedAdjustment(0,0);
	return 1;
}


/*

* �������ܣ�������ת����ǶȺ�����0-180��
* ���������angle����ת�Ƕȣ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��@����

*/
u8 rotAngle_Left(float angle)
{
	int err,speed;
	float set;
	u8 i;
	//sgAngleControl(R_ARM,UP);//������
	speedAdjustment(0,0);
	#ifdef _NEW_MPU6050_
	MPU6050_Pose_usart();
	#else
	for(i=0;i<50;i++)	
		MPU6050_Pose();
	#endif
	set = setYaw(glYaw,-angle);
	
	err=errCalculation(glYaw,set);
	if(err<0)err=-err;
	
    #ifdef _NEW_MPU6050_
	PID_Init(&glrotAnglePID,0,4000,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{
		MPU6050_Pose_usart();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(-speed-1000,speed+1000);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#else
	PID_Init(&glrotAnglePID,0,4200,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{ 
		for(i=0;i<50;i++)
		MPU6050_Pose();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(speed+1000,-speed-1000);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#endif
	speedAdjustment(0,0);
	return 1;
}
/*

* �������ܣ�������ת����ǶȺ�����0-180��
* ���������angle����ת�Ƕȣ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��@����

*/
u8 rotAngle_Right_F(float angle)
{
	int err,speed;
	float set;
	u8 i;
	//sgAngleControl(R_ARM,UP);//������
	speedAdjustment(0,0);
	#ifdef _NEW_MPU6050_
	MPU6050_Pose_usart();
	#else
	for(i=0;i<50;i++)	
		MPU6050_Pose();
	#endif
	set = setYaw(glYaw,angle);

	err=errCalculation(glYaw,set);
	if(err<0)err=-err;
	#ifdef _NEW_MPU6050_
	PID_Init(&glrotAnglePID,0,4700,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{
		MPU6050_Pose_usart();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(speed+1200,-speed-1200);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#else
	PID_Init(&glrotAnglePID,0,4200,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{ 
		for(i=0;i<50;i++)
		MPU6050_Pose();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(speed+1000,-speed-1000);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#endif
	speedAdjustment(0,0);
	return 1;
}


/*

* �������ܣ�������ת����ǶȺ�����0-180��
* ���������angle����ת�Ƕȣ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��@����

*/
u8 rotAngle_Left_F(float angle)
{
	int err,speed;
	float set;
	u8 i;
	//sgAngleControl(R_ARM,UP);//������
	speedAdjustment(0,0);
	#ifdef _NEW_MPU6050_
	MPU6050_Pose_usart();
	#else
	for(i=0;i<50;i++)	
		MPU6050_Pose();
	#endif
	set = setYaw(glYaw,-angle);
	
	err=errCalculation(glYaw,set);
	if(err<0)err=-err;
	
    #ifdef _NEW_MPU6050_
	PID_Init(&glrotAnglePID,0,4700,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{
		MPU6050_Pose_usart();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(-speed-1200,speed+1200);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#else
	PID_Init(&glrotAnglePID,0,4200,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{ 
		for(i=0;i<50;i++)
		MPU6050_Pose();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(speed+1000,-speed-1000);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#endif
	speedAdjustment(0,0);
	return 1;
}
/*

* �������ܣ����ҹ�35�Ƕ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��@����

*/
u8 rotAngleMethod_R35()
{
	speedAdjustment(2000,-2000);
	delay_ms(210);
	speedAdjustment(0,0);
	return 1;

}

/*

* �������ܣ����ҹ�90�Ƕ�
* �����������
* ����ֵ  ����
* ����    ����ת������ʮ��·�ڲ���ת
* ����    ��@����

*/
u8 rotAngleMethod_R90()
{
	static u8 flag=0;
	static u8 times=0;
	int rank;
	if(1==sampingStatus())
	{
		glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  		//����ֵ�ȽϺ�ģ����ת����������
		if(flag!=2 && flag!=3)
		{
			speedAdjustment(4000,-4000);
		}
		if((0x000==glsensor_dig_value)&&(flag==0))
		{
			flag=1; 
		}
	  if((flag==1)&&(calculateNum(glsensor_dig_value)!=0))
		{
			flag=2;
		}
	  if(2 == flag|3 == flag)
		{
			if(2 == flag)
			{
				PID_Init(&glsensorPID,22,8000,500,0,0);																					//���ٶ�PID�Ĳ������г�ʼ������
				speedRec_Init(&glmotorSpeed,0,0);
				flag = 3;
			}
			rank=sensorDigitalRank_HR90(glsensor_dig_value);		//�ּ�
			gldSpeed=positionPIDCalc(&glsensorPID,rank);   			//�ٶ�λ��ʽPID���
			positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�
		//sensorBit_u3printf(glsensor_dig_value);//����3��λ���������
		//u3_printf("ds:%d  ",gldSpeed);//����3���������
		if(rank==22)
		{
			times++;
			if(times>2)
			{
				flag=0;
				times=0;
				speedAdjustment(0,0);
				return 1;
			}
		}
			
		}
	}
	return 0;
}


/*

* �������ܣ����Ѳ��
* �����������
* ����ֵ  ����
* ����    ��
* ����    ��@����

*/
u8 rotAngleMethod_LFL()
{
	static u8 flag=0;
	if(((glsensor_dig_value&0x200)||(glsensor_dig_value&0x800)||(glsensor_dig_value&0x400)) && (0==flag))
		flag=1;
	
	if(flag==1)
	{
		glHello_control.linkInform.findLineWays =FL_left; 
		findLineFlag = 0;
		flag=2;
	}
	if((2==flag) && (glsensor_dig_value&0x001))
	{
		flag = 3;
		
	}
	if(3==flag && 0==(glsensor_dig_value&0x001))
	{
		flag = 0;
		return 1;
	}
	
	return 0;
}

/*

* �������ܣ��ҹ�Ѳ��
* �����������
* ����ֵ  ����
* ����    ��
* ����    ��@����

*/
u8 rotAngleMethod_RFL()
{
	static u8 flag=0;
	if((glsensor_dig_value&0x002) && (0==flag))
		flag=1;
	if(flag==1)
	{
		glHello_control.linkInform.findLineWays =FL_Right; 
		findLineFlag = 0;
		flag=2;
	}
	if((2==flag) && (glsensor_dig_value&0xf00))
	{
		flag = 3;
		
	}
	if(3==flag && 0==(glsensor_dig_value&0xf00))
	{
		flag = 0;
		return 1;
	}
	
	return 0;
}



/*

* �������ܣ����ҵ�����ת����ǶȺ�����0-180��
* ���������angle����ת�Ƕȣ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��@����

*/
u8 rotAngle_UR(float angle)
{
	int err,speed;
	float set;
	u8 i;
	//sgAngleControl(R_ARM,UP);//������
	speedAdjustment(0,0);
	#ifdef _NEW_MPU6050_
	MPU6050_Pose_usart();
	#else
	for(i=0;i<50;i++)	
		MPU6050_Pose();
	#endif
	set = setYaw(glYaw,-angle);
	
	err=errCalculation(glYaw,set);
	if(err<0)err=-err;
	
    #ifdef _NEW_MPU6050_
	PID_Init(&glrotAnglePID,0,4700,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{
		MPU6050_Pose_usart();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(-speed,speed+2400);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#else
	PID_Init(&glrotAnglePID,0,4200,60,0,160);																	//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ
	while(err > 5)
	{ 
		for(i=0;i<50;i++)
		MPU6050_Pose();
		err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		//speed = 4500-(3500/angle)*(angle-err);
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(speed+1000,-speed-1000);
		//u3_printf("glYaw:%0.2f err:%d\n",glYaw,err);
	}
	#endif
	speedAdjustment(0,0);
	return 1;
}


/*

* �������ܣ����󵥱���ת����ǶȺ�����0-180��
* ���������angle����ת�Ƕȣ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��@����

*/
u8 rotAngle_UL(float angle)
{
	int err,speed;
	float set;
	u8 i;
	//speedAdjustment(-1000,-1000);
    #ifdef _NEW_MPU6050_
	   MPU6050_Pose_usart();
	#else
	for(i=0;i<50;i++)	
		MPU6050_Pose();
	#endif
	set = setYaw(glYaw,-angle);
	
	err=errCalculation(glYaw,set);
	if(err<0)err=-err;
	
	PID_Init(&glrotAnglePID,0,3500,0,0,0);//��ת��PID�Ĳ������г�ʼ�����ã���תPIDֱ�Ӵ����ֵ

	while(err>5)
	{
    #ifdef _NEW_MPU6050_
			MPU6050_Pose_usart();
		#else
			for(i=0;i<50;i++)	
			MPU6050_Pose();
		#endif
			err = errCalculation(glYaw,set);
		if(err<0)err=-err;
		
		speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //�ٶ�λ��ʽPID���,ֱ�Ӵ���������
		speedAdjustment(0,speed+2500);
		
	}
	
	return 1;
}
/*

* �������ܣ�����ת����������ɲ����_����ʮ��·�ڣ�
* ���������angle����ת�Ƕȣ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��λʤ

*/
u8 rotAngle_UR_crossroad()
{
	  static u8 flag;
    speedAdjustment(2800,-1800);
	   
	  if((glsensor_dig_value&0x040||glsensor_dig_value&0x020) && flag == 0)
		{
      speedAdjustment(2800,-1800);
		}
		else 
			flag=1;
			
//	   delay_ms(140);
	   if((glsensor_dig_value&0x020||glsensor_dig_value&0x040||glsensor_dig_value&0x010)&&flag == 1)
		 { 
//			 speedAdjustment(0,0);
			 flag = 0;
			 return 1;
		 }
			 
     return 0;
}

/*

* �������ܣ�����ת����������ɲ����_����ʮ��·�ڣ�
* ���������angle����ת�Ƕȣ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��λʤ

*/
u8 rotAngle_UL_crossroad()
{
	   static u8 flag;
     speedAdjustment(-1800,2800);
	   
	  if((glsensor_dig_value&0x010||glsensor_dig_value&0x040)&&flag == 0)
		{
      speedAdjustment(-1800,2800);
		}
		else flag=1;
			
//	   delay_ms(140);
	   if((glsensor_dig_value&0x020||glsensor_dig_value&0x040||glsensor_dig_value&0x010)&&flag == 1)
		 { 
//			 speedAdjustment(0,0);
			 flag = 0;
			 return 1;
		}
			 
     return 0;
}


/*********************************************��ת����*********************************************************/
/*

* �������ܣ������35�Ƕ�
* �����������
* ����ֵ  ����
* ����    ����
* ����    ��@����

*/
u8 rotAngleMethod_L35()
{
	speedAdjustment(-2000,2000);
	delay_ms(210);
	speedAdjustment(0,0);
	return 1;

}


