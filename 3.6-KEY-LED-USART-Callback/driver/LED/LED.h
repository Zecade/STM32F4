#ifndef __LED_H__
#define __LED_H__

#include "stm32f4xx.h"
#include <stdbool.h>

typedef struct
{
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
    BitAction ON_BitVal;
    BitAction OFF_BitVal;
}LED_Desc;

extern LED_Desc LED1;
extern LED_Desc LED2;
extern LED_Desc LED3;

void LED_Init(LED_Desc* LED);
void LED_SetState(LED_Desc* LED, bool State);
void LED_ON(LED_Desc* LED);
void LED_OFF(LED_Desc* LED);
void LED_Toggle(LED_Desc* LED);
void LED1_Toggle(void);
void LED2_Toggle(void);
void LED3_Toggle(void);
void LED_ALL_OFF(void);


#endif /* __LED_H__ */
