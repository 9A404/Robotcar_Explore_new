#ifndef _FINDLINE_H_
#define _FINDLINE_H_
#include "sys.h"
#include "myconfig.h"

void flMethod_default(void);    //Ĭ��Ѳ�߷���   3300
void flMethod_middle(void);    //����Ѳ�߷���    4500
void flMethod_brige(void);			//����Ѳ��
void flMethod_brige_up(void);   //����б��ʱ��Ѳ�߷���
void flMethod_brige_down(void); //����б��ʱ��Ѳ�߷���
void flMethod_slow(void);				//����Ѳ��
void flMethod_slowest(void);				//����Ѳ��
void flMethod_UpPlatform(void);//��ƽ̨Ѳ��
void flMethod_DownPlatform(void);//��ƽ̨Ѳ��
void flMethod_quick(void);      //����Ѳ��        5500
void flMethod_stop(void);				//ͣ��Ѳ��
void flMethod_quickest(void);   //������Ѳ��       6800
void flMethod_upPeak(void);     //�����Ѳ��
void flMethod_downPeak(void);   //�����Ѳ��
void flMethod_left(void);       //ƫ��Ѳ��
void flMethod_right(void);      //ƫ��Ѳ��
void flMethod_node(void);      //Բ��Ѳ�߷���
void flMethod_43_44(void);      //Բ��Ѳ�߷���
void flMethod_16_44(void);      //Բ��Ѳ�߷���
void flMethod_circular(void);      //Բ��Ѳ�߷���
void flMethod_NFL(void);        //ѭ�Ƕȷ���
void flMethod_NFL_slow(void);        //ѭ�Ƕȷ���
void flMethod_Encoder(void);
void No_flMethod(void);
void No_flMethod_Slow(void);
void No_flMethod_Back(void);
#endif




