//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Usart.hpp"
#include "UsartHolder.hpp"

#ifdef UNITTEST

void gric::Usart::init(UartName::name_t, u32) const {
     return;
}

#else
#include "ch32x035.h"

void gric::Usart::init(UartName::name_t n, u32 s) const {
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

void gric::Usart::disable(u32 v) const {
     USART_Cmd((USART_TypeDef*)v, DISABLE);
}

void gric::Usart::enable(u32 v) const {
     USART_Cmd((USART_TypeDef*)v, ENABLE);
}

void gric::Usart::send(u32 u, u8 v) const {
     USART_SendData((USART_TypeDef*)u, v);
}

u8 gric::Usart::receive(u32 u) const {
     return USART_ReceiveData((USART_TypeDef*)u);
}
#endif
