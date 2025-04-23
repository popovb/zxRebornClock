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
	  DisplayTime(ms_t, ms_t, u8);

	  u32 calc_iters_per_second() const;

     private:
	  ms_t display;
	  ms_t pause;
	  u8 n_lamps;
     };
}
#endif // _GRIC_DISPLAY_TIME_HPP_
