#include "BUZZER.h"

void BUZZER_Init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;   // ✅ 使用 SPL 的速度宏
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_7;

    GPIO_Init(GPIOC, &GPIO_InitStruct);

    // 默认关闭蜂鸣器（依据硬件有效电平调整）
    GPIO_ResetBits(GPIOC, GPIO_Pin_7);
}
