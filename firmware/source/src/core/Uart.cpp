//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Uart.hpp"
#include "Usart.hpp"

gric::Uart::Uart(u32 i):
     usart(i)
{
     return;
}

gric::Uart::Uart():
     usart(0)
{
     return;
}

void gric::Uart::disable() const {
     Usart u;
     u.disable(usart);
}

void gric::Uart::enable() const {
     Usart u;
     u.enable(usart);
}

void gric::Uart::send(u8 v) const {
     Usart u;
     u.send(usart, v);
}

gric::u8 gric::Uart::receive() const {
     Usart u;
     return u.receive(usart);
}
