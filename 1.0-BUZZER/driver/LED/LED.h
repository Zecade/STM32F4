#ifndef __LED_H__
#define __LED_H__

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdbool.h>

#define ON      true
#define OFF     false

typedef struct{
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;
}led_t;

void LED_Init(void);
void LED_Switch(led_t led, bool Switch);
void LED1_Switch(bool Switch);
void LED2_Switch(bool Switch);
void LED3_Switch(bool Switch);

#endif /* __LED_H__ */
