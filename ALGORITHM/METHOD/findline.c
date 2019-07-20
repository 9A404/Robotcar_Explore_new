#include "findline.h"


/*

* �������ܣ�ȱʡѲ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_default()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		//��������ѡ������õ��ٶ�
		#ifdef _FINDLINE_DEBUG_
			PID_Init(&glsensorPID,20,2500,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
			speedRec_Init(&glmotorSpeed,2050,2200); 																				//�Գ�ʼ�ٶȽ����趨
		#else
			PID_Init(&glsensorPID,20,3500,200,0,650);																					//���ٶ�PID�Ĳ������г�ʼ������
			speedRec_Init(&glmotorSpeed,3310,3500); 																				//�Գ�ʼ�ٶȽ����趨
		#endif
		
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed+gldYaw);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ������ٶ�Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_slowest()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,2000,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,1690,1800); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ����ٶ�Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_slow()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,2500,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2050,2200); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ����ٶ�Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_middle()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
				//��������ѡ������õ��ٶ�
		#ifdef _FINDLINE_DEBUG_
			PID_Init(&glsensorPID,20,2500,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
			speedRec_Init(&glmotorSpeed,2050,2200); 																				//�Գ�ʼ�ٶȽ����趨
		#else
			PID_Init(&glsensorPID,20,2500,200,0,600);																					//���ٶ�PID�Ĳ������г�ʼ������
			speedRec_Init(&glmotorSpeed,4180,4500); 																				//�Գ�ʼ�ٶȽ����趨
		#endif

		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ����ٶ�Ѳ�߷��������ڼ��٣�
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_quick()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
				//��������ѡ������õ��ٶ�
		#ifdef _FINDLINE_DEBUG_
			PID_Init(&glsensorPID,20,2500,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
			speedRec_Init(&glmotorSpeed,2050,2200); 																				//�Գ�ʼ�ٶȽ����趨
		#else
			PID_Init(&glsensorPID,20,4000,230,0,1400);																					//���ٶ�PID�Ĳ������г�ʼ������
			speedRec_Init(&glmotorSpeed,4640,5000); 																				//�Գ�ʼ�ٶȽ����趨
		#endif

		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}

/*

* �������ܣ������ٶ�Ѳ�߷��������ڼ��٣�
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_quickest()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		//��������ѡ������õ��ٶ�
		#ifdef _FINDLINE_DEBUG_
			PID_Init(&glsensorPID,20,2500,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
			speedRec_Init(&glmotorSpeed,2050,2200); 																				//�Գ�ʼ�ٶȽ����趨
		#else
			PID_Init(&glsensorPID,20,5500,250,0,2800);																					//���ٶ�PID�Ĳ������г�ʼ������
			speedRec_Init(&glmotorSpeed,6145,6500); 																				//�Գ�ʼ�ٶȽ����趨
		#endif
		
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value&0x7FE);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}



/*

* �������ܣ�����Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_brige()
{
	int rank;
	if(findLineFlag == 0)   //��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,14,2500,200,0,0);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2320,2500); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,brige_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank_Brige(glsensor_dig_value); 															//�����������еȼ�����
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}

/*

* �������ܣ�����б��ʱ��Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_brige_up()
{
	int rank;
	if(findLineFlag == 0)   //��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,14,2500,400,0,0);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,1670,1800); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,brige_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank_Brige_Up(glsensor_dig_value); 															//�����������еȼ�����
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ�����б��ʱ��Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_brige_down()
{
	int rank;
	if(findLineFlag == 0)   //��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,14,2500,400,0,0);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,1395,1500); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,brige_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank_Brige_Down(glsensor_dig_value); 															//�����������еȼ�����
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ���̨Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_UpPlatform(void)
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,2500,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2230,2400); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}

/*

* �������ܣ���̨Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_DownPlatform(void)
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,1500,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,1210,1300); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ�ͣ��Ѳ�߷���(��Ҫ���ڽڵ�ͣ����ײ��̨)
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_stop()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,1000,100,0,0);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,1310,1400); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}


/*

* �������ܣ�����ɽѲ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_sword()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,1000,100,0,0);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,1310,1400); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank_Sword(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}



/*

* �������ܣ������Ѳ�߷���()
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_upPeak()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,3500,400,0,100);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2800,3000); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}


/*

* �������ܣ������Ѳ�߷���()
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_downPeak()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,2000,400,0,100);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,1300,1400); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}

/*

* �������ܣ�����Ѳ�߷���(��Ҫ���ڽڵ�ͣ����ײ��̨)��2017-7-21����δͨ����
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_back()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,4000,250,0,0);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,-1940,-2000); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=-sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}


/*

* �������ܣ�ƫ��Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_left()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,4000,120,0,0);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,1400,2080); 																				//�Գ�ʼ�ٶȽ����趨2200+200
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value & 0xF00);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed+gldYaw);			//λ��ʽ�ı����ٶ�

}

/*

* �������ܣ�ƫ��Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_right()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,3500,80,0,0);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2080,1400); 																				//�Գ�ʼ�ٶȽ����趨2200+200
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value & 0x00F);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}

/*

* �������ܣ����ӽڵ�Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_node()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,2000,300,0,400);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2320,2500); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value&0X1F8);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ�ԲѲ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_circular()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,20,2000,500,0,400);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2230,2400); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ�43_44Ѳ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_43_44()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,21,2000,200,0,400);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2300,2500); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value & 0X1F0);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ�ԲѲ�߷���
* �����������
* �����������
* ����ֵ  ��
* ����    ��ÿ����������Ҫ������1��glmotorSpeed��ʼ�ٶ� 2��glsensorPID��P I D��������
* ����    ��@����

*/
void flMethod_16_44()
{
	int rank;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,10,2000,300,0,400);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,1395,1500); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;
	}
	glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	rank=sensorDigitalRank(glsensor_dig_value);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);			//λ��ʽ�ı����ٶ�

}
/*

* �������ܣ�ѭ�Ƕ��ܷ�
* �����������
* �����������
* ����ֵ  ��
* ����    �����

*/
void flMethod_NFL()
{
	int rank;
	float err;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,18,2600,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2230,2400); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;

	}
	//glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	if(angle_flag == 0)
	{ 
		MPU6050_Pose_usart();
		glsensor_angle=glYaw;
		angle_flag = 1;
	}  
	MPU6050_Pose_usart();		  
	err = errCalculation(glYaw,glsensor_angle);
//		u3_printf("%d\n",glsensor_angle);
	rank=rotangle_run(err);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);	
}
/*

* �������ܣ�ѭ�Ƕ��ܷ�
* �����������
* �����������
* ����ֵ  ��
* ����    �����

*/
void flMethod_NFL_slow()
{
	int rank;
	float err;
	if(findLineFlag == 0)//��֤ÿ��·�γ�ʼ��һ��
	{
		PID_Init(&glsensorPID,18,2600,200,0,200);																					//���ٶ�PID�Ĳ������г�ʼ������
		speedRec_Init(&glmotorSpeed,2230,2400); 																				//�Գ�ʼ�ٶȽ����趨
		findLineFlag=1;

	}
	//glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
	if(angle_flag == 0)
	{ 
		MPU6050_Pose_usart();
		glsensor_angle=glYaw;
		angle_flag = 1;
	}  
	MPU6050_Pose_usart();		  
	err = errCalculation(glYaw,glsensor_angle);
//		u3_printf("%d\n",glsensor_angle);
	rank=rotangle_run(err);                                    //�ּ�
	gldSpeed=positionPIDCalc(&glsensorPID,rank);   //�ٶ�λ��ʽPID���
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,gldSpeed);	
}





/*

* �������ܣ���Ѳ�ߣ���
* �����������
* �����������
* ����ֵ  ����
* ����    ��panshao

*/
void No_flMethod()
{
	if(0 == findLineFlag)
	{
		speedRec_Init(&glmotorSpeed,1690,1800);
		findLineFlag=1;
	}
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,0);
}

/*

* �������ܣ���Ѳ�ߣ����٣�
* �����������
* �����������
* ����ֵ  ����
* ����    ��panshao

*/
void No_flMethod_Slow()
{
	if(0 == findLineFlag)
	{
		speedRec_Init(&glmotorSpeed,1300,1320);
		findLineFlag=1;
	}
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,0);
}

/*

* �������ܣ���Ѳ�ߣ����ˣ�
* �����������
* �����������
* ����ֵ  ����
* ����    ��panshao

*/
void No_flMethod_Back()
{
	
	if(0 == findLineFlag)
	{
		speedRec_Init(&glmotorSpeed,-1500,-1500);
		findLineFlag=1;
	}
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,0);
}

/*

* �������ܣ��ջ���������ʹ��ʾ��
* �����������
* �����������
* ����ֵ  ����
* ����    �����

*/
void flMethod_Encoder()
{
	speedRec_Init(&glmotorSpeed,2000,2000);
	positionSpeedOut(glmotorSpeed.leftSpeed,glmotorSpeed.rightSpeed,0);
}





