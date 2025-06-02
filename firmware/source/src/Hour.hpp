//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_HOUR_HPP_
#define _GRIC_HOUR_HPP_

namespace gric {

     class Hour {

     public:
	  Hour(u8, u8);

	  void operator++();

	  u8 get() const;

     private:
	  u8 value;
     };
}
#endif // _GRIC_HOUR_HPP_
