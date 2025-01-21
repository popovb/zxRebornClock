//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/UartName.hpp"

#ifndef _GRIC_RCC_USART_HOLDER_HPP_
#define _GRIC_RCC_USART_HOLDER_HPP_

namespace gric {

     class RccUsartHolder {

     public:
	  u32 get(UartName::name_t) const;

     private:
	  static constexpr u8 len = 4;
	  static const u32 rcc[len];
     };
}
#endif // _GRIC_RCC_USART_HOLDER_HPP_
