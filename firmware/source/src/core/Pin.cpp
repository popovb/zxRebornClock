//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Pin.hpp"
#include "Gpio.hpp"
/*
void gric::Pin::toggle() {
     if (emit)
	  off();
     else
	  on();
}

void gric::Pin::on() {
     Gpio gpio;
     gpio.write_bit(port, pin, false);
     emit = true;
}

void gric::Pin::off() {
     Gpio gpio;
     gpio.write_bit(port, pin, true);
     emit = false;
}
*/
gric::Pin::Pin(u32 p, u32 i):
     port(p),
     pin(i)
{
     return;
}
