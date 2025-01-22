//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/UartName.hpp"

#ifndef _GRIC_USART_HPP_
#define _GRIC_USART_HPP_

namespace gric {

     class Usart {

     public:
	  void init(UartName::name_t, u32) const;

	  void disable(u32) const;
	  void enable(u32) const;

	  void send(u32, u8) const;
	  u8 receive(u32) const;
     };
}
#endif // _GRIC_USART_HPP_
