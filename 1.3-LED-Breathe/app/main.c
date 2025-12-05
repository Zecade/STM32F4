#include "main.h"

void LED_Breathe(int duty, uint32_t time)
{
    for(int i = 0; i < time; i++)
    {
        LED_Switch(1, ON);
        LED_Switch(2, ON);
        LED_Switch(3, ON);
        for (uint16_t i = 0; i < duty; i++)
            ;
        LED_Switch(1, OFF);
        LED_Switch(2, OFF);
        LED_Switch(3, OFF);
        for (uint16_t i = duty; i < 100; i++)
            ;
    }
}

int main(void)
{
    LED_Init();
    const uint16_t period = 100;
    while (1)
    {
        for (int16_t duty = 0; duty <= period; duty++)
        {
            LED_Breathe(duty, 5000);
        }

        for (int16_t duty = period; duty >= 0; duty--)
        {
            LED_Breathe(duty, 5000);
        }
    }
}
