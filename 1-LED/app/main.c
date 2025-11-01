#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "LED.h"
#include "Delay.h"
#include "BUZZER.h"

void Delay(uint16_t ms)
{
	for(uint16_t i = 0; i < ms ; i++)
	{
		for(uint16_t j = 0; j < ms ; j++);
	}
}

int main(void)
{
    LED_Init();

    while (1)
    {
        LED1_Switch(ON);
        LED2_Switch(ON);
        LED3_Switch(ON);
        Delay_ms(500);
        LED1_Switch(OFF);
        LED2_Switch(OFF);
        LED3_Switch(OFF);
        Delay_ms(500);
    }
}
