#include "myconfig.h"


/*ȫ�ֱ���*/
const u16  basic_sensorThreshold[NUM_OF_SENSOR] = {3900,3900,3900,3900 ,3900,3900,3900,3900,3900,3900,3900,3900 };
const u16  brige_sensorThreshold[NUM_OF_SENSOR] = {800,900,930,900,900,900,900,900,900,900,900,900 };
 


/*****************************************************����·��****************************************************************************************/
/*������·��*/
const u8 runMethodTable[][100]=
{
///*����·��0 ������267*2=534	*/{1,2,5,6,8,6,7,12,10,11,10,9,5,2,1,2},				
/*����·��1  ����	282*2=564	*/{1,2,3,4,3,5,9,10,11,10,12,10,9,5,6,8,6,7,6,5,2,1,2},	
///*�߷�·��2 ������484*2=968	*/{1,2,5,6,8,6,7,12,10,11,10,24,36,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,37,36,24,10,9,5,2,1,2},			
/*�߷�·��3	 ���� 499*2=998	*/{1,2,3,4,3,5,6,8,6,7,12,10,11,10,24,36,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,37,36,24,10,9,5,2,1,2},
/*�߷�·��4	����Բ510*2=1020*/{1,2,3,4,3,5,6,8,6,7,12,10,11,10,24,36,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,17,18,19,18,17,37,36,24,10,9,5,2,1,2},
///*�߷�·��5	 ȫ�� 550*2=1100*/{1,2,3,4,3,5,6,8,6,7,12,10,11,10,24,36,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,17,18,19,18,17,43,16,44,45,46,47,46,43,37,36,24,10,9,5,2,1,2},
};
/*����ǰ·��ͬʱҲ�����39�ſ��ߵ�·��*/
const u8 runMethodTableDoor[][100]=
{
/* 0 */	{1,2,3,4,3,5,6,8,6,7,12,10,11,10,9,39,15,31,32,31,30,34,35,36,35,14,16,44,45,46,47,46,48,43,16,17,18,19,18,20,21,22,23,24,23,22,21,20,18,17,14,34,30,50,28,25,26,27,26,25,28,50,49,37,15,9,5,2,1,2},//����
///* 1 */	{1,2,3,4,3,5,6,8,6,7,12,10,11,10,9,39,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,16,17,18,19,18,17,37,36,15,9,5,2,1,2},//����
};
/*���ź�·��*/
const u8 runMethodTableDoorAuto[][100]=
{
/* 0 	39���Ź�*/	{39,9,40,13,14,17,18,19,18,17,37,36,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,13,9,5,2,1,2},        			//��һ��·�����40�ſ�������·��
/* 1 	40���Ź�*/	{40,9,5,6,14,17,18,19,18,17,37,36,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,6,5,2,1,2},         				//��һ��·�����41�ſ�������·��
/* 2 	42���Ź�*/	{6,}, 
/* 3 	��39����*/	{1,2,3,4,3,5,6,8,6,7,12,10,11,10,9,39,15,31,32,31,30,34,35,36,35,14,16,44,45,46,47,46,48,43,16,17,18,19,18,20,21,22,23,24,23,22,21,20,18,17,14,34,30,50,28,25,26,27,26,25,28,50,49,37,15,9,5,2,1,2},
/* 4 	��40����*/	{1,2,3,4,3,5,6,8,6,7,12,10,11,10,9,13,14,17,18,19,18,17,37,36,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,13,9,5,2,1,2},	//�ڶ���·�߸����ߵ�·�ߣ����ü���ŵĿ�����
/* 5 	��42����*/	{1,2,3,4,3,5,6,8,6,7,12,10,11,10,9,5,6,14,17,18,19,18,17,37,36,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,6,5,2,1,2}, 
};

/*����·�߱��*/
const u8  runMethodTableDebug[][100]=
{
  {1,2,3,4,3,5,6,8,6,7,12,10,11,10,9,39,15,31,32,31,30,34,35,36,35,14,16,44,45,46,47,46,48,43,16,17,18,19,18,20,21,22,23,24,23,22,21,20,18,17,14,34,30,50,28,25,26,27,26,25,28,50,49,37,15,9,5,2,1,2},
	{1,2,5,6,8,6,7,12,10,11,10,9,39,15,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,16,17,18,19,18,17,37,36,15,9,5,2,1,2},//�����ţ�ȥ19
	{1,2,3,4,3,5,6,8,6,7,12,10,11,10,9,39,30,31,32,31,33,23,24,23,25,26,27,26,25,33,34,35,36,35,14,17,18,19,18,17,37,36,15,9,5,2,1,2},
    
};
u8 runMethod[100]=	{1,2,5,9};							//���ر��ܵ�·��:������
u8 runMethod_2[100]={1,2,5,9};  						//���ر��ܵ�·��:������
/***********************************************************************************************************************************************/

u16 glsensor_ad_value[NUM_OF_SENSOR];				//����ģ����
u16 glsensor_dig_value;											//����ת�����������
u8 	USART3_TX_BUF[USART3_MAX_SEND_LEN];			//����3 DMA������

PIDTypeDef glsensorPID;											//����һ��������PID������
PIDTypeDef glrotAnglePID;										//����һ��ת��PID������
motorSpeedTypeDef glmotorSpeed;							//����һ���ٶȼ�¼��
controlCenterTypeDef glHello_control;				//����һ������̨
runStateTypeDef		glrunState;								//����һ������״̬��¼��
//rankTypeDef glrankInformation[50];				//����һ���ּ������ 

float angle_read_back;
u8 angle_flag=0;                         		//Ѳ�߽Ƕȱ�־
float glsensor_angle;
int gldSpeed;															 	//�����ٶ�PID���
float gldYaw=0;														 	//����ƫ����PID���
u8 findLineFlag=0;											   	//Ѳ�߷�����ʼ����־λ
u8 rotAngleFlag=0;                         	//��ת������ʼ����־λ
float glPitch,glRoll,glYaw;							   	//�洢mpu6050������ŷ����
float glsetYaw;                            	//�����趨��ƫ����

float angle_read_temp[5];
float angle_read;

float glPitchbuff[2];											 	//�����ǻ�����
float gldif_Pitch;                         	//ǰ������֮��	  
u8 mpu6050_flag=0;												 	//��־����̨
u8 U_Dswitch;                             	//����̨���ƿ��� 1������̨��2������̨
u8  USART1_RX_BUF[66];											//����1 DMA������
u16 gl_time=0;														 	//��ʱ��3��־
u8 runTimes=0;															//��¼���ܴ���
u8 DoorFlag=0;                        			//��¼�ſ���־λ
u8 DoorFlag_2=0;

u8 runMethodNumDebug;                       //��¼����·������
u8 runMethodNum;                            //��¼�����ű���·������
u8 runMethodNumDoor;                        //��¼���ű���·������

u8 pes_L=0;																	//��߹�紫����״̬
u8 pes_R=0;																	//�ұ߹�紫����״̬

u8 SecondGameNum1 = 0;											//һ���л��ڶ���·��1������·�ߣ�
u8 SecondGameNum2 = 1;											//һ���л��ڶ���·��2���߷�·�ߣ�
/*

* �������ܣ�����
* �����������
* �����������
* ����ֵ  ����
* ����    ��@���䣨�޸�@ �£�

*/
void Fun_game(void)
{
	Lcd_Clear(WHITE);//����
	Gui_DrawFont_GBK16(0,0,BLUE,WHITE,"����:");
	#ifndef _NEW_MPU6050_
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"MPU6050_Init...");
	MPU6050_Init();		        //MPU6050��ʼ��
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"               ");
	#endif
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"Start");
	/*���³�ʼ��*/
	runTimes = 0;						//��¼���ܴ���
	gl_time=0;							//��ʱ��3��־
	mpu6050_flag=0;					//��־����̨
	findLineFlag=0;					//Ѳ�߷�����ʼ����־λ
	
	while(1)
	{
		keyFlag = keyScan(0);
		
		/*���а������¾�����*/
		if(keyFlag==KEY0_UP || keyFlag==KEY4_ESC)
		{
			speedAdjustment(0,0);
			Time3(STOP);     //�رն�ʱ��
			mpu6050_samping(STOP); //�ر�mpu6050����
			/*�����λ*/
			__set_FAULTMASK(1);  // �ر������ж�
			NVIC_SystemReset();  // ��λ
		} 
		
		if(0 == runTimes)
			{
				Gui_DrawFont_GBK16(0,40,BLUE,WHITE,"First round...");
				runTimes=3;																		//��֤��һ��ֻ��ʼ��
				/*****����߼����ʼ������*****/
				Control_Init(&glHello_control,runMethod);     //��ʼ������̨
				runStateInit(&glrunState,&glHello_control);		//���ݿ���̨��ʼ·�γ�ʼ������״̬
			}
		if(1 == runTimes)
			{
				Gui_DrawFont_GBK16(0,60,BLUE,WHITE,"Second round...");
				runTimes=4;																		//��֤��һ��ֻ��ʼ��
				if(1==DoorFlag)
					runMethodResetDoorSecond(runMethod_2,DoorFlag_2,runMethodTableDoorAuto);//���ݿ������Ǻ��Ÿ�������runMethodTableDoorAuto�ж�Ӧ�ı��·�ߵ�runMethod_2��ע���Ǵ�3��ʼ��
				runMethodReset(runMethod,runMethod_2);				//����·��
				/*****����߼����ʼ������*****/
				Control_Init(&glHello_control,runMethod);     //��ʼ������̨
				runStateInit(&glrunState,&glHello_control);		//���ݿ���̨��ʼ·�γ�ʼ������״̬
			}
			/*����һ��·�βŸ���һ��*/
		 if(control_Update(&glHello_control,strlen((const char*)runMethod),runMethod,mapInformation))//����⵽�ڵ��ͻ���¿���̨������//sizeof(runMethod)/sizeof(runMethod[0])
			{
				//u3_printf("Control_Update\r\n");
				runStateReset(&glrunState,&glHello_control);//��������״̬
				findLineFlag=0;
			}
				/*�������һ�ξͽ���һ�δ���*/
		if(sampingStatus() == 1) 
			{	
				findLine_Task(&glHello_control,&glrunState);        	 // Ѳ������
				roadBlocksHandle_Task(&glHello_control,&glrunState);	 // �ϰ���������
        speed_Task(&glHello_control,&glrunState);				//��������
				carPark_Task(&glHello_control, &glrunState);       		 // ͣ������
				seekNode_Task(&glHello_control,&glrunState);      		 // �ҵ�����				
			}
		rotAngle_Task(&glHello_control,&glrunState);           // ת������	
	}
}
/*

* �������ܣ�������һ��ȷ������·�ߣ�
* �����������
* �����������
* ����ֵ  ����
* ����    ��@ ��

*/

void Fun_SecondGameMethod1(void)
{
	Lcd_Clear(WHITE);//����
	Gui_DrawFont_GBK16(0,0,BLUE,WHITE,"����:");
	#ifndef _NEW_MPU6050_
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"MPU6050_Init...");
	MPU6050_Init();		        //MPU6050��ʼ��
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"               ");
	#endif
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"Start");
	/*���³�ʼ��*/
	runTimes = 0;						//��¼���ܴ���
	gl_time=0;							//��ʱ��3��־
	mpu6050_flag=0;					//��־����̨
	findLineFlag=0;					//Ѳ�߷�����ʼ����־λ
	
	while(1)
	{
		keyFlag = keyScan(0);
		
		/*���а������¾�����*/
		if(keyFlag==KEY0_UP || keyFlag==KEY4_ESC)
		{
			speedAdjustment(0,0);
			Time3(STOP);     //�رն�ʱ��
			mpu6050_samping(STOP); //�ر�mpu6050����
			/*�����λ*/
			__set_FAULTMASK(1);  // �ر������ж�
			NVIC_SystemReset();  // ��λ
		} 
		
		if(0 == runTimes)
			{
				Gui_DrawFont_GBK16(0,40,BLUE,WHITE,"Second round...");
				runTimes=4;																		//��֤��һ��ֻ��ʼ��
				runMethodUpdate(runMethod,SecondGameNum1,runMethodTable);
				/*****����߼����ʼ������*****/
				Control_Init(&glHello_control,runMethod);     //��ʼ������̨
				runStateInit(&glrunState,&glHello_control);		//���ݿ���̨��ʼ·�γ�ʼ������״̬
			}
			/*����һ��·�βŸ���һ��*/
		 if(control_Update(&glHello_control,strlen((const char*)runMethod),runMethod,mapInformation))//����⵽�ڵ��ͻ���¿���̨������//sizeof(runMethod)/sizeof(runMethod[0])
			{
				//u3_printf("Control_Update\r\n");
				runStateReset(&glrunState,&glHello_control);//��������״̬
				findLineFlag=0;
			}
				/*�������һ�ξͽ���һ�δ���*/
		if(sampingStatus() == 1) 
			{	
				findLine_Task(&glHello_control,&glrunState);        	 // Ѳ������
				roadBlocksHandle_Task(&glHello_control,&glrunState);	 // �ϰ���������
        speed_Task(&glHello_control,&glrunState);				//��������
				carPark_Task(&glHello_control, &glrunState);       		 // ͣ������
				seekNode_Task(&glHello_control,&glrunState);      		 // �ҵ�����				
			}
		rotAngle_Task(&glHello_control,&glrunState);           // ת������	
	}
}
/*

* �������ܣ�������һ��ȷ������·�ߣ�
* �����������
* �����������
* ����ֵ  ����
* ����    ��@ ��

*/

void Fun_SecondGameMethod2(void)
{
	Lcd_Clear(WHITE);//����
	Gui_DrawFont_GBK16(0,0,BLUE,WHITE,"����:");
	#ifndef _NEW_MPU6050_
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"MPU6050_Init...");
	MPU6050_Init();		        //MPU6050��ʼ��
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"               ");
	#endif
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"Start");
	/*���³�ʼ��*/
	runTimes = 0;						//��¼���ܴ���
	gl_time=0;							//��ʱ��3��־
	mpu6050_flag=0;					//��־����̨
	findLineFlag=0;					//Ѳ�߷�����ʼ����־λ
	
	while(1)
	{
		keyFlag = keyScan(0);
		
		/*���а������¾�����*/
		if(keyFlag==KEY0_UP || keyFlag==KEY4_ESC)
		{
			speedAdjustment(0,0);
			Time3(STOP);     //�رն�ʱ��
			mpu6050_samping(STOP); //�ر�mpu6050����
			/*�����λ*/
			__set_FAULTMASK(1);  // �ر������ж�
			NVIC_SystemReset();  // ��λ
		} 
		
		if(0 == runTimes)
			{
				Gui_DrawFont_GBK16(0,40,BLUE,WHITE,"Second round...");
				runTimes=4;																		//��֤��һ��ֻ��ʼ��
				runMethodUpdate(runMethod,SecondGameNum2,runMethodTable);
				/*****����߼����ʼ������*****/
				Control_Init(&glHello_control,runMethod);     //��ʼ������̨
				runStateInit(&glrunState,&glHello_control);		//���ݿ���̨��ʼ·�γ�ʼ������״̬
			}
			/*����һ��·�βŸ���һ��*/
		 if(control_Update(&glHello_control,strlen((const char*)runMethod),runMethod,mapInformation))//����⵽�ڵ��ͻ���¿���̨������//sizeof(runMethod)/sizeof(runMethod[0])
			{
				//u3_printf("Control_Update\r\n");
				runStateReset(&glrunState,&glHello_control);//��������״̬
				findLineFlag=0;
			}
				/*�������һ�ξͽ���һ�δ���*/
		if(sampingStatus() == 1) 
			{	
				findLine_Task(&glHello_control,&glrunState);        	 // Ѳ������
				roadBlocksHandle_Task(&glHello_control,&glrunState);	 // �ϰ���������
				carPark_Task(&glHello_control, &glrunState);       		 // ͣ������
        speed_Task(&glHello_control,&glrunState);				//��������
				seekNode_Task(&glHello_control,&glrunState);      		 // �ҵ�����				
			}
		rotAngle_Task(&glHello_control,&glrunState);           // ת������	
	}
}
/*********************************************************************************************************************/
int main(void)
{	
		/************Ӳ����ʼ������*****************************************************************************/	
	  NVIC_Configuration();				//ϵͳ�ж����ȼ�������ռ2����Ӧ2	
		delay_init();	    	  		//��ʱ������ʼ��	
		Lcd_Init();             //TFT��Ļ��ʾ��ʼ��
		bootDisplay();					//��������
		ADC_DMA_Init();        	//ADC&DMA��ʼ��
		sampingTime_Init(150);	//��������Ϊ15ms��Ӧ��ֵΪ150 
//		mpu6050_sampingTime_Init(80);//mpu6050��������8ms
		TIM3_Config(100-1,7200-1); // ��ʱ��3��ʱ����Ϊ10ms
		motor_PWM_Init();       //PWM��ʼ��
		uart_init(115200);			//����1��ʼ��	
//		usart3_init(115200);			//����DMA��ʼ������		
		sg_PWM_Init();					//�����ʼ��
		keyInit();							//������ʼ��
	  pesInit();							//��紫������ʼ��
		ledInit();							//led��ʼ��
		//buzzerInit();         //��������ʼ��
		
		runMethodNum=sizeof(runMethodTable)/sizeof(runMethodTable[0]);
		runMethodNumDoor=sizeof(runMethodTableDoor)/sizeof(runMethodTableDoor[0]);
		runMethodNumDebug=sizeof(runMethodTableDebug)/sizeof(runMethodTableDebug[0]);
		
		while(1)
		{
			displayOperation();
    //  speedAdjustment(-1452,-1500);
			//////////////////
		}
		
}

 



