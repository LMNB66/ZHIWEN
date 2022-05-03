#ifndef _LED_H_
#define _LED_H_

#include "sys.h"

#define LED GPIO_Pin_13
#define led PCout(13)

void Led_Init(void);

#endif
