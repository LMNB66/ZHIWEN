#ifndef _ADC_H_
#define _ADC_H_

#include "sys.h"

void ADCx_Init(void);
u16 Get_ADC_Value(u8 ch,u8 times);

#endif
