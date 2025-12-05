#include "Delay.h"

void Delay_us(uint32_t xus)
{
    SysTick->LOAD = xus * 168;     // 168 MHz 时钟：1us = 168 tick
    SysTick->VAL  = 0x00;          // 清零当前值
    SysTick->CTRL = 0x00000005;    // 选择 HCLK，启动计数

    while(!(SysTick->CTRL & (1 << 16)));  // 等待 COUNTFLAG 置位

    SysTick->CTRL = 0x00000004;    // 关闭计数器（保留时钟源配置）
}

void Delay_ms(uint32_t xms)
{
    while(xms--)
        Delay_us(1000);
}

void Delay_s(uint32_t xs)
{
    while(xs--)
        Delay_ms(1000);
}
