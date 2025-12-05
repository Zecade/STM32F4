#ifndef __LED_DESC_H__
#define __LED_DESC_H__

#include "stm32f4xx.h"

typedef struct
{
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
    BitAction ON_BitVal;
    BitAction OFF_BitVal;
}LED_Desc;

#endif /* __LED_DESC_H__ */
