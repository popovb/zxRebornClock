//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_TIME_HPP_
#define _GRIC_TIME_HPP_

namespace gric {

     class Time {

     public:
	  Time();
	  Time(u8, u8);

	  u8* get() const;
	  operator bool() const;

     private:
	  i8 hour;
	  i8 minute;
     };
}
#endif // _GRIC_TIME_HPP_
