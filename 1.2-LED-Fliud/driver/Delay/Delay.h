#ifndef __DELAY_TIMER_H__
#define __DELAY_TIMER_H__

#include "stm32f4xx.h"

void Timer2_Delay_Init_1MHz(void);  // 初始化 TIM2 为 1MHz 计数（1tick = 1us）
void Delay_us(uint32_t us);         // 微秒延时（轮询）
void Delay_ms(uint32_t ms);         // 毫秒延时（轮询）

#endif
