//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "UartExchanger.hpp"

gric::UartExchanger::UartExchanger(Mcu& v) {
     init_uart(v);
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
