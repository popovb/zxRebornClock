//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "UartExchanger.hpp"

gric::UartExchanger::UartExchanger(Mcu& v):
     buffer{ '\0', },
     ndx(0)
{
     init_uart(v);
}

void gric::UartExchanger::reset() {
     ndx = 0;
     for (u8 i = 0; i < len; i++) buffer[i] = '\0';
}

void gric::UartExchanger::init_uart(Mcu& m) {
     UartConf uc(UartName::Uart1, 115200);
     m.init(uc);
     uart = m.get(UartName::Uart1);
}

void gric::UartExchanger::enable() const {
     uart.enable();
}

void gric::UartExchanger::disable() const {
     uart.disable();
}

void gric::UartExchanger::write(const char* s) const {
     char* p = (char*)s;
     while ((*p) != 0) {
	  uart.send(*p);
	  wait_sending();
	  ++p;
     }
}

void gric::UartExchanger::wait_sending() const {
     while (uart.tx_not_empty()) { ; }
}

void gric::UartExchanger::write_buffer() const {
     write(buffer);
}

void gric::UartExchanger::read() {
     while (true) {
	  if (uart.rx_not_empty()) {
	       u8 c = uart.receive();
	       if (c == '\r') return;
	       if (c == '\n') return;
	       if (c == 0x00) continue;
	       if (c < 0x21) continue;
	       if (c > 0x7E) continue;
	       buffer[ndx] = c;
	       ++ndx;
	       if (ndx == len - 2) return;
	  }
     }
}

const char* gric::UartExchanger::get() const {
     return buffer;
}
