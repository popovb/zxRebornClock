//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Key.hpp"

gric::Key::Key(const Button& b, press_t v1, long_press_t v2):
     button(b),
     press(v1),
     long_press(v2),
     counter(0)
{
     return;
}

gric::Key::event_t gric::Key::poll(bool v) {
     if (v) return down();
     return up();
}

gric::Key::event_t gric::Key::up() {
     counter = 0;
     return Release;
}

gric::Key::event_t gric::Key::down() {
     ++counter;
     if (counter == press) {
	  counter = 0;
	  return Press;
     }
     return Release;
}
