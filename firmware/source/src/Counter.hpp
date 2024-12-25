//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRI_COUNTER_HPP_
#define _GRI_COUNTER_HPP_

namespace gri {

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
#endif // _GRI_COUNTER_HPP_
