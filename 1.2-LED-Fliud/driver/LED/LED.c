#include "LED.h"

led_t leds[] = {
    {GPIOB, GPIO_Pin_0},
    {GPIOB, GPIO_Pin_1},
    {GPIOE, GPIO_Pin_9}
};


void LED_Init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    /* Configure PG6 and PG8 in output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = LED1_PIN | LED2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED3_PIN;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_SetBits(LED2_PORT, LED2_PIN);
    GPIO_SetBits(LED3_PORT, LED3_PIN);
}

void LED_Switch(uint8_t index, bool Switch)
{
    switch(index)
    {
        case 1:
            GPIO_WriteBit(LED1_PORT, LED1_PIN, Switch ? Bit_RESET : Bit_SET);
            break;
        case 2:
            GPIO_WriteBit(LED2_PORT, LED2_PIN, Switch ? Bit_RESET : Bit_SET);
            break;
        case 3:
            GPIO_WriteBit(LED3_PORT, LED3_PIN, Switch ? Bit_RESET : Bit_SET);
            break;
    }
}

void LED_ON(uint8_t index)
{
    LED_Switch(index, true);
}

void LED_OFF(uint8_t index)
{
    LED_Switch(index, false);
}

void LED_ALL_OFF(void)
{
    LED_OFF(1);
    LED_OFF(2);
    LED_OFF(3);
}
