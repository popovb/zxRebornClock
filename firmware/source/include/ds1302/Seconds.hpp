//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Data.hpp"
#include "ClockHalt.hpp"

#ifndef _DS1302_SECONDS_HPP_
#define _DS1302_SECONDS_HPP_

namespace ds1302 {

     class Seconds : public Data {

     public:
	  Seconds();
	  Seconds(ClockHalt::flag_t);
	  Seconds(u8);

	  u8 get() const;
	  ClockHalt::flag_t get_flag() const;
     };
}
#endif // _DS1302_SECONDS_HPP_
