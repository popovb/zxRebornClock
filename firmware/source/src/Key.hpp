//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Button.hpp"

#ifndef _GRIC_KEY_HPP_
#define _GRIC_KEY_HPP_

namespace gric {

     class Key {

     public:
	  enum event_t : u8 {
	       Release   = 0,
	       Press     = 1,
	       LongPress = 2,
	       Repeat    = 3,
	  };

     public:
	  using press_t      = u32;
	  using long_press_t = u32;

     public:
	  Key(const Button&, press_t, long_press_t);

	  event_t poll(bool);
	  event_t poll();

     private:
	  Button button;
	  press_t press;
	  long_press_t long_press;
     };
}
#endif // _GRIC_KEY_HPP_
