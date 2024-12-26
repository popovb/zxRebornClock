//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _DS1302_DATA_HPP_
#define _DS1302_DATA_HPP_

namespace ds1302 {

     class Data {

     public:
	  Data();
	  Data(u8);

	  u8 get_byte() const;
	  void set_byte(u8);

	  virtual u8 get() const = 0;

     protected:
	  u8 data;

     protected:
	  u8 to_bcd(u8) const;
	  u8 from_bcd(u8, u8) const;
     };
}
#endif // _DS1302_DATA_HPP_
