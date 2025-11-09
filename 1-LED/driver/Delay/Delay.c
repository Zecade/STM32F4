#include "Delay.h"

void Delay_us(uint32_t us)
{
    uint32_t temp;
    SysTick->LOAD = (SystemCoreClock / 1000000) * us;  // 计算重装值（1us = SystemCoreClock/1MHz 次）
    SysTick->VAL = 0x00;                               // 清空当前值寄存器
    SysTick->CTRL = 0x00000005;                        // 选择HCLK作为时钟源，启动SysTick

    // 等待计数到0
    do {
        temp = SysTick->CTRL;
    } while ((temp & 0x01) && !(temp & (1 << 16)));

    SysTick->CTRL = 0x00000004;                        // 关闭SysTick
    SysTick->VAL  = 0x00;                              // 清空计数
}

void Delay_ms(uint32_t ms)
{
    while(ms--)
    {
        Delay_us(1000);
    }
}

void Delay_s(uint32_t s)
{
    while(s--)
    {
        Delay_ms(1000);
    }
}
