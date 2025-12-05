#include "KEY_Desc.h"

// KEY1: PA0
// KEY2: PC4
// KEY3: PC5

void KEY_Init(KEY_Desc_t* KEY)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Pin = KEY->KEY_PIN;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEY->KEY_PORT, &GPIO_InitStruct);

    SYSCFG_EXTILineConfig(KEY->KEY_EXTI_PORT_SRC, KEY->KEY_EXTI_PIN_SRC);

    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_StructInit(&EXTI_InitStruct);
    EXTI_InitStruct.EXTI_Line = KEY->KEY_EXTI_Line;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStruct);

    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = KEY->KEY_IRQ;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 4;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&NVIC_InitStruct);
}

void KEY_Press_Callback_Register(KEY_Desc_t* KEY, KEY_Func_t Func)
{
    KEY->KEY_Func = Func;
}
