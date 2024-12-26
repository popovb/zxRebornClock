//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Data.hpp"

#ifndef _DS1302_YEAR_HPP_
#define _DS1302_YEAR_HPP_

namespace ds1302 {

     class Year : public Data {

     public:
	  Year();
	  Year(u8);

	  u8 get() const;
     };
}
#endif // _DS1302_YEAR_HPP_
