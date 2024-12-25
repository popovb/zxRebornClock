//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Counter.hpp"

gri::Counter::Counter():
     count(0)
{
     return;
}

gri::Counter::Counter(u16 v):
     count(v)
{
     return;
}

gri::u16 gri::Counter::get() const {
     return count;
}

void gri::Counter::tick() {
     ++count;
     if (count == max) count = 0;
}
