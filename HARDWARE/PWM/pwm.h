#ifndef __PWM_H
#define __PWM_H

#include "sys.h"
/*记录当前左右电机的速度*/
typedef struct{
	
	int leftSpeed;
	int rightSpeed;
	
}motorSpeedTypeDef;

/*舵机编号*/
typedef enum {HEAD,BODY,L_ARM,R_ARM}SgNumber;

/*舵机转过角度*/
typedef enum {L_UP = 800,L_DOWN = 450,R_DOWN = 310,R_UP = 700,H_MID = 660,H_L=800,H_R=360,B_UP=150,B_DOWN=450}RotationAngle;

void motor_PWM_Init(void);
void speedAdjustment(int lspeed,int rspeed);
void incrementalSpeedOut(motorSpeedTypeDef *p,int dSpeed);
void speedRec_Init(motorSpeedTypeDef *speedRegulator,int leftSpeed,int rightSpeed);
void positionSpeedOut(int leftSpeed,int rightSpeed,int dSpeed);
void sg_PWM_Init(void);
void sgAngleControl(SgNumber num,RotationAngle angle);


#endif

