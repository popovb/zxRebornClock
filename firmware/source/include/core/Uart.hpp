//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_UART_HPP_
#define _GRIC_UART_HPP_

namespace gric {

     class Uart {

	  friend class Mcu;

     public:
	  Uart();

     private:
	  u32 usart;

     private:
	  Uart(u32);
     };
}
#endif // _GRIC_UART_HPP_
