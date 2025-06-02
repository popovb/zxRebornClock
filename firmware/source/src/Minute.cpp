//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Minute.hpp"

gric::Minute::Minute(u8 a, u8 b):
     value((a * 10) + b)
{
     return;
}

void gric::Minute::operator++() {
     ++value;
     if (value > 59) value = 0;
}

gric::u8 gric::Minute::get() const {
     return value;
}
