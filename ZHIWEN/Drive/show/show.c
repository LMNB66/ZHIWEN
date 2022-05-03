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

u8 func_index=0;//��ʾҳ������

void (*current_operation_index)();//���庯��ָ��

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
};//��һ�����ֱ�ʾҳ���������ڶ�����ʾ���ϼ�������һҳ����������Ҳ�����

/***************************************************
 * @function	:���ݰ���ֵѡ������
 * @parameters	:��
 * @retvalue	:��
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
	//ҳ�治ͬʱˢ��ҳ��
	if(_index!=func_index)
	{
		OLED_Clear(0);
		_index=func_index;
	}
	current_operation_index=menue[func_index].current_operation;
	(*current_operation_index)();//���ú���
}

/***************************************************
 * @function	:���ָ���Ƿ���ڣ���������ƶ����
 * @parameters	:��
 * @retvalue	:��
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
 * @function	:��ʾһЩϵͳ��Ϣ��������ָ����
 * @parameters	:��
 * @retvalue	:��
***************************************************/
void menue_1(void)
{
	u8 str[10];
	UART_Get_User();
	GUI_ShowCHinese(1,10,16,(u8 *)"ָ����",1);
	sprintf((char *)str, ": %3d", user_ID);
	GUI_ShowString(50,10,str, 16, 1);
	GUI_ShowCHinese(1,36,16,(u8 *)"����",1);
	sprintf((char *)str, ": %3d%%", vol);
	GUI_ShowString(50,36,str, 16, 1);
}

/***************************************************
 * @function	:��ʾ�����ָ�ơ�
 * @parameters	:��
 * @retvalue	:��
***************************************************/
void menue_2(void)
{
	GUI_ShowCHinese(30,24,16,(u8 *)"���ָ��",1);
	GUI_FillTriangel(13,31,22,22,22,40,1);
	GUI_FillTriangel(110,31,101,22,101,40,1);
	GUI_DrawRectangle(28, 20, 95, 43,1);
	GUI_DrawRectangle(26, 18, 97, 45,1);
}

/***************************************************
 * @function	:��ʾ��ɾ��ָ�ơ�
 * @parameters	:��
 * @retvalue	:��
***************************************************/
void menue_3(void)
{
	GUI_ShowCHinese(30,24,16,(u8 *)"ɾ��ָ��",1);
	GUI_FillTriangel(13,31,22,22,22,40,1);
	GUI_FillTriangel(110,31,101,22,101,40,1);
	GUI_DrawRectangle(28, 20, 95, 43,1);
	GUI_DrawRectangle(26, 18, 97, 45,1);
}

/***************************************************
 * @function	:��ʾ�����ָ�ơ�
 * @parameters	:��
 * @retvalue	:��
***************************************************/
void menue_4(void)
{
	GUI_ShowCHinese(30,24,16,(u8 *)"���ָ��",1);
	GUI_FillTriangel(13,31,22,22,22,40,1);
	GUI_FillTriangel(110,31,101,22,101,40,1);
	GUI_DrawRectangle(28, 20, 95, 43,1);
	GUI_DrawRectangle(26, 18, 97, 45,1);
}

/***************************************************
 * @function	:ע��ָ�ƣ���ʾע�����
 * @parameters	:��
 * @retvalue	:��
***************************************************/
void menue_5(void)
{
	u8 a, str[10];
	GUI_ShowCHinese(32,24,16,(u8 *)"��ѹָ��",1);
	a=UART_Enroll();
	if(a==1)
	{
		GUI_ShowCHinese(32,24,16,(u8 *)"�ɼ��ɹ�",1);
		GUI_ShowCHinese(20,45,16,(u8 *)"ָ��",1);
		sprintf((char *)str, "ID: %3d", user_ID);
		GUI_ShowString(53,45,str, 16, 1);
		UART_Timer(2000);
		ack_sta=0;
		OLED_Clear(0);
	}
	else if(a==2)
	{
		GUI_ShowCHinese(32,24,16,(u8 *)"�ɿ�ָ��",1);
		UART_Timer(700);
		ack_sta=0;
	}
}

/***************************************************
 * @function	:ɾ�����棬��ֹ��ɾ
 * @parameters	:��
 * @retvalue	:��
***************************************************/
void menue_6(void)
{
	u8 str[10];
	GUI_ShowCHinese(40,1,24,(u8 *)"��ʾ",1);
	GUI_ShowCHinese(12,28,16,(u8 *)"ȷ��ɾ��ָ��",1);
	GUI_ShowChar(108,28,'?',16,1);
	UART_Get_User();
	sprintf((char *)str, "ID: %3d", user_ID);
	GUI_ShowString(30,45,str, 16, 1);
}

/***************************************************
 * @function	:ɾ�����棬��ֹ��ɾ
 * @parameters	:��
 * @retvalue	:��
***************************************************/
void menue_7(void)
{
	GUI_ShowCHinese(40,1,24,(u8 *)"��ʾ",1);
	GUI_ShowCHinese(12,40,16,(u8 *)"ȷ�����ָ��",1);
	GUI_ShowChar(108,40,'?',16,1);
}

/***************************************************
 * @function	:ɾ�����һ��ע����û��ɹ�
 * @parameters	:��
 * @retvalue	:��
***************************************************/
void menue_8(void)
{
	if(UART_Del_AppUser((u32)user_ID)==1)
	{
		GUI_ShowCHinese(30,24,16,(u8 *)"ɾ���ɹ�",1);
	}
	else
	{
		GUI_ShowCHinese(30,24,16,(u8 *)"ɾ��",1);
	}
}

/***************************************************
 * @function	:ɾ�������û��ɹ�
 * @parameters	:��
 * @retvalue	:��
***************************************************/
void menue_9(void)
{
	if(UART_Del_AllUser()==1)
	{
		GUI_ShowCHinese(30,24,16,(u8 *)"ɾ���ɹ�",1);
	}
	else
	{
		GUI_ShowCHinese(30,24,16,(u8 *)"ɾ��",1);
	}
}


