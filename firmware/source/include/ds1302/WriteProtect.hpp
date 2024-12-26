//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Data.hpp"

#ifndef _DS1302_WRITE_PROTECT_HPP_
#define _DS1302_WRITE_PROTECT_HPP_

namespace ds1302 {

     class WriteProtect : public Data {

     public:
	  enum bit_t : u8 {
	       UnSet = 0,
	       Set   = 1,
	  };

     public:
	  WriteProtect();

	  u8 get() const;

	  void set();
	  void reset();
     };
}
#endif // _DS1302_WRITE_PROTECT_HPP_
