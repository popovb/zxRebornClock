//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Hour.hpp"

gric::Hour::Hour(u8 a, u8 b):
     value((a * 10) + b)
{
     return;
}

void gric::Hour::operator++() {
     ++value;
     if (value > 23) value = 0;
}
