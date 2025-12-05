#include "main.h"

static void board_lowerlevel_init(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
}

static void USART1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 配置GPIO复用功能为USART1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);   // PA9: USART1_TX
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);  // PA10: USART1_RX

    USART_InitTypeDef USART_InitStruct;
    USART_StructInit(&USART_InitStruct);
    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART_InitStruct);

    USART_Cmd(USART1, ENABLE);

}

//static void USART1_SendByte(const char Bytes[])
//{
//    int len = strlen(Bytes);
//    for(int i = 0; i < len; i++)
//    {
//        USART_ClearFlag(USART1, USART_FLAG_TC);
//        USART_SendData(USART1, Bytes[i]);
//        while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
//    }
//}

int main(void)
{
    board_lowerlevel_init();
    USART1_Init();
    // USART1_SendByte("Hello World!\r\n");
    // printf("Hello World!\r\n");

    while (1)
    {
        USART_ClearFlag(USART1, USART_FLAG_RXNE);
        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
        uint8_t c = (uint8_t)USART_ReceiveData(USART1);
        printf("c = %c, ASCII: %d\r\n", c, c);
    }
}


int fputc(int c, FILE *stream)
{
    (void)stream;

    USART_ClearFlag(USART1, USART_FLAG_TC);
    USART_SendData(USART1, c);
    while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);

    return c;
}
