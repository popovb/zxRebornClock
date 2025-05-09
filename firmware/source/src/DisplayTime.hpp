//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_DISPLAY_TIME_HPP_
#define _GRIC_DISPLAY_TIME_HPP_

namespace gric {

     class DisplayTime {

	  friend class Tubes;

     public:
	  DisplayTime(ms_t, us_t, u8);

	  u32 iters_per_second() const;
	  ms_t iter_time() const;

     private:
	  const ms_t display;
	  const us_t blank;
	  const ms_t i_time;
	  const u32 iters;
     };
}
#endif // _GRIC_DISPLAY_TIME_HPP_
