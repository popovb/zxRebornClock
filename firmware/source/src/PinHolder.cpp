//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PinHolder.hpp"

gric::u32 gric::PinHolder::get(pin_t v) const {
     if (v >= len) v = len - 1;
     return pins[v];
}
