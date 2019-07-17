#ifndef _ROADBLOCK_H_
#define _ROADBLOCK_H_
#include "sys.h"
#include "myconfig.h"

u8 BlockHandleMethod_Brige(void);      //���Ŵ���
u8 BlockHandleMethod_DOOR(void);      //����1����
u8 BlockHandleMethod_DOOR_2(void);
//u8 BlockHandleMethod_DOORBack(void);   //�ؼҹ��Ŵ���
u8 BlockHandleMethod_Platform (void);	 //ƽ̨����
u8 BlockHandleMethod_Platform_1 (void); //���
u8 BlockHandleMethod_Peak(void); //����徰��
u8 BlockHandleMethod_downPlatform(void);//�����
u8 BlockHandleMethod_S_BOARD_1(void);//���ٰ�1
u8 BlockHandleMethod_S_BOARD_2(void);//���ٰ�2
u8 BlockHandleMethod_S_BOARD_Double(void);
u8 BlockHandleMethod_26_27(void);//26��27�ڵ�
u8 Angle_read(void);
u8 BlockHandleMethod_Seesaw(void);
u8 BlockHandleMethod_Slope(void);      //ɽ��
u8 BlockHandleMethod_down_27_26(void);
u8 BlockHandleMethod_S_BOARD_Double(void);



u8 BlockHandleMethod_Trapezoid_1(void);
u8 BlockHandleMethod_Trapezoid_2(void);	 //���ξ���
u8 BlockHandleMethod_Trapezoid_3(void);

u8 BlockHandleMethod_GO_Tilt_R(void);     //ǰ����תб�¾���
u8 BlockHandleMethod_GO_Tilt_L(void);     //ǰ����תб�¾��� 

u8 BlockHandleMethod_BACK_TILT_R(void);   //������תб��
u8 BlockHandleMethod_BACK_TILT_L(void);		//������תб��
u8 BlockHandleMethod_Crossing_All_TILT(void); //��������б��
u8 BlockHandleMethod_Slope (void);

#endif



