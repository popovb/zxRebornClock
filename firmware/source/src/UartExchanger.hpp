//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Mcu.hpp"

#ifndef _GRIC_UART_EXCHANGER_HPP_
#define _GRIC_UART_EXCHANGER_HPP_

namespace gric {

     class UartExchanger {

     public:
	  UartExchanger(Mcu&);

	  void enable() const;
	  void disable() const;
	  void write(const char*) const;
	  void write_buffer() const;
	  void read();
	  void reset();

     private:
	  void init_uart(Mcu&);
	  void wait_sending() const;

     private:
	  Uart uart;

     private:
	  static constexpr u8 len = 128;
	  char buffer[len];
	  u8 ndx;
     };
}
#endif // _GRIC_UART_EXCHANGER_HPP_
