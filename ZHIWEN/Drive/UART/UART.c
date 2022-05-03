/*******************************************************
UART通信协议
8字节格式
数据格式如下
-------------------------------------------------------
Byte  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8
------|-----|-----|-----|-----|-----|-----|-----|------
CMD   |  F5 |TYPE |  P1 |  P2 |  P3 |  00 | CHK | F5
------|-----|-----|-----|-----|-----|-----|-----|------
ACK	  |  F5 |TYPE |  Q1 |  Q2 |  Q3 |  00 | CHK | F5
-------------------------------------------------------


 @NOTE   :本库只简单实现了指纹模组的基本操作，控制光圈
 修改注册设置等未能实现。本库操作指纹模组时只是返回一些
 状态参数，仍需要根据datasheet二次开发，不能直接调用。
 @author :LMNB66
*******************************************************/

#include "UART.h"
#include "string.h"
#include "delay.h"


u16 user_ID;//用户ID号或用户数暂存

u8 ack_buff[buff_size];//串口接收ACK缓存

u8 ack_size=0;//接收到的字节数

u8 ack_sta=0;//接收状态，0-未完成，1-已完成

/***************************************************
 * @function	:校验和，是第2个字节到第6个字节的异
				 或校验和。
 * @parameters	:8字节CMD/ACK命令
 * @retvalue	:CHK异或校验和
***************************************************/
u8 UART_Exclusive_Or_Check(u8 data[])
{
	u8 i, chk=data[1];
	for(i=2;i<6;i++)
	{
		chk^=data[i];
	}
	return chk;
}

/***************************************************
 * @function	:串口接收ACK存到ack_buff
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void UART_ACK_Receive(void)
{
	if(ack_size>=buff_size)ack_size=0;
	ack_buff[ack_size++]=USART_ReceiveData(USART2);	//读取接收到的数据
//	USART_SendData(USART1, ack_buff[ack_size-1]);
//	while((USART1->SR&0X40)==0){};
}

/***************************************************
 * @function	:对ACK进行异或校验
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void UART_ACK_Check(void)
{
	//判断接收到的字节数是否等于完整8字节
	if(ack_size==buff_size)
	{
		//判断帧头帧尾是否正确
		if(ack_buff[0]==0xf5 && ack_buff[7]==0xf5)
		{
			//异或校验
			if(ack_buff[6]==UART_Exclusive_Or_Check(ack_buff))
			{
				ack_sta=1;//接收完成
			}
		}
	}
	ack_size=0;//接收不成功，接收未完成
}

/***************************************************
 * @function	:将事先定义好的4字节(Byte 2~5)关键数
				 据帧打包成完整的8字节格式
 * @parameters	:cmd_data :4字节(Byte 2~5)关键数据帧
				 data	  :8字节格式数据包
 * @retvalue	:无
***************************************************/
void UART_CMD_Data_Frame(u32 cmd_data, u8 data[])
{
	data[0]=0xf5;
	data[1]=(cmd_data>>24)&0xff;
	data[2]=(cmd_data>>16)&0xff;
	data[3]=(cmd_data>>8)&0xff;
	data[4]=cmd_data&0xff;
	data[5]=0x00;
	data[6]=UART_Exclusive_Or_Check(data);//异或校验
	data[7]=0xf5;
} 

/***************************************************
 * @function	:发送8字节格式数据包
 * @parameters	:cmd_data :4字节(Byte 2~5)关键数据帧
 * @retvalue	:无
***************************************************/
void UART_CMD_Send(u32 cmd_data)
{
	u8 cmd_send[8], i;
	UART_CMD_Data_Frame(cmd_data, cmd_send);//阿姨，打包
	for(i=0;i<8;i++)
	{
		USART_SendData(USART2, cmd_send[i]);
		while((USART2->SR&0X40)==0){};
	}
}

/***************************************************
 * @function	:等待接收完成，等待超时退出
 * @parameters	:等待时间ms
 * @retvalue	:无
***************************************************/
void UART_Timer(u16 ms)
{
	u16 timer=0;
	while(1)
	{
		timer++;
		if(timer>=ms || ack_sta==1)break;//接收完成时或等待超时时退出
		delay_ms(1);
	}
}

/***************************************************
 * @function	:获取用户总数，存到user_ID
 * @parameters	:无
 * @retvalue	:0 - 获取失败
				 1 - 获取到用户数，存到user_ID
***************************************************/
u8 UART_Get_User(void)
{
	UART_CMD_Send(CMD_GET_USER);
	UART_Timer(50);//等待50ms
	if(ack_sta==1)
	{
		ack_sta=0;
		//判断接收到的TYPE类型和是否获取成功
		if(ack_buff[1]==ACK_GET_USER && ack_buff[4]==ACK_SUCCESS)
		{
			user_ID=ack_buff[2];
			user_ID<<=8;
			user_ID|=ack_buff[3];
			return 1;
		}
	}
	return 0;
}

/***************************************************
 * @function	:删除所有用户
 * @parameters	:无
 * @retvalue	:0 - 删除失败
				 1 - 删除成功
***************************************************/
u8 UART_Del_AllUser(void)
{
	UART_CMD_Send(CMD_DEL_ALLUSER);
	UART_Timer(100);
	if(ack_sta==1)
	{
		ack_sta=0;
		if(ack_buff[1]==ACK_DEL_ALLUSER && ack_buff[4]==ACK_SUCCESS)
		{
			return 1;
		}
	}
	return 0;
}

/***************************************************
 * @function	:删除指定用户
 * @parameters	:用户ID
 * @retvalue	:0 - 删除失败
				 1 - 删除成功
***************************************************/
u8 UART_Del_AppUser(u32 _user_ID)
{
	UART_CMD_Send(CMD_DEL_APPUSER|(_user_ID<<8));//把用户ID写到CMD发送
	UART_Timer(100);
	if(ack_sta==1)
	{
		ack_sta=0;
		if(ack_buff[1]==ACK_DEL_APPUSER && ack_buff[4]==ACK_SUCCESS)
		{
			return 1;
		}
	}
	return 0;
}

/***************************************************
 * @function	:采集指纹与指纹库所有用户比对
 * @parameters	:无
 * @retvalue	:0 - 对比失败
				 1 - 对比成功，模组返回的ID号存放到
					 user_ID
***************************************************/
u8 UART_Compare(void)
{
	UART_CMD_Send(CMD_COMPARE);
	UART_Timer(8000);//等待8s
	if(ack_sta==1)
	{
		ack_sta=0;
		//Q1,Q2都为0表示对比失败
		if(ack_buff[1]==ACK_COMPARE && (ack_buff[2]|ack_buff[3])!=0x00)
		{
			user_ID=ack_buff[2];
			user_ID<<=8;
			user_ID|=ack_buff[3];
			return 1;
		}
	}
	return 0;
}

/***************************************************
 * @function	:按压检测
 * @parameters	:无
 * @retvalue	:0 - 无按压
				 1 - 有按压
***************************************************/
u8 UART_Press(void)
{
	UART_CMD_Send(CMD_PRESS);
	UART_Timer(50);
	if(ack_sta==1)
	{
		ack_sta=0;
		if(ack_buff[1]==ACK_PRESS && ack_buff[4]==ACK_SUCCESS)
		{
			return 1;
		}
	}
	return 0;
}

/***************************************************
 * @function	:注册指纹ID（NCNR）
 * @parameters	:无
 * @retvalue	:0 - 注册失败
				 1 - 注册成功
				 2 - 注册中
***************************************************/
u8 UART_Enroll(void)
{
	UART_CMD_Send(CMD_ENROLL_NCNR);
	UART_Timer(8000);
	
	if(ack_sta==1)
	{
		ack_sta=0;
		if(ack_buff[1]==ACK_ENROLL_NCNR1 && ack_buff[4]==ACK_SUCCESS)
		{
			user_ID=ack_buff[2];
			user_ID<<=8;
			user_ID|=ack_buff[3];
			return 1;
		}
		else if(ack_buff[1]==ACK_ENROLL_NCNR)
		{
			return 2;
		}
	}
	return 0;
}

/***************************************************
 * @function	:打断操作
 * @parameters	:无
 * @retvalue	:0 - 打断失败
				 1 - 打断成功
***************************************************/
u8 UART_Stop(void)
{
	UART_CMD_Send(CMD_STOP);
	UART_Timer(50);
	if(ack_sta==1)
	{
		ack_sta=0;
		if(ack_buff[4]==ACK_SUCCESS)
		{
			return 1;
		}
	}
	return 0;
}

///***************************************************
// * @function	:设置拒绝重复注册相同指纹
// * @parameters	:无
// * @retvalue	:0 - 设置失败
//				 1 - 设置成功
//***************************************************/
//u8 UART_NoEcho_Enroll(void)
//{
//	
//}

/***************************************************
 * @function	:读指纹模组TOUCH_OUT引脚初始化
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void ZHIWEN_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	mos_zhiwen=0;//mos管导通
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource1);
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Line=EXTI_Line1;
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=3;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_InitStruct);
}

/***************************************************
 * @function	:指纹模组TOUCH_OUT中断唤醒
 * @parameters	:无
 * @retvalue	:无
***************************************************/
void EXTI1_IRQHandler(void)
{
	EXTI_ClearITPendingBit(EXTI_Line1);
}
