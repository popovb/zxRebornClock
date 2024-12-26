//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Data.hpp"

#ifndef _DS1302_MINUTES_HPP_
#define _DS1302_MINUTES_HPP_

namespace ds1302 {

     class Minutes : public Data {

     public:
	  Minutes();
	  Minutes(u8);

	  u8 get() const;
     };
}
#endif // _DS1302_MINUTES_HPP_
