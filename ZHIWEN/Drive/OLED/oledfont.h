/****************************************************************************************************
//=========================================��Դ����================================================//
// OLEDģ��               STM32��Ƭ��
//   VCC         ��       DC 5V/3.3V      //OLED����Դ��
//   GND         ��          GND          //OLED����Դ��
//=======================================Һ���������߽���==========================================//
//��ģ��Ĭ��������������Ϊ4����SPI
// OLEDģ��               STM32��Ƭ��
//   D1          ��          PB15        //OLED��SPIд�ź�
//=======================================Һ���������߽���==========================================//
// OLEDģ��               STM32��Ƭ��
//   CS          ��          PB11        //OLED��Ƭѡ�����ź�
//   RES         ��          PB12        //OLED����λ�����ź�
//   DC          ��          PB10        //OLED������/����ѡ������ź�
//   D0          ��          PB13        //OLED��SPIʱ���ź�
****************************************************************************************************/	
/***************************************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
****************************************************************************************************/	
#ifndef __OLEDFONT_H
#define __OLEDFONT_H 
	   
//����ASCII��
//ƫ����32
//ASCII�ַ���
//ƫ����32
//��С:6*8
//����ʽ��˳�򣨸�λ��ǰ��
/************************************6*8�ĵ���************************************/
const unsigned char F6x8[][8] =		
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // sp
	0x10,0x10,0x10,0x10,0x00,0x10,0x00,0x00, // !
	0x28,0x28,0x28,0x00,0x00,0x00,0x00,0x00, // "
	0x28,0x28,0x7C,0x28,0x7C,0x28,0x28,0x00, // #
	0x10,0x3C,0x50,0x38,0x14,0x78,0x10,0x00, // $
	0x00,0x4C,0x2C,0x10,0x08,0x60,0x60,0x00, // %
	0x30,0x48,0x50,0x20,0x54,0x48,0x34,0x00, // &
	0x30,0x10,0x20,0x00,0x00,0x00,0x00,0x00, // '
	0x08,0x10,0x20,0x20,0x20,0x10,0x08,0x00, // (
	0x20,0x10,0x08,0x08,0x08,0x10,0x20,0x00, // )
	0x00,0x10,0x54,0x38,0x54,0x10,0x00,0x00, // *
	0x00,0x10,0x10,0x7C,0x10,0x10,0x00,0x00, // +
	0x00,0x00,0x00,0x00,0x00,0x18,0x08,0x10, // ,
	0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00, // -
	0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00, // .
	0x00,0x04,0x08,0x10,0x20,0x40,0x00,0x00, // /
	0x38,0x44,0x4C,0x54,0x64,0x44,0x38,0x00, // 0
	0x10,0x30,0x10,0x10,0x10,0x10,0x38,0x00, // 1
	0x38,0x44,0x04,0x08,0x10,0x20,0x7C,0x00, // 2
	0x7C,0x08,0x10,0x08,0x04,0x44,0x38,0x00, // 3 
	0x08,0x18,0x28,0x48,0x7C,0x08,0x08,0x00, // 4
	0x7C,0x40,0x78,0x04,0x04,0x44,0x38,0x00, // 5
	0x18,0x20,0x40,0x78,0x44,0x44,0x38,0x00, // 6
	0x7C,0x04,0x08,0x10,0x20,0x20,0x20,0x00, // 7
	0x38,0x44,0x44,0x38,0x44,0x44,0x38,0x00, // 8
	0x38,0x44,0x44,0x3C,0x04,0x08,0x30,0x00, // 9
	0x00,0x30,0x30,0x00,0x30,0x30,0x00,0x00, // :
	0x00,0x30,0x30,0x00,0x30,0x10,0x20,0x00, // ;
	0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x00, // <
	0x00,0x00,0x7C,0x00,0x7C,0x00,0x00,0x00, // =
	0x20,0x10,0x08,0x04,0x08,0x10,0x20,0x00, // >
	0x38,0x44,0x04,0x08,0x10,0x00,0x10,0x00, // ?
	0x38,0x44,0x04,0x34,0x5C,0x44,0x38,0x00, // @
	0x10,0x28,0x44,0x44,0x7C,0x44,0x44,0x00, // A
	0x78,0x44,0x44,0x78,0x44,0x44,0x78,0x00, // B
	0x38,0x44,0x40,0x40,0x40,0x44,0x38,0x00, // C
	0x70,0x48,0x44,0x44,0x44,0x48,0x70,0x00, // D
	0x7C,0x40,0x40,0x78,0x40,0x40,0x7C,0x00, // E
	0x7C,0x40,0x40,0x78,0x40,0x40,0x40,0x00, // F
	0x38,0x44,0x40,0x5C,0x44,0x44,0x3C,0x00, // G
	0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x00, // H
	0x38,0x10,0x10,0x10,0x10,0x10,0x38,0x00, // I
	0x1C,0x08,0x08,0x08,0x08,0x48,0x30,0x00, // J
	0x44,0x48,0x50,0x60,0x50,0x48,0x44,0x00, // K
	0x40,0x40,0x40,0x40,0x40,0x40,0x7C,0x00, // L
	0x44,0x6C,0x54,0x54,0x44,0x44,0x44,0x00, // M
	0x44,0x44,0x64,0x54,0x4C,0x44,0x44,0x00, // N
	0x38,0x44,0x44,0x44,0x44,0x44,0x38,0x00, // O
	0x78,0x44,0x44,0x78,0x40,0x40,0x40,0x00, // P
	0x38,0x44,0x44,0x44,0x54,0x48,0x34,0x00, // Q
	0x78,0x44,0x44,0x78,0x50,0x48,0x44,0x00, // R
	0x3C,0x40,0x40,0x38,0x04,0x04,0x78,0x00, // S
	0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x00, // T
	0x44,0x44,0x44,0x44,0x44,0x44,0x38,0x00, // U
	0x44,0x44,0x44,0x44,0x44,0x28,0x10,0x00, // V
	0x44,0x44,0x44,0x54,0x54,0x54,0x28,0x00, // W
	0x44,0x44,0x28,0x10,0x28,0x44,0x44,0x00, // X
	0x44,0x44,0x44,0x28,0x10,0x10,0x10,0x00, // Y
	0x7C,0x04,0x08,0x10,0x20,0x40,0x7C,0x00, // Z
	0x38,0x20,0x20,0x20,0x20,0x20,0x38,0x00, // [
	0x00,0x40,0x20,0x10,0x08,0x04,0x00,0x00, // '\'
	0x38,0x08,0x08,0x08,0x08,0x08,0x38,0x00, // ]
	0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00, // ^
	0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00, // _
	0x20,0x10,0x08,0x00,0x00,0x00,0x00,0x00, // '
	0x00,0x00,0x38,0x04,0x3C,0x44,0x3C,0x00, // a
	0x40,0x40,0x58,0x64,0x44,0x44,0x78,0x00, // b
	0x00,0x00,0x38,0x40,0x40,0x44,0x38,0x00, // c
	0x04,0x04,0x34,0x4C,0x44,0x44,0x3C,0x00, // d
	0x00,0x00,0x38,0x44,0x7C,0x40,0x38,0x00, // e
	0x38,0x24,0x20,0x70,0x20,0x20,0x20,0x00, // f
	0x00,0x00,0x3C,0x44,0x44,0x3C,0x04,0x38, // g
	0x40,0x40,0x58,0x64,0x44,0x44,0x44,0x00, // h
	0x10,0x00,0x30,0x10,0x10,0x10,0x38,0x00, // i
	0x08,0x00,0x18,0x08,0x08,0x08,0x48,0x30, // j
	0x40,0x40,0x48,0x50,0x60,0x50,0x48,0x00, // k
	0x30,0x10,0x10,0x10,0x10,0x10,0x38,0x00, // l
	0x00,0x00,0x68,0x54,0x54,0x44,0x44,0x00, // m
	0x00,0x00,0x58,0x64,0x44,0x44,0x44,0x00, // n
	0x00,0x00,0x38,0x44,0x44,0x44,0x38,0x00, // o
	0x00,0x00,0x58,0x64,0x64,0x58,0x40,0x40, // p
	0x00,0x00,0x34,0x4C,0x4C,0x34,0x04,0x04, // q
	0x00,0x00,0x58,0x64,0x40,0x40,0x40,0x00, // r
	0x00,0x00,0x3C,0x40,0x38,0x04,0x78,0x00, // s
	0x20,0x20,0x70,0x20,0x20,0x24,0x18,0x00, // t
	0x00,0x00,0x44,0x44,0x44,0x4C,0x34,0x00, // u
	0x00,0x00,0x44,0x44,0x44,0x28,0x10,0x00, // v
	0x00,0x00,0x44,0x44,0x54,0x54,0x28,0x00, // w
	0x00,0x00,0x44,0x28,0x10,0x28,0x44,0x00, // x
	0x00,0x00,0x44,0x44,0x44,0x3C,0x04,0x38, // y
	0x00,0x00,0x7C,0x08,0x10,0x20,0x7C,0x00, // z
	0x10,0x20,0x20,0x40,0x20,0x20,0x10,0x00, // {
	0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x00, // |
	0x20,0x10,0x10,0x08,0x10,0x10,0x20,0x00, // }
	0x00,0x00,0x00,0x20,0x54,0x08,0x00,0x00, // ~
};

//����ASCII��
//ƫ����32
//ASCII�ַ���
//ƫ����32
//��С:8*16
//����ʽ��˳�򣨸�λ��ǰ��
/****************************************8*16�ĵ���************************************/
const unsigned char F8X16[]=	  
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 0
  0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x18,0x18,0x00,0x00,//! 1
  0x00,0x12,0x36,0x24,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//" 2
  0x00,0x00,0x00,0x24,0x24,0x24,0xFE,0x48,0x48,0x48,0xFE,0x48,0x48,0x48,0x00,0x00,//# 3
  0x00,0x00,0x10,0x38,0x54,0x54,0x50,0x30,0x1C,0x14,0x14,0x54,0x54,0x38,0x10,0x10,//$ 4
  0x00,0x00,0x00,0x44,0xA4,0xA8,0xA8,0xA8,0x54,0x1A,0x2A,0x2A,0x2A,0x44,0x00,0x00,//% 5
  0x00,0x00,0x00,0x30,0x48,0x48,0x48,0x50,0x6E,0xA4,0x94,0x88,0x89,0x76,0x00,0x00,//& 6
  0x00,0x60,0x60,0x20,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//' 7
  0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00,//( 8
  0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00,//) 9
  0x00,0x00,0x00,0x00,0x10,0x10,0xD6,0x38,0x38,0xD6,0x10,0x10,0x00,0x00,0x00,0x00,//* 10
  0x00,0x00,0x00,0x00,0x10,0x10,0x10,0x10,0xFE,0x10,0x10,0x10,0x10,0x00,0x00,0x00,//+ 11
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x20,0xC0,//, 12
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//- 13
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x00,0x00,//. 14
  0x00,0x00,0x01,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x00,/// 15
  0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,//0 16
  0x00,0x00,0x00,0x10,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//1 17
  0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x04,0x04,0x08,0x10,0x20,0x42,0x7E,0x00,0x00,//2 18
  0x00,0x00,0x00,0x3C,0x42,0x42,0x04,0x18,0x04,0x02,0x02,0x42,0x44,0x38,0x00,0x00,//3 19
  0x00,0x00,0x00,0x04,0x0C,0x14,0x24,0x24,0x44,0x44,0x7E,0x04,0x04,0x1E,0x00,0x00,//4 20
  0x00,0x00,0x00,0x7E,0x40,0x40,0x40,0x58,0x64,0x02,0x02,0x42,0x44,0x38,0x00,0x00,//5 21
  0x00,0x00,0x00,0x1C,0x24,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x24,0x18,0x00,0x00,//6 22
  0x00,0x00,0x00,0x7E,0x42,0x44,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,//7 23
  0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,//8 24
  0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x26,0x1A,0x02,0x02,0x24,0x38,0x00,0x00,//9 25
  0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,//: 26
  0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x08,0x30,0x00,//; 27
  0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00,//< 28
  0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,//= 29
  0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00,//> 30
  0x00,0x00,0x00,0x3C,0x42,0x42,0x62,0x02,0x04,0x08,0x08,0x00,0x18,0x18,0x00,0x00,//? 31
  0x00,0x00,0x00,0x38,0x44,0x5A,0xAA,0xAA,0xAA,0xAA,0xB4,0x42,0x44,0x38,0x00,0x00,//@ 32
  0x00,0x00,0x00,0x10,0x10,0x18,0x28,0x28,0x24,0x3C,0x44,0x42,0x42,0xE7,0x00,0x00,//A 33
  0x00,0x00,0x00,0xF8,0x44,0x44,0x44,0x78,0x44,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,//B 34
  0x00,0x00,0x00,0x3E,0x42,0x42,0x80,0x80,0x80,0x80,0x80,0x42,0x44,0x38,0x00,0x00,//C 35
  0x00,0x00,0x00,0xF8,0x44,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x44,0xF8,0x00,0x00,//D 36
  0x00,0x00,0x00,0xFE,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x42,0x42,0xFE,0x00,0x00,//E 37
  0x00,0x00,0x00,0xFE,0x42,0x48,0x48,0x78,0x48,0x48,0x40,0x40,0x40,0xE0,0x00,0x00,//F 38
  0x00,0x00,0x00,0x3C,0x44,0x44,0x80,0x80,0x80,0x8E,0x84,0x44,0x44,0x38,0x00,0x00,//G 39
  0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,//H 40
  0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//I 41
  0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x88,0xF0,//J 42
  0x00,0x00,0x00,0xEE,0x44,0x48,0x50,0x70,0x50,0x48,0x48,0x44,0x44,0xEE,0x00,0x00,//K 43
  0x00,0x00,0x00,0xE0,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x42,0xFE,0x00,0x00,//L 44
  0x00,0x00,0x00,0xEE,0x6C,0x6C,0x6C,0x6C,0x54,0x54,0x54,0x54,0x54,0xD6,0x00,0x00,//M 45
  0x00,0x00,0x00,0xC7,0x62,0x62,0x52,0x52,0x4A,0x4A,0x4A,0x46,0x46,0xE2,0x00,0x00,//N 46
  0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00,//O 47
  0x00,0x00,0x00,0xFC,0x42,0x42,0x42,0x42,0x7C,0x40,0x40,0x40,0x40,0xE0,0x00,0x00,//P 48
  0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0xB2,0xCA,0x4C,0x38,0x06,0x00,//Q 49
  0x00,0x00,0x00,0xF8,0x44,0x44,0x44,0x78,0x48,0x48,0x44,0x44,0x42,0xE3,0x00,0x00,//R 50
  0x00,0x00,0x00,0x3E,0x42,0x42,0x40,0x20,0x18,0x04,0x02,0x42,0x42,0x7C,0x00,0x00,//S 51
  0x00,0x00,0x00,0xFE,0x92,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,//T 52
  0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,//U 53
  0x00,0x00,0x00,0xE7,0x42,0x42,0x44,0x24,0x24,0x28,0x28,0x18,0x10,0x10,0x00,0x00,//V 54
  0x00,0x00,0x00,0xD6,0x92,0x92,0x92,0x92,0xAA,0xAA,0x6C,0x44,0x44,0x44,0x00,0x00,//W 55
  0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00,//X 56
  0x00,0x00,0x00,0xEE,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00,//Y 57
  0x00,0x00,0x00,0x7E,0x84,0x04,0x08,0x08,0x10,0x20,0x20,0x42,0x42,0xFC,0x00,0x00,//Z 58
  0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00,//[ 59
  0x00,0x00,0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x04,0x04,0x02,0x02,0x02,0x01,0x01,//\ 60
  0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00,//] 61
  0x00,0x08,0x14,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//^ 62
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,//_ 63
  0x00,0x60,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//` 64
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x1E,0x22,0x42,0x42,0x3F,0x00,0x00,//a 65
  0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x64,0x58,0x00,0x00,//b 66
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x22,0x40,0x40,0x40,0x22,0x1C,0x00,0x00,//c 67
  0x00,0x00,0x00,0x06,0x02,0x02,0x02,0x1E,0x22,0x42,0x42,0x42,0x26,0x1B,0x00,0x00,//d 68
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x40,0x40,0x42,0x3C,0x00,0x00,//e 69
  0x00,0x00,0x00,0x0F,0x11,0x10,0x10,0x7E,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//f 70
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x44,0x44,0x38,0x40,0x3C,0x42,0x42,0x3C,//g 71
  0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x5C,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,//h 72
  0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//i 73
  0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x1C,0x04,0x04,0x04,0x04,0x04,0x04,0x44,0x78,//j 74
  0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x4E,0x48,0x50,0x68,0x48,0x44,0xEE,0x00,0x00,//k 75
  0x00,0x00,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,//l 76
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF6,0x49,0x49,0x49,0x49,0x49,0xED,0x00,0x00,//m 77
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDC,0x62,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,//n 78
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,//o 79
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0x64,0x42,0x42,0x42,0x64,0x58,0x40,0xE0,//p 80
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x22,0x42,0x42,0x42,0x26,0x1A,0x02,0x07,//q 81
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x32,0x20,0x20,0x20,0x20,0xF8,0x00,0x00,//r 82
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x42,0x40,0x3C,0x02,0x42,0x7C,0x00,0x00,//s 83
  0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x7C,0x10,0x10,0x10,0x10,0x10,0x0C,0x00,0x00,//t 84
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x42,0x42,0x42,0x42,0x46,0x3B,0x00,0x00,//u 85
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x10,0x10,0x00,0x00,//v 86
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD7,0x92,0x92,0xAA,0xAA,0x44,0x44,0x00,0x00,//w 87
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0x24,0x18,0x18,0x18,0x24,0x76,0x00,0x00,//x 88
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x28,0x18,0x10,0x10,0xE0,//y 89
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x44,0x08,0x10,0x10,0x22,0x7E,0x00,0x00,//z 90
  0x00,0x03,0x04,0x04,0x04,0x04,0x04,0x08,0x04,0x04,0x04,0x04,0x04,0x04,0x03,0x00,//{ 91
  0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,//| 92
  0x00,0x60,0x10,0x10,0x10,0x10,0x10,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x60,0x00,//} 93
  0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x52,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//~ 94
};

typedef struct 
{
	unsigned char Index[2];	
	char Msk[32];
}typFNT_GB16; 

//����
//16*16��С
//����ʽ��˳�򣨸�λ��ǰ��
const typFNT_GB16 cfont16[] = 
{
	
	"��",	0x00,0x00,0x23,0xFC,0x10,0x40,0x10,0x40,0x87,0xFE,0x40,0xA0,0x41,0x10,0x12,0x08,
			0x14,0x46,0x20,0x40,0xE0,0x48,0x22,0x64,0x22,0x52,0x24,0x52,0x21,0x40,0x00,0x80,
			
	"��",	0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x7C,0xFE,0x44,0x12,0x44,0x12,0x44,0x12,0x44,
			0x12,0x44,0x12,0x44,0x12,0x44,0x12,0x44,0x22,0x44,0x22,0x7C,0x4A,0x44,0x84,0x00,
			
	"ɾ",	0x00,0x02,0x7B,0xC2,0x4A,0x42,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0xFF,0xEA,
			0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x42,0x5A,0x42,0x85,0x4A,0x08,0x84,
			
	"��",	0x00,0x40,0x78,0x40,0x48,0xA0,0x51,0x10,0x52,0x08,0x65,0xF6,0x50,0x40,0x48,0x40,
			0x4F,0xFC,0x48,0x40,0x6A,0x50,0x52,0x48,0x44,0x44,0x48,0x44,0x41,0x40,0x40,0x80,
			
	"��",	0x00,0x40,0x20,0x40,0x17,0xFC,0x10,0x40,0x83,0xF8,0x40,0x40,0x47,0xFE,0x10,0x00,
			0x13,0xF8,0x22,0x08,0xE3,0xF8,0x22,0x08,0x23,0xF8,0x22,0x08,0x22,0x28,0x02,0x10,
			
	"��",	0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x02,0x88,0x24,0x10,0x10,0x20,0x08,0x00,0x00,
			0x1F,0xF0,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x7F,0xFC,0x00,0x00,
					
	"ָ",	0x11,0x00,0x11,0x04,0x11,0x38,0x11,0xC0,0xFD,0x02,0x11,0x02,0x10,0xFE,0x14,0x00,
			0x19,0xFC,0x31,0x04,0xD1,0x04,0x11,0xFC,0x11,0x04,0x11,0x04,0x51,0xFC,0x21,0x04,
			
	"��",	0x10,0x80,0x10,0x40,0x20,0x40,0x27,0xFC,0x49,0x10,0xF1,0x10,0x11,0x10,0x21,0x10,
			0x41,0x10,0xF8,0xA0,0x40,0xA0,0x00,0x40,0x18,0xA0,0xE1,0x10,0x42,0x08,0x0C,0x06,
			
	"��",	0x08,0x20,0x49,0x20,0x2A,0x20,0x08,0x3E,0xFF,0x44,0x2A,0x44,0x49,0x44,0x88,0xA4,
			0x10,0x28,0xFE,0x28,0x22,0x10,0x42,0x10,0x64,0x28,0x18,0x28,0x34,0x44,0xC2,0x82,
			
	"��",	0x01,0x00,0x01,0x00,0x01,0x00,0x3F,0xF8,0x21,0x08,0x21,0x08,0x21,0x08,0x3F,0xF8,
			0x21,0x08,0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x0A,0x01,0x02,0x01,0x02,0x00,0xFE,
			
	"��",	0x00,0x00,0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x10,0x10,0xFF,0xFE,0x00,0x00,0x1F,0xF0,
			0x11,0x10,0x1F,0xF0,0x11,0x10,0x1F,0xF0,0x01,0x00,0x1F,0xF0,0x01,0x00,0x7F,0xFC,
	
	"ȷ",	0x00,0x40,0x00,0x40,0xFC,0x7C,0x10,0x84,0x11,0x08,0x22,0xFE,0x3C,0x92,0x64,0x92,
			0x64,0xFE,0xA4,0x92,0x24,0x92,0x24,0xFE,0x3C,0x92,0x25,0x12,0x21,0x0A,0x02,0x04,
			
	"��",	0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x02,0x80,0x04,0x00,0x00,0x3F,0xF8,0x01,0x00,
			0x01,0x00,0x11,0x00,0x11,0xF8,0x11,0x00,0x11,0x00,0x29,0x00,0x47,0xFE,0x80,0x00,
	
	"��",	0x10,0x40,0x10,0x20,0x10,0x20,0x13,0xFE,0xFA,0x02,0x14,0x44,0x10,0x40,0x1B,0xFE,
			0x30,0x88,0xD0,0x88,0x11,0x08,0x10,0xD0,0x10,0x20,0x10,0x50,0x50,0x88,0x23,0x04,
	
	"ѹ",	0x00,0x00,0x3F,0xFE,0x20,0x00,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x2F,0xFC,
			0x20,0x80,0x20,0x80,0x20,0x90,0x20,0x88,0x20,0x88,0x40,0x80,0x5F,0xFE,0x80,0x00,
	
	"��",	0x10,0x10,0x10,0x90,0x10,0x90,0x10,0x88,0xFC,0x88,0x11,0x24,0x31,0x24,0x3A,0x22,
			0x54,0x40,0x54,0x40,0x90,0x88,0x10,0x84,0x11,0x04,0x13,0xFE,0x11,0x02,0x10,0x00,
	
	"��",	0x00,0x00,0x7F,0xFC,0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0xFF,0xFE,
			0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0x10,0x20,0x10,0x20,0x20,0x20,0x40,0x20,

	"��",	0x00,0x10,0x00,0xF8,0x3F,0x00,0x02,0x00,0x11,0x10,0x09,0x10,0x08,0x20,0x01,0x00,
			0x7F,0xFC,0x03,0x80,0x05,0x40,0x09,0x20,0x11,0x10,0x21,0x08,0xC1,0x06,0x01,0x00,
	
	"��",	0x09,0x00,0x08,0x80,0x1F,0xFC,0x30,0x80,0x5F,0xF8,0x90,0x80,0x1F,0xF8,0x10,0x80,
			0x1F,0xFC,0x11,0x00,0xFF,0xFE,0x05,0x40,0x09,0x20,0x31,0x18,0xC1,0x06,0x01,0x00,
	
	"��",	0x00,0x50,0x00,0x48,0x00,0x40,0x3F,0xFE,0x20,0x40,0x20,0x40,0x20,0x44,0x3E,0x44,
			0x22,0x44,0x22,0x28,0x22,0x28,0x22,0x12,0x2A,0x32,0x44,0x4A,0x40,0x86,0x81,0x02,
	
	"��",	0x00,0x40,0x00,0x40,0x00,0x40,0xFE,0x40,0x11,0xFC,0x10,0x44,0x10,0x44,0x10,0x44,
			0x10,0x44,0x10,0x84,0x10,0x84,0x1E,0x84,0xF1,0x04,0x41,0x04,0x02,0x28,0x04,0x10,
	
};

typedef struct 
{
	unsigned char Index[2];	
	char Msk[72];
}typFNT_GB24; 


//����
//24*24��С
//����ʽ��˳�򣨸�λ��ǰ��
const typFNT_GB24 cfont24[] = 
{
	"��",	0x00,0x00,0x00,0x0E,0x10,0x30,0x0E,0x3F,0xF8,0x0E,0x38,0x30,0x0E,0x38,0x30,0x0F,
			0xBF,0xF0,0x7F,0xF8,0x30,0x0E,0x38,0x30,0x0E,0x38,0x30,0x0E,0x3F,0xF0,0x0F,0xF8,
			0x30,0x0F,0x90,0x0C,0x3F,0xFF,0xFE,0xFE,0x83,0x80,0x7E,0x73,0x80,0x0E,0x73,0x98,
			0x0E,0x73,0xFC,0x0E,0x73,0x80,0x0E,0xFB,0x80,0x0E,0xCF,0x80,0x7F,0xC7,0xFF,0x3F,
			0x81,0xFC,0x1F,0x00,0x00,0x00,0x00,0x00,
	"ʾ",	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x0F,0xFF,0xF8,0x04,0x00,0x00,0x00,
			0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x7F,0xFF,0xFE,0x20,0x1C,
			0x00,0x00,0x1C,0x00,0x03,0x9F,0x00,0x03,0xDD,0xC0,0x07,0x1C,0xE0,0x0F,0x1C,0x70,
			0x0E,0x1C,0x38,0x1C,0x1C,0x3C,0x38,0x1C,0x1C,0x70,0x1C,0x1C,0xE3,0xFC,0x00,0x00,
			0xF8,0x00,0x00,0x70,0x00,0x00,0x00,0x00,

};

typedef struct 
{
       unsigned char Index[2];	
       char Msk[128];
}typFNT_GB32; 

//����
//32*32��С
//����ʽ��˳�򣨸�λ��ǰ��
const typFNT_GB32 cfont32[] = 
{	
			
	"��",	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x78,0x00,
			0x00,0x00,0x70,0x00,0x00,0x18,0xF0,0x00,0x7F,0xFC,0xE0,0x00,0x00,0x38,0xE0,0x00,
			0x00,0x38,0xE0,0x38,0x30,0x79,0xFF,0xFC,0x38,0x71,0xC0,0x7C,0x1C,0x71,0xDC,0x70,
			0x0E,0x73,0x9E,0xE0,0x07,0xE3,0x1C,0xC0,0x07,0xE7,0x3C,0x00,0x03,0xE6,0x3C,0x00,
			0x01,0xC4,0x3E,0x00,0x01,0xE0,0x3E,0x00,0x03,0xF0,0x3E,0x00,0x03,0xF0,0x7E,0x00,
			0x07,0x78,0x77,0x00,0x0E,0x3C,0x77,0x00,0x0E,0x3C,0xE3,0x80,0x1C,0x1C,0xE3,0x80,
			0x38,0x19,0xC3,0xC0,0x30,0x03,0x81,0xE0,0x60,0x07,0x00,0xF0,0x00,0x0E,0x00,0xFC,
			0x00,0x3C,0x00,0x7C,0x00,0xF0,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};

#endif

