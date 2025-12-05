#include "main.h"

int main(void)
{
    LED_Init(&LED1);
    LED_Init(&LED2);
    LED_Init(&LED3);

    LED_ALL_OFF();

    USART1_Init();
    KEY_Init();

    KEY_Serial_PressedCallback(USART_Write);
	KEY_LED_PressedCallback(1, LED1_Toggle);
    KEY_LED_PressedCallback(2, LED2_Toggle);
    KEY_LED_PressedCallback(3, LED3_Toggle);

    while (1)
    {
        ;
    }
}
