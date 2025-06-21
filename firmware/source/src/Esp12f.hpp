//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "EspReceiveBuffer.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_ESP_12_F_HPP_
#define _GRIC_ESP_12_F_HPP_

namespace gric {

     class Esp12f {

     public:
	  Esp12f(Mcu&, const McuNetConfig&);

	  void uart_enable() const;
	  void uart_disable() const;

	  void on() const;
	  void off() const;

	  void send(const char*) const;
	  void receive(EspReceiveBuffer&) const;
	  void receive_byte(EspReceiveBuffer&) const;

	  bool has_data() const;

     private:
	  void init_pin(const Mcu&, const McuNetConfig&);
	  void init_uart(Mcu&);
	  void wait_sending() const;

     private:
	  Pin chip_select;
	  Uart uart;
     };
}
#endif // _GRIC_ESP_12_F_HPP_
