/****************************************************************************************************
//=========================================电源接线================================================//
// OLED模块               STM32单片机
//   VCC         接       DC 5V/3.3V      //OLED屏电源正
//   GND         接          GND          //OLED屏电源地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为4线制SPI
// OLED模块               STM32单片机
//   D1          接          PB15        //OLED屏SPI写信号
//=======================================液晶屏控制线接线==========================================//
// OLED模块               STM32单片机
//   CS          接          PB11        //OLED屏片选控制信号
//   RES         接          PB12        //OLED屏复位控制信号
//   DC          接          PB10        //OLED屏数据/命令选择控制信号
//   D0          接          PB13        //OLED屏SPI时钟信号
****************************************************************************************************/	
#ifndef __GUI_H__
#define __GUI_H__

#include "stm32f10x.h"
void GUI_DrawPoint(u8 x, u8 y, u8 color);
void GUI_Fill(u8 sx,u8 sy,u8 ex,u8 ey,u8 color);
void GUI_DrawLine(u8 x1, u8 y1, u8 x2, u8 y2,u8 color);
void GUI_DrawRectangle(u8 x1, u8 y1, u8 x2, u8 y2,u8 color);
void GUI_FillRectangle(u8 x1, u8 y1, u8 x2, u8 y2,u8 color);
void GUI_DrawCircle(u8 xc, u8 yc, u8 color, u8 r);
void GUI_FillCircle(u8 xc, u8 yc, u8 color, u8 r);
void GUI_DrawTriangel(u8 x0,u8 y0,u8 x1,u8 y1,u8 x2,u8 y2,u8 color);
void GUI_FillTriangel(u8 x0,u8 y0,u8 x1,u8 y1,u8 x2,u8 y2,u8 color);
void GUI_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size,u8 mode);
void GUI_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 Size,u8 mode);
void GUI_ShowString(u8 x,u8 y,u8 *chr,u8 Char_Size,u8 mode);
void GUI_ShowFont16(u8 x,u8 y,u8 *s,u8 mode);
void GUI_ShowFont24(u8 x,u8 y,u8 *s,u8 mode);
void GUI_ShowFont32(u8 x,u8 y,u8 *s,u8 mode);
void GUI_ShowCHinese(u8 x,u8 y,u8 hsize,u8 *str,u8 mode);
void GUI_DrawBMP(u8 x,u8 y,u8 width, u8 height, u8 BMP[], u8 mode);
#endif

