#ifndef __LED_DESC_H__
#define __LED_DESC_H__

#include "LED.h"
#include "stm32f4XX.h"

typedef struct LED_Desc
{
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
    BitAction ON_BitVal;
    BitAction OFF_BitVal;
}LED_Desc_t;

#endif /* __LED_DESC_H__ */
