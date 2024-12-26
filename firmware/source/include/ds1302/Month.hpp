//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Data.hpp"

#ifndef _DS1302_MONTH_HPP_
#define _DS1302_MONTH_HPP_

namespace ds1302 {

     class Month : public Data {

     public:
	  Month();
	  Month(u8);

	  u8 get() const;
     };
}
#endif // _DS1302_MONTH_HPP_
