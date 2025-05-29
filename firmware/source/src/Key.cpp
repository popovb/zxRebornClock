//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Key.hpp"

gric::Key::Key(const Button& b, press_t v1, long_press_t v2):
     button(b),
     press(v1),
     long_press(v2)
{
     return;
}
