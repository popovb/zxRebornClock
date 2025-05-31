//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Button.hpp"
#include "Gpio.hpp"

gric::Button::Button():
     port(0),
     pin(0)
{
     return;
}

gric::Button::Button(u32 p, u32 i):
     port(p),
     pin(i)
{
     return;
}

gric::Button::operator bool() const {
     Gpio gpio;
     return gpio.read_bit(port, pin);
}
