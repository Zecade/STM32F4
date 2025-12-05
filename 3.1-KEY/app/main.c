#include "main.h"

int main(void)
{
    Board_LowerLevel_Init();

    LED_OFF(&LED1);
    LED_OFF(&LED2);
    LED_OFF(&LED3);

    while (1)
    {
        if(KEY_Scan(&KEY1))
        {
            // LED_Toggle(&LED1);
            printf("KEY1 pressed!\n");
        }

        if(KEY_Scan(&KEY2))
        {
            // LED_Toggle(&LED2);
            printf("KEY2 pressed!\n");
        }

        if(KEY_Scan(&KEY3))
        {
            // LED_Toggle(&LED3);
            printf("KEY3 pressed!\n");
        }
    }
}
