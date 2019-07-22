#include "myGUI.h"

extern const unsigned char bootLogo[32768];

u8 keyFun=0;        //装载菜单索引
void (*keyFunPt)(); //指针函数
u8 keyFlag=0;				//记载键值

/*

* 函数介绍：图片显示(取模方式 水平扫描 从左到右 低位在前)
* 输入参数：x(图片开始显示x坐标)y(图片开始显示y坐标)xMax（图片宽度）yMax（图片长度）image（图片地址）
* 输出参数：
* 返回值  ：
* 作者    ：@断忆

*/
static void showImage(u16 x,u16 y,u8 xMax,u8 yMax,const u8 *image)
{
	int i;
	u16 date;
	
	Lcd_Clear(WHITE); //清屏 

	Lcd_SetRegion(x,y,x+xMax-1,y+yMax-1);		//坐标设置	
	for(i=0;i<xMax*yMax;i++)
	{
			date = image[i*2+1];
			date<<=8;
			date|=image[i*2];
			LCD_WriteData_16Bit(date);
	}


}



/*

* 函数介绍：开机界面显示
* 输入参数：无
* 输出参数：
* 返回值  ：
* 作者    ：@断忆

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

* 函数介绍：控制状态显示
* 输入参数：无
* 输出参数：
* 返回值  ：
* 作者    ：@断忆

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
/******************************************对应界面执行函数**************************************************************/
/************************************************************************************************************************/

/*

* 函数介绍：菜单显示（模式选择）
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

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

* 函数介绍：竞赛光标
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_compCursor(void)
{
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"  "); //清除调试光标
	Gui_DrawFont_GBK16(100,40,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN || keyFlag==KEY2_ENTER)break; //当有按键按下就跳出
	}
}

/*

* 函数介绍：第一轮路线选择界面(是否过门)
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@林

*/
void Fun_RouteSelectionInterfaceFirst(void)
{
		Lcd_Clear(WHITE);
		Gui_DrawFont_GBK16(30,10,RED,WHITE,"һ��·��");      //第一轮路线选择
		Gui_DrawFont_GBK16(30,40,RED,WHITE,"�Ƿ����");   //是否过门
	Gui_DrawFont_GBK16(0,70,BLUE,WHITE,"��");            //不过门
		Gui_DrawFont_GBK16(0,100,BLUE,WHITE,"��");          //过门
		while(1)
		{
			keyFlag = keyScan(0);
			if(keyFlag==KEY0_UP||keyFlag==KEY1_DOWN||keyFlag==KEY4_ESC)break; //当有按键按下就跳
		}
}
/*

* 函数介绍：第二轮路线选择界面(是否过门)
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@林

*/
void Fun_RouteSelectionInterfaceSecond(void)
{
		Lcd_Clear(WHITE);
		Gui_DrawFont_GBK16(30,10,RED,WHITE,"����·��");      //第二轮路线选择
		Gui_DrawFont_GBK16(30,40,RED,WHITE,"�Ƿ����");   //是否过门
		Gui_DrawFont_GBK16(0,70,BLUE,WHITE,"��");            //不过门
		Gui_DrawFont_GBK16(0,100,BLUE,WHITE,"��");          //过门
		while(1)
		{
			keyFlag = keyScan(0);
			if(keyFlag==KEY0_UP||keyFlag==KEY1_DOWN||keyFlag==KEY4_ESC)break; //当有按键按下就跳
		}
}
/*

* 函数介绍：过门光标
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@林

*/
void Fun_EnterDoor(void)
{
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"  "); //清除不过门光标
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN|| keyFlag==KEY0_UP  || keyFlag==KEY2_ENTER||keyFlag==KEY4_ESC)break; //当有按键按下就跳出
	}
}
/*

* 函数介绍：不过门光标
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@林

*/
void Fun_DontEnterDoor(void)
{
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"  "); //清除过门光标光标
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN|| keyFlag==KEY0_UP  || keyFlag==KEY2_ENTER||keyFlag==KEY4_ESC)break; //当有按键按下就跳出
	}
}



/*

* 函数介绍：路段调试光标
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_debugCursor(void)
{
	Gui_DrawFont_GBK16(100,40,RED,WHITE,"  "); //清除竞赛光标
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"  ");//清除光敏光标
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN || keyFlag==KEY0_UP || keyFlag == KEY2_ENTER)break; //当有按键按下就跳出
	}
}

/*

* 函数介绍：光敏传感器光标
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_sensorCursor(void)
{
	Gui_DrawFont_GBK16(100,70,RED,WHITE,"  ");//清除路段调试光标
	Gui_DrawFont_GBK16(100,130,RED,WHITE,"  ");//清除陀螺仪光标
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"<-");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN || keyFlag==KEY0_UP || keyFlag == KEY2_ENTER)break; //当有按键按下就跳出
	}
}

/*

* 函数介绍：陀螺仪光标
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_gyroCursor(void)
{
	Gui_DrawFont_GBK16(100,100,RED,WHITE,"  ");//清除光敏传感器光标
	Gui_DrawFont_GBK16(100,130,RED,WHITE,"<-");
	
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY0_UP || keyFlag == KEY2_ENTER || keyFlag == KEY1_DOWN)break; //当有按键按下就跳出
	}
}

/*

* 函数介绍：路线显示光标
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

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
		if(keyFlag==KEY0_UP || keyFlag == KEY2_ENTER)break; //当有按键按下就跳出
	}
}






/*

* 函数介绍：将数字量转化成二进制字符串
* 输入参数：（buff）储存字符串value（数字量）
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

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

* 函数介绍：绿毯数字量按位显示
* 输入参数：value（数字量）
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_sensorBitDisplay(void)
{
	u8 buff[12];
	u16 temp_dig_value;
	Lcd_Clear(WHITE); //清屏
	Gui_DrawFont_GBK16(0,0,RED,WHITE,"GreenCarpet������:");
	Gui_DrawFont_GBK16(0,40,RED,WHITE,"Hex:0x");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY0_UP || keyFlag == KEY4_ESC ||keyFlag == KEY1_DOWN)break; //当有按键按下就跳出
		
		if(sampingStatus() == 1)
		{
			temp_dig_value = sensorAD(glsensor_ad_value,basic_sensorThreshold);  				//与阈值比较后将模拟量转化成数字量
			dig_Binary(buff,temp_dig_value) ;    //转化成2进制储存在buff中
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

* 函数介绍：桥数字量按位显示
* 输入参数：value（数字量）
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_sensorBitDisplay_brige(void)
{
	u8 buff[12];
	u16 temp_dig_value;
	Lcd_Clear(WHITE); //清屏
	Gui_DrawFont_GBK16(0,0,RED,WHITE,"Brige������:");
	Gui_DrawFont_GBK16(0,40,RED,WHITE,"Hex:0x");
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY0_UP || keyFlag == KEY4_ESC)break; //当有按键按下就跳出
		
		if(sampingStatus() == 1)
		{
			temp_dig_value = sensorAD(glsensor_ad_value,brige_sensorThreshold);  				//与阈值比较后将模拟量转化成数字量
			dig_Binary(buff,temp_dig_value) ;    //转化成2进制储存在buff中
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

* 函数介绍：模拟量显示
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_analogDisplay(void)
{
	u8 buff[4];
	u8 i;
	Lcd_Clear(WHITE); //清屏
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY1_DOWN || keyFlag==KEY4_ESC)break; //当有按键按下就跳出
		
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

* 函数介绍：欧拉角显示
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_groyDisplay(void)
{
	u8 buff[7];
	u8 i;
	Lcd_Clear(WHITE); //清屏
	Gui_DrawFont_GBK16(0,20,RED,WHITE,"MPU6050_Init...");
	MPU6050_Init();		        //MPU6050初始化
    Gui_DrawFont_GBK16(0,20,RED,WHITE,"               ");

	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC)break; //当有按键按下就跳出
		#ifdef _NEW_MPU6050_
		/*多次循环保证有数据，单次读取没有数据输出*/
			MPU6050_Pose_usart();			//更新欧拉角
		#else
			for(i=0;i<20;i++)
			MPU6050_Pose();				//更新欧拉角
	   #endif
		/*偏航角*/
		sprintf((char *)buff,"%0.1f",glYaw);
		Gui_DrawFont_GBK16(0,0,RED,WHITE,"glYAW:");
		Gui_DrawFont_GBK16(70,0,BLUE,WHITE,"      ");
		Gui_DrawFont_GBK16(70,0,BLUE,WHITE,(const char*)buff);
		/*俯仰角*/
		sprintf((char *)buff,"%0.1f",glPitch);
		Gui_DrawFont_GBK16(0,30,RED,WHITE,"glPitch:");
		Gui_DrawFont_GBK16(70,30,BLUE,WHITE,"      ");
		Gui_DrawFont_GBK16(70,30,BLUE,WHITE,(const char*)buff);
		/*翻滚角*/
		sprintf((char *)buff,"%0.1f",glRoll);
		Gui_DrawFont_GBK16(0,60,RED,WHITE,"glRoll:");
		Gui_DrawFont_GBK16(70,60,BLUE,WHITE,"      ");
		Gui_DrawFont_GBK16(70,60,BLUE,WHITE,(const char*)buff);
		
	}
}
/*

* 函数介绍：不过门第一轮比赛路线选择
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@林

*/
void Fun_runMethodSelectionFirst()
{
	u8 run_1=0;
	char buff[2];
	Lcd_Clear(WHITE); //清屏
	Gui_DrawFont_GBK16(10,20,RED,WHITE,"һ��·�߲�����");
	Gui_DrawFont_GBK16(0,60,RED,WHITE,"·��:");
	sprintf(buff,"%d",run_1);
	Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
	/*第一轮路线选择*/
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
			runMethodUpdate(runMethod,run_1,runMethodTable);//将路线表中的路线更新到第一轮的跑法中
			Gui_DrawFont_GBK16(40,100,BLUE,WHITE,"ȷ��?");
			break;
		}
	}
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC||keyFlag == KEY2_ENTER)break; //当有按键按下
	}
	
}
/*

* 函数介绍：不过门第二轮比赛路线选择
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@林

*/
void Fun_runMethodSelectionSecond()
{
	u8 run_2=0;
	char buff[2];
	Lcd_Clear(WHITE); //清屏
	Gui_DrawFont_GBK16(10,20,RED,WHITE,"����·�߲�����");
	Gui_DrawFont_GBK16(0,60,RED,WHITE,"·��:");
	sprintf(buff,"%d",run_2);
	Gui_DrawFont_GBK16(60,60,BLUE,WHITE,buff);
	/*第一轮路线选择*/
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
			runMethodUpdate(runMethod_2,run_2,runMethodTable);//将路线表中的路线更新到第一轮的跑法中			Gui_DrawFont_GBK16(40,100,BLUE,WHITE,"ȷ��?");
			break;
		}
	}
	while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC||keyFlag == KEY2_ENTER)break; //当有按键按下
	}
	
}

/*

* 函数介绍：过门第一轮比赛路线选择
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@林

*/
void Fun_runDoorMethodSelectionFirst()
{
	u8 run_1=0;
	char buff[2];
	Lcd_Clear(WHITE); //清屏
	/*第一轮路线选择*/
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
			runMethodUpdate(runMethod,run_1,runMethodTableDoor);//将路线表中的路线更新到第一轮的跑法中			runMethodUpdate(runMethod,run_1,runMethodTableDoor);//��·�߱��е�·�߸��µ���һ�ֵ��ܷ���
			Gui_DrawFont_GBK16(40,100,BLUE,WHITE,"ȷ��?");
			break;
		}

}
		while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC||keyFlag == KEY2_ENTER)break; //当有按键按下
	}
}

/*

* 函数介绍：过门第二轮比赛路线选择
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@林

*/
void Fun_runDoorMethodSelectionSecond()
{
	u8 run_2=0;
	char buff[2];
	Lcd_Clear(WHITE); //清屏
	/*第一轮路线选择*/
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
			runMethodUpdate(runMethod_2,run_2,runMethodTableDoor);//将路线表中的路线更新到第一轮的跑法中			Gui_DrawFont_GBK16(40,100,BLUE,WHITE,"ȷ��?");
			break;
		}

}
		while(1)
	{
		keyFlag = keyScan(0);
		if(keyFlag==KEY4_ESC||keyFlag == KEY2_ENTER)break; //当有按键按下
	}
}

/*

* 函数介绍：已有跑法显示
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void  runMethodDisplay()
{
	u8 temp=0;
	u8 tempRunMethod[100];
	char buff[2];
	u8 i=0,j=0,k=0;
	Lcd_Clear(WHITE); //清屏
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
			Lcd_Clear_partial(0,40,128,160,WHITE);    //局部清屏
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

* 函数介绍：选择调试的线路
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_debug()
{
	u8 temp=0;
	u8 tempRunMethod[100];
	char buff[2];
	u8 i=0,j=0,k=0;
	Lcd_Clear(WHITE); //清屏
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
	/*选择调试的路线*/
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
			Lcd_Clear_partial(0,34,128,160,WHITE);    //局部清屏
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
			Lcd_Clear_partial(0,34,128,160,WHITE);    //局部清屏
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
			runMethodUpdate(runMethod,temp,runMethodTableDebug);  //将路线表中的路线更新到runMethod
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

* 函数介绍：选择调试的线路的调试路段
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

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
			
			Lcd_Clear_partial(80,20,128,100,WHITE); //局部清屏
			
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
			
			Lcd_Clear_partial(80,20,128,100,WHITE); //局部清屏
			
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
			MPU6050_Init();		        //MPU6050初始化
			Gui_DrawFont_GBK16(0,130,RED,WHITE,"               ");
			Gui_DrawFont_GBK16(0,130,RED,WHITE,"Start...");
		
			/*****软件逻辑层初始化部分*****/
			Control_Init(&glHello_control,runMethod_Test);     //初始化控制台
			runStateInit(&glrunState,&glHello_control);		//根据控制台起始路段初始化运行状态
		
			/*重新初始化*/
			runTimes = 0;						//记录奔跑次数
			gl_time=0;							//定时器3标志
			mpu6050_flag=0;					//标志上下台
			findLineFlag=0;					//巡线方法初始化标志位
			
			while(1)
			{
				/*当有按键按下就跳出*/
				keyFlag = keyScan(0);
				if(keyFlag==KEY4_ESC)
				{
					speedAdjustment(0,0);
					Time7(STOP);    			 //关闭定时器
					mpu6050_samping(STOP); //关闭mpu6050采样
					Lcd_Clear_partial(0,105,128,160,WHITE);  //局部清屏
					break;
				} 
				/*跑完一个路段才更新一次*/
				if(control_Update(&glHello_control,strlen((const char*)runMethod_Test),runMethod_Test,mapInformation))//当检测到节点后就会更新控制台的数据//sizeof(runMethod)/sizeof(runMethod[0])
				{
					runStateReset(&glrunState,&glHello_control);//重置运行状态
					findLineFlag=0;
					//controlCenter_u3printf(runMethod_Test,&glHello_control);
				}
				/*采样完成一次就进行一次处理*/
				if(sampingStatus() == 1) 
				{	
						if(glrunState.F_LineState == EIC)
					{
						speedAdjustment(0,0);
						Lcd_Clear_partial(0,105,128,160,WHITE);  //局部清屏
						Time7(STOP);    			 //关闭定时器
						mpu6050_samping(STOP); //关闭mpu6050采样
						break;
					}
					
					findLine_Task(&glHello_control,&glrunState);        	 // 巡线任务
					roadBlocksHandle_Task(&glHello_control,&glrunState);	 // 障碍处理任务
          speed_Task(&glHello_control,&glrunState);			      	//加速任务
					seekNode_Task(&glHello_control,&glrunState);      		 // 找点任务
					carPark_Task(&glHello_control, &glrunState);       		 // 停车任务
					rotAngle_Task(&glHello_control,&glrunState);           // 转弯任务
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

* 函数介绍：显示调试的路段
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

*/
void Fun_debugDisplay()
{
	u8 i=0;
	u8 j=0;
	u8 k=0;
	char buff[2];
	Lcd_Clear(WHITE); //清屏
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
	/*菜单分4级，共10个界面*/
	/*当前、下、上、进入、返回*/
// 当前界面索引
// 向下按键需要跳转的索引
// 向上按键需要跳转的索引
// 确认按键需要跳转的索引
// 返回按键需要跳转的索引
myGUIIndexTypeDef const keyTab[GUI_NUM]={
	{0,1,0,25,26,(*Fun_menuDisplay)	},   //菜单显示（模式选择）
	{1,2,1,8,1,(*Fun_compCursor)	},  //竞赛光标
	{2,3,1,7,2,(*Fun_debugCursor)	},  //路段调试光标
	{3,4,2,6,3,(*Fun_sensorCursor)},  //光敏传感器光标
	{4,11,3,5,4,(*Fun_gyroCursor)	},  //陀螺仪光标
	{5,5,5,5,0,(*Fun_groyDisplay)	},  //欧拉角显示
	{6,9,6,6,0,(*Fun_analogDisplay)},  //模拟量显示
	{7,7,7,13,0,(*Fun_debug)},        //选择调试的线路
	{8,17,16,8,0,(*Fun_RouteSelectionInterfaceFirst)},  //第一轮路线选择，是否过门
	{9,15,6,9,0,(*Fun_sensorBitDisplay)},   //绿毯数字量按位显示
	{10,10,8,10,0,(*Fun_game)},     //比赛
	{11,11,0,12,11,(*Fun_runMethodCursor)},  //路线显示光标
	{12,12,12,12,0,(*runMethodDisplay)},   //已有跑法显示
	{13,14,13,13,14,(*Fun_roadDebug)},    //选择调试的线路的调试路段
	{14,13,14,13,0,(*Fun_debugDisplay)},    //显示调试的路段
	{15,15,9,15,0,(*Fun_sensorBitDisplay_brige)},   //桥数字量按位显示
	
	
	{16,17,17,18,0,(*Fun_EnterDoor)},               //过门光标
	{17,16,16,19,0,(*Fun_DontEnterDoor)},           //不过门光标
	{18,18,18,20,0,(*Fun_runDoorMethodSelectionFirst)},      //过门的第一轮路线选择
	{19,19,19,20,0,(*Fun_runMethodSelectionFirst)},       //不过门的第一轮路线选择
	
	
	{20,22,21,20,0,(*Fun_RouteSelectionInterfaceSecond)},         //第二轮路线选择，是否过门
	{21,22,22,23,0,(*Fun_EnterDoor)},                 //过门光标
	{22,21,21,24,0,(*Fun_DontEnterDoor)},                         //不过门光标
	{23,23,23,10,0,(*Fun_runDoorMethodSelectionSecond)},                      //过门的第二轮路线选择
	{24,24,24,10,0,(*Fun_runMethodSelectionSecond)},                      //不过门的第二轮路线选择
	{25,0,0,0,0,(*Fun_SecondGameMethod1)},
	{26,0,0,0,0,(*Fun_SecondGameMethod2)},
};


/*

* 函数介绍：界面操作
* 输入参数：无
* 输出参数：无
* 返回值  ：无
* 作者    ：@断忆

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
		(*keyFunPt)();                     //执行当前按键功能
}





