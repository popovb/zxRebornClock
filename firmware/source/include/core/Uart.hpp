//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_UART_HPP_
#define _GRIC_UART_HPP_

namespace gric {

     class Uart {

	  friend class Mcu;

     public:
	  Uart();

	  void enable() const;
	  void disable() const;

	  void send(u8) const;
	  u8 receive() const;

     private:
	  u32 usart;

     private:
	  Uart(u32);
     };
}
#endif // _GRIC_UART_HPP_
