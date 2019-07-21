#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "sys.h"


#define NODEFORKNUM  	15			//��ͼ����һ�ڵ���������Ŀ * ���½ڵ���������Ŀ


/*Ѳ�߷���*/
typedef enum {FL_sword,FL_circular,FL_angle,FL_angle_slow,FL_node,FL_43_44,FL_16_44,FL_default,FL_middle,	\
							FL_brige,FL_brigeup,FL_brigedown,FL_slow,FL_slowest,FL_quick,FL_stop,FL_quickest,	\
							FL_upPeak,FL_downPeak,FL_UpPlatform,FL_DownPlatform,FL_left,FL_Right,NFL,NFL_slow,BACK_NFL}findLine;

/*·������*/
typedef enum {SWORD,FREE,ANGLE,BRIGE,DOOR,DOOR_CLICK,S_BOARD,S_BOARD_DOUBLE,SEESAW,GO_TILT_R,GO_TILT_L,\
							BACK_TILT_R,BACK_TILT_L,SLOPE,PLATFORM,PLATFORM_1,Peak,TRAPEZOID_1,TRAPEZOID_2,TRAPEZOID_3,\
							TIME,TIME_1,TIME_2,DOWNPLATFORM,ALL_TILT,\
							DOWN27_26,Block_PESR,Platform_37_15,		
							UP_26_27,TIME_45_46}typeRoadblock;	//���ϰ����š��š����ٴ������ΰ塢��б·�桢б�¡�ƽ̨���㡢���ξ��㡢���ӽڵ㶨ʱ                                                                                                                                  

/*��������*/
typedef enum {DOWN_SPEED,COMMON_SPEED,NOSPEED,TME}typeSpeed;//��̨���٣���ͨ���٣������٣�ռʱ�䣨���ڴ����ӽڵ�)			

/*�ҽڵ㷽��*/
typedef enum {SEEK_SeeSaw,SEEK_PESL,SEEK_PESR,SEEK3,SEEK4,SEEK_default,	\
							NOTSEEK,SEEK_PesPlatform,SEEK_Collision,SEEK_DIGR,SEEK_DIGL,SEEK_SeeSaw_back}seekNodeWay;

/*ͣ������*/
typedef enum {NOTPARK,PARK1,PARK_pesR,PARK_pesR_200,PARK_pesR_250,PARK_pesR_300,PARK_pesR_350,PARK_pesR_400,	\
							PARK_default,PARK_pesL,PARK_pesL_200,PARK_pesL_250,PARK_pesL_300,PARK_pesL_350,PARK_pesL_400,	\
							PARK_PesPlatform,PARK_Door,PARK_start,PARK_pesR_45,PARK_pesL_45,PARK_pesR_No,PARK_pesL_No,PARK_pesL_back,PARK_pesR_back}carPark;

/*��ͷ��ת�Ƕ�*/
typedef enum {HR_120_F,HR_135_F,HL_180_F,HL_185,HL_180,HL_145,HL_135,HL_110,HL_120,HL_105,HL_90,	\
							HL_80,HL_60,HL_45,HL_35,HN_Rotate,HR_35,HR_45,HR_60,HR_80,HR_90,HR_110,HR_120,HR_135,	\
							HR_145,HR_150,HR_160,HR_170,HR_180,HR_180_F,rot_LFL,rot_RFL,rot_UL,rot_UR,Sensor_L90,Sensor_R90}carRotAngle;

/*״̬�ź�*/
typedef enum {NTBE,EIC,STANDBY}updataState;		//��Ҫִ�� ִ����� ����


/*��·����Ϣ���м�¼*/
typedef	struct{

	u8	nextNode;										//��һ���ڵ�
	u8	nnNode;											//���¸��ڵ�
	findLine      findLineWays;			//Ѳ�߷���
	typeRoadblock	typeRoadblock;		//·������
	typeSpeed typeSpeed; 				//��������
	u16 speedTime;						//����ʱ��
	seekNodeWay   seekways;					//�ҵ㷽��
	carPark  			parkways;					//ͣ������
	carRotAngle 	rotateAngle;			//��ǰ��ͷλ�û���������ת�Ƕ�
	
}linkInforTypeDef;

/*�Ե�ͼ·����Ϣ���м�¼*/
typedef	struct{

	u8	map_nextNode;										//��ͼ��һ���ڵ�
	u8	map_nnNode;											//��ͼ���¸��ڵ�
	findLine      map_findLineWays;			//��ͼѲ�߷���
	typeRoadblock	map_typeRoadblock;		//��ͼ·������
	typeSpeed map_typeSpeed; 				//��ͼ��������
	u16 map_speedTime;						//��ͼ����ʱ��
	seekNodeWay   map_seekways;					//��ͼ�ҵ㷽��
	carPark  			map_parkways;					//��ͼͣ������
	carRotAngle 	map_rotateAngle;			//��ͼ��ͷ��ת����
	
}map_linkInforTypeDef;



/*�Կ�������״̬���м�¼*/
typedef	struct{

	u8  curNode;								//��ǰ�ڵ�
	u8	nextNode;								//��һ���ڵ�
	u8	nnNode;									//���¸��ڵ�
	u8	nodeNum;								//�ڵ���
	linkInforTypeDef	linkInform;//·����Ϣ
	updataState	update;						//״̬�ź�
		

}controlCenterTypeDef;


/*������״̬���м�¼,��ÿ��·�θ���״̬�������*/
/*˼·��
ÿ����������״̬
1��NTBE����Ҫִ�У���
2��EIC��ִ����ɣ���
3��STANDBY������������ζ����Ҫ����״̬����������������״̬����ɣ�NTBE��
���磺�ҵ���Ҫ·��״̬�Ĵ�����ͣ����Ҫ�ҵ�״̬�Ĵ�����ת����Ҫ�ҵ�״̬����
*/
typedef	struct{

	updataState	F_LineState;					//Ѳ��״̬
	updataState	F_RoadBlockState;			//���ϰ�״̬
	updataState speedState;					//����״̬
	updataState seekNodeState;				//�ҵ�״̬
	updataState carParkState;					//ͣ��״̬
	updataState	RotangleState;				//ת��״̬
	
}runStateTypeDef;

void Control_Init(controlCenterTypeDef *controlp,u8*runMethod);//�������ĳ�ʼ������
void updataState_Reset(controlCenterTypeDef *p,updataState state);//���Ŀ�������״̬�ź�
unsigned char control_Update(controlCenterTypeDef *controlp,u8 nodeLength,const u8 *runMethod,const map_linkInforTypeDef(*p)[NODEFORKNUM] );//���¿������ģ�controlCenterTypeDef�ṹ�壩�Ĳ���
void runStateInit(runStateTypeDef *runState,const controlCenterTypeDef *controlp);//���ݿ���̨��ʼ·�γ�ʼ������״̬
void runStateReset(runStateTypeDef *runState,const controlCenterTypeDef *controlp);//���ݿ���̨�ж��Ƿ������µ�·�Σ�Ȼ��������������״̬
void runMethodReset(u8 runMethod[],const u8 runMethod_2[]); //����·��
//void DoorMethodUpdate(controlCenterTypeDef *controlp,u8 runMethod[],u8 DoorFlag,const u8 runMethodTableDoorAuto[][100]);   //�Զ��л�������·����
void runMethodUpdate(u8 runMethod[],u8 runMethodNum, const u8 runMethodTab[][100]); //�ӱ���и���·��

void findLine_Task(const controlCenterTypeDef *controlp,runStateTypeDef *runState);         //Ѳ������
void roadBlocksHandle_Task(const controlCenterTypeDef *controlp,runStateTypeDef *runState);//�ϰ���������
void seekNode_Task(const controlCenterTypeDef *controlp,runStateTypeDef *runState);       // �ҵ�����
void carPark_Task(const controlCenterTypeDef *controlp,runStateTypeDef *runState);       // ͣ������
void rotAngle_Task(controlCenterTypeDef *controlp,runStateTypeDef *runState);           //  ת������
void speed_Task(const controlCenterTypeDef *controlp,runStateTypeDef *runState);


#endif

