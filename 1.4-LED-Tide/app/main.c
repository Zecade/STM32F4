#include "main.h"


int main(void)
{
    LED_Init();
    LED_ALL_OFF();

    while (1)
    {
        for(uint8_t i = 1; i <= 3; i++)
        {
            LED_ON(i);
            Delay_ms(500);
            LED_OFF(i);
        }

        for(uint8_t i = 3 - 1; i >= 1; i--)
        {
            LED_ON(i);
            Delay_ms(500);
            LED_OFF(i);
        }

    }
}
