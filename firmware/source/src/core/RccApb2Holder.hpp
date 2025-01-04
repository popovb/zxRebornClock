//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/PortName.hpp"

#ifndef _GRIC_RCC_APB2_HOLDER_HPP_
#define _GRIC_RCC_APB2_HOLDER_HPP_

namespace gric {

     class RccApb2Holder {

     public:
	  u32 get(PortName::name_t) const;

     private:
	  static constexpr u8 len = 3;
	  static const u32 rcc_apb2[len];
     };
}
#endif // _GRIC_RCC_APB2_HOLDER_HPP_
