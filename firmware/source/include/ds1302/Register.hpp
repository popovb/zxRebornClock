//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _DS1302_REGISTER_HPP_
#define _DS1302_REGISTER_HPP_

namespace ds1302 {

     class Register {

     public:
	  enum reg_t : u8 {
	       Seconds       = 0x00,
	       Minutes       = 0x02,
	       Hour          = 0x04,
	       Date          = 0x06,
	       Month         = 0x08,
	       Day           = 0x0A,
	       Year          = 0x0C,
	       WriteProtect  = 0x0E,
	       TrickleCharge = 0x10,
	  };
     };
}
#endif // _DS1302_REGISTER_HPP_
