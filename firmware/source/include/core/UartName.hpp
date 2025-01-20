//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_UART_NAME_HPP_
#define _GRIC_UART_NAME_HPP_

namespace gric {

     class UartName {

     public:
	  enum name_t : u8 {
	       Uart1 = 0,
	       Uart2 = 1,
	       Uart3 = 2,
	       Uart4 = 3,
	  };
     };
}
#endif // _GRIC_UART_NAME_HPP_
