//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "KeyState.hpp"
#include "KeyEvent.hpp"
#include "core/Button.hpp"

#ifndef _GRIC_KEY_HPP_
#define _GRIC_KEY_HPP_

namespace gric {

     class Key {

     public:
	  using press_t      = u32;
	  using long_press_t = u32;

     public:
	  Key(const Button&, press_t, long_press_t);

	  KeyEvent::event_t poll(KeyState::state_t);
	  KeyEvent::event_t poll();

     private:
	  Button button;
	  press_t press;
	  long_press_t long_press;

     private:
	  u32 counter;
	  bool repeat;

     private:
	  KeyEvent::event_t down();
	  KeyEvent::event_t up();

     private:
	  KeyState::state_t state;
     };
}
#endif // _GRIC_KEY_HPP_
