#include "delay.h"
#include "usart.h"
#include "UART.h"
#include "show.h"
#include "oled.h"
#include "key.h"
#include "servo.h"
#include "stopmode.h"
#include "ADC.h"
#include "gui.h"
#include "led.h"
#include "beep.h"

u8 timer=0;
u8 vol=0;

int main(void)
{
	delay_init();
	delay_ms(1000);
	uart2_init(115200);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Led_Init();
	led=0;
	Beep_Init();
	ADCx_Init();
	OLED_Init();
	OLED_Clear(0);
	SERVO_TIM3_Init(1999, 719);
	Key_Init();
	ZHIWEN_Init();
	UART_Get_User();
	delay_ms(1000);
	vol=Get_ADC_Value(ADC_Channel_5, 100)-320;
	led=1;
	while(1)
	{
		timer++;
		if(timer%50==0)
		{
			timer=0;
			func_index=0;
			OLED_Clear(0);
			stopmode();
			uart2_init(115200);
			Beep_Init();
			Led_Init();
			ADCx_Init();
			Key_Init();
			ZHIWEN_Init();
			OLED_Init();
			OLED_Clear(0);
			SERVO_TIM3_Init(1999, 719);
		}
		if(timer%10==0)
		{
			vol=Get_ADC_Value(ADC_Channel_5, 100)-320;
		}
		else if(timer%3==0)
		{
			menue_key();
		}
		delay_ms(100);
	}
}
