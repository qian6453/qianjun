//-------------------------------------------------
//功能: 按键控制LED闪烁
//版本号：v0.0.0
//编写： 王晓荣
//日期： 20111212
//-------------------------------------------------
#include "stm32f10x.h"	 

GPIO_InitTypeDef GPIO_InitStructure1;  
GPIO_InitTypeDef GPIO_InitStructure2;  
void Delay(unsigned int t);	
////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------
//主程序
//------------------------------------------------- 
int main(void)
{	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); 	//使能GPIOD			
	GPIO_InitStructure1.GPIO_Pin   = GPIO_Pin_2;						//测试github
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure1.GPIO_Mode  = GPIO_Mode_Out_OD;
	GPIO_Init(GPIOD, &GPIO_InitStructure1);	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); 	//使能GPIOC			
	GPIO_InitStructure2.GPIO_Pin   = GPIO_Pin_4;
	GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure2.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_Init(GPIOC, &GPIO_InitStructure2);	
	
	while (1)
	{ 
		if(GPIOC->IDR & GPIO_Pin_4) 
		{
			GPIOD->BSRR = GPIO_Pin_2;
		}
		else 
		{
			GPIOD->BRR = GPIO_Pin_2;
		}		  
		Delay(5); 
	}
}

//-------------------------------------------------
//延时
//-------------------------------------------------
void Delay(unsigned int t)
{ 
	while(t--) ;	
}	

