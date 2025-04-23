//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Led.hpp"
#include "Gpio.hpp"

void gric::Led::toggle() {
     if (emit)
	  off();
     else
	  on();
}

void gric::Led::on() {
     Gpio gpio;
     gpio.write_bit(port, pin, false);
     emit = true;
}

void gric::Led::off() {
     Gpio gpio;
     gpio.write_bit(port, pin, true);
     emit = false;
}

gric::Led::Led(u32 p, u32 i):
     port(p),
     pin(i)
{
     return;
}

gric::Led::operator bool() const {
     return emit;
}
