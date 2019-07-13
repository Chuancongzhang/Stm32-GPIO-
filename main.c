/*
* �˺�����ʵ��GPIO�Ŀ⺯�����ã�
* stm32���š�������ʹ��keil�½�����
*/
#include "stm32f10x.h"

#define uint unsigned int
#define uchar unsigned char
#define CLOCK 8 //���õ�ʱ����8M

//ʵ�� xx us ��ʱ
void delay_us(uint us)
{
	uint n;		    
	while(us--)for(n=0;n<CLOCK;n++); 	 
}

//ʵ�� xx ms ��ʱ
void delay_ms(uint ms)
{
	while(ms--)delay_us(1000);	 
}

//GPIO �ܽ����� 
void GPIO_Configuration(void)
{ 
   	//�����ṹ��
		GPIO_InitTypeDef GPIO_InitStructure; 
		//����ѡ������
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13; 
		//��������������Ƶ��
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; 
		//�����������ģʽ���������������
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; 
		//�������õ�InitStructure��ʼ��GPIO��
	  GPIO_Init(GPIOC,&GPIO_InitStructure);
}

/*------------------------------------------------------------
                       main
------------------------------------------------------------*/
int main()
{
	//ʹ��GPIOCʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_Configuration(); 
	 	
	while (1)
  {
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		delay_ms(100);
    GPIO_ResetBits(GPIOC,GPIO_Pin_13);
    delay_ms(100);	
	}
}
