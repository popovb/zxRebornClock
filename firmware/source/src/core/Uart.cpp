//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Uart.hpp"
#include "UsartHolder.hpp"
#include "ch32x035.h"

void gric::Uart::init(UartName::name_t n, u32 s) const {
     UsartHolder uh;
     USART_InitTypeDef u;
     u.USART_BaudRate = s;
     u.USART_WordLength = USART_WordLength_8b;
     u.USART_StopBits = USART_StopBits_1;
     u.USART_Parity = USART_Parity_No;
     u.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
     u.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
     USART_Init((USART_TypeDef*)(uh.get(n)), &u);
}
/*
 * USART_InitTypeDef USART_InitStructure = {0};
 * USART_InitStructure.USART_BaudRate = 115200;
 * USART_InitStructure.USART_WordLength = USART_WordLength_8b;
 * USART_InitStructure.USART_StopBits = USART_StopBits_1;
 * USART_InitStructure.USART_Parity = USART_Parity_No;
 * USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
 * USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

 * USART_Init(USART2, &USART_InitStructure);
    USART_Cmd(USART2, ENABLE);

#define USART2_BASE                             (APB1PERIPH_BASE + 0x4400)
#define USART3_BASE                             (APB1PERIPH_BASE + 0x4800)
#define USART4_BASE                             (APB1PERIPH_BASE + 0x4C00)
#define USART1_BASE                             (APB2PERIPH_BASE + 0x3800)
#define USART2                                  ((USART_TypeDef *)USART2_BASE)
#define USART3                                  ((USART_TypeDef *)USART3_BASE)
#define USART4                                  ((USART_TypeDef *)USART4_BASE)
#define USART1                                  ((USART_TypeDef *)USART1_BASE)
 */
