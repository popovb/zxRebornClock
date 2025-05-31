//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Key.hpp"

gric::Key::Key(const Button& b, press_t v1, long_press_t v2):
     button(b),
     press(v1),
     long_press(v2),
     press_cnt(0),
     long_press_cnt(0),
     repeat(false),
     state(KeyState::Up)
{
     return;
}

gric::KeyEvent::event_t gric::Key::poll(KeyState::state_t v) {
     if (v == KeyState::Down) return down();
     return up();
}

gric::KeyEvent::event_t gric::Key::up() {
     press_cnt = 0;
     long_press_cnt = 0;
     repeat = false;
     if (state == KeyState::Down) {
	  state = KeyState::Up;
	  return KeyEvent::Release;
     }
     return KeyEvent::Undef;
}

gric::KeyEvent::event_t gric::Key::down() {
     ++press_cnt;
     ++long_press_cnt;
     state = KeyState::Down;

     if (long_press_cnt == long_press) {
	  return KeyEvent::LongPress;
     }

     if (press_cnt >= press) {
	  press_cnt = 0;
	  if (repeat) {
	       return KeyEvent::Repeat;

	  } else {
	       repeat = true;
	       return KeyEvent::Press;
	  }
     }
     return KeyEvent::Undef;
}
