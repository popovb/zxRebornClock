//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/UartName.hpp"

#ifndef _GRIC_UART_HPP_
#define _GRIC_UART_HPP_

namespace gric {

     class Uart {

     public:
	  void init(UartName::name_t, u32) const;
     };
}
#endif // _GRIC_UART_HPP_
