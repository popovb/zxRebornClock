//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Uart.hpp"

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
