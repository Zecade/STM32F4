#ifndef __BOARD_H__
#define __BOARD_H__

#include "KEY_Desc.h"
#include "LED_Desc.h"
#include "Delay.h"

extern LED_Desc_t LED1;
extern LED_Desc_t LED2;
extern LED_Desc_t LED3;

extern KEY_Desc_t KEY1;
extern KEY_Desc_t KEY2;
extern KEY_Desc_t KEY3;

void Board_Lowerlevel_Init(void);



#endif /* __BOARD_H__ */
