#include "LED.h"

void LED_Init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Fast_Speed;

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init(GPIOE, &GPIO_InitStruct);

}

void LED_Switch(uint8_t index, bool Switch)
{
    switch(index)
    {
        case 1:
            GPIO_WriteBit(GPIOB, GPIO_Pin_0, Switch ? Bit_RESET : Bit_SET);
            break;
        case 2:
            GPIO_WriteBit(GPIOB, GPIO_Pin_1, Switch ? Bit_RESET : Bit_SET);
            break;
        case 3:
            GPIO_WriteBit(GPIOE, GPIO_Pin_9, Switch ? Bit_RESET : Bit_SET);
            break;
        default:
            break;
    }
}


