#include "KEY.h"

// KEY_t KEY1 = {GPIOA, GPIO_Pin_0};
// KEY_t KEY2 = {GPIOC, GPIO_Pin_4};
// KEY_t KEY3 = {GPIOC, GPIO_Pin_5};

static KEY_LED_t func1, func2, func3;
static KEY_Serial_t func4;

void KEY_Init()
{

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);


    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_InitStruct.GPIO_Pin = KEY1_PIN;
    GPIO_Init(KEY1_PORT, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = KEY2_PIN;
    GPIO_Init(KEY2_PORT, &GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = KEY3_PIN;
    GPIO_Init(KEY3_PORT, &GPIO_InitStruct);

    SYSCFG_EXTILineConfig(KEY1_EXTI_PortSource, KEY1_EXTI_PinSource);
    SYSCFG_EXTILineConfig(KEY2_EXTI_PortSource, KEY2_EXTI_PinSource);
    SYSCFG_EXTILineConfig(KEY3_EXTI_PortSource, KEY3_EXTI_PinSource);

    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_StructInit(&EXTI_InitStruct);
    EXTI_InitStruct.EXTI_Line = EXTI_Line0 | EXTI_Line4 | EXTI_Line5;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStruct);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

    NVIC_InitTypeDef NVIC_InitStruct;
    memset(&NVIC_InitStruct, 0, sizeof(NVIC_InitStruct));
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 4;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;

    NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_Init(&NVIC_InitStruct);

    NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_Init(&NVIC_InitStruct);

    NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_Init(&NVIC_InitStruct);
}

void KEY_LED_PressedCallback(uint8_t KEY_Index, KEY_LED_t func)
{
    switch (KEY_Index)
    {
        case 1: func1 = func; break;
        case 2: func2 = func; break;
        case 3: func3 = func; break;
        default: break;
    }
}

void KEY_Serial_PressedCallback(KEY_Serial_t func)
{
    func4 = func;
}

void EXTI0_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line0) == SET)
    {
		if(func1 != NULL)
		{
			func1();
		}

       if(func4 != NULL)
       {
           func4("KEY1 Pressed!\n");
       }
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

void EXTI4_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line4) == SET)
    {
        if(func2 != NULL)
        {
            func2();
        }
        EXTI_ClearITPendingBit(EXTI_Line4);
    }
}

void EXTI9_5_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line5) == SET)
    {
        if(func3 != NULL)
        {
            func3();
        }
        EXTI_ClearITPendingBit(EXTI_Line5);
    }

}
