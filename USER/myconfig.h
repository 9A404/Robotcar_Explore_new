#ifndef  _MY_CONFIG_H_
#define  _MY_CONFIG_H_

#include "sys.h"
#include "delay.h"
#include "timer.h"
#include "pwm.h"
#include "usart.h"
#include "pid.h"
#include "usart3.h"
#include "control.h"
#include "findline.h"
#include "roadblock.h"
#include "rotangle.h"
#include "seeknodeway.h"
#include "carpark.h"
#include "adc.h"
#include "mpu6050.h"
#include "key.h"
#include "pes.h"
#include "led.h"
#include "string.h"
#include "GUI.h"
#include "Lcd_Driver.h"
#include "myGUI.h"
#include "door.h"
#include "danger.h"
#include "speed.h"

//#define _DEBUG_
//#define _DEBUG_U3_P		//���Դ�����������ӡ
//#define _LED_CONTROL_		//һ������
#define _DJ_CONTROL_ 	//���Ͷ��
//#define _FINDLINE_DEBUG_//�������ٶ�
#define _NEW_MPU6050_//�°�������

//����ʱ��

#define Door_Time 		120
#define Door_Time_2 	100

#define S_TIME_6_8 		80
#define S_TIME_8_6 		80
#define S_TIME_6_7 		70
#define S_TIME_7_12 	280
#define S_TIME_10_11 	60
#define S_TIME_11_10 	45
#define S_TIME_10_12 	90
#define S_TIME_36_37 	50
#define S_TIME_38_37 	100
#define S_TIME_14_37 	160
#define S_TIME_44_37 	250
#define S_TIME_17_37 	280
#define S_TIME_15_37 	120
#define S_TIME_36_17 	200
#define S_TIME_14_44 	110
#define S_TIME_9_30 	90
#define S_TIME_39_30 	50

#define max(a,b)			(a>b ? a:b)
#define min(a,b)			(a<b ? a:b)
#define limit(x,a,b)	(min(max(x,a) , b))	

#define NUM_OF_SENSOR 	12					//����������
#define USART3_MAX_SEND_LEN 200		 // ���ͻ����С

extern s16	hall_L_counter;	//�������������ֵ����ӦTIM2����ֵ
extern s16	hall_R_counter;//��ӦTIM3����ֵ
extern unsigned short glsensor_ad_value[NUM_OF_SENSOR];       //������ģ��������
extern unsigned short glsensor_dig_value;									    //����������������
extern unsigned char 	USART3_TX_BUF[USART3_MAX_SEND_LEN];     //����3���ͻ���
extern unsigned char  USART1_RX_BUF[66];											//����1 DMA������
/********************************��������ֵ******************************************************************/
extern const unsigned short int  basic_sensorThreshold[NUM_OF_SENSOR]; //��������ֵ
extern const  u16  brige_sensorThreshold[NUM_OF_SENSOR];//������ֵ

/*******************************������*******************************************************************/
extern const map_linkInforTypeDef mapInformation[][NODEFORKNUM]; //��ͼ��Ϣ���ֻ���
extern const rankTypeDef rankInformation_FL[22];                   //Ѳ�߷ּ���

extern float glPitchbuff[2];
extern float gldif_Pitch;
extern u8 mpu6050_flag;
extern u8 U_Dswitch;                                //����̨���ƿ��� 1������̨��2������̨
extern float gldYaw;																//����ƫ����PID���
extern float glPitch,glRoll,glYaw;							  //ŷ����
extern float glsetYaw;																		//�����趨��ƫ����
extern int gldSpeed;															//�����ٶ�PID���
extern float angle_read_temp[5];
extern float angle_read;
extern u8 findLineFlag;														//Ѳ�߷�����ʼ����־λ
extern u8 rotAngleFlag;                         //��ת������ʼ����־λ

extern u8 key0_Flag;																//����0��־λ
extern u16 gl_time;														 		 //��ʱ��3��־
extern u8 runTimes;																//��¼���ܴ���
extern float angle_read;			//��¼��һ���̰�ת��ĽǶ�
extern float angle_read_back;		//��¼�ڶ����̰�ת��ĽǶ�
extern float glsensor_angle;
extern  u8 angle_flag;
/********************************�߼��������**************************************************/
extern PIDTypeDef glsensorPID;										//����һ��������PID������
extern PIDTypeDef glrotAnglePID;									//����һ��ת��PID������
extern motorSpeedTypeDef glmotorSpeed;				  	//����һ���ٶȼ�¼��
//extern rankTypeDef glrankInformation[50];				//����һ���ּ������ 
extern controlCenterTypeDef glHello_control;			//����һ������̨
extern runStateTypeDef		glrunState;							//����һ������״̬��¼��

void Fun_game(void);															//
void Fun_SecondGameMethod1(void);
void Fun_SecondGameMethod2(void);
extern const u8  runMethodTable[][100];						//�����ű���·�߱��
extern const u8  runMethodTableDoor[][100];
extern const u8  runMethodTableDoorAuto[][100]; 

extern const u8  runMethodTableDebug[][100];						//����·�ߵ��Ա��
extern u8 runMethodNum;
extern u8 runMethodNumDebug;
extern u8 runMethodNumDoor;                       //���ڼ�¼39�ſ��ı�������
extern u8 DoorFlag;                         //���ڵ��Ź��л�·�ߵĴ��������Զ��л�·�߱�־λ   
extern u8 DoorFlag_2;                               //����ѡ����ű�־λ��Ϊ���õڶ��ֱ��ܲ���Ѱ���ĸ����ǿ���
extern u8 runMethod[100];													//�����һ�α���·��
extern u8 runMethod_2[100];                       //����ڶ��α���·��

extern u8 pes_L;																		//��߹�紫����״̬
extern u8 pes_R;																		//�ұ߹�紫����״̬

extern u8 SecondGameNum1;														//һ���л��ڶ���·��1������·�ߣ�
extern u8 SecondGameNum2;														//һ���л��ڶ���·��2���߷�·�ߣ�
//extern u8 DangerFlag;                         //Σ�ձ�־λ



#endif



