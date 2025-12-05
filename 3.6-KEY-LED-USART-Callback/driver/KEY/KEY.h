#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f4xx.h"
#include <stdbool.h>
#include <string.h>

#define KEY1_PORT                   GPIOA
#define KEY1_PIN                    GPIO_Pin_0
#define KEY1_EXTI_PortSource        EXTI_PortSourceGPIOA
#define KEY1_EXTI_PinSource         EXTI_PinSource0

#define KEY2_PORT                   GPIOC
#define KEY2_PIN                    GPIO_Pin_4
#define KEY2_EXTI_PortSource        EXTI_PortSourceGPIOC
#define KEY2_EXTI_PinSource         EXTI_PinSource4

#define KEY3_PORT                   GPIOC
#define KEY3_PIN                    GPIO_Pin_5
#define KEY3_EXTI_PortSource        EXTI_PortSourceGPIOC
#define KEY3_EXTI_PinSource         EXTI_PinSource5

typedef void (*KEY_LED_t)(void);
typedef void (*KEY_Serial_t)(const char* str);


void KEY_Init(void);
void KEY_LED_PressedCallback(uint8_t KEY_Index, KEY_LED_t func);
void KEY_Serial_PressedCallback(KEY_Serial_t func);

#endif /* __KEY_H__ */
