#include "LED.h"

led_t leds[] = {
    {GPIOB, GPIO_Pin_0},
    {GPIOB, GPIO_Pin_1},
    {GPIOE, GPIO_Pin_9}
};


void LED_Init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    // LED1 & LED2
    GPIO_InitStruct.GPIO_Pin = leds[0].GPIO_Pin | leds[1].GPIO_Pin;
    GPIO_Init(leds[0].GPIOx, &GPIO_InitStruct);

    // LED3
    GPIO_InitStruct.GPIO_Pin = leds[2].GPIO_Pin;
    GPIO_Init(leds[2].GPIOx, &GPIO_InitStruct);
}

void LED_Switch(led_t led, bool Switch)
{
    GPIO_WriteBit(led.GPIOx, led.GPIO_Pin, Switch ? Bit_RESET : Bit_SET);
}

void LED1_Switch(bool Switch)
{
    LED_Switch(leds[0], Switch);
}

void LED2_Switch(bool Switch)
{
    LED_Switch(leds[1], Switch);
}

void LED3_Switch(bool Switch)
{
    LED_Switch(leds[2], Switch);
}
