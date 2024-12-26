//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_COUNTER_HPP_
#define _GRIC_COUNTER_HPP_

namespace gric {

     class Counter {

     public:
	  Counter();
	  Counter(u16);

	  void tick();
	  u16 get() const;

     private:
	  u16 count;

     private:
	  static const u16 max = 10000;
     };
}
#endif // _GRIC_COUNTER_HPP_
