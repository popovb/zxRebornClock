//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Tubes.hpp"

gric::Tubes::Tubes(const DisplayTime& v0,
		   const Anodes& v1,
		   const Cathodes& v2):
     time(v0),
     as(v1),
     cs(v2)
{
     return;
}

void gric::Tubes::display(u8 v[4]) const {
     display_1(v[3]);
     display_2(v[2]);
     display_3(v[1]);
     display_4(v[0]);
}

void gric::Tubes::display_1(u8 v) const {
     display_(1, v);
}

void gric::Tubes::display_2(u8 v) const {
     display_(2, v);
}

void gric::Tubes::display_3(u8 v) const {
     display_(3, v);
}

void gric::Tubes::display_4(u8 v) const {
     display_(4, v);
}

void gric::Tubes::display_(u8 n, u8 v) const {
     cs.set(v);
     as.set(n);
     delay.ms(time.display);
     as.clear(n);
     delay.ms(time.pause);
}

gric::u32 gric::Tubes::calc_iters_per_second() const {
     return 1000 / ((time.display + time.pause) * 4);
}
