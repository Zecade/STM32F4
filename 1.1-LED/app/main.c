#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "LED.h"
#include "Delay.h"

// LED1     PB0
// LED2     PB1
// LED3     PE9
#define LED1_PORT       GPIOB
#define LED2_PORT       GPIOB
#define LED3_PORT       GPIOE
#define LED1_PIN        GPIO_Pin_0
#define LED2_PIN        GPIO_Pin_1
#define LED3_PIN        GPIO_Pin_9

void CPU_Delay(void)
{
    uint32_t Delay = 16800000;
    for(uint32_t t = 0; t < Delay; t++);
}

int main(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    /* Configure PG6 and PG8 in output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = LED1_PIN | LED2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED3_PIN;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_SetBits(LED2_PORT, LED2_PIN);
    GPIO_SetBits(LED3_PORT, LED3_PIN);

    while (1)
    {
        GPIO_SetBits(LED1_PORT, LED1_PIN);
		GPIO_SetBits(LED2_PORT, LED2_PIN);
		GPIO_SetBits(LED3_PORT, LED3_PIN);
        CPU_Delay();
        GPIO_ResetBits(LED1_PORT, LED1_PIN);
		GPIO_ResetBits(LED2_PORT, LED2_PIN);
		GPIO_ResetBits(LED3_PORT, LED3_PIN);
        CPU_Delay();
    }
}
