#include "show.h"
#include "stdlib.h"
#include "stdio.h"
#include "oled.h"
#include "delay.h"
#include "gui.h"
#include "key.h"
#include "UART.h"
#include "servo.h"
#include "ADC.h"

extern u8 vol;

u8 func_index=0;//显示页面索引

void (*current_operation_index)();//定义函数指针

menue_ menue[]={
	{0,0,1,0,(*menue_0)},
	{1,0,2,1,(*menue_1)},
	{2,1,3,5,(*menue_2)},
	{3,2,4,6,(*menue_3)},
	{4,3,4,7,(*menue_4)},
	{5,2,5,5,(*menue_5)},
	{6,3,6,8,(*menue_6)},
	{7,4,7,9,(*menue_7)},
	{8,3,8,8,(*menue_8)},
	{9,4,9,9,(*menue_9)}
};//第一个数字表示页面索引，第二个表示按上键跳到哪一页，第三第四也是如此

/***************************************************
 * @function	:根据按键值选择索引
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_key(void)
{
	static u8 _index=0;
	switch (key_sign)
	{
		case 1:
			func_index=menue[func_index].up;
			break;
		case 2:
			func_index=menue[func_index].down;
			break;
		case 3:
			func_index=menue[func_index].enter;
			break;
		default:break;
	}
	key_sign=0;
	//页面不同时刷新页面
	if(_index!=func_index)
	{
		OLED_Clear(0);
		_index=func_index;
	}
	current_operation_index=menue[func_index].current_operation;
	(*current_operation_index)();//调用函数
}

/***************************************************
 * @function	:检测指纹是否存在，存在则控制舵机开
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_0(void)
{
	OLED_Clear(0);
	if(UART_Press()==1)
	{
		UART_Timer(700);
		ack_sta=0;
		if(UART_Compare())
		{
			servo_control(130);
		}
	}
}

/***************************************************
 * @function	:显示一些系统信息，电量，指纹数
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_1(void)
{
	u8 str[10];
	UART_Get_User();
	GUI_ShowCHinese(1,10,16,(u8 *)"指纹数",1);
	sprintf((char *)str, ": %3d", user_ID);
	GUI_ShowString(50,10,str, 16, 1);
	GUI_ShowCHinese(1,36,16,(u8 *)"电量",1);
	sprintf((char *)str, ": %3d%%", vol);
	GUI_ShowString(50,36,str, 16, 1);
}

/***************************************************
 * @function	:显示“添加指纹”
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_2(void)
{
	GUI_ShowCHinese(30,24,16,(u8 *)"添加指纹",1);
	GUI_FillTriangel(13,31,22,22,22,40,1);
	GUI_FillTriangel(110,31,101,22,101,40,1);
	GUI_DrawRectangle(28, 20, 95, 43,1);
	GUI_DrawRectangle(26, 18, 97, 45,1);
}

/***************************************************
 * @function	:显示“删除指纹”
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_3(void)
{
	GUI_ShowCHinese(30,24,16,(u8 *)"删除指纹",1);
	GUI_FillTriangel(13,31,22,22,22,40,1);
	GUI_FillTriangel(110,31,101,22,101,40,1);
	GUI_DrawRectangle(28, 20, 95, 43,1);
	GUI_DrawRectangle(26, 18, 97, 45,1);
}

/***************************************************
 * @function	:显示“清空指纹”
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_4(void)
{
	GUI_ShowCHinese(30,24,16,(u8 *)"清空指纹",1);
	GUI_FillTriangel(13,31,22,22,22,40,1);
	GUI_FillTriangel(110,31,101,22,101,40,1);
	GUI_DrawRectangle(28, 20, 95, 43,1);
	GUI_DrawRectangle(26, 18, 97, 45,1);
}

/***************************************************
 * @function	:注册指纹，显示注册过程
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_5(void)
{
	u8 a, str[10];
	GUI_ShowCHinese(32,24,16,(u8 *)"按压指纹",1);
	a=UART_Enroll();
	if(a==1)
	{
		GUI_ShowCHinese(32,24,16,(u8 *)"采集成功",1);
		GUI_ShowCHinese(20,45,16,(u8 *)"指纹",1);
		sprintf((char *)str, "ID: %3d", user_ID);
		GUI_ShowString(53,45,str, 16, 1);
		UART_Timer(2000);
		ack_sta=0;
		OLED_Clear(0);
	}
	else if(a==2)
	{
		GUI_ShowCHinese(32,24,16,(u8 *)"松开指纹",1);
		UART_Timer(700);
		ack_sta=0;
	}
}

/***************************************************
 * @function	:删除警告，防止误删
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_6(void)
{
	u8 str[10];
	GUI_ShowCHinese(40,1,24,(u8 *)"提示",1);
	GUI_ShowCHinese(12,28,16,(u8 *)"确定删除指纹",1);
	GUI_ShowChar(108,28,'?',16,1);
	UART_Get_User();
	sprintf((char *)str, "ID: %3d", user_ID);
	GUI_ShowString(30,45,str, 16, 1);
}

/***************************************************
 * @function	:删除警告，防止误删
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_7(void)
{
	GUI_ShowCHinese(40,1,24,(u8 *)"提示",1);
	GUI_ShowCHinese(12,40,16,(u8 *)"确定清空指纹",1);
	GUI_ShowChar(108,40,'?',16,1);
}

/***************************************************
 * @function	:删除最后一次注册的用户成功
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_8(void)
{
	if(UART_Del_AppUser((u32)user_ID)==1)
	{
		GUI_ShowCHinese(30,24,16,(u8 *)"删除成功",1);
	}
	else
	{
		GUI_ShowCHinese(30,24,16,(u8 *)"删除",1);
	}
}

/***************************************************
 * @function	:删除所有用户成功
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void menue_9(void)
{
	if(UART_Del_AllUser()==1)
	{
		GUI_ShowCHinese(30,24,16,(u8 *)"删除成功",1);
	}
	else
	{
		GUI_ShowCHinese(30,24,16,(u8 *)"删除",1);
	}
}


