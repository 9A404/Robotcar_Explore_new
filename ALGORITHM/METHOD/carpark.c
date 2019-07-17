#include "carpark.h"

/*

* �������ܣ�Ĭ��ͣ������
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_default()
{
	delay_ms(510);
	return 1;	
}


/*

* �������ܣ���߹�紫����ͣ������(����ת����)
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_pesL_back()
{
	static u8 flag=0;
	if(flag ==0)
	{
		/*��ת����ɲ��*/
		speedAdjustment(-3500,-3500);
		delay_ms(20);
		glHello_control.linkInform.findLineWays = FL_stop;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_L && 1==flag)
	{	
		/*ͣ��*/
		speedAdjustment(-2000,-2000);
		delay_ms(40);
		speedAdjustment(0,0);
		flag = 0;
		delay_ms(40);		
		//delay_ms(1000);
		//delay_ms(1000);
		return 1;
	}
	
	return 0;	
}


/*

* �������ܣ��ұ߹�紫����ͣ������������ת���٣�
* ���������
* ���������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_pesR_back()
{
	static u8 flag=0;
	if(flag ==0)
	{	
		/*��ת����ɲ��*/
		speedAdjustment(-3500,-3500);
		delay_ms(20);
		glHello_control.linkInform.findLineWays = FL_stop;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_R && 1==flag)
	{
		/*ͣ��*/
		speedAdjustment(-3500,-3500); 
		delay_ms(15);
		speedAdjustment(0,0);
		flag = 0;
		return 1 ;
	}
	
	return 0;	
}







/*
* �������ܣ���߹�紫����ͣ������(����ת����)
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_pesL()
{
	static u8 flag=0;
	if(flag ==0)
	{
		glHello_control.linkInform.findLineWays = FL_stop;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_L && 1==flag)
	{	
//		speedAdjustment(-2000,-2000); 
//		delay_ms(15);
		
		flag = 0;
			
		return 1;
	}
	
	return 0;	
}




/*

* �������ܣ��ұ߹�紫����ͣ������(����ת����)
* ���������
* ���������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_pesR()
{
	static u8 flag=0;
	if(flag ==0)
	{	
		glHello_control.linkInform.findLineWays = FL_stop;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_R && 1==flag)
	{
//		speedAdjustment(-2000,-2000); 
//		delay_ms(15);
		flag = 0;
		return 1 ;
	}
	
	return 0;	
}

/*

* �������ܣ�
* ���������
* ���������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_stop()
{
		speedAdjustment(-2000,-2000);
		delay_ms(10);
		return 1 ;
}



/*

* �������ܣ���߹�紫������ʱͣ������
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/
u8 parkMethod_pesL_Delay(int time)
{
	static u8 flag=0;
	if(flag ==0)
	{
		glHello_control.linkInform.findLineWays = FL_stop;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_L && 1==flag)
	{	
		glHello_control.linkInform.findLineWays = NFL;
		findLineFlag = 0; 
		delay_ms(time);
		flag = 0;
		return 1 ;
	}
	
	return 0;	
}

/*

* �������ܣ��ұ߹�紫����ʱͣ������
* ���������
* ���������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/
u8 parkMethod_pesR_Delay(int time)
{
	static u8 flag=0;
	if(flag ==0)
	{	
		glHello_control.linkInform.findLineWays = FL_stop;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_R && 1==flag)
	{
		glHello_control.linkInform.findLineWays = NFL;
		findLineFlag = 0; 
		delay_ms(time);
		flag = 0;
		return 1 ;
	}
	
	return 0;	
}



/*

* �������ܣ���ͣ������
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_Door()
{
	speedAdjustment(0,0);
//	delay_ms(270);
	return 1;	
}



/*

* �������ܣ�ƽ̨ͣ������
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_pesPlatform()
{
	static u8 flag=0;
	if(0==flag)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = NFL;
		flag=1;
	}
	if(1==flag&&0==PES_H)
	{
//		speedAdjustment(0,0);
//		delay_ms(500);
		glHello_control.linkInform.findLineWays = NFL_slow;
		flag=2;
	}
	if(2==flag&&1==Collision)
	{
		flag=3;
	}
	else if(3==flag)
	{
		speedAdjustment(-1400,-1400);
		delay_ms(200);
		speedAdjustment(0,0);
		#ifdef _DJ_CONTROL_ //��������
			sgAngleControl(L_ARM,L_UP);
			delay_ms(200);
			sgAngleControl(L_ARM,L_DOWN);
			sgAngleControl(R_ARM,R_UP);
			delay_ms(200);
			sgAngleControl(R_ARM,R_DOWN);
			delay_ms(200);
		#endif
		#ifdef _LED_CONTROL_ //��������
			led_light(2);
		#endif
		flag=0;
		return 1;
	}
	return 0;

}
/*

* �������ܣ���߹�紫����45��ͣ������
* �����������
* �����������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_pesL_45()
{
	static u8 flag=0;
	if(flag ==0)
	{
		/*��ת����ɲ��*/
		speedAdjustment(-3500,-3500);
		delay_ms(20);
		glHello_control.linkInform.findLineWays = FL_stop;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_L && 1==flag)
	{	
		/*ͣ��*/
		speedAdjustment(2000,2000);
		delay_ms(150);
		speedAdjustment(0,0);
		flag = 0;
		delay_ms(40);		
		//delay_ms(1000);
		//delay_ms(1000);
		return 1;
	}
	
	return 0;	
}
/*

* �������ܣ��ұ߹�紫����45��ͣ������
* ���������
* ���������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_pesR_45()
{
	static u8 flag=0;
	if(flag ==0)
	{	
		/*��ת����ɲ��*/
		speedAdjustment(-3500,-3500);
		delay_ms(20);
		glHello_control.linkInform.findLineWays = FL_stop;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_R && 1==flag)
	{
		/*ͣ��*/
		speedAdjustment(2000,2000);
		delay_ms(150);
		speedAdjustment(0,0);
		flag = 0;
		return 1 ;
	}
	
	return 0;	
}
/*

* �������ܣ��ұ߹�紫����ǰ��û����ͣ������
* ���������
* ���������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_pesR_noline()
{
	static u8 flag=0;
	if(flag ==0)
	{	
//		/*��ת����ɲ��*/
//		speedAdjustment(-3500,-3500);
//		delay_ms(20);
		glHello_control.linkInform.findLineWays = NFL;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_R && 1==flag)
	{
		/*ͣ��*/
		speedAdjustment(-3500,-3500); 
		delay_ms(15);
//		speedAdjustment(0,0);
		flag = 0;
		return 1 ;
	}
	
	return 0;	
}
/*

* �������ܣ���߹�紫����ǰ��û����ͣ������
* ���������
* ���������
* ����ֵ  ��1(���)0��δ��ɣ�
* ����		��
* ����    ��@����

*/

u8 parkMethod_pesL_noline()
{
	static u8 flag=0;
	if(flag ==0)
	{	
//		/*��ת����ɲ��*/
//		speedAdjustment(-3500,-3500);
//		delay_ms(20);
		glHello_control.linkInform.findLineWays = NFL;
		findLineFlag = 0;
		flag = 1;
	}
	if(0==PES_L && 1==flag)
	{
		/*ͣ��*/
		speedAdjustment(-3500,-3500); 
		delay_ms(15);
//		speedAdjustment(0,0);
		flag = 0;
		return 1 ;
	}
	
	return 0;	
}





