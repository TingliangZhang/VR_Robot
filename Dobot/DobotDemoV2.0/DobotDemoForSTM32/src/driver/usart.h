#ifndef __USART_H
#define __USART_H

#define TXBUF_SIZE        256
#define RXBUF_SIZE      512
#define INC_MOD(x,s)    (((x)+1) & ((s)-1))

#define cli()     NVIC_DisableIRQ(USART1_IRQn)
#define sei()    NVIC_EnableIRQ(USART1_IRQn)


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void Uart1Init(uint32_t baudrate);
void Uart4Init(uint32_t baudrate);

#ifdef __cplusplus
}
#endif

#endif
