//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "KeyEvent.hpp"

#ifndef _GRIC_KEY_BLOCK_EVENT_HPP_
#define _GRIC_KEY_BLOCK_EVENT_HPP_

namespace gric {

     struct KeyBlockEvent {
	  KeyEvent::event_t hour;
	  KeyEvent::event_t minute;
	  KeyEvent::event_t second;
	  KeyEvent::event_t func;
     };
}
#endif // _GRIC_KEY_BLOCK_EVENT_HPP_
