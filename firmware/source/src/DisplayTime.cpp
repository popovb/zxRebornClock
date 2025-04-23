//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "DisplayTime.hpp"

gric::DisplayTime::DisplayTime(ms_t d, ms_t p, u8 v):
     display(d),
     pause(p),
     n_lamps(v),
     i_time((display + pause) * n_lamps),
     iters(1000 / i_time)
{
     return;
}

gric::u32 gric::DisplayTime::iter_time() const {
     return i_time;
}

gric::u32 gric::DisplayTime::iters_per_second() const {
     return iters;
}
