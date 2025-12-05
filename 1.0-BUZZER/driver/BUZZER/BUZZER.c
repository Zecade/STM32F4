#include "BUZZER.h"

void BUZZER_Init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    TIM_InternalClockConfig(TIM3);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);

    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Prescaler = 84 - 1;
    TIM_TimeBaseInitStruct.TIM_Period = 366 - 1;
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);

    TIM_ARRPreloadConfig(TIM3, ENABLE);

    TIM_OCInitTypeDef TIM_OCInitStruct;
    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_Pulse = 50;
    TIM_OC2Init(TIM3, &TIM_OCInitStruct);
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Fast_Speed;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);


    TIM_Cmd(TIM3, ENABLE);

}

void BUZZER_Set(uint32_t Compare2)
{
    TIM_SetCompare2(TIM3, Compare2);
}

// 设置无源蜂鸣器频率（Hz）
void BUZZER_SetFreq(uint32_t freq_hz)
{
    if (freq_hz == 0)
    {
        // 休止符：输出 0% 占空比
        TIM_SetCompare2(TIM3, 0);
        return;
    }

    // TIM3 时钟：84MHz（APB1 定时器倍频×2）
    // 你的 PSC 设置为 83 → 定时器计数频率 = 84MHz / 84 = 1MHz
    // ARR = 1MHz / freq
    uint32_t arr = 1000000 / freq_hz;
    if (arr == 0) arr = 1;
    arr -= 1;

    TIM3->ARR = arr;
    TIM3->CCR2 = (arr + 1) / 2;    // 50% 占空比

    // 立即更新
    TIM_GenerateEvent(TIM3, TIM_EventSource_Update);
}
