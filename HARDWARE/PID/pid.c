#include "pid.h"
#include <string.h>
#include "myconfig.h"


/*

* �������ܣ���תλ��ʽPID����
* ���������p��PID������������err�����ֵ��
* ���������
* ����ֵ  ��

*/
int positionPIDCalc_rotAngle(PIDTypeDef *p,int err)
{
	int derror,error;
	int out;
	error = err;													//ƫ��
	p->sumerror += error;									//����
	derror = p->lastError - p->prevError;	//��ǰ΢��
	p->prevError = p->lastError;					//����error[-1]��ֵ
	p->lastError = error;									//����error[-2]��ֵ
	out = 	p->kp * error								//������
				+	p->ki * p->sumerror					//������
				+ p->kd * derror			;				//΢����
	
	out=limit(out,-p->limit,p->limit);
	
	return(out);
					
					
}


/*

* �������ܣ�λ��ʽPID����
* ���������p��PID������������nextVaule������ֵ��
* ���������
* ����ֵ  ��

*/
int positionPIDCalc(PIDTypeDef *p,int nextVaule)
{
	int derror,error;
	int out;
	error = p->setVaule - nextVaule;			//ƫ��
	p->sumerror += error;									//����
	derror = p->lastError - p->prevError;	//��ǰ΢��
	p->prevError = p->lastError;					//����error[-1]��ֵ
	p->lastError = error;									//����error[-2]��ֵ
	out = 	p->kp * error								//������
				+	p->ki * p->sumerror					//������
				+ p->kd * derror			;				//΢����
	
	out=limit(out,-p->limit,p->limit);
	
	return(out);
					
					
}

/*

* �������ܣ�����ʽPID����
* ���������p��PID������������nextVaule������ֵ��
* ���������
* ����ֵ  ��

*/
int incrementalPIDcalc(PIDTypeDef *p,int nextVaule)
{
	int error;
	int ep,ei,ed;
	int out;
	error = p->setVaule - nextVaule;				//ƫ��
	ep = error - p->lastError;
	ei = error; 
	ed = error - 2*p->lastError + p->prevError;
	
	p->prevError = p->lastError;					//����error[-1]��ֵ
	p->lastError = error;									//����error[-2]��ֵ
	
	out = 	p->kp * ep				//������
				+	p->ki * ei				//������
				+ p->kd * ed	;			//΢����
	
	out=limit(out,-p->limit,p->limit);
	
	return(out);
						
			
}

///*

//* �������ܣ���PID�ṹ������
//* ���������p��PID������������nextVaule������ֵ��
//* ���������
//* ����ֵ  ��

//*/
//static void PID_Reset(PIDTypeDef *p)
//{
//	memset(p,0,sizeof(PIDTypeDef));

//}

/*

* �������ܣ���PID������������������
* ���������pidRegulator(�����õ�PID������),setVaule(����ֵ),limit(�������ֵ�����޶�),kp(����ϵ��),ki(����ϵ��),kd(΢��ϵ��)
* ���������
* ����ֵ  ��
* ����		������limit = 100��������ֵ�ķ�Χ��+-100֮�䣬��ζ���������ֵ�PWM���ܳ���1000
*/
void PID_Init(PIDTypeDef *pidRegulator,int setVaule,int limit,int kp,int ki,int kd)
{
	memset(pidRegulator,0,sizeof(PIDTypeDef));//��PID�ṹ������
	
	pidRegulator->setVaule = setVaule;
	pidRegulator->limit = limit;
	pidRegulator->kp = kp;
	pidRegulator->ki = ki;
	pidRegulator->kd = kd;

}



