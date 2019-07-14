#ifndef _MYGUI_H_
#define _MYGUI_H_

#include "myconfig.h"

#define  GUI_NUM 30

extern u8 keyFlag;


typedef struct{
	
	u8 curIndex;				// ��ǰ��������
	u8 downIndex;				// ���°�����Ҫ��ת������
	u8 upIndex;					// ���ϰ�����Ҫ��ת������
	u8 enterIndex;			// ȷ�ϰ�����Ҫ��ת������
	u8 escIndex;				// ���ذ�����Ҫ��ת������
//	excState state;     //ִ��״̬ 
	void (*function)(); // ��ǰ����ִ�к�������ڵ�ַ
		
}myGUIIndexTypeDef;

void bootDisplay(void);
void displayOperation(void);
void displayControl(controlCenterTypeDef *controlp);



#endif











