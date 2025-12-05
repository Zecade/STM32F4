#ifndef __USART_H__
#define __USART_H__

#include "stm32f4xx.h"
#include <stdio.h>

void USART1_Init(void);
void USART_Write(const char* str);

#endif /* __USART_H__ */
