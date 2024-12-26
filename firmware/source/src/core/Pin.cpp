//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Pin.hpp"
#include "Gpio.hpp"

void gric::Pin::write(bool v) const {
     Gpio gpio;
     gpio.write_bit(port, pin, v);
}

bool gric::Pin::read() const {
     Gpio gpio;
     return gpio.read_bit(port, pin);
}

gric::Pin::Pin(u32 p, u32 i):
     port(p),
     pin(i)
{
     return;
}

gric::Pin::Pin():
     port(0),
     pin(0)
{
     return;
}
