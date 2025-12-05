#include "KEY.h"

void KEY_Init(KEY_t* KEY)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_InitStruct.GPIO_Pin = KEY->GPIO_Pin;
    GPIO_Init(KEY->GPIOx, &GPIO_InitStruct);
}

bool KEY_Scan(KEY_t* KEY)
{
    if (GPIO_ReadInputDataBit(KEY->GPIOx, KEY->GPIO_Pin) == Bit_RESET)
    {
        Delay_ms(10);
        if (GPIO_ReadInputDataBit(KEY->GPIOx, KEY->GPIO_Pin) == Bit_RESET)
        {
            // 等待松手
            while (GPIO_ReadInputDataBit(KEY->GPIOx, KEY->GPIO_Pin) == Bit_RESET);
            Delay_ms(10);
            return true;
        }
    }
    return false;
}
