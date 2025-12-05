#include "board.h"

KEY_t KEY1 = {GPIOA, GPIO_Pin_0};
KEY_t KEY2 = {GPIOC, GPIO_Pin_4};
KEY_t KEY3 = {GPIOC, GPIO_Pin_5};

LED_Desc LED1 = {
    GPIOB,
    GPIO_Pin_0,
    Bit_RESET,
    Bit_SET
};

LED_Desc LED2 = {
    GPIOB,
    GPIO_Pin_1,
    Bit_RESET,
    Bit_SET
};

LED_Desc LED3 = {
    GPIOE,
    GPIO_Pin_9,
    Bit_RESET,
    Bit_SET
};

void Board_LowerLevel_Init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    /* 初始化 LED 引脚并设为默认关闭 */
    LED_Init(&LED1);
    LED_Init(&LED2);
    LED_Init(&LED3);

    /* 初始化按键引脚 */
    KEY_Init(&KEY1);
    KEY_Init(&KEY2);
    KEY_Init(&KEY3);

    USART1_Init();
}
