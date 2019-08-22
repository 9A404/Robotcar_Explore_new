#include "control.h"
#include "myconfig.h"

/*通过一个表示出地图  巡线方法 路障类型  加速方法  加速时间 找节点方法 停车方法 车头旋转角度*/

const map_linkInforTypeDef mapInformation[][NODEFORKNUM]={
/*节点*/	{	{0,0,},			},//没有用到

/*1节点*/	{	{2,1,FL_brige,FREE,NOSPEED,0,SEEK_default,PARK_default,HN_Rotate,0},{2,3,FL_default,PLATFORM_1,COMMON_SPEED,30,NOTSEEK,NOTPARK,HN_Rotate,0},	\
						{2,5,FL_default,PLATFORM_1,NOSPEED,0,SEEK_default,NOTPARK,rot_LFL,0},	
					},	

/*2节点*/	{	{1,2,FL_slow,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_default,HL_F,180},{3,4,FL_slow,BRIGE,COMMON_SPEED,25,NOTSEEK,NOTPARK,HN_Rotate,0},	\
						{5,9,FL_default,S_BOARD,NOSPEED,0,SEEK_default,PARK_pesL,HL,120},{5,6,FL_default,S_BOARD,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},	\
					},		

/*3节点*/	{	{2,1,FL_brige,FREE,NOSPEED,0,SEEK_default,PARK_default,HN_Rotate,0},{4,3,FL_default,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL_F,180},	\
						{5,9,FL_slow,SLOPE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},{5,6,FL_slow,SLOPE,NOSPEED,0,SEEK_default,PARK_pesR_150,HR,135},	\
					},		
	
/*4节点*/	{	{3,5,FL_default,PLATFORM,NOSPEED,0,SEEK_default,NOTPARK,rot_RFL,0},
					},

/*5节点*/	{	{2,1,FL_slow,S_BOARD,NOSPEED,0,SEEK_default,NOTPARK,HN_Rotate,0},{6,7,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},	\
						{6,8,FL_default,FREE,COMMON_SPEED,40,SEEK_default,NOTPARK,rot_RFL,0},{9,10,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate,0},	\
						{6,42,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_45,HL,90},{6,14,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_200,HL,90},	\
					},      

/*6节点*/	{	{7,6,FL_default,FREE,COMMON_SPEED,50,SEEK_PesPlatform,PARK_PesPlatform,HL_F,180},{8,6,FL_default,FREE,COMMON_SPEED,60,SEEK_Collision,NOTPARK,HL_F,180},	\
						{14,15,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL,90},{5,2,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,rot_LFL,0},	\
						{7,12,FL_default,FREE,COMMON_SPEED,50,SEEK_PesPlatform,PARK_PesPlatform,HL_F,180},{14,16,FL_default,FREE,COMMON_SPEED,60,SEEK4,PARK_pesR,HR,90},\
						{42,14,FL_slow,DOOR,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate,0},{14,35,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},	\
						{14,17,FL_default,FREE,COMMON_SPEED,60,SEEK4,PARK_pesR,HR,90},
					},                 

						
/*7节点*/	{	{12,11,FL_default,PLATFORM,COMMON_SPEED,330,SEEK_PesPlatform,PARK_PesPlatform,HN_Rotate,0},{6,14,FL_default,PLATFORM,NOSPEED,0,SEEK_default,PARK_pesR,HR,90},	\
						{12,10,FL_slow,PLATFORM,COMMON_SPEED,330,SEEK_PesPlatform,PARK_PesPlatform,HL_F,180},{6,42,FL_default,PLATFORM,NOSPEED,0,SEEK4,PARK_pesR,HR,90},	\
					},
	
/*8节点*/ {	{6,7,FL_slow,FREE,COMMON_SPEED,80,SEEK_default,PARK_pesR_300,HR_F,140},
					},

/*9节点*/	{	{10,12,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},{10,11,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,rot_LFL,0},	\
						{5,6,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},{39,15,FL_slow,DOOR,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate,0},	\
						{5,2,FL_default,FREE,COMMON_SPEED,10,SEEK_DIGR,PARK_pesR_200,HR_F,135},{39,9,FL_slow,FREE,NOSPEED,0,SEEK_Collision,PARK_Door,HL,180}, \
						{40,14,FL_slow,DOOR,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate,0},{40,9,FL_slow,FREE,NOSPEED,0,SEEK_Collision,PARK_Door,HL,180},	\
						{15,31,FL_default,FREE,COMMON_SPEED,50,SEEK_DIGL,NOTPARK,HN_Rotate,0},{31,32,FL_slow,FREE,COMMON_SPEED,100,SEEK_DIGR,PARK_pesR,HR,90},	\
						{39,30,FL_slow,DOOR,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate,0},{6,14,FL_default,FREE,COMMON_SPEED,80,SEEK_DIGL,PARK_pesL_300,HL,90},	\
						{14,17,FL_default,FREE,COMMON_SPEED,120,SEEK4,PARK_pesR,HR,35},{14,16,FL_default,FREE,COMMON_SPEED,120,SEEK4,PARK_pesR,HR,35},	\
						
					},

/*10节点*/{	{12,10,FL_default,PLATFORM,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL_F,180},{9,5,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},	\
						{9,40,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL,45},{9,39,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL,90},	\
						{9,15,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL,90},{9,14,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL,45},	\
						{11,10,FL_default,FREE,COMMON_SPEED,50,SEEK_Collision,NOTPARK,HL_F,180},{9,31,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL,90},	\
						{6,14,FL_default,FREE,COMMON_SPEED,120,SEEK_DIGL,PARK_pesL_300,HL,90},
					},         

/*11节点*/{	{10,9,FL_default,FREE,COMMON_SPEED,50,SEEK_PESL,NOTPARK,HR,35},{10,12,FL_slow,FREE,NOSPEED,0,SEEK_default,PARK_pesL_250,HL,120},	\
						{10,6,FL_default,FREE,COMMON_SPEED,50,SEEK_PESL,NOTPARK,HR,35},
					},

/*12节点*/{	{10,9,FL_default,PLATFORM,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},{10,11,FL_default,PLATFORM,COMMON_SPEED,30,SEEK_default,PARK_pesL,HR,135},	\
						
						
					},

/*13节点*/{	{14,35,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_45,HL,45},{9,5,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL,135}, \
						{14,17,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_45,HR,45},{40,9,FL_default,DOOR,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate,0},	\
					},

/*14节点*/{	{15,9,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL,90},{37,36,FL_default,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL,180},	\
						{16,17,FL_quick,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},{44,16,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},	\
						{35,36,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR,90},{42,6,FL_default,DOOR,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate,0},	\
						{44,43,FL_middle,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate,0},{6,5,FL_default,FREE,COMMON_SPEED,60,SEEK_default,PARK_pesL,HR,90},	\
						{34,30,FL_default,FREE,COMMON_SPEED,25,SEEK_DIGL,PARK_pesL_No,HL,90},{17,18,FL_default,FREE,COMMON_SPEED,80,SEEK_DIGL,PARK_pesL_No,HL,90},	\
            {16,44,FL_slow,ANGLE,NOSPEED,0,SEEK_default,PARK_pesR,HR_F,120},{17,20,FL_default,FREE,COMMON_SPEED,80,SEEK_DIGL,PARK_pesL_No,HL,90},		\
						{9,5,FL_default,FREE,COMMON_SPEED,120,SEEK4,PARK_pesR_200,HL,135},
					},	

/*15节点*/{	{9,5,FL_default,FREE,COMMON_SPEED,50,SEEK4,PARK_pesR,HL,90},{39,9,FL_default,DOOR,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate,0},	\
						{31,32,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR,90},	
					},

/*16节点*/{	{17,18,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_No,HL,90},{44,45,FL_16_44,FREE,NOSPEED,0,SEEK_SeeSaw,NOTPARK,HN_Rotate,0},	\
						{17,20,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_No,HL,90},
						
					},
	
/*17节点*/{	{18,20,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},{18,19,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesL,HL,90}, \
            {14,34,FL_default,FREE,COMMON_SPEED,90,SEEK_DIGR,PARK_pesR,HR,90},{43,44,FL_default,FREE,NOSPEED,0,SEEK_default,NOTPARK,HN_Rotate,0}, \
						{43,16,FL_slow,ANGLE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},{20,21,FL_default,FREE,COMMON_SPEED,80,SEEK4,PARK_pesL_No,HL,90},	\
					},

/*18节点*/{	{20,21,FL_default,FREE,COMMON_SPEED,30,SEEK4,PARK_pesL_No,HL,90},{19,18,FL_slow,FREE,NOSPEED,0,SEEK_Collision,NOTPARK,HN_Rotate,0},	\
            {17,43,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR_No,HR,90},{17,14,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR_No,HR,90},	\
						{17,37,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR_No,HR,90},
					},

/*19节点*/{	{18,17,BACK_NFL,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HL,90},{18,20,BACK_NFL,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HR,90},	\
					},

/*20节点*/{	{21,22,FL_default,FREE,COMMON_SPEED,30,SEEK4,PARK_pesL_No,HL,90},{18,17,FL_default,FREE,COMMON_SPEED,45,SEEK4,NOTPARK,HN_Rotate,0},		\
            {17,14,FL_default,FREE,COMMON_SPEED,70,SEEK4,PARK_pesR_No,HR,90},{18,19,FL_default,FREE,COMMON_SPEED,45,SEEK4,PARK_pesR,HR,90},	\
					},

					
/*21节点*/{	{22,23,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesR_200,HR_F,120},{20,18,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesR_No,HR,90},	\
					},

/*22节点*/{	{23,24,FL_slow,FREE,COMMON_SPEED,70,SEEK_default,PARK_pesR_250,HR,135},{21,20,FL_default,FREE,COMMON_SPEED,35,SEEK4,PARK_pesR_No,HR,90},	\
					},

/*23节点*/{	{24,23,FL_default,Peak,NOSPEED,0,NOTSEEK,PARK_PesPlatform,HL_F,180},{25,26,FL_sword,SWORD,NOSPEED,0,SEEK4,PARK_pesR,HR,90},\
						{22,21,FL_default,FREE,COMMON_SPEED,60,SEEK_default,PARK_pesL_200,HL,120},
					},
	
/*24节点*/{	{23,25,FL_default,DOWNPLATFORM,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},{23,22,FL_default,DOWNPLATFORM,NOSPEED,0,SEEK_default,PARK_pesL_200,HL,135},	\
						
					},

/*25节点*/{	{26,27,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesL,HL,90},{28,50,FL_slow,SLOPE,NOSPEED,20,SEEK4,PARK_pesL,HL,90},	\

					},

/*26节点*/{	{27,26,FL_default,UP_26_27,NOSPEED,0,NOTSEEK,PARK_PesPlatform,HL_F,180},{25,28,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR,90},	\
					},

/*27节点*/{	{26,25,FL_default,DOWN27_26,NOSPEED,20,SEEK4,PARK_pesR,HR,90},		\
					
					},

/*28节点*/{	{25,26,FL_slow,SLOPE,NOSPEED,0,SEEK4,PARK_pesL,HL,90},	{50,49,FL_default,FREE,COMMON_SPEED,10,SEEK4,PARK_pesL,HL,35},  \
           },

/*29节点*/{	{36,37,},	},

/*30节点*/{	{34,35,FL_slow,S_BOARD_DOUBLE,COMMON_SPEED,20,SEEK4,PARK_pesR,HR,90},{50,28,FL_slow,SLOPE,NOSPEED,0,SEEK_DIGR,PARK_pesR_No,HR,90},	\
					},

/*31节点*/{	{32,31,FL_slow,FREE,NOSPEED,0,SEEK_Collision,NOTPARK,HN_Rotate,0},{30,34,FL_slow,FREE,NOSPEED,0,SEEK_default,PARK_pesR_No,HR,90},	\
						
					},

/*32节点*/{	{31,30,BACK_NFL,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HL,90},
					},

/*33节点*/{	{33,33,},
					},

/*34节点*/{	{35,36,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesL,HL,90},{30,50,FL_slow,S_BOARD_DOUBLE,COMMON_SPEED,50,NOTSEEK,NOTPARK,HN_Rotate,0},	\
					},

/*35节点*/{	{36,35,FL_slow,FREE,NOSPEED,0,SEEK_Collision,NOTPARK,HN_Rotate,0},{14,37,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesL,HR,90},	\
						{14,42,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate,0},{14,17,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL,90},	\
						{14,16,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL,HL,90},{14,44,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL,90},	\
						{14,6,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate,0},	{14,9,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR,45},	\
						{6,5,FL_default,FREE,COMMON_SPEED,100,SEEK_default,PARK_pesL,HR,90},
					},

/*36节点*/{	{35,14,BACK_NFL,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HR,90},{35,34,BACK_NFL,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HL,90},	\
						{35,6,BACK_NFL,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HR,90},
						
					},

						
/*37节点*/{	{15,9,FL_quickest,PLATFORM,COMMON_SPEED,60,SEEK4,PARK_pesL,HR,90},{49,15,FL_default,PLATFORM,COMMON_SPEED,20,SEEK_PESL,NOTPARK,HN_Rotate,0},	\
						{15,31,FL_quickest,PLATFORM,COMMON_SPEED,60,SEEK4,PARK_pesL,HL,90},
					},

/*38节点*/{	{33,23,},{15,9,FL_quickest,Platform_37_15,NOSPEED,0,SEEK4,PARK_pesL,HR,90},	\
					},

/*39节点*/	{ {15,31,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0}, {9,5,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL,90}, \
							{9,40,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR_No,HL,120},
						},

/*40节点*/  {	{13,14,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},{9,6,FL_slow,FREE,NOSPEED,0,SEEK_DIGL,PARK_pesR_No,HL,120},	\
							{9,5,FL_slow,FREE,NOSPEED,0,SEEK_DIGL,PARK_pesL_No,HL,135},{14,17,FL_default,FREE,COMMON_SPEED,80,SEEK4,PARK_pesR,HR,35},	\
							{14,16,FL_default,FREE,COMMON_SPEED,80,SEEK4,PARK_pesR,HR,35},
						},

/*41节点*/  { {13,15,},
						},

/*42节点*/  {	{14,35,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},{14,37,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL,90},	\
							{6,5,FL_default,FREE,NOSPEED,0,SEEK_default,PARK_pesL,HR,90},{14,44,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR,90},	\
							{14,17,FL_default,FREE,COMMON_SPEED,40,SEEK4,PARK_pesR,HR,90},
						},

/*43节点*/  {	{44,14,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},{16,44,FL_slow,FREE,NOSPEED,0,NOTSEEK,NOTPARK,rot_LFL,0},	\
							{17,18,FL_default,FREE,NOSPEED,0,SEEK_default,PARK_pesL,HL,90},{44,37,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate,0},	\
						  {37,36,FL_slow,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL,180},{16,17,FL_circular,FREE,NOSPEED,0,SEEK_default,PARK_pesR_250,HR,145},	\
						},

/*44节点*/  {	{14,38,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate,0},{45,46,FL_slow,SEESAW,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate,0},	\
							{37,36,FL_quickest,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL,180},{43,17,FL_node,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},	\
						},

/*45节点*/  {{46,47,FL_circular,FREE,NOSPEED,0,SEEK_default,PARK_pesL,HL,90},
						},

/*46节点*/  {	{47,46,FL_default,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL_F,180},	{43,16,FL_circular,BRIGE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},	\
							{43,44,FL_circular,BRIGE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},{43,37,FL_circular,BRIGE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate,0},	\
							{48,43,FL_circular,FREE,NOSPEED,0,SEEK_SeeSaw_back,NOTPARK,HN_Rotate,0},
						},

/*47节点*/  {	{46,43,FL_slow,PLATFORM,NOSPEED,0,SEEK_default,PARK_pesL,HL,105},
              {46,48,FL_slow,PLATFORM,NOSPEED,0,SEEK_default,PARK_pesL,HL,90},
						},

/*48节点*/  {	{46,43,FL_slow,PLATFORM,NOSPEED,0,SEEK_default,PARK_pesL,HL,105},{43,16,FL_slow,SEESAW,NOSPEED,0,SEEK_default,NOTPARK,HN_Rotate,0},	\
						},

/*49节点*/  {	{37,15,FL_default,FREE,COMMON_SPEED,30,SEEK_PesPlatform,PARK_PesPlatform,HL_F,180},{15,9,FL_default,FREE,COMMON_SPEED,20,SEEK4,PARK_pesL,HR,90},	\
						},

/*50节点*/  {	{28,25,FL_default,FREE,COMMON_SPEED,10,SEEK4,PARK_pesR_No,HR,90},{49,37,FL_default,FREE,COMMON_SPEED,30,SEEK4,PARK_pesR_200,HR,120},	\
						},




};

