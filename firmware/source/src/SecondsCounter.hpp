//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_SECONDS_COUNTER_HPP_
#define _GRIC_SECONDS_COUNTER_HPP_

namespace gric {

     class SecondsCounter {

     public:
	  SecondsCounter(u16);

	  void operator++();
	  operator bool() const;
	  void reset();

     private:
	  const u16 max;
	  u16 curr;
     };
}
#endif // _GRIC_SECONDS_COUNTER_HPP_
