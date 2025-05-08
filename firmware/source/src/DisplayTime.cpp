//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "DisplayTime.hpp"

gric::DisplayTime::DisplayTime(us_t d, us_t p, u8 v):
     display(d),
     blank(p),
     i_time((d + p) * v),
     iters(1'000'000 / i_time)
{
     return;
}

gric::ms_t gric::DisplayTime::iter_time() const {
     return i_time / 1000;
}

gric::u32 gric::DisplayTime::iters_per_second() const {
     return iters;
}
