#include "myGUI.h"

extern const unsigned char bootLogo[32768];

u8 keyFun=0;        //װ�ز˵�����
void (*keyFunPt)(); //ָ�뺯��
u8 keyFlag=0;				//���ؼ�ֵ

/*

* �������ܣ�ͼƬ��ʾ(ȡģ��ʽ ˮƽɨ�� ������ ��λ��ǰ)
* ���������x(ͼƬ��ʼ��ʾx����)y(ͼƬ��ʼ��ʾy����)xMax��ͼƬ��ȣ�yMax��ͼƬ���ȣ�image��ͼƬ��ַ��
* ���������
* ����ֵ  ��
* ����    ��@����

*/
static void showImage(u16 x,u16 y,u8 xMax,u8 yMax,const u8 *image)
{
	int i;
	u16 date;
	
	Lcd_Clear(WHITE); //���� 

	Lcd_SetRegion(x,y,x+xMax-1,y+yMax-1);		//��������	
	for(i=0;i<xMax*yMax;i++)
	{
			date = image[i*2+1];
			date<<=8;
			date|=image[i*2];
			LCD_WriteData_16Bit(date);
	}


}



/*

* �������ܣ�����������ʾ
* �����������
* ���������
* ����ֵ  ��
* ����    ��@����

*/
void bootDisplay(void)
{
	Lcd_Clear(WHITE);
	showImage(13,0,99,100,bootLogo);
	Gui_DrawFont_GBK16(17,110,BLUE,WHITE,"������ʵ����");
	Gui_DrawFont_GBK16(40,130,RED,WHITE,"R U N"); 
//DisplayButtonUp(27,128,95,145);
	
}

/*

* �������ܣ�����״̬��ʾ
* �����������
* ���������
* ����ֵ  ��
* ����    ��@����

*/
void displayControl(controlCenterTypeDef *controlp)
{
	u8 control_node[10];
	char buff[2];
	u8 i=0,j=0,k=0;
	while(control_node[i]!= 0)
	{
		control_node[i]= 0;
		i++;
	}
	i=0;
	control_node[0]=controlp->curNode;
	control_node[1]=controlp->nextNode;
	control_node[2]=controlp->nnNode;
	control_node[3]=controlp->nodeNum;
		Lcd_Clear(WHITE);
		while(control_node[i]!=0)
			{
				sprintf(buff,"%d",control_node[i]);
				Gui_DrawFont_GBK16(0+20*j,40+20*k,BLUE,WHITE,buff);
				i++;
				if(j<6)
					j++;
				else 
					j=0;
				if(j==0)
					k++;
			}
}

/************************************************************************************************************************/
/******************************************��Ӧ����ִ�к���**************************************************************/
/************************************************************************************************************************/

/*

* �������ܣ��˵���ʾ��ģʽѡ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_menuDisplay(void)
{
	Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(30,10,RED,WHITE,"ģʽѡ��");
	Gui_DrawFont_GBK16(0,40,BLUE,WHITE,"����");
	Gui_DrawFont_GBK16(0,70,BLUE,WHITE,"·�ε���");
	Gui_DrawFont_GBK16(0,100,BLUE,WHITE,"����������");
	Gui_DrawFont_GBK16(0,130,BLUE,WHITE,"������");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag == KEY1_DOWN ||keyFlag==KEY0_UP||keyFlag==KEY4_ESC||keyFlag==KEY3_MENU)break;
	}
}

/*

* �������ܣ��������
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_compCursor(void)
{
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"  "); //������Թ��
	Gui_DrawFont_GBK16(100,40,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN || keyFlag==KEY2_ENTER)break; //���а������¾�����
	}
}

/*

* �������ܣ���һ��·��ѡ�����(�Ƿ����)
* �����������
* �����������
* ����ֵ  ����
* ����    ��@��

*/
void Fun_RouteSelectionInterfaceFirst(void)
{
		Lcd_Clear(WHITE);
		Gui_DrawFont_GBK16(30,10,RED,WHITE,"һ��·��");      //��һ��·��ѡ��
		Gui_DrawFont_GBK16(30,40,RED,WHITE,"�Ƿ����");   //�Ƿ����
		Gui_DrawFont_GBK16(0,70,BLUE,WHITE,"��");            //������
		Gui_DrawFont_GBK16(0,100,BLUE,WHITE,"��");          //����
		while(1)
		{
			keyFlag = keyScan(0);
			if(keyFlag==KEY0_UP||keyFlag==KEY1_DOWN||keyFlag==KEY4_ESC)break; //���а������¾���
		}
}
/*

* �������ܣ��ڶ���·��ѡ�����(�Ƿ����)
* �����������
* �����������
* ����ֵ  ����
* ����    ��@��

*/
void Fun_RouteSelectionInterfaceSecond(void)
{
		Lcd_Clear(WHITE);
		Gui_DrawFont_GBK16(30,10,RED,WHITE,"����·��");      //�ڶ���·��ѡ��
		Gui_DrawFont_GBK16(30,40,RED,WHITE,"�Ƿ����");   //�Ƿ����
		Gui_DrawFont_GBK16(0,70,BLUE,WHITE,"��");            //������
		Gui_DrawFont_GBK16(0,100,BLUE,WHITE,"��");          //����
		while(1)
		{
			keyFlag = keyScan(0);
			if(keyFlag==KEY0_UP||keyFlag==KEY1_DOWN||keyFlag==KEY4_ESC)break; //���а������¾���
		}
}
/*

* �������ܣ����Ź��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@��

*/
void Fun_EnterDoor(void)
{
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"  "); //��������Ź��
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN|| keyFlag==KEY0_UP  || keyFlag==KEY2_ENTER||keyFlag==KEY4_ESC)break; //���а������¾�����
	}
}
/*

* �������ܣ������Ź��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@��

*/
void Fun_DontEnterDoor(void)
{
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"  "); //������Ź����
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN|| keyFlag==KEY0_UP  || keyFlag==KEY2_ENTER||keyFlag==KEY4_ESC)break; //���а������¾�����
	}
}



/*

* �������ܣ�·�ε��Թ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_debugCursor(void)
{
	Gui_DrawFont_GBK16(100,40,RED,WHITE,"  "); //����������
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"  ");//����������
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN || keyFlag==KEY0_UP || keyFlag == KEY2_ENTER)break; //���а������¾�����
	}
}

/*

* �������ܣ��������������
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_sensorCursor(void)
{
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"  ");//���·�ε��Թ��
	Gui_DrawFont_GBK16(100,130,RED,WHITE,"  ");//��������ǹ��
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN || keyFlag==KEY0_UP || keyFlag == KEY2_ENTER)break; //���а������¾�����
	}
}

/*

* �������ܣ������ǹ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_gyroCursor(void)
{
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"  ");//����������������
	Gui_DrawFont_GBK16(100,130,RED,WHITE,"<-");
	
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY0_UP || keyFlag == KEY2_ENTER || keyFlag == KEY1_DOWN)break; //���а������¾�����
	}
}

/*

* �������ܣ�·����ʾ���
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_runMethodCursor(void)
{
	Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(30,10,RED,WHITE,"ģʽѡ��");
	Gui_DrawFont_GBK16(0,40,BLUE,WHITE,"·��_Show");
	Gui_DrawFont_GBK16(100,40,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY0_UP || keyFlag == KEY2_ENTER)break; //���а������¾�����
	}
}






/*

* �������ܣ���������ת���ɶ������ַ���
* �����������buff�������ַ���value����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
static void dig_Binary(u8 *buff,u16 value)
{
	u8 i;
	u16 temp=0x0800;
	for(i=0;i<NUM_OF_SENSOR;i++)
	{
		if(value & temp)
			buff[i]='1';
		else
			buff[i]='0';
		temp=temp>>1;
	}
}

/*

* �������ܣ���̺��������λ��ʾ
* ���������value����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_sensorBitDisplay(void)
{
	u8 buff[12];
	u16 temp_dig_value;
	Lcd_Clear(WHITE); //����
	Gui_DrawFont_GBK16(0,0,RED,WHITE,"GreenCarpet������:");
	Gui_DrawFont_GBK16(0,40,RED,WHITE,"Hex:0x");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY0_UP || keyFlag == KEY4_ESC ||keyFlag == KEY1_DOWN)break; //���а������¾�����
		
		if(sampingStatus() == 1)
		{
			temp_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
			dig_Binary(buff,temp_dig_value) ;    //ת����2���ƴ�����buff��
			Gui_DrawFont_GBK16(0,20,BLUE,WHITE,(const char*)buff);
			
			Lcd_Clear_partial(49,40,128,60,WHITE);
			sprintf((char*)buff,"%x",temp_dig_value);
			Gui_DrawFont_GBK16(49,40,BLUE,WHITE,(const char*)buff);
			
			sprintf((char*)buff,"%d",calculateNum(temp_dig_value));
			Lcd_Clear_partial(20,60,40,80,WHITE);
			Gui_DrawFont_GBK16(20,60,BLUE,WHITE,(const char*)buff);
			
			
		}
	}
}



/*

* �������ܣ�����������λ��ʾ
* ���������value����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_sensorBitDisplay_brige(void)
{
	u8 buff[12];
	u16 temp_dig_value;
	Lcd_Clear(WHITE); //����
	Gui_DrawFont_GBK16(0,0,RED,WHITE,"Brige������:");
	Gui_DrawFont_GBK16(0,40,RED,WHITE,"Hex:0x");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY0_UP || keyFlag == KEY4_ESC)break; //���а������¾�����
		
		if(sampingStatus() == 1)
		{
			temp_dig_value = sensorAD(glsensor_ad_value,brige_sensorThreshold);  				//����ֵ�ȽϺ�ģ����ת����������
			dig_Binary(buff,temp_dig_value) ;    //ת����2���ƴ�����buff��
			Gui_DrawFont_GBK16(0,20,BLUE,WHITE,(const char*)buff);
			
			Lcd_Clear_partial(49,40,128,60,WHITE);
			sprintf((char*)buff,"%x",temp_dig_value);
			Gui_DrawFont_GBK16(49,40,BLUE,WHITE,(const char*)buff);
			
			sprintf((char*)buff,"%d",calculateNum(temp_dig_value));
			Lcd_Clear_partial(20,60,40,80,WHITE);
			Gui_DrawFont_GBK16(20,60,BLUE,WHITE,(const char*)buff);
			
			
		}
	}
}



/*

* �������ܣ�ģ������ʾ
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_analogDisplay(void)
{
	u8 buff[4];
	u8 i;
	Lcd_Clear(WHITE); //����
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN || keyFlag==KEY4_ESC)break; //���а������¾�����
		
		if(sampingStatus() == 1)
		{
			Gui_DrawFont_GBK16(0,0,RED,WHITE,"ģ����:");
			for(i=0;i<12;i++)
			{
				sprintf((char *)buff,"%d",glsensor_ad_value[i]);
			
				if(i<3)
					{
						Lcd_Clear_partial(5+40*i,20,5+40*i +32,20 +20,WHITE);
						//Gui_DrawFont_GBK16(5+40*i,20,BLUE,WHITE,"    ");
						Gui_DrawFont_GBK16(5+40*i,20,BLUE,WHITE,(const char*)buff);
					}
					else if(2<i && i<6)
					{
						Lcd_Clear_partial(5+40*(i-3),20+20,5+40*(i-3)+32,20+20+20,WHITE);
						//Gui_DrawFont_GBK16(5+40*(i-3),20+20,BLUE,WHITE,"    ");
						Gui_DrawFont_GBK16(5+40*(i-3),20+20,BLUE,WHITE,(const char*)buff);
					}
					else if(5<i && i<9)
					{	
						Lcd_Clear_partial(5+40*(i-6),20+40,5+40*(i-6) +32,20+40 +20,WHITE);
						//Gui_DrawFont_GBK16(5+40*(i-6),20+40,BLUE,WHITE,"    ");
						Gui_DrawFont_GBK16(5+40*(i-6),20+40,BLUE,WHITE,(const char*)buff);
					}
					else if(i>8)
					{
						Lcd_Clear_partial(5+40*(i-9),20+60,5+40*(i-9) +32,20+60 +20,WHITE);
					//	Gui_DrawFont_GBK16(5+40*(i-9),20+60,BLUE,WHITE,"    ");
						Gui_DrawFont_GBK16(5+40*(i-9),20+60,BLUE,WHITE,(const char*)buff);
					}
			}
		
		}
	}
}

/*

* �������ܣ�ŷ������ʾ
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_groyDisplay(void)
{
	u8 buff[7];
	u8 i;
	Lcd_Clear(WHITE); //����
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"MPU6050_Init...");
	MPU6050_Init();		        //MPU6050��ʼ��
    Gui_DrawFont_GBK16(0,20,RED,WHITE,"               ");

	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC)break; //���а������¾�����
		#ifdef _NEW_MPU6050_
		/*���ѭ����֤�����ݣ����ζ�ȡû���������*/
			MPU6050_Pose_usart();			//����ŷ����
		#else
			for(i=0;i<20;i++)
			MPU6050_Pose();				//����ŷ����
	   #endif
		/*ƫ����*/
		sprintf((char *)buff,"%0.1f",glYaw);
		Gui_DrawFont_GBK16(0,0,RED,WHITE,"glYAW:");
		Gui_DrawFont_GBK16(70,0,BLUE,WHITE,"      ");
		Gui_DrawFont_GBK16(70,0,BLUE,WHITE,(const char*)buff);
		/*������*/
		sprintf((char *)buff,"%0.1f",glPitch);
		Gui_DrawFont_GBK16(0,30,RED,WHITE,"glPitch:");
		Gui_DrawFont_GBK16(70,30,BLUE,WHITE,"      ");
		Gui_DrawFont_GBK16(70,30,BLUE,WHITE,(const char*)buff);
		/*������*/
		sprintf((char *)buff,"%0.1f",glRoll);
		Gui_DrawFont_GBK16(0,60,RED,WHITE,"glRoll:");
		Gui_DrawFont_GBK16(70,60,BLUE,WHITE,"      ");
		Gui_DrawFont_GBK16(70,60,BLUE,WHITE,(const char*)buff);
		
	}
}
/*

* �������ܣ������ŵ�һ�ֱ���·��ѡ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@��

*/
void Fun_runMethodSelectionFirst()
{
	u8 run_1=0;
	char buff[2];
	Lcd_Clear(WHITE); //����
	Gui_DrawFont_GBK16(10,20,RED,WHITE,"һ��·�߲�����");
	Gui_DrawFont_GBK16(0,60,RED,WHITE,"·��:");
	sprintf(buff,"%d",run_1);
	Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
	/*��һ��·��ѡ��*/
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag == KEY0_UP)
		{
			if(run_1<runMethodNum-1)
				run_1++;
			
			sprintf(buff,"%d",run_1);
			Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		}
		else if(keyFlag == KEY1_DOWN)
		{
			if(run_1>0)
				run_1--;
			
			sprintf(buff,"%d",run_1);
			Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		}
			
		if(keyFlag == KEY2_ENTER)
		{
			keyFlag = 0;
			runMethodUpdate(runMethod,run_1,runMethodTable);//��·�߱��е�·�߸��µ���һ�ֵ��ܷ���
			Gui_DrawFont_GBK16(40,100,BLUE,WHITE,"ȷ��?");
			break;
		}
	}
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC||keyFlag == KEY2_ENTER)break; //���а�������
	}
	
}
/*

* �������ܣ������ŵڶ��ֱ���·��ѡ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@��

*/
void Fun_runMethodSelectionSecond()
{
	u8 run_2=0;
	char buff[2];
	Lcd_Clear(WHITE); //����
	Gui_DrawFont_GBK16(10,20,RED,WHITE,"����·�߲�����");
	Gui_DrawFont_GBK16(0,60,RED,WHITE,"·��:");
	sprintf(buff,"%d",run_2);
	Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
	/*��һ��·��ѡ��*/
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag == KEY0_UP)
		{
			if(run_2<runMethodNum-1)
				run_2++;
			
			sprintf(buff,"%d",run_2);
			Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		}
		else if(keyFlag == KEY1_DOWN)
		{
			if(run_2>0)
				run_2--;
			
			sprintf(buff,"%d",run_2);
			Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		}
			
		if(keyFlag == KEY2_ENTER)
		{
			keyFlag = 0;
			runMethodUpdate(runMethod_2,run_2,runMethodTable);//��·�߱��е�·�߸��µ���һ�ֵ��ܷ���
			Gui_DrawFont_GBK16(40,100,BLUE,WHITE,"ȷ��?");
			break;
		}
	}
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC||keyFlag == KEY2_ENTER)break; //���а�������
	}
	
}

/*

* �������ܣ����ŵ�һ�ֱ���·��ѡ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@��

*/
void Fun_runDoorMethodSelectionFirst()
{
	u8 run_1=0;
	char buff[2];
	Lcd_Clear(WHITE); //����
	/*��һ��·��ѡ��*/
	Gui_DrawFont_GBK16(10,20,RED,WHITE,"һ��·�߹���");
	Gui_DrawFont_GBK16(0,60,RED,WHITE,"·��:");
	sprintf(buff,"%d",run_1);
	Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag == KEY0_UP)
		{
			if(run_1<runMethodNumDoor-1)
				run_1++;
			
			sprintf(buff,"%d",run_1);
			Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		}
		else if(keyFlag == KEY1_DOWN)
		{
			if(run_1>0)
				run_1--;
			
			sprintf(buff,"%d",run_1);
			Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		}
			
		if(keyFlag == KEY2_ENTER)
		{
			keyFlag = 0;
			runMethodUpdate(runMethod,run_1,runMethodTableDoor);//��·�߱��е�·�߸��µ���һ�ֵ��ܷ���
			Gui_DrawFont_GBK16(40,100,BLUE,WHITE,"ȷ��?");
			break;
		}

}
		while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC||keyFlag == KEY2_ENTER)break; //���а�������
	}
}

/*

* �������ܣ����ŵڶ��ֱ���·��ѡ��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@��

*/
void Fun_runDoorMethodSelectionSecond()
{
	u8 run_2=0;
	char buff[2];
	Lcd_Clear(WHITE); //����
	/*��һ��·��ѡ��*/
	Gui_DrawFont_GBK16(10,20,RED,WHITE,"����·�߹���");
	Gui_DrawFont_GBK16(0,60,RED,WHITE,"·��:");
	sprintf(buff,"%d",run_2);
	Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag == KEY0_UP)
		{
			if(run_2<runMethodNumDoor-1)
				run_2++;
			
			sprintf(buff,"%d",run_2);
			Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		}
		else if(keyFlag == KEY1_DOWN)
		{
			if(run_2>0)
				run_2--;
			
			sprintf(buff,"%d",run_2);
			Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
		}
			
		if(keyFlag == KEY2_ENTER)
		{
			keyFlag = 0;
			runMethodUpdate(runMethod_2,run_2,runMethodTableDoor);//��·�߱��е�·�߸��µ���һ�ֵ��ܷ���
			Gui_DrawFont_GBK16(40,100,BLUE,WHITE,"ȷ��?");
			break;
		}

}
		while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC||keyFlag == KEY2_ENTER)break; //���а�������
	}
}

/*

* �������ܣ������ܷ���ʾ
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void  runMethodDisplay()
{
	u8 temp=0;
	u8 tempRunMethod[100];
	char buff[2];
	u8 i=0,j=0,k=0;
	Lcd_Clear(WHITE); //����
	Gui_DrawFont_GBK16(0,0,RED,WHITE,"Total_Methods:");
	sprintf(buff,"%d",runMethodNum);
	Gui_DrawFont_GBK16(110,0,BLUE,WHITE,buff);
	
	sprintf(buff,"%d",temp);
	Gui_DrawFont_GBK16(60,20,RED,WHITE,buff);
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY0_UP && temp<runMethodNum-1)
		{
			i=j=k=0;
			temp++;
			sprintf(buff,"%d",temp);
			Gui_DrawFont_GBK16(60,20,RED,WHITE,buff);
			
			runMethodUpdate(tempRunMethod,temp,runMethodTable);
			Lcd_Clear_partial(0,40,128,160,WHITE);    //�ֲ�����
			while(tempRunMethod[i]!=0)
			{
				sprintf(buff,"%d",tempRunMethod[i]);
				Gui_DrawFont_GBK16(0+20*j,40+20*k,BLUE,WHITE,buff);
				i++;
				if(j<6)
					j++;
				else 
					j=0;
				if(j==0)
					k++;
			}
			
		}
		else if(keyFlag==KEY1_DOWN && temp>0)
		{
			i=j=k=0;
			temp--;
			sprintf(buff,"%d",temp);
			Gui_DrawFont_GBK16(60,20,RED,WHITE,buff);
			
			runMethodUpdate(tempRunMethod,temp,runMethodTable);
			Lcd_Clear_partial(0,40,128,160,WHITE);
			while(tempRunMethod[i]!=0)
			{
				sprintf(buff,"%d",tempRunMethod[i]);
				Gui_DrawFont_GBK16(0+20*j,40+20*k,BLUE,WHITE,buff);
				i++;
				if(j<6)
					j++;
				else 
					j=0;
				if(j==0)
					k++;
			}
		}
	
		else if(keyFlag == KEY4_ESC)
			break;
	}
	
}


/*

* �������ܣ�ѡ����Ե���·
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_debug()
{
	u8 temp=0;
	u8 tempRunMethod[100];
	char buff[2];
	u8 i=0,j=0,k=0;
	Lcd_Clear(WHITE); //����
	Gui_DrawFont_GBK16(60,0,RED,WHITE,"debug");
	Gui_DrawFont_GBK16(0,18,RED,WHITE,"chose Method:");
	sprintf(buff,"%d",temp);
	Gui_DrawFont_GBK16(105,20,RED,WHITE,buff);
	runMethodUpdate(tempRunMethod,temp,runMethodTableDebug);
	while(tempRunMethod[i]!=0)
	{
		sprintf(buff,"%d",tempRunMethod[i]);
		Gui_DrawFont_GBK16(0+20*j,40+17*k,BLUE,WHITE,buff);
		i++;
		if(j<6)
			j++;
		else 
			j=0;
		if(j==0)
				k++;
	}
	/*ѡ����Ե�·��*/
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY0_UP && temp<runMethodNumDebug-1)
		{
			i=j=k=0;
			temp++;
			sprintf(buff,"%d",temp);
			Gui_DrawFont_GBK16(105,20,RED,WHITE,buff);
			
			runMethodUpdate(tempRunMethod,temp,runMethodTableDebug);
			Lcd_Clear_partial(0,34,128,160,WHITE);    //�ֲ�����
			while(tempRunMethod[i]!=0)
			{
				sprintf(buff,"%d",tempRunMethod[i]);
				Gui_DrawFont_GBK16(0+20*j,40+17*k,BLUE,WHITE,buff);
				i++;
				if(j<6)
					j++;
				else 
					j=0;
				if(j==0)
					k++;
			}
			
		}
		else	if(keyFlag==KEY0_UP && temp==runMethodNumDebug-1)
		{
			i=j=k=0;
			temp=0;
			sprintf(buff,"%d",temp);
			Gui_DrawFont_GBK16(105,20,RED,WHITE,buff);
			
			runMethodUpdate(tempRunMethod,temp,runMethodTableDebug);
			Lcd_Clear_partial(0,34,128,160,WHITE);    //�ֲ�����
			while(tempRunMethod[i]!=0)
			{
				sprintf(buff,"%d",tempRunMethod[i]);
				Gui_DrawFont_GBK16(0+20*j,40+17*k,BLUE,WHITE,buff);
				i++;
				if(j<6)
					j++;
				else 
					j=0;
				if(j==0)
					k++;
			}
			
		}
		else if(keyFlag==KEY1_DOWN && temp>0)
		{
			i=j=k=0;
			temp--;
			sprintf(buff,"%d",temp);
			Gui_DrawFont_GBK16(105,20,RED,WHITE,buff);
			
			runMethodUpdate(tempRunMethod,temp,runMethodTableDebug);
			Lcd_Clear_partial(0,34,128,160,WHITE);
			while(tempRunMethod[i]!=0)
			{
				sprintf(buff,"%d",tempRunMethod[i]);
				Gui_DrawFont_GBK16(0+20*j,40+17*k,BLUE,WHITE,buff);
				i++;
				if(j<6)
					j++;
				else 
					j=0;
				if(j==0)
					k++;
			}
		}
		else if(keyFlag==KEY1_DOWN && temp==0)
		{
			i=j=k=0;
			temp=runMethodNumDebug-1;
			sprintf(buff,"%d",temp);
			Gui_DrawFont_GBK16(105,20,RED,WHITE,buff);
			
			runMethodUpdate(tempRunMethod,temp,runMethodTableDebug);
			Lcd_Clear_partial(0,34,128,160,WHITE);
			while(tempRunMethod[i]!=0)
			{
				sprintf(buff,"%d",tempRunMethod[i]);
				Gui_DrawFont_GBK16(0+20*j,40+17*k,BLUE,WHITE,buff);
				i++;
				if(j<6)
					j++;
				else 
					j=0;
				if(j==0)
					k++;
			}
		}
		else if(keyFlag == KEY2_ENTER)
		{
			runMethodUpdate(runMethod,temp,runMethodTableDebug);  //��·�߱��е�·�߸��µ�runMethod
			Gui_DrawFont_GBK16(60,140,BLUE,WHITE,"OK");
			delay_ms(500);
			break;
		}	
		else if(keyFlag == KEY4_ESC)
		{
			break;
		}
	}
	
}




/*

* �������ܣ�ѡ����Ե���·�ĵ���·��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_roadDebug()
{
	static u8 runMethod_Test[5];
	static char Num;
	char buff[2];
	Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(20,0,RED,WHITE,"chose road");
	
	Gui_DrawFont_GBK16(0,20,BLUE,WHITE,"curNode:");
	Gui_DrawFont_GBK16(0,40,BLUE,WHITE,"nextNode:");
	Gui_DrawFont_GBK16(0,60,BLUE,WHITE,"nnNode:");
	Gui_DrawFont_GBK16(0,80,BLUE,WHITE,"nnnNode:");
	
	sprintf(buff,"%d",runMethod_Test[0]);
	Gui_DrawFont_GBK16(80,20,BLUE,WHITE,buff);
			
  sprintf(buff,"%d",runMethod_Test[1]);
  Gui_DrawFont_GBK16(80,40,BLUE,WHITE,buff);
			
	sprintf(buff,"%d",runMethod_Test[2]);
	Gui_DrawFont_GBK16(80,60,BLUE,WHITE,buff);
			
	sprintf(buff,"%d",runMethod_Test[3]);
	Gui_DrawFont_GBK16(80,80,BLUE,WHITE,buff);
	
	while(1)
	{
		keyFlag = keyScan(1);
		if(keyFlag == KEY0_UP && Num<strlen((const char*)runMethod)-4)
		{	
			Num++;
			runMethod_Test[0]=runMethod[Num];
			runMethod_Test[1]=runMethod[Num+1];
			runMethod_Test[2]=runMethod[Num+2];
			runMethod_Test[3]=runMethod[Num+3];
		//	runMethod_Test[4]=runMethod[Num+4];
			
			Lcd_Clear_partial(80,20,128,100,WHITE); //�ֲ�����
			
			sprintf(buff,"%d",runMethod_Test[0]);
			Gui_DrawFont_GBK16(80,20,BLUE,WHITE,buff);
			
			sprintf(buff,"%d",runMethod_Test[1]);
			Gui_DrawFont_GBK16(80,40,BLUE,WHITE,buff);
			
			sprintf(buff,"%d",runMethod_Test[2]);
			Gui_DrawFont_GBK16(80,60,BLUE,WHITE,buff);
			
			sprintf(buff,"%d",runMethod_Test[3]);
			Gui_DrawFont_GBK16(80,80,BLUE,WHITE,buff);
		}
		else if(keyFlag == KEY1_DOWN && Num>0)
		{
			Num--;
			runMethod_Test[0]=runMethod[Num];
			runMethod_Test[1]=runMethod[Num+1];
			runMethod_Test[2]=runMethod[Num+2];
			runMethod_Test[3]=runMethod[Num+3];
		//	runMethod_Test[4]=runMethod[Num+4];
			
			Lcd_Clear_partial(80,20,128,100,WHITE); //�ֲ�����
			
			sprintf(buff,"%d",runMethod_Test[0]);
			Gui_DrawFont_GBK16(80,20,BLUE,WHITE,buff);
			
			sprintf(buff,"%d",runMethod_Test[1]);
			Gui_DrawFont_GBK16(80,40,BLUE,WHITE,buff);
			
			sprintf(buff,"%d",runMethod_Test[2]);
			Gui_DrawFont_GBK16(80,60,BLUE,WHITE,buff);
			
			sprintf(buff,"%d",runMethod_Test[3]);
			Gui_DrawFont_GBK16(80,80,BLUE,WHITE,buff);
		
		}
		else if(keyFlag == KEY2_ENTER)
		{
			Gui_DrawFont_GBK16(20,105,RED,WHITE,"debug_start");
			Gui_DrawFont_GBK16(0,130,RED,WHITE,"MPU6050_Init...");
			MPU6050_Init();		        //MPU6050��ʼ��
			Gui_DrawFont_GBK16(0,130,RED,WHITE,"               ");
			Gui_DrawFont_GBK16(0,130,RED,WHITE,"Start...");
		
			/*****����߼����ʼ������*****/
			Control_Init(&glHello_control,runMethod_Test);     //��ʼ������̨
			runStateInit(&glrunState,&glHello_control);		//���ݿ���̨��ʼ·�γ�ʼ������״̬
		
			/*���³�ʼ��*/
			runTimes = 0;						//��¼���ܴ���
			gl_time=0;							//��ʱ��3��־
			mpu6050_flag=0;					//��־����̨
			findLineFlag=0;					//Ѳ�߷�����ʼ����־λ
			
			while(1)
			{
				/*���а������¾�����*/
				keyFlag = keyScan(0);
				if(keyFlag==KEY4_ESC)
				{
					speedAdjustment(0,0);
					Time7(STOP);    			 //�رն�ʱ��
					mpu6050_samping(STOP); //�ر�mpu6050����
					Lcd_Clear_partial(0,105,128,160,WHITE);  //�ֲ�����
					break;
				} 
				/*����һ��·�βŸ���һ��*/
				if(control_Update(&glHello_control,strlen((const char*)runMethod_Test),runMethod_Test,mapInformation))//����⵽�ڵ��ͻ���¿���̨������//sizeof(runMethod)/sizeof(runMethod[0])
				{
					runStateReset(&glrunState,&glHello_control);//��������״̬
					findLineFlag=0;
					//controlCenter_u3printf(runMethod_Test,&glHello_control);
				}
				/*�������һ�ξͽ���һ�δ���*/
				if(sampingStatus() == 1) 
				{	
						if(glrunState.F_LineState == EIC)
					{
						speedAdjustment(0,0);
						Lcd_Clear_partial(0,105,128,160,WHITE);  //�ֲ�����
						Time7(STOP);    			 //�رն�ʱ��
						mpu6050_samping(STOP); //�ر�mpu6050����
						break;
					}
					
					findLine_Task(&glHello_control,&glrunState);        	 // Ѳ������
					roadBlocksHandle_Task(&glHello_control,&glrunState);	 // �ϰ���������
          speed_Task(&glHello_control,&glrunState);			      	//��������
					seekNode_Task(&glHello_control,&glrunState);      		 // �ҵ�����
					carPark_Task(&glHello_control, &glrunState);       		 // ͣ������
					rotAngle_Task(&glHello_control,&glrunState);           // ת������
				}
					
				else if(keyFlag == KEY4_ESC)
				{
					break;
				}
			}
		
		}
		
		
		
	}

	

}



/*

* �������ܣ���ʾ���Ե�·��
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void Fun_debugDisplay()
{
	u8 i=0;
	u8 j=0;
	u8 k=0;
	char buff[2];
	Lcd_Clear(WHITE); //����
	Gui_DrawFont_GBK16(2,0,RED,WHITE,"debug runMethod");
	while(runMethod[i]!=0)
	{
		sprintf(buff,"%d",runMethod[i]);
		Gui_DrawFont_GBK16(0+20*j,20+17*k,BLUE,WHITE,buff);
		i++;
		if(j<6)
			j++;
		else 
			j=0;
		if(j==0)
				k++;
	}
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN || keyFlag==KEY2_ENTER || keyFlag==KEY4_ESC)
			break;
	}

}



/******************************************************************************************************************/
	/*�˵���4������10������*/
	/*��ǰ���¡��ϡ����롢����*/
// ��ǰ��������
// ���°�����Ҫ��ת������
// ���ϰ�����Ҫ��ת������
// ȷ�ϰ�����Ҫ��ת������
// ���ذ�����Ҫ��ת������
myGUIIndexTypeDef const keyTab[GUI_NUM]={
	{0,1,0,25,26,(*Fun_menuDisplay)	},   //�˵���ʾ��ģʽѡ��
	{1,2,1,8,1,(*Fun_compCursor)	},  //�������
	{2,3,1,7,2,(*Fun_debugCursor)	},  //·�ε��Թ��
	{3,4,2,6,3,(*Fun_sensorCursor)},  //�������������
	{4,11,3,5,4,(*Fun_gyroCursor)	},  //�����ǹ��
	{5,5,5,5,0,(*Fun_groyDisplay)	},  //ŷ������ʾ
	{6,9,6,6,0,(*Fun_analogDisplay)},  //ģ������ʾ
	{7,7,7,13,0,(*Fun_debug)},        //ѡ����Ե���·
	{8,17,16,8,0,(*Fun_RouteSelectionInterfaceFirst)},  //��һ��·��ѡ���Ƿ����
	{9,15,6,9,0,(*Fun_sensorBitDisplay)},   //��̺��������λ��ʾ
	{10,10,8,10,0,(*Fun_game)},     //����
	{11,11,0,12,11,(*Fun_runMethodCursor)},  //·����ʾ���
	{12,12,12,12,0,(*runMethodDisplay)},   //�����ܷ���ʾ
	{13,14,13,13,14,(*Fun_roadDebug)},    //ѡ����Ե���·�ĵ���·��
	{14,13,14,13,0,(*Fun_debugDisplay)},    //��ʾ���Ե�·��
	{15,15,9,15,0,(*Fun_sensorBitDisplay_brige)},   //����������λ��ʾ
	
	
	{16,17,17,18,0,(*Fun_EnterDoor)},               //���Ź��
	{17,16,16,19,0,(*Fun_DontEnterDoor)},           //�����Ź��
	{18,18,18,20,0,(*Fun_runDoorMethodSelectionFirst)},      //���ŵĵ�һ��·��ѡ��
	{19,19,19,20,0,(*Fun_runMethodSelectionFirst)},       //�����ŵĵ�һ��·��ѡ��
	
	
	{20,22,21,20,0,(*Fun_RouteSelectionInterfaceSecond)},         //�ڶ���·��ѡ���Ƿ����
	{21,22,22,23,0,(*Fun_EnterDoor)},                 //���Ź��
	{22,21,21,24,0,(*Fun_DontEnterDoor)},                         //�����Ź��
	{23,23,23,10,0,(*Fun_runDoorMethodSelectionSecond)},                      //���ŵĵڶ���·��ѡ��
	{24,24,24,10,0,(*Fun_runMethodSelectionSecond)},                      //�����ŵĵڶ���·��ѡ��
	{25,0,0,0,0,(*Fun_SecondGameMethod1)},
	{26,0,0,0,0,(*Fun_SecondGameMethod2)},
};


/*

* �������ܣ��������
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void displayOperation(void)
{
	switch(keyFlag)
	{
		case KEY1_DOWN	:	keyFun = keyTab[keyFun].downIndex;	keyFlag=0;	break;
		case KEY0_UP		:	keyFun = keyTab[keyFun].upIndex;		keyFlag=0;	break;
		case KEY2_ENTER	:	keyFun = keyTab[keyFun].enterIndex;	keyFlag=0;	break;
		case KEY4_ESC		:	keyFun = keyTab[keyFun].escIndex;		keyFlag=0;	break;
		case KEY3_MENU  : keyFun = keyTab[keyFun].enterIndex;	keyFlag=0;	break;
		
		default:break;
	}
		keyFunPt = keyTab[keyFun].function;
		(*keyFunPt)();                     //ִ�е�ǰ��������
}





