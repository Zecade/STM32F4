#ifndef __BUZZER_H__
#define __BUZZER_H__


#include "stm32f4xx.h"
void BUZZER_Init(void);
void BUZZER_Set(uint32_t Compare2);
void BUZZER_SetFreq(uint32_t freq_hz);
#endif /* __BUZZER_H__ */
