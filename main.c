/*
* 此函数是实现GPIO的库函数配置，
* stm32入门————使用keil新建工程
*/
#include "stm32f10x.h"

#define uint unsigned int
#define uchar unsigned char
#define CLOCK 8 //所用的时钟是8M

//实现 xx us 延时
void delay_us(uint us)
{
	uint n;		    
	while(us--)for(n=0;n<CLOCK;n++); 	 
}

//实现 xx ms 延时
void delay_ms(uint ms)
{
	while(ms--)delay_us(1000);	 
}

//GPIO 管脚配置 
void GPIO_Configuration(void)
{ 
   	//声明结构体
		GPIO_InitTypeDef GPIO_InitStructure; 
		//设置选择引脚
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13; 
		//设置引脚最大输出频率
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; 
		//设置引脚输出模式————推挽输出
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; 
		//根据设置的InitStructure初始化GPIO口
	  GPIO_Init(GPIOC,&GPIO_InitStructure);
}

/*------------------------------------------------------------
                       main
------------------------------------------------------------*/
int main()
{
	//使能GPIOC时钟
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
