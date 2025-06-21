//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Esp12f.hpp"

gric::Esp12f::Esp12f(Mcu& m, const McuNetConfig& mnc) {
     init_pin(m, mnc);
     init_uart(m);
}

void gric::Esp12f::on() const {
     chip_select.write(true);
}

void gric::Esp12f::off() const {
     chip_select.write(false);
}

void gric::Esp12f::uart_enable() const {
     uart.enable();
}

void gric::Esp12f::uart_disable() const {
     uart.disable();
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
	  wait_sending();
	  ++p;
     }
}

void gric::Esp12f::wait_sending() const {
     while (uart.tx_not_empty()) { ; }
}

bool gric::Esp12f::has_data() const {
     return uart.rx_not_empty();
}

void gric::Esp12f::
receive_one(EspReceiveBuffer& erb) const {
     u8 v = uart.receive();
     erb.put(v);
}
/*
void gric::Esp12f::
receive(EspReceiveBuffer& erb) const {
     erb.clean();
     int count = 0;
     int empty_count = 1600;
     while (true) {
	  if (empty_count == 0) break;
	  if (uart.rx_empty()) {
	       --empty_count;
	       continue;
	  }
	  if (count == (erb.size - 1)) break;
	  u8 v = uart.receive();
	  erb.buffer[count] = v;
	  ++count;
       }
}
*/
