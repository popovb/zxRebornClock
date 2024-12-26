//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Data.hpp"
#include "HourMode.hpp"
#include "Meridiem.hpp"

#ifndef _DS1302_HOUR_HPP_
#define _DS1302_HOUR_HPP_

namespace ds1302 {

     class Hour : public Data {

     public:
	  Hour();
	  Hour(u8);

	  u8 get() const;
	  HourMode::mode_t get_hour_mode() const;
	  Meridiem::type_t get_meridiem() const;

     private:
	  u8 get_24() const;
	  u8 get_12() const;
     };
}
#endif // _DS1302_HOUR_HPP_
