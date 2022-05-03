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

#ifndef _SPI_H_
#define _SPI_H_

#include "sys.h"

//--------------SPI总线引脚定义-----------------------
#define OLED_MOSI      GPIO_Pin_15  //OLED屏SPI写数据信号
#define OLED_CLK       GPIO_Pin_13  //OLED屏SPI时钟信号

//--------------SPI端口操作定义---------------------
#define	OLED_MOSI_SET()  	GPIO_SetBits(GPIOB,OLED_MOSI) 
#define	OLED_MOSI_CLR()  	GPIO_ResetBits(GPIOB,OLED_MOSI) 
  
#define	OLED_CLK_SET()  	GPIO_SetBits(GPIOB,OLED_CLK)    
#define	OLED_CLK_CLR()  	GPIO_ResetBits(GPIOB,OLED_CLK)    

//SPI写数据函数
void SPI_WriteByte(u8 Data);
#endif
