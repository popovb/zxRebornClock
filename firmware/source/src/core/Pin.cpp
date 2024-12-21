//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Pin.hpp"
#include "Gpio.hpp"

void gric::Pin::write(bool v) const {
     Gpio gpio;
     gpio.write_bit(port, pin, v);
}

gric::Pin::Pin(u32 p, u32 i):
     port(p),
     pin(i)
{
     return;
}
