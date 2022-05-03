#ifndef _SERVO_H_
#define _SERVO_H_

#include "sys.h"

#define mos_servo PAout(11)

void SERVO_TIM3_Init(u16 arr,u16 psc);
void servo_control(u8 pwm_);

#endif

