//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Data.hpp"

#ifndef _DS1302_DATE_HPP_
#define _DS1302_DATE_HPP_

namespace ds1302 {

     class Date : public Data {

     public:
	  Date();
	  Date(u8);

	  u8 get() const;
     };
}
#endif // _DS1302_DATE_HPP_
