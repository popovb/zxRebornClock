//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/UartName.hpp"

#ifndef _GRIC_USART_HOLDER_HPP_
#define _GRIC_USART_HOLDER_HPP_

namespace gric {

     class UsartHolder {

     public:
	  u32 get(UartName::name_t) const;

     private:
	  static constexpr u8 len = 4;
	  static const u32 usarts[len];
     };
}
#endif // _GRIC_USART_HOLDER_HPP_
