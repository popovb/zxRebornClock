//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _DS1302_CLOCK_HALT_HPP_
#define _DS1302_CLOCK_HALT_HPP_

namespace ds1302 {

     class ClockHalt {

     public:
	  enum flag_t : u8 {
	       UnSet = 0,
	       Set   = 1,
	  };
     };
}
#endif // _DS1302_CLOCK_HALT_HPP_
