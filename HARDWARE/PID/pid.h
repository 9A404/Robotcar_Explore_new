#ifndef _PID_H_
#define _PID_H_

#include "sys.h"

/*PID������*/
typedef struct{
	
	int setVaule; 	//�趨Ŀ��
	int kp;        //��������
	int ki;   			//���ֳ���
	int kd;				//΢�ֳ���
	
	int lastError;	//Error[-1]
	int prevError;	//Error[-2]
	int sumerror;	//����ۼ�
	
	int limit;		//����ֵ
	
}PIDTypeDef;

void PID_Init(PIDTypeDef *pidRegulator,int setVaule,int limit,int kp,int ki,int kd);
int incrementalPIDcalc(PIDTypeDef *p,int nextVaule);	//����ʽPID
int positionPIDCalc(PIDTypeDef *p,int nextVaule);			//λ��ʽPID
int positionPIDCalc_rotAngle(PIDTypeDef *p,int err);  // ��ת�õ�λ��ʽPID

#endif

