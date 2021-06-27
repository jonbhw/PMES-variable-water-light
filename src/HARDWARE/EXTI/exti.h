#ifndef __EXTI_H
#define __EXTI_H

#include "sys.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "delay.h"

void EXTI_SW0_Init(void);
void EXTI_SW1_Init(void);

//void EXTI_DIP_Init(void);

#endif
