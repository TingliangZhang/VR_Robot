/****************************************Copyright(c)*****************************************************
**                            Shenzhen Yuejiang Technology Co., LTD.
**
**                                 http://www.dobot.cc
**
**--------------File Info---------------------------------------------------------------------------------
** File name:           HardFault.c
** Latest modified Date:
** Latest Version:      V1.0.0
** Descriptions:
**
**--------------------------------------------------------------------------------------------------------
** Created by:          Liu Zhufu
** Created date:        2016-05-25
** Version:             V1.0.0
** Descriptions:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/

#include "usart.h"
#include "stm32f10x.h"
#include "stdio.h"
#include "../ComPlatform/Protocol.h"

/*********************************************************************************************************
** Function name:       Uart1Init
** Descriptions:        Uart1 initialize
** Input parameters:    baudrate
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/
void Uart1Init(uint32_t baudrate)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    //NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = baudrate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);

    USART_Cmd(USART1, ENABLE);
    USART_ClearFlag(USART1, USART_FLAG_TC);
    #if 0
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    #endif
}

/*********************************************************************************************************
** Function name:       Uart4Init
** Descriptions:        Uart4 initialize
** Input parameters:    baudrate
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/
void Uart4Init(uint32_t baudrate)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC ,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4 ,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOC,&GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = baudrate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(UART4, &USART_InitStructure);

    USART_Cmd(UART4, ENABLE);
    USART_ClearFlag(UART4, USART_FLAG_TC);
    USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/*********************************************************************************************************
** Function name:       UART4_IRQHandler
** Descriptions:        Interrupt service function
** Input parameters:    none
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/
void UART4_IRQHandler(void)
{
    if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET) {
        uint8_t data = USART_ReceiveData(UART4);
        if (RingBufferIsFull(&gUART4ProtocolHandler.rxRawByteQueue) == false) {
            RingBufferEnqueue(&gUART4ProtocolHandler.rxRawByteQueue, &data);
        }
    } else if (USART_GetITStatus(UART4, USART_IT_TXE) != RESET) {
        if (RingBufferIsEmpty(&gUART4ProtocolHandler.txRawByteQueue) == false) {
            uint8_t data;
            RingBufferDequeue(&gUART4ProtocolHandler.txRawByteQueue, &data);
            USART_SendData(UART4, data);
        } else {
            USART_ITConfig(UART4, USART_IT_TXE, DISABLE);
        }
    }
}

/*********************************************************************************************************
** Function name:       fputc
** Descriptions:        Uart1 output redirection for printf
** Input parameters:    ch
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/
int fputc(int ch, FILE *f)
{
    /* Place your implementation of fputc here */

    /* e.g. write a character to the USART */
    USART_SendData(USART1, (uint8_t) ch);
    //Usart1_putc((uint8_t)ch);

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
    {}

    return ch;
}
