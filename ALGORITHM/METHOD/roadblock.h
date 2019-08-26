#ifndef _ROADBLOCK_H_
#define _ROADBLOCK_H_
#include "sys.h"
#include "myconfig.h"

u8 BlockHandleMethod_Brige(void);      //过桥处理
u8 BlockHandleMethod_DOOR(void);      //过门处理(门开状态不需要撞)
u8 BlockHandleMethod_DOOR_Click(void);//过门处理（门开状态需要撞）
u8 BlockHandleMethod_Platform (void);	 //平台景点
u8 BlockHandleMethod_Platform_1 (void); //起点
u8 BlockHandleMethod_Peak(void); //上珠峰景点
u8 BlockHandleMethod_downPlatform(void);//下珠峰
u8 BlockHandleMethod_BOARD(void);//平板
u8 BlockHandleMethod_S_BOARD(void);//减速板1个
u8 BlockHandleMethod_S_BOARD_Double(void);//减速板2个
u8 BlockHandleMethod_26_27(void);//26到27节点
u8 Angle_read(void);
u8 BlockHandleMethod_Sword (void);
u8 BlockHandleMethod_Seesaw(void);
u8 BlockHandleMethod_Slope(void);      //山丘
u8 BlockHandleMethod_down_27_26(void);
u8 BlockHandleMethod_S_BOARD_Double(void);
u8 BlockHandleBODY_UP(void);
u8 blockHandleBODY_DOWN(void);



u8 BlockHandleMethod_Trapezoid_1(void);
u8 BlockHandleMethod_Trapezoid_2(void);	 //梯形景点
u8 BlockHandleMethod_Trapezoid_3(void);

u8 BlockHandleMethod_GO_Tilt_R(void);     //前往右转斜坡景点
u8 BlockHandleMethod_GO_Tilt_L(void);     //前往左转斜坡景点 

u8 BlockHandleMethod_BACK_TILT_R(void);   //返回右转斜坡
u8 BlockHandleMethod_BACK_TILT_L(void);		//返回左转斜坡
u8 BlockHandleMethod_Crossing_All_TILT(void); //穿过整个斜坡
u8 BlockHandleMethod_Slope (void);

#endif



