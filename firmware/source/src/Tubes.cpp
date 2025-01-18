//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Tubes.hpp"

gric::Tubes::Tubes(const Anodes& v1, const Cathodes& v2):
     as(v1),
     cs(v2)
{
     return;
}

void gric::Tubes::display(u8 v[4]) const {
     display_1(v);
     display_2(v);
     display_3(v);
     display_4(v);
}

void gric::Tubes::display_1(u8 v[4]) const {
     cs.set(v[3]);
     as.set(1);
     delay.ms(display_time);
     as.clear(1);
     delay.ms(pause_time);
}

void gric::Tubes::display_2(u8 v[4]) const {
     cs.set(v[2]);
     as.set(2);
     delay.ms(display_time);
     as.clear(2);
     delay.ms(pause_time);
}

void gric::Tubes::display_3(u8 v[4]) const {
     cs.set(v[1]);
     as.set(3);
     delay.ms(display_time);
     as.clear(3);
     delay.ms(pause_time);
}

void gric::Tubes::display_4(u8 v[4]) const {
     cs.set(v[0]);
     as.set(4);
     delay.ms(display_time);
     as.clear(4);
     delay.ms(pause_time);
}
