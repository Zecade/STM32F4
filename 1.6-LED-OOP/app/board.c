#include "board.h"

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

    /* 初始化 LED 引脚并设为默认关闭 */
    LED_Init(&LED1);
    LED_Init(&LED2);
    LED_Init(&LED3);

    LED_OFF(&LED1);
    LED_OFF(&LED2);
    LED_OFF(&LED3);
}
