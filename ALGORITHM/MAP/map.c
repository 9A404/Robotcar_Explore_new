#include "control.h"
#include "myconfig.h"

/*ͨ��һ����ʾ����ͼ  Ѳ�߷��� ·������  ���ٷ���  ����ʱ�� �ҽڵ㷽�� ͣ������ ��ͷ��ת�Ƕ�*/

const map_linkInforTypeDef mapInformation[][NODEFORKNUM]={
/*�ڵ�*/	{	{0,0,},			},//û���õ�	1

/*1�ڵ�*/	{	{2,1,FL_brige,FREE,NOSPEED,0,SEEK_default,PARK_default,HN_Rotate},{2,3,FL_default,PLATFORM_1,COMMON_SPEED,30,NOTSEEK,NOTPARK,HN_Rotate},	\
						{2,5,FL_default,PLATFORM_1,NOSPEED,0,SEEK_default,NOTPARK,rot_LFL},	
					},	

/*2�ڵ�*/	{	{1,2,FL_slow,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_default,HL_180_F},{3,4,FL_slow,BRIGE,COMMON_SPEED,28,NOTSEEK,NOTPARK,HN_Rotate},	\
						{5,9,FL_default,S_BOARD,NOSPEED,0,SEEK_default,PARK_pesL,HL_120},{5,6,FL_default,S_BOARD,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},	
					},		

/*3�ڵ�*/	{	{2,1,FL_brige,FREE,NOSPEED,0,SEEK_default,PARK_default,HN_Rotate},{4,3,FL_default,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL_180_F},	\
						{5,9,FL_slow,SLOPE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},{5,6,FL_slow,SLOPE,NOSPEED,0,SEEK_default,PARK_pesR_200,HR_135},	
					},		
	
/*4�ڵ�*/	{	{3,5,FL_default,PLATFORM,NOSPEED,0,SEEK_default,NOTPARK,rot_RFL},	
					},

/*5�ڵ�*/	{	{2,1,FL_slow,S_BOARD,NOSPEED,0,SEEK_default,NOTPARK,HN_Rotate},{6,7,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},	\
						{6,8,FL_default,FREE,COMMON_SPEED,40,SEEK_default,NOTPARK,rot_RFL},{9,10,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate},	\
						{6,42,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_45,HL_90},{6,14,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_200,HL_90},
					},      

/*6�ڵ�*/	{	{7,6,FL_default,FREE,COMMON_SPEED,50,SEEK_PesPlatform,PARK_PesPlatform,HL_180_F},{8,6,FL_default,FREE,COMMON_SPEED,60,SEEK_Collision,NOTPARK,HL_180_F},	\
						{14,15,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL_90},{5,2,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,rot_LFL},	\
						{7,12,FL_default,FREE,COMMON_SPEED,50,SEEK_PesPlatform,PARK_PesPlatform,HL_180_F},{14,16,FL_default,FREE,COMMON_SPEED,60,SEEK4,PARK_pesR,HR_90},\
						{42,14,FL_slow,DOOR_CLICK,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate},{14,35,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},	\
						{14,17,FL_default,FREE,COMMON_SPEED,60,SEEK4,PARK_pesR,HR_90},
					},                 

						
/*7�ڵ�*/	{	{12,11,FL_default,PLATFORM,COMMON_SPEED,330,SEEK_PesPlatform,PARK_PesPlatform,HN_Rotate},{6,14,FL_default,PLATFORM,NOSPEED,0,SEEK_default,PARK_pesR,HR_90},	\
						{12,10,FL_slow,PLATFORM,COMMON_SPEED,330,SEEK_PesPlatform,PARK_PesPlatform,HL_180_F},{6,42,FL_default,PLATFORM,NOSPEED,0,SEEK4,PARK_pesR,HR_90},\
					},
	
/*8�ڵ�*/ {	{6,7,FL_slow,FREE,COMMON_SPEED,80,SEEK_default,PARK_pesR_250,HR_135_F},
					},

/*9�ڵ�*/	{	{10,12,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},{10,11,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,rot_LFL},	\
						{5,6,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},{39,15,FL_slow,DOOR_CLICK,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate},	\
						{5,2,FL_default,FREE,COMMON_SPEED,10,SEEK_DIGR,PARK_pesR_200,HR_135_F},{39,9,FL_slow,FREE,NOSPEED,0,SEEK_Collision,PARK_Door,HL_180}, \
						{40,14,FL_slow,DOOR_CLICK,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate},{40,9,FL_slow,FREE,NOSPEED,0,SEEK_Collision,PARK_Door,HL_180},	\
						{15,31,FL_default,FREE,COMMON_SPEED,50,SEEK_DIGL,NOTPARK,HN_Rotate},{31,32,FL_slow,FREE,COMMON_SPEED,100,SEEK_DIGR,PARK_pesR,HR_90},	\
						{39,30,FL_slow,DOOR_CLICK,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate},{6,14,FL_default,FREE,COMMON_SPEED,80,SEEK_DIGL,PARK_pesL_300,HL_90},	\
						{14,17,FL_default,FREE,COMMON_SPEED,120,SEEK4,PARK_pesR,HR_35},{14,16,FL_default,FREE,COMMON_SPEED,120,SEEK4,PARK_pesR,HR_35},	\
						
					},

/*10�ڵ�*/{	{12,10,FL_default,PLATFORM,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL_180_F},{9,5,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},	\
						{9,40,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL_45},{9,39,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL_90},	\
						{9,15,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL_90},{9,14,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL_45},	\
						{11,10,FL_default,FREE,COMMON_SPEED,50,SEEK_Collision,NOTPARK,HL_180_F},{9,31,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesL,HL_90},	\
						{6,14,FL_default,FREE,COMMON_SPEED,120,SEEK_DIGL,PARK_pesL_300,HL_90},
					},         

/*11�ڵ�*/{	{10,9,FL_default,FREE,COMMON_SPEED,50,SEEK_PESL,NOTPARK,HR_35},{10,12,FL_slow,FREE,NOSPEED,0,SEEK_default,PARK_pesL_250,HL_120},	\
						{10,6,FL_default,FREE,COMMON_SPEED,50,SEEK_PESL,NOTPARK,HR_35},
					},

/*12�ڵ�*/{	{10,9,FL_default,PLATFORM,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},{10,11,FL_default,PLATFORM,COMMON_SPEED,30,SEEK_default,PARK_pesL,HR_135},	\
						
						
					},

/*13�ڵ�*/{	{14,35,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_45,HL_45},{9,5,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL_135}, \
						{14,17,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_45,HR_45},{40,9,FL_default,DOOR_CLICK,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate},	\
					},

/*14�ڵ�*/{	{15,9,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL_90},{37,36,FL_default,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL_180},	\
						{16,17,FL_quick,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},{44,16,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},	\
						{35,36,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR_90},{42,6,FL_default,DOOR_CLICK,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate},	\
						{44,43,FL_middle,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate},{6,5,FL_default,FREE,COMMON_SPEED,60,SEEK_default,PARK_pesL,HR_90},	\
						{34,30,FL_default,FREE,COMMON_SPEED,25,SEEK_DIGL,PARK_pesL_No,HL_90},{17,18,FL_default,FREE,COMMON_SPEED,80,SEEK_DIGL,PARK_pesL_No,HL_90},	\
            {16,44,FL_slow,ANGLE,COMMON_SPEED,30,SEEK_default,PARK_pesR,HR_120_F},{17,20,FL_default,FREE,COMMON_SPEED,80,SEEK_DIGL,PARK_pesL_No,HL_90},		\
						{9,5,FL_default,FREE,COMMON_SPEED,120,SEEK4,PARK_pesR_200,HL_135},
					},	

/*15�ڵ�*/{	{9,5,FL_default,FREE,COMMON_SPEED,50,SEEK4,PARK_pesR,HL_90},{39,9,FL_default,DOOR_CLICK,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate},	\
						{31,32,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR_90},	
					},

/*16�ڵ�*/{	{17,18,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_No,HL_90},{44,45,FL_16_44,FREE,NOSPEED,0,SEEK_SeeSaw,NOTPARK,HN_Rotate},	\
						{17,20,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL_No,HL_90}
						
					},
	
/*17�ڵ�*/{	{18,20,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},{18,19,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesL,HL_90}, \
            {14,34,FL_default,FREE,COMMON_SPEED,90,SEEK_DIGR,PARK_pesR,HR_90},{43,44,FL_default,FREE,NOSPEED,0,SEEK_default,NOTPARK,HN_Rotate}, \
						{43,16,FL_slow,ANGLE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},{20,21,FL_default,FREE,COMMON_SPEED,80,SEEK4,PARK_pesL_No,HL_90},
					},

/*18�ڵ�*/{	{20,21,FL_default,FREE,COMMON_SPEED,30,SEEK4,PARK_pesL_No,HL_90},{19,18,FL_slow,FREE,NOSPEED,0,SEEK_Collision,NOTPARK,HN_Rotate},	\
            {17,43,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR_No,HR_90},{17,14,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR_No,HR_90},	\
						{17,37,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR_No,HR_90},
					},

/*19�ڵ�*/{	{18,17,BACK_NFL,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HL_90},{18,20,BACK_NFL,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HR_90},	\
					},

/*20�ڵ�*/{	{21,22,FL_default,FREE,COMMON_SPEED,30,SEEK4,PARK_pesL_No,HL_90},{18,17,FL_default,FREE,COMMON_SPEED,45,SEEK4,NOTPARK,HN_Rotate},		\
            {17,14,FL_default,FREE,COMMON_SPEED,70,SEEK4,PARK_pesR_No,HR_90},{18,19,FL_default,FREE,COMMON_SPEED,45,SEEK4,PARK_pesR,HR_90},
					},

					
/*21�ڵ�*/{	{22,23,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesR_200,HR_120_F},{20,18,FL_default,FREE,COMMON_SPEED,30,SEEK_default,PARK_pesR_No,HR_90},	\
					},

/*22�ڵ�*/{	{23,24,FL_slow,FREE,COMMON_SPEED,70,SEEK_default,PARK_pesR_250,HR_135},{21,20,FL_default,FREE,COMMON_SPEED,35,SEEK4,PARK_pesR_No,HR_90},
					},

/*23�ڵ�*/{	{24,23,FL_default,Peak,NOSPEED,0,NOTSEEK,PARK_PesPlatform,HL_180_F},{25,26,FL_slow,ALL_TILT,NOSPEED,0,SEEK4,PARK_pesR,HR_90},\
						{22,21,FL_default,FREE,COMMON_SPEED,60,SEEK_default,PARK_pesL_200,HL_120},
					},
	
/*24�ڵ�*/{	{23,25,FL_default,DOWNPLATFORM,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},{23,22,FL_default,DOWNPLATFORM,NOSPEED,0,SEEK_default,PARK_pesL_200,HL_135},	\
						
					},

/*25�ڵ�*/{	{26,27,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesL,HL_90},{28,50,FL_slow,SLOPE,NOSPEED,20,SEEK4,PARK_pesL,HL_90},	\

					},

/*26�ڵ�*/{	{27,26,FL_default,UP_26_27,NOSPEED,0,NOTSEEK,PARK_PesPlatform,HL_180_F},{25,28,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR_90},
					},

/*27�ڵ�*/{	{26,25,FL_default,DOWN27_26,NOSPEED,20,SEEK4,PARK_pesR,HR_90},		\
					
					},

/*28�ڵ�*/{	{25,26,FL_slow,SLOPE,NOSPEED,0,SEEK4,PARK_pesL,HL_90},	{50,49,FL_default,FREE,COMMON_SPEED,10,SEEK4,PARK_pesL,HL_35},  \
           },

/*29�ڵ�*/{	{36,37,},	},

/*30�ڵ�*/{	{34,35,FL_slow,S_BOARD_DOUBLE,COMMON_SPEED,20,SEEK4,PARK_pesR,HR_90},{50,28,FL_slow,SLOPE,NOSPEED,0,SEEK_DIGR,PARK_pesR_No,HR_90},	\
					},

/*31�ڵ�*/{	{32,31,FL_slow,FREE,NOSPEED,0,SEEK_Collision,NOTPARK,HN_Rotate},{30,34,FL_slow,FREE,NOSPEED,0,SEEK_default,PARK_pesR_No,HR_90},	\
						
					},

/*32�ڵ�*/{	{31,30,BACK_NFL,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HL_90},
					},

/*33�ڵ�*/{	{33,33,},
					},

/*34�ڵ�*/{	{35,36,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesL,HL_90},{30,50,FL_slow,S_BOARD_DOUBLE,COMMON_SPEED,50,NOTSEEK,NOTPARK,HN_Rotate},	\
					},

/*35�ڵ�*/{	{36,35,FL_slow,FREE,NOSPEED,0,SEEK_Collision,NOTPARK,HN_Rotate},{14,37,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesL,HR_90},	\
						{14,42,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate},{14,17,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL_90},	\
						{14,16,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesL,HL_90},{14,44,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL_90},	\
						{14,6,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate},	{14,9,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR_45},	\
						{6,5,FL_default,FREE,COMMON_SPEED,100,SEEK_default,PARK_pesL,HR_90},
					},

/*36�ڵ�*/{	{35,14,BACK_NFL,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HR_90},{35,34,BACK_NFL,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HL_90},	\
						{35,6,BACK_NFL,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HR_90},
						
					},

						
/*37�ڵ�*/{	{15,9,FL_quickest,PLATFORM,COMMON_SPEED,60,SEEK4,PARK_pesL,HR_90},{49,15,FL_default,PLATFORM,COMMON_SPEED,20,SEEK_PESL,NOTPARK,HN_Rotate},	\
						{15,31,FL_quickest,PLATFORM,COMMON_SPEED,60,SEEK4,PARK_pesL,HL_90},
					},

/*38�ڵ�*/{	{33,23,},{15,9,FL_quickest,Platform_37_15,NOSPEED,0,SEEK4,PARK_pesL,HR_90},	\
					},

/*39�ڵ�*/	{ {15,31,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate}, {9,5,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL_90}, \
							{9,40,FL_slow,FREE,NOSPEED,0,SEEK4,PARK_pesR_No,HL_120},
						},

/*40�ڵ�*/  {	{13,14,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},{9,6,FL_slow,FREE,NOSPEED,0,SEEK_DIGL,PARK_pesR_No,HL_120},	\
							{9,5,FL_slow,FREE,NOSPEED,0,SEEK_DIGL,PARK_pesL_No,HL_135},{14,17,FL_default,FREE,COMMON_SPEED,80,SEEK4,PARK_pesR,HR_35},	\
						},

/*41�ڵ�*/  { {13,15,},
						},

/*42�ڵ�*/  {	{14,35,FL_default,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},{14,37,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HL_90},	\
							{6,5,FL_default,FREE,NOSPEED,0,SEEK_default,PARK_pesL,HR_90},{14,44,FL_default,FREE,NOSPEED,0,SEEK4,PARK_pesR,HR_90},	\
							{14,17,FL_default,FREE,COMMON_SPEED,40,SEEK4,PARK_pesR,HR_90},
						},

/*43�ڵ�*/  {	{44,14,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},{16,44,FL_slow,FREE,NOSPEED,0,NOTSEEK,NOTPARK,rot_LFL},	\
							{17,18,FL_default,FREE,NOSPEED,0,SEEK_default,PARK_pesL,HL_90},{44,37,FL_default,FREE,NOSPEED,0,SEEK_PESL,NOTPARK,HN_Rotate},	\
						  {37,36,FL_slow,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL_180},{16,17,FL_circular,FREE,NOSPEED,0,SEEK_default,PARK_pesR_250,HR_145},
						},

/*44�ڵ�*/  {	{14,38,FL_default,FREE,NOSPEED,0,SEEK4,NOTPARK,HN_Rotate},{45,46,FL_slow,SEESAW,NOSPEED,0,NOTSEEK,NOTPARK,HN_Rotate},	\
							{37,36,FL_quickest,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL_180},{43,17,FL_node,FREE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},	\
						},

/*45�ڵ�*/  {{46,47,FL_circular,FREE,NOSPEED,0,SEEK_default,PARK_pesL,HL_90},
						},

/*46�ڵ�*/  {	{47,46,FL_default,FREE,NOSPEED,0,SEEK_PesPlatform,PARK_PesPlatform,HL_180_F},	{43,16,FL_circular,BRIGE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},	\
							{43,44,FL_circular,BRIGE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},{43,37,FL_circular,BRIGE,NOSPEED,0,SEEK_PESR,NOTPARK,HN_Rotate},
							{48,43,FL_circular,FREE,NOSPEED,0,SEEK_SeeSaw_back,NOTPARK,HN_Rotate},
						},

/*47�ڵ�*/  {	{46,43,FL_slow,PLATFORM,NOSPEED,0,SEEK_default,PARK_pesL,HL_105},
              {46,48,FL_slow,PLATFORM,NOSPEED,0,SEEK_default,PARK_pesL,HL_90},
						},

/*48�ڵ�*/  {	{46,43,FL_slow,PLATFORM,NOSPEED,0,SEEK_default,PARK_pesL,HL_105},{43,16,FL_slow,SEESAW,NOSPEED,0,SEEK_default,NOTPARK,HN_Rotate},
						},

/*49�ڵ�*/  {	{37,15,FL_default,FREE,COMMON_SPEED,30,SEEK_PesPlatform,PARK_PesPlatform,HL_180_F},{15,9,FL_default,FREE,COMMON_SPEED,20,SEEK4,PARK_pesL,HR_90},	\
						},

/*50�ڵ�*/  {	{28,25,FL_default,FREE,COMMON_SPEED,10,SEEK4,PARK_pesR_No,HR_90},{49,37,FL_default,FREE,COMMON_SPEED,30,SEEK4,PARK_pesR_200,HR_120},
						},




};

