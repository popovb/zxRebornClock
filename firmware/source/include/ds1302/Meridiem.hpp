//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _DS1302_MERIDIEM_HPP_
#define _DS1302_MERIDIEM_HPP_

namespace ds1302 {

     class Meridiem {

     public:
	  enum type_t : u8 {
	       AM = 0,
	       PM = 1,
	  };
     };
}
#endif // _DS1302_MERIDIEM_HPP_
