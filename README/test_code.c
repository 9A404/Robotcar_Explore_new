/*************���ļ��Ĵ����Ϊ������ͼ*****************/

/*2017-7-10*/
/*���Զ����ͼ��
				sgAngleControl(HEAD,L_90);
				delay_ms(500);
				sgAngleControl(HEAD,R_90);
				delay_ms(500);
*/

/*

if(sampingStatus() == 1)
			{
				//array_u3printf(glsensor_ad_value);//����3���ģ����
				//arrayPrintf(glsensor_ad_value,12); //����1���ģ����
				glsensor_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  //��ģ����ת����������
				//u3_printf("%d\r\n",sensorDigitalRank(glsensor_dig_value));
				u3_printf("%d \r\n",glsensor_dig_value);//����3���������
				//sensorBit_u3printf(glsensor_dig_value);//����3��λ���������
				
				//sensorBitPrintf(glsensor_dig_value);	//����1��λ���������																										//����������λ���

				//dSpeed=incrementalPIDcalc(&sensorPID,sensorDigitalRank(glsensor_dig_value));//����ʽPID���
				dSpeed=positionPIDCalc(&sensorPID,sensorDigitalRank(glsensor_dig_value));   //λ��ʽPID���
				//printf("dSpedd:%d \r\n ",dSpeed);
				//printf("%f  ",sensorPID.setVaule);
				//printf("%f  ",sensorPID.kp);
				 //incrementalSpeedOut(&motorSpeed,dSpeed);	//�ڵ�ǰ���ٶ��ϵ����ٶ�
				 positionSpeedOut(motorSpeed.leftSpeed,motorSpeed.rightSpeed,dSpeed);
				 //u3_printf(" %d ds:%d left:%d right:%d \r\n",sensorDigitalRank(glsensor_dig_value),dSpeed,motorSpeed.leftSpeed,motorSpeed.rightSpeed);
				//u3_printf("ds:%d\r\n",dSpeed);
				//printf("left:%d \r\n",motorSpeed.leftSpeed);
				//printf("right:%d \r\n",motorSpeed.rightSpeed);
				
				//printf("digital:%d ",glsensor_dig_value );
				//printf("\r\n");
			}
*/








