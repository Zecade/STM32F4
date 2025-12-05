#include "board.h"

LED_Desc_t LED1 = {
    .GPIO_Pin = GPIO_Pin_0,
    .GPIOx = GPIOB,
    .OFF_BitVal = Bit_SET,
    .ON_BitVal = Bit_RESET
};

LED_Desc_t LED2 = {
    .GPIO_Pin = GPIO_Pin_1,
    .GPIOx = GPIOB,
    .OFF_BitVal = Bit_SET,
    .ON_BitVal = Bit_RESET
};

LED_Desc_t LED3 = {
    .GPIO_Pin = GPIO_Pin_9,
    .GPIOx = GPIOE,
    .OFF_BitVal = Bit_SET,
    .ON_BitVal = Bit_RESET
};

KEY_Desc_t KEY1 = {
    .KEY_PORT = GPIOA,
    .KEY_PIN = GPIO_Pin_0,
    .KEY_EXTI_PORT_SRC = EXTI_PortSourceGPIOA,
    .KEY_EXTI_PIN_SRC = EXTI_PinSource0,
    .KEY_EXTI_Line = EXTI_Line0,
    .KEY_IRQ = EXTI0_IRQn,
    .KEY_Func = NULL
};

KEY_Desc_t KEY2 = {
    .KEY_PORT = GPIOC,
    .KEY_PIN = GPIO_Pin_4,
    .KEY_EXTI_PORT_SRC = EXTI_PortSourceGPIOC,
    .KEY_EXTI_PIN_SRC = EXTI_PinSource4,
    .KEY_EXTI_Line = EXTI_Line4,
    .KEY_IRQ = EXTI4_IRQn,
    .KEY_Func = NULL
};

KEY_Desc_t KEY3 = {
    .KEY_PORT = GPIOC,
    .KEY_PIN = GPIO_Pin_5,
    .KEY_EXTI_PORT_SRC = EXTI_PortSourceGPIOC,
    .KEY_EXTI_PIN_SRC = EXTI_PinSource5,
    .KEY_EXTI_Line = EXTI_Line5,
    .KEY_IRQ = EXTI9_5_IRQn,
    .KEY_Func = NULL
};

void Board_Lowerlevel_Init(void)
{
    // 配置NVIC优先级组（整个系统只需配置一次）
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    
    // 使能GPIO时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    
    // 使能SYSCFG时钟（EXTI需要）
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}

void EXTI0_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line0) == SET)
    {
        Delay_ms(10);
        if(GPIO_ReadInputDataBit(KEY1.KEY_PORT, KEY1.KEY_PIN) == Bit_RESET)
        {
            if(KEY1.KEY_Func != NULL)
            {
                KEY1.KEY_Func(&KEY1);
            }
            while(GPIO_ReadInputDataBit(KEY1.KEY_PORT, KEY1.KEY_PIN) == Bit_RESET);
            Delay_ms(10);
        }

        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

void EXTI4_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line4) == SET)
    {
        Delay_ms(10);
        if(GPIO_ReadInputDataBit(KEY2.KEY_PORT, KEY2.KEY_PIN) == Bit_RESET)
        {
            if(KEY2.KEY_Func != NULL)
            {
                KEY2.KEY_Func(&KEY2);
            }
            while(GPIO_ReadInputDataBit(KEY2.KEY_PORT, KEY2.KEY_PIN) == Bit_RESET);
            Delay_ms(10);
        }

        EXTI_ClearITPendingBit(EXTI_Line4);
    }
}

void EXTI9_5_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line5) == SET)
    {
        Delay_ms(10);
        if(GPIO_ReadInputDataBit(KEY3.KEY_PORT, KEY3.KEY_PIN) == Bit_RESET)
        {
            if(KEY3.KEY_Func != NULL)
            {
                KEY3.KEY_Func(&KEY3);
            }
            while(GPIO_ReadInputDataBit(KEY3.KEY_PORT, KEY3.KEY_PIN) == Bit_RESET);
            Delay_ms(10);
        }

        EXTI_ClearITPendingBit(EXTI_Line5);
    }
}
