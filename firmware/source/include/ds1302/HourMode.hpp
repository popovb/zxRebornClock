//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _DS1302_HOUR_MODE_HPP_
#define _DS1302_HOUR_MODE_HPP_

namespace ds1302 {

     class HourMode {

     public:
	  enum mode_t : u8 {
	       H24 = 0,
	       H12 = 1,
	  };
     };
}
#endif // _DS1302_HOUR_MODE_HPP_
