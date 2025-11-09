#ifndef __LED_H__
#define __LED_H__

#include "stm32f4xx.h"
#include <stdbool.h>

void LED_Init(void);
void LED_Switch(uint8_t index, bool Switch);


#endif /* __LED_H__ */
