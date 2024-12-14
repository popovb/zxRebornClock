//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_PIN_MODE_HPP_
#define _GRIC_PIN_MODE_HPP_

namespace gric {

     class PinMode {

     public:
	  enum mode_t : u8 {
	       PushPull = 0,
	       Float    = 1,
	       PullUp   = 2,
	       PullDown = 3,
	       Analog   = 4,
	       Alter    = 5,
	  };
     };
}
#endif // _GRIC_PIN_MODE_HPP_
