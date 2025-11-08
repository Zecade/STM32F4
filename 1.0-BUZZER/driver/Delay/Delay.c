#include "Delay.h"

/*
 * 原理：
 *  - TIM2 挂在 APB1，总线时钟(APB1)通常为 42 MHz；
 *  - 当 APB1 预分频 != 1 时，定时器时钟 = APB1*2 = 84 MHz（F4 默认配置）；
 *  - 我们把 TIM2 的计数频率设置成 1 MHz（1 tick = 1 us），然后用 CNT 做差值轮询。
 */

static uint32_t __tim2_clk_hz = 84000000UL;  // 典型 F407: TIM2时钟=84MHz

void Timer2_Delay_Init_1MHz(void)
{
    // 同步系统时钟变量
    SystemCoreClockUpdate();

    // 根据常见默认时钟推断：APB1=42MHz, TIM2=APB1*2=84MHz
    // 如果你自定义了时钟树，改这里：
    __tim2_clk_hz = 84000000UL;

    // 使能 TIM2 时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    // 复位 TIM2
    TIM_DeInit(TIM2);

    // 计算分频：psc = (TIM2CLK / 1MHz) - 1
    uint16_t psc = (uint16_t)((__tim2_clk_hz / 1000000UL) - 1UL);  // 84MHz/1MHz -1 = 83

    TIM_TimeBaseInitTypeDef tb;
    tb.TIM_Prescaler         = psc;          // 预分频到 1MHz
    tb.TIM_CounterMode       = TIM_CounterMode_Up;
    tb.TIM_Period            = 0xFFFF;       // 最大 65535（自由运行）
    tb.TIM_ClockDivision     = TIM_CKD_DIV1;
    tb.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &tb);

    // 计数器清零并启动
    TIM_SetCounter(TIM2, 0);
    TIM_Cmd(TIM2, ENABLE);
}

void Delay_us(uint32_t us)
{
    // 利用无符号减法溢出性质：处理 CNT 回绕
    uint16_t start = (uint16_t)TIM_GetCounter(TIM2);
    while ((uint16_t)(TIM_GetCounter(TIM2) - start) < us) {
        __NOP();
    }
}

void Delay_ms(uint32_t ms)
{
    // 拆成 1ms*ms，避免乘法溢出
    while (ms--) {
        Delay_us(1000);
    }
}
