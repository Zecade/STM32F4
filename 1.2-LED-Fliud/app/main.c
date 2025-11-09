#include "main.h"

void CPU_Delay(void)
{
    uint32_t Delay = 16800000;
    for(uint32_t t = 0; t < Delay; t++);
}



int main(void)
{
    LED_Init();
    LED_ALL_OFF();

    while (1)
    {
        for(uint8_t i = 1; i <= 3; i++)
        {
            LED_ON(i);
            Delay_ms(1000);
            LED_OFF(i);
        }

    }
}
