#include "LED.h"

void LED_Init(LED_Desc* LED)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

    GPIO_InitStruct.GPIO_Pin = LED->GPIO_Pin;
    GPIO_Init(LED->GPIOx, &GPIO_InitStruct);
}

void LED_SetState(LED_Desc* LED, bool State)
{
    GPIO_WriteBit(LED->GPIOx, LED->GPIO_Pin, State ? LED->ON_BitVal : LED->OFF_BitVal);
}

void LED_ON(LED_Desc* LED)
{
    GPIO_WriteBit(LED->GPIOx, LED->GPIO_Pin, LED->ON_BitVal);
}

void LED_OFF(LED_Desc* LED)
{
    GPIO_WriteBit(LED->GPIOx, LED->GPIO_Pin, LED->OFF_BitVal);
}

void LED_Toggle(LED_Desc* LED)
{
    GPIO_ToggleBits(LED->GPIOx, LED->GPIO_Pin);
}
