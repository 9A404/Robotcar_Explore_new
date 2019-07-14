#include "usart3.h"	
#include "sys.h"
#include "stdarg.h"
#include "string.h"
#include "stdio.h"
#include "myconfig.h"

char *findLinep[]={"FL_default","FL_brige","FL_brigeup","FL_brigedown","FL_slow","FL_quick","FL_stop","FL_quickest","FL_upPeak","FL_downPeak","FL_left","FL_Right","rot_RFL","NFL","BACK_NFL"};

char *typeRoadblockp[]={"FREE","BRIGE","DOOR","S_BOARD_1","S_BOARD_2","S_BOARD_26_27","SEESAW","GO_TILT_R","GO_TILT_L","BACK_TILT_R","BACK_TILT_L","SLOPE",\
												"PLATFORM","PLATFORM_1","Peak","TRAPEZOID_1","TRAPEZOID_2","TRAPEZOID_3",\
												"TIME","TIME_1","TIME_2","TIME_3","SPEEDTIME_1","SPEEDTIME_2","SPEEDTIE_36_17","SPEEDTIME_17_37","DOWNPLATFORM","ALL_TILT","DOWN27_26"};

char *seekNodeWayp[]={"SEEK_PESL","SEEK_PESR","SEEK3","SEEK4","SEEK_default","NOTSEEK","SEEK_PesPlatform","SEEK_Collision"};

char *carParkp[]={"NOTPARK","PARK1","PARK_pesR","PARK_def","PARK_pesL","PARK_PesPlatform"};

char *carRotAnglep[]={"HL_180","HL_145","HL_135","HL_90","HL_60","HL_45","HL_35","HN_Rotate",\
											"HR_35","HR_45","HR_60","HR_90","HR_110","HR_135","HR_145","HR_180","rot_LFL","rot_RFL","rot_UL","rot_UR","Sensor_L90","Sensor_R90"};

char *updataStatep[]={"NTBE","EIC","STANDBY"};

//u8 uartData;

/*

* �������ܣ�����3��DMA��������
* ���������(DMA_CHx)DMAͨ��CHx	(cpar)�����ַ	(cmar)�洢����ַ
* ���������
* ����ֵ  ��
* ����    ��@����

*/

void USART3_DMA_Config(DMA_Channel_TypeDef*DMA_CHx,u32 cpar,u32 cmar)
{
	DMA_InitTypeDef DMA_InitStructure;
 	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	//ʹ��DMA����
    DMA_DeInit(DMA_CHx);   															//��DMA��ͨ��1�Ĵ�������Ϊȱʡֵ
	DMA_InitStructure.DMA_PeripheralBaseAddr = cpar;  	//DMA����ADC����ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = cmar;  			//DMA�ڴ����ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;  //���ݴ��䷽�򣬴��ڴ��ȡ���͵�����
	DMA_InitStructure.DMA_BufferSize = 0;  							//DMAͨ����DMA����Ĵ�С
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  //�����ַ�Ĵ�������
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  									//�ڴ��ַ�Ĵ�������
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  	//���ݿ��Ϊ8λ
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; 					//���ݿ��Ϊ8λ
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  													//��������������ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; 									//DMAͨ�� xӵ�������ȼ� 
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;  													//DMAͨ��xû������Ϊ�ڴ浽�ڴ洫��
	DMA_Init(DMA_CHx, &DMA_InitStructure);  																//����DMA_InitStruct��ָ���Ĳ�����ʼ��DMA��ͨ��USART1_Tx_DMA_Channel����ʶ�ļĴ���	
}

/*

* �������ܣ�DMA1�ĸ�ͨ������,����Ĵ�����ʽ�ǹ̶���,���Ҫ���ݲ�ͬ��������޸�,�Ӵ洢��->����ģʽ/8λ���ݿ��/�洢������ģʽ
* ���������(DMA_CHx)DMAͨ��CHx	(cpar)�����ַ	(cmar)�洢����ַ
* ���������
* ����ֵ  ��
* ����    ��@����

*/
void USART_DMA_Config(DMA_Channel_TypeDef*DMA_CHx,u32 cpar,u32 cmar)
{
	DMA_InitTypeDef DMA_InitStructure;
 	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	//ʹ��DMA����
  DMA_DeInit(DMA_CHx);   															//��DMA��ͨ��1�Ĵ�������Ϊȱʡֵ
	DMA_InitStructure.DMA_PeripheralBaseAddr = cpar;  	//DMA����ADC����ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = cmar;  			//DMA�ڴ����ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;  //���ݴ��䷽�򣬴��ڴ��ȡ���͵�����
	DMA_InitStructure.DMA_BufferSize = 66;  							//DMAͨ����DMA����Ĵ�С
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  //�����ַ�Ĵ�������
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  									//�ڴ��ַ�Ĵ�������
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  	//���ݿ��Ϊ8λ
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; 					//���ݿ��Ϊ8λ
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  													//��������������ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_High; 									//DMAͨ�� xӵ�������ȼ� 
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;  													//DMAͨ��xû������Ϊ�ڴ浽�ڴ洫��
	DMA_Init(DMA_CHx, &DMA_InitStructure);  																//����DMA_InitStruct��ָ���Ĳ�����ʼ��DMA��ͨ��USART1_Tx_DMA_Channel����ʶ�ļĴ���	
}

/*����3�жϷ������*/
//ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���   	
u8 USART3_RX_BUF[USART3_REC_LEN];     //���ջ���,���USART3_REC_LEN���ֽ�.
//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�0x0d
//bit13~0��	���յ�����Ч�ֽ���Ŀ
u16 USART3_RX_STA=0;       //����״̬���	  

//��ʼ��IO ����3 
//bound:������
void usart3_init(u32 bound)
{
    /*GPIO�˿�����*/
		 /*GPIO�˿�����*/
		GPIO_InitTypeDef GPIO_InitStructure;
		USART_InitTypeDef USART_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
		/*ʹ��USART3*/
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);	
		/*ʹ��USART1��GPIOBʱ��*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
		/*��λ����3*/
		USART_DeInit(USART3);  
		/*USART3_TX   PB10*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
    GPIO_Init(GPIOB, &GPIO_InitStructure); //��ʼ��PB10
    /*USART1_RX	  PB11*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
    GPIO_Init(GPIOB, &GPIO_InitStructure);  //��ʼ��PB11
   /*Usart3 NVIC ����*/
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;//��ռ���ȼ�1
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//�����ȼ�1
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
		NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
   /*USART3 ��ʼ������*/
		USART_InitStructure.USART_BaudRate = bound;																				//һ������Ϊ9600;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;												//�ֳ�Ϊ8λ���ݸ�ʽ
		USART_InitStructure.USART_StopBits = USART_StopBits_1;													//һ��ֹͣλ
		USART_InitStructure.USART_Parity = USART_Parity_No;															//����żУ��λ
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;								//�շ�ģʽ

    USART_Init(USART3, &USART_InitStructure); 			//��ʼ������
		
		/*ʹ�ܴ���3��DMA����*/
		USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);  	
		/*DMA1ͨ��3,����Ϊ����3,�洢��ΪUSART3_TX_BUF*/
		USART_DMA_Config(DMA1_Channel5,(u32)&USART1->DR,(u32)USART3_TX_BUF);
    
		/*ʹ�ܴ���3��DMA����*/
		USART_DMACmd(USART3,USART_DMAReq_Tx,ENABLE);  	
		/*DMA1ͨ��3,����Ϊ����3,�洢��ΪUSART3_TX_BUF*/
		USART3_DMA_Config(DMA1_Channel2,(u32)&USART3->DR,(u32)USART3_TX_BUF);

}
#if EN_USART3_RX   //���ʹ���˽���
void USART3_IRQHandler(void)                	//����1�жϷ������
	{
	//u8 Res;
#ifdef OS_TICKS_PER_SEC	 	//���ʱ�ӽ�����������,˵��Ҫʹ��ucosII��.
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
		{
				if(USART3->DR == 1)
				{
					speedAdjustment(0,0);
					while(1);
				}
				
		
				
     } 
#ifdef OS_TICKS_PER_SEC	 	//���ʱ�ӽ�����������,˵��Ҫʹ��ucosII��.
	OSIntExit();  											 
#endif
} 
#endif	




/*

* �������ܣ�����һ�δ���1DMA����
* �����������
* �����������
* ����ֵ  ����
* ����   :@λʤ

*/
void USART_DMA_Enable(DMA_Channel_TypeDef*DMA_CHx)
{
	/*�⺯���汾*/
		//	DMA_Cmd(DMA_CHx, DISABLE ); 				 //�ر� ָʾ��ͨ��        
		//	DMA_SetCurrDataCounter(DMA_CHx,len);//DMAͨ����DMA����Ĵ�С	
		//	DMA_Cmd(DMA_CHx, ENABLE);           //����DMA����
	/*�Ĵ����汾*/
				DMA_CHx->CCR&=~(1<<0);//�ر�DMA����
				DMA_CHx->CNDTR=66;   //DMA1,���������� 
				DMA_CHx->CCR|=1<<0;   //����DMA����
}	  		

/*

* �������ܣ�����һ����3DMA����
* �����������
* �����������
* ����ֵ  ����
* ����    ��@����

*/
void USART3_DMA_Enable(DMA_Channel_TypeDef*DMA_CHx,u8 len)
{
	/*�⺯���汾*/
		//	DMA_Cmd(DMA_CHx, DISABLE ); 				 //�ر� ָʾ��ͨ��        
		//	DMA_SetCurrDataCounter(DMA_CHx,len);//DMAͨ����DMA����Ĵ�С	
		//	DMA_Cmd(DMA_CHx, ENABLE);           //����DMA����
	/*�Ĵ����汾*/
				DMA_CHx->CCR&=~(1<<0);//�ر�DMA����
				DMA_CHx->CNDTR=len;   //DMA1,���������� 
				DMA_CHx->CCR|=1<<0;   //����DMA����
}	 

/*

* �������ܣ�����3,printf ����
* �����������
* �����������
* ����ֵ  ����
*	����		��ȷ��һ�η������ݲ�����USART2_MAX_SEND_LEN�ֽ�
* ����    ��@����

*/
void u3_printf(char* fmt,...)  
{  
	va_list ap;
	va_start(ap,fmt);
	while(DMA1_Channel2->CNDTR!=0);					//�ȴ�ͨ��2������ɲŸ��»�����
	vsprintf((char*)USART3_TX_BUF,fmt,ap);
	va_end(ap);  
		USART_DMA_Enable(DMA1_Channel3); 	//ͨ��dma���ͳ�ȥ
	
}

/*

* �������ܣ�ͨ������3��������ģ����ȫ����ӡ
* �����������sourceArray�����鴢���׵�ַ
* �����������
* ����ֵ  ����
*	����		����
* ����    ��@����

*/
void array_u3printf(const unsigned short int *sourceArray)
{
	u3_printf("%d %d %d %d %d %d %d %d %d %d %d %d\r\n",
						sourceArray[0],sourceArray[1],sourceArray[2],sourceArray[3],sourceArray[4],sourceArray[5],
						sourceArray[6],sourceArray[7],sourceArray[8],sourceArray[9],sourceArray[10],sourceArray[11]);
}

/*

* �������ܣ�������������1����
* ���������digital�����������������
* �����������
* ����ֵ  ��1�ĸ���
* ����    ��@����

*/
u8 calculateNum(u16 digital)
{
	u8 i;
	u8 temp=0;
	for(i=0;i<NUM_OF_SENSOR;i++)
	{
		if(digital & (1<<i) )
			temp++;
	}
	return temp;
}


///*

//* �������ܣ�ͨ������3����������������ӡ����
//* �����������value��������
//* �����������
//* ����ֵ  ����
//*	����		����
//* ����    ��@����(value&0x40)>>6

//*/
//void sensorBit_u3printf(const unsigned short int value)
//{
//	unsigned short int temp = 0x0800;
//	u3_printf("Digital:%d%d%d%d %d%d%d%d %d%d%d%d %x %d\r\n",(value&temp)>>11,(value&(temp>>1))>>10,(value&(temp>>2))>>9,(value&(temp>>3))>>8,(value&(temp>>4))>>7,
//	(value&(temp>>5))>>6,(value&(temp>>6))>>5,(value&(temp>>7))>>4,(value&(temp>>8))>>3,(value&(temp>>9))>>2,(value&(temp>>10))>>1,value&1,value,calculateNum(value));

//}	

///*

//* �������ܣ�ͨ������3������̨��Ϣ��ӡ����
//* ���������controlp������̨��ַ��
//* �����������
//* ����ֵ  ����
//*	����		����
//* ����    ��@����

//*/
//void controlCenter_u3printf(const u8 *runMethod ,const controlCenterTypeDef *controlp)
//{
//	static char i=0;
//	u3_printf("LD:%d-%d\ncurNode:%d  nextNode:%d  nnNode:%d \n updataState:%s\n findLineWays:%s\n typeRoadblock:%s\n seekways:%s\n parkways:%s\n rotateAngle:%s\n",
//	*(runMethod+i),
//	*(runMethod+i+1),
//	controlp->curNode,controlp->nextNode,controlp->nnNode,
//	updataStatep[controlp->update],
//	findLinep[controlp->linkInform.findLineWays],
//	typeRoadblockp[controlp->linkInform.typeRoadblock],
//	seekNodeWayp[controlp->linkInform.seekways],
//	carParkp[controlp->linkInform.parkways],
//	carRotAnglep[controlp->linkInform.rotateAngle]
//	);
//	i++;
//	
//}	

///*

//* �������ܣ�ͨ������3������״̬��ӡ����
//* ���������runState������״̬��¼��״̬��
//* �����������
//* ����ֵ  ����
//*	����		����
//* ����    ��@����

//*/
//void runState_u3printf(runStateTypeDef *runState)
//{
//	u3_printf("findLine:%s\n fB:%s\n seekNode:%s\n carpark:%s\n rotangle:%s\n",
//	updataStatep[runState->F_LineState],
//	updataStatep[runState->F_RoadBlockState],
//	updataStatep[runState->seekNodeState],
//	updataStatep[runState->carParkState],
//	updataStatep[runState->RotangleState]
//	);
//}	





