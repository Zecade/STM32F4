#ifndef __LED_H__
#define __LED_H__

#include <stdbool.h>
#include "LED_Desc.h"


void LED_Init(LED_Desc* LED);
void LED_SetState(LED_Desc* LED, bool State);
void LED_ON(LED_Desc* LED);
void LED_OFF(LED_Desc* LED);
void LED_Toggle(LED_Desc* LED);


#endif /* __LED_H__ */
