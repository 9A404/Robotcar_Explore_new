#include "door.h"
#include "myconfig.h"

/*

* �������ܣ��ڶ����Զ����ñ���·�ߣ������һ�ֱ���·��Ϊ���Ų��ҵڶ��ֱ���·���д��ڴ��ڻ��ߵ���39�Ľڵ�������ڶ���·�߹���
* ���������runMethod_2���ڶ��ֱ��ܵ�·�ߣ�
* �����������
* ����ֵ  ����
* ����    ��@��

*/
u8 runMethodDoorSecondCheck(u8 runMethod[],const u8 runMethod_2[])
{
	u8 i=0;
	while(runMethod[i]!=0)
	{
		if(runMethod_2[i]>=39) break;
		else i++;
	}
	i=0;
	while(runMethod_2[i]!= 0)
	{
		if(runMethod_2[i]>=39) return 1;
		else i++;
	}
	return 0;
}
/*

* �������ܣ��ڶ����Զ����ñ���·��
* ���������runMethod_2������Ļ��ѡ��ĵڶ��ֹ���·��  DoorFlag(�ſ���־λ����¼�Ǹ��Ŵ��ڿ���״̬    runMethodTableDoorAuto(����·�߱�))��
* �����������
* ����ֵ  ����
* ����    ��@��

*/
void runMethodResetDoorSecond(u8 runMethod_2[],u8 doorflag,const u8 runMethodTableDoorAuto[][100])
{
	u8 i=0;
	
	/*��������*/
	while(runMethod_2[i]!= 0)
	{
		runMethod_2[i]= 0;
		i++;
	}
	/*����·��*/
	i=0;
	while(runMethodTableDoorAuto[doorflag+3][i] != 0)
	{
		runMethod_2[i] = runMethodTableDoorAuto[doorflag+3][i];
		i++;
	}
	
}
	

	
	
	
	
	
	

