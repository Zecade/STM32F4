#ifndef __KEY_DEC_H__
#define __KEY_DEC_H__

#include "stm32f4xx.h"

typedef struct
{
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
}KEY_t;


#endif /* __KEY_DEC_H__ */
