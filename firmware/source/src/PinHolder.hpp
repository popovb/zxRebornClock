//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_PIN_HOLDER_HPP_
#define _GRIC_PIN_HOLDER_HPP_

namespace gric {

     class PinHolder {

     public:
	  u32 get(pin_t) const;

     private:
	  static const u8 len = 24;
	  static const u32 pins[len];
     };
}
#endif // _GRIC_PIN_HOLDER_HPP_
