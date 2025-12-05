#ifndef __KEY_DESC_H__
#define __KEY_DESC_H__

#include "KEY.h"
#include "stm32f4xx.h"

typedef struct KEY_Desc
{
    GPIO_TypeDef *KEY_PORT;
    uint16_t KEY_PIN;
    uint8_t KEY_EXTI_PORT_SRC;
    uint8_t KEY_EXTI_PIN_SRC;
    uint32_t KEY_EXTI_Line;
    uint8_t KEY_IRQ;
    KEY_Func_t KEY_Func;
}KEY_Desc_t;




#endif /* __KEY_DESC_H__ */
