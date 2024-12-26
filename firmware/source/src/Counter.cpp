//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Counter.hpp"

gric::Counter::Counter():
     count(0)
{
     return;
}

gric::Counter::Counter(u16 v):
     count(v)
{
     return;
}

gric::u16 gric::Counter::get() const {
     return count;
}

void gric::Counter::tick() {
     ++count;
     if (count == max) count = 0;
}
