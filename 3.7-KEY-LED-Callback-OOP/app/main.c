#include "main.h"

void KEY_PressHandler(KEY_Desc_t* KEY)
{
    if(KEY == &KEY1)
    {
        LED_Toggle(&LED1);
    }
    else if(KEY == &KEY2)
    {
        LED_Toggle(&LED2);
    }
    else if(KEY == &KEY3)
    {
        LED_Toggle(&LED3);
    }
}

int main(void)
{
    Board_Lowerlevel_Init();
    LED_Init(&LED1);
    LED_Init(&LED2);
    LED_Init(&LED3);

    KEY_Init(&KEY1);
    KEY_Init(&KEY2);
    KEY_Init(&KEY3);

    KEY_Press_Callback_Register(&KEY1, KEY_PressHandler);
    KEY_Press_Callback_Register(&KEY2, KEY_PressHandler);
    KEY_Press_Callback_Register(&KEY3, KEY_PressHandler);

    while (1)
    {
        ;
    }
}
