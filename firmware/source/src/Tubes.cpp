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
     delay.ms(display_time_ms);
     blank();
     delay.us(blank_time_us);

     display_2(v);
     delay.ms(display_time_ms);
     blank();
     delay.us(blank_time_us);

     display_3(v);
     delay.ms(display_time_ms);
     blank();
     delay.us(blank_time_us);

     display_4(v);
     delay.ms(display_time_ms);
     blank();
     delay.us(blank_time_us);
}

void gric::Tubes::blank() const {
     as.clear();
     cs.clear();
}

void gric::Tubes::display_1(u8 v[4]) const {
     cs.set(v[3]);
     as.set(1);
}

void gric::Tubes::display_2(u8 v[4]) const {
     cs.set(v[2]);
     as.set(2);
}

void gric::Tubes::display_3(u8 v[4]) const {
     cs.set(v[1]);
     as.set(3);
}

void gric::Tubes::display_4(u8 v[4]) const {
     cs.set(v[0]);
     as.set(4);
}
