#include "danger.h"
#include "myconfig.h"

u8 danger24_23(void)
{
	int err;
	speedAdjustment(0,0);
	delay_ms(1000);
	speedAdjustment(-1800,-1800);
	delay_ms(350);
		speedAdjustment(0,0);
		delay_ms(200);	   
		PID_Init(&glrotAnglePID,0,0,0,0,0);//对转弯PID的参数进行初始化设置，旋转PID直接传误差值
		err=errCalculation(glYaw,peak_angle);
		if(err<0)
		{
			err=-err;
	  	while(err > 2)
	  	{
		  	#ifdef _NEW_MPU6050_
		  	MPU6050_Pose_usart();
		  	#else 
		  	for(int i=0;i<50;i++) MPU6050_Pose();
		  	#endif
		    err = errCalculation(glYaw,peak_angle);
		    if(err<0)err=-err;	
	     // speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //速度位置式PID输出,直接传入误差参数
	      rotAngle_Right(7);
	  		delay_ms(2000);
	  	}
		}
		else
		{
			while(err > 2)
	  	{
		  	#ifdef _NEW_MPU6050_
		  	MPU6050_Pose_usart();
		  	#else 
		  	for(int i=0;i<50;i++) MPU6050_Pose();
		  	#endif
		    err = errCalculation(glYaw,peak_angle);
		    if(err<0)err=-err;	
	     // speed=positionPIDCalc_rotAngle(&glrotAnglePID,err); //速度位置式PID输出,直接传入误差参数
	      rotAngle_Left(7);
	  		delay_ms(2000);
			}
		}
	return 1;
}



