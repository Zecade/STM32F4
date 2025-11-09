#include "main.h"

int main(void)
{
    LED_Init();
    while (1)
    {
        LED_Switch(1, true);
        LED_Switch(2, true);
        LED_Switch(3, true);
        Delay_ms(1000);
        LED_Switch(1, 0);
        LED_Switch(2, 0);
        LED_Switch(3, 0);
        Delay_ms(1000);
    }
}
