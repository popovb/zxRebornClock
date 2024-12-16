//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Led.hpp"
#include "Gpio.hpp"

void gric::Led::toggle() {
     if (emit) {
	  off();
	  emit = false;

     } else {
	  on();
	  emit = true;
     }
}

void gric::Led::on() {
     Gpio gpio;
     gpio.write_bit(port, pin, false);
     emit = true;
}
