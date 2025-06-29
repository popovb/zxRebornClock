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

     private:
	  void init_uart(Mcu&);

     private:
	  Uart uart;
     };
}
#endif // _GRIC_UART_EXCHANGER_HPP_
