#include "main.h"

int main(void)
{
    Board_LowerLevel_Init();
    while (1)
    {
//        LED_Toggle(&LED1);
//        LED_Toggle(&LED2);
//        LED_Toggle(&LED3);
		
	LED_ON(&LED1);
    LED_ON(&LED2);
    LED_ON(&LED3);

        Delay_ms(500);
    }
}
