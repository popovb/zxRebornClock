//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#ifndef _DS1302_DIRECTION_HPP_
#define _DS1302_DIRECTION_HPP_

namespace ds1302 {

     class Direction {

     public:
	  enum dir_t : u8 {
	       Write  = 0,
	       Input  = 0,
	       Read   = 1,
	       Output = 1,
	  };
     };
}
#endif // _DS1302_DIRECTION_HPP_
