#ifndef __BOARD_H__
#define __BOARD_H__

#include "KEY.h"
#include "LED.h"
#include "USART.h"

extern KEY_t KEY1;
extern KEY_t KEY2;
extern KEY_t KEY3;

extern LED_Desc LED1;
extern LED_Desc LED2;
extern LED_Desc LED3;

void Board_LowerLevel_Init(void);

#endif /* __BOARD_H__ */
