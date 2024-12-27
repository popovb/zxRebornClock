//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_TIME_HPP_
#define _GRIC_TIME_HPP_

namespace gric {

     struct Time {
	  Time();

	  i8 hour;
	  i8 minute;

	  u8* get() const;
	  operator bool() const;
     };
}
#endif // _GRIC_TIME_HPP_
