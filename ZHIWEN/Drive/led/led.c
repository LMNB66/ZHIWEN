#include "led.h"

void Led_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStruct;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
 GPIO_InitStruct.GPIO_Pin = LED;
 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStruct);
 GPIO_SetBits(GPIOC,LED);
}
