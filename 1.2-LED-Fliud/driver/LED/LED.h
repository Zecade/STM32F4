#ifndef __LED_H__
#define __LED_H__

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdbool.h>

// LED1     PB0
// LED2     PB1
// LED3     PE9
#define LED1_PORT       GPIOB
#define LED2_PORT       GPIOB
#define LED3_PORT       GPIOE
#define LED1_PIN        GPIO_Pin_0
#define LED2_PIN        GPIO_Pin_1
#define LED3_PIN        GPIO_Pin_9

typedef struct{
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;
}led_t;

void LED_Init(void);
void LED_Switch(uint8_t index, bool Switch);
void LED_ON(uint8_t index);
void LED_OFF(uint8_t index);
void LED_ALL_OFF(void);

#endif /* __LED_H__ */
