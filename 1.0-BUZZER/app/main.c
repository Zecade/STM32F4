#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "Delay.h"
<<<<<<< HEAD:1-LED/app/main.c

=======
#include "BUZZER.h"

void Delay(uint16_t ms)
{
	for(uint16_t i = 0; i < ms ; i++)
	{
		for(uint16_t j = 0; j < ms ; j++);
	}
}
 
>>>>>>> 3c92ade5e0dbee2116cb2c2f5dca0be960131d1d:1.0-BUZZER/app/main.c
int main(void)
{
    LED_Init();

    while (1)
    {

    }
}
