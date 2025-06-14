//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Esp12f.hpp"

gric::Esp12f::Esp12f(Mcu& m, const McuNetConfig& mnc) {
     init_pin(m, mnc);
     init_uart(m);
}

void gric::Esp12f::enable() const {
     chip_select.write(true);
     uart.enable();
}

void gric::Esp12f::disable() const {
     uart.disable();
     chip_select.write(false);
}

void gric::Esp12f::
init_pin(const Mcu& m, const McuNetConfig& mnc) {
     const PortPinConf& ppc = mnc.get(McuNet::ESP_EN);
     chip_select = m.get(PortPinConf(ppc.port, ppc.pin));
}

void gric::Esp12f::init_uart(Mcu& m) {
     UartConf uc(UartName::Uart2, 115200);
     m.init(uc);
     uart = m.get(UartName::Uart2);
}

void gric::Esp12f::send(const char* s) const {
     char* p = (char*)s;
     while ((*p) != 0) {
	  uart.send(*p);
	  while (! uart.tx_empty()) { ; }
	  ++p;
     }
}
