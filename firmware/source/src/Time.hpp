//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_TIME_HPP_
#define _GRIC_TIME_HPP_

namespace gric {

     struct Time {
	  u8 hour;
	  u8 minute;

	  u8* get() const;
     };
}
#endif // _GRIC_TIME_HPP_
