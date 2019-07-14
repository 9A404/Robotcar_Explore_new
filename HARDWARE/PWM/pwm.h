#ifndef __PWM_H
#define __PWM_H

#include "sys.h"
/*��¼��ǰ���ҵ�����ٶ�*/
typedef struct{
	
	int leftSpeed;
	int rightSpeed;
	
}motorSpeedTypeDef;

/*������*/
typedef enum {HEAD , L_ARM , R_ARM}SgNumber;

/*���ת���Ƕ�*/
typedef enum {L_UP = 450,L_DOWN = 700,R_DOWN = 310,R_UP = 600,H_MID = 660,H_L=960,H_R=360}RotationAngle;

void motor_PWM_Init(void);
void speedAdjustment(int lspeed,int rspeed);
void incrementalSpeedOut(motorSpeedTypeDef *p,int dSpeed);
void speedRec_Init(motorSpeedTypeDef *speedRegulator,int leftSpeed,int rightSpeed);
void positionSpeedOut(int leftSpeed,int rightSpeed,int dSpeed);
void sg_PWM_Init(void);
void sgAngleControl(SgNumber num,RotationAngle angle);


#endif

