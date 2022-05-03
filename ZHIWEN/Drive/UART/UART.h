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
#ifndef _UART_H_
#define _UART_H_

#include "sys.h"

//接收ACK状态
#define ACK_SUCCESS 		0x00 	//执行成功
#define ACK_FAIL 			0x01 	//执行失败
#define ACK_FULL 			0x04 	//数据库满
#define ACK_NOUSER 			0x05 	//没有这个用户
#define ACK_USER_EXIST 		0x07 	//用户已存在
#define ACK_TIMEOUT 		0x08 	//图像采集超时
#define ACK_HARDWAREERROR 	0x0A 	//硬件错误
#define ACK_IMAGEERROR 		0x10 	//图像错误
#define ACK_BREAK 			0x18 	//终止当前指令
#define ACK_ALGORITHMFAIL 	0x11 	//贴膜攻击检测
#define ACK_HOMOLOGYFAIL 	0x12 	//同源性校验错误

//接收ACK类型(type)
#define ACK_GET_USER		0x09	//获取用户总数
#define ACK_ENROLL_NCNR		0x01	//多次按压注册(NCNR)
#define ACK_ENROLL_NCNR1	0x03	//多次按压注册(NCNR)(最后一次)
#define ACK_DEL_APPUSER		0x04	//删除指定用户
#define ACK_DEL_ALLUSER		0x05	//删除所有用户
#define ACK_COMPARE			0x0C	//1:N对比
#define ACK_NOECHO_ENROLL	0x2D	//拒绝重复注册
#define ACK_PRESS			0x30	//手指按压检测

//4字节(Byte 2~5)关键数据帧
#define CMD_GET_USER		0x09000000	//获取用户总数
#define CMD_ENROLL_NCNR		0x01000001	//多次按压注册(NCNR)
#define CMD_NOECHO_ENROLL	0x2D000100	//拒绝重复注册
#define CMD_COMPARE			0x0C000000	//1:N对比
#define CMD_STOP			0xFE000000	//打断指令
#define CMD_PRESS			0x30000000	//手指按压检测
#define CMD_DEL_ALLUSER		0x05000000	//删除所有用户
#define CMD_DEL_APPUSER		0x04000000	//删除指定用户(需要定义userID)

#define buff_size	8	//最大接收字节数，8字节格式

#define mos_zhiwen PAout(12)	//控制mos管导通截止

extern u16 user_ID;
extern u8 ack_buff[buff_size];
extern u8 ack_size;
extern u8 ack_sta;

void UART_Timer(u16 ms);
void UART_ACK_Receive(void);
void UART_ACK_Check(void);
void UART_CMD_Send(u32 cmd_data);
u8 UART_Get_User(void);
u8 UART_Del_AllUser(void);
u8 UART_Del_AppUser(u32 _user_ID);
u8 UART_Compare(void);
u8 UART_Press(void);
u8 UART_Enroll(void);
u8 UART_Stop(void);
//u8 UART_NoEcho_Enroll(void);
void ZHIWEN_Init(void);

#endif

