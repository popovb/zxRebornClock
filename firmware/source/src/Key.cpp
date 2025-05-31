//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Key.hpp"

gric::Key::Key(const Button& b, press_t v1, long_press_t v2):
     button(b),
     press(v1),
     long_press(v2),
     counter(0),
     repeat(false),
     state(KeyState::Up),
     event(KeyEvent::Undef)
{
     return;
}

gric::KeyEvent::event_t gric::Key::poll(KeyState::state_t v) {
     if (v == KeyState::Down) return down();
     return up();
}

gric::KeyEvent::event_t gric::Key::up() {
     counter = 0;
     repeat = false;
     if (state == KeyState::Down) {
	  state = KeyState::Up;
	  return KeyEvent::Release;
     }
     return KeyEvent::Undef;
}

gric::KeyEvent::event_t gric::Key::down() {
     ++counter;
     state = KeyState::Down;
     if (counter == press) {
	  counter = 0;
	  if (repeat) {
	       return KeyEvent::Repeat;

	  } else {
	       repeat = true;
	       return KeyEvent::Press;
	  }
     }
     return KeyEvent::Undef;
}
