//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _DS1302_TARGET_HPP_
#define _DS1302_TARGET_HPP_

namespace ds1302 {

     class Target {

     public:
	  enum target_t : u8 {
	       Clock = 0,
	       Ram   = 1,
	  };
     };
}
#endif // _DS1302_TARGET_HPP_
