//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_KEY_EVENT_HPP_
#define _GRIC_KEY_EVENT_HPP_

namespace gric {

     class KeyEvent {

     public:
	  enum event_t : u8 {
	       Undef     = 0,
	       Release   = 1,
	       Press     = 2,
	       LongPress = 3,
	       Repeat    = 4,
	  };
     };
}
#endif // _GRIC_KEY_EVENT_HPP_
