//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Tubes.hpp"

volatile static int tt = 4000;
volatile static int ttt = 150;

gric::Tubes::Tubes(DisplayTime& v0,
		   const Anodes& v1,
		   const Cathodes& v2):
     time(v0),
     as(v1),
     cs(v2)
     //tt(v0.display)
{
     //tt = v0.display;
     return;
}

void gric::Tubes::display(u8 v[4]) {
     display_1(v[3]);
     display_2(v[1]);
     display_3(v[2]);
     display_4(v[0]);
}

void gric::Tubes::display_1(u8 v) {
     display_(1, v);
}

void gric::Tubes::display_2(u8 v) {
     display_(2, v);
}

void gric::Tubes::display_3(u8 v) {
     display_(3, v);
}

void gric::Tubes::display_4(u8 v) {
     display_(4, v);
}

void gric::Tubes::display_(u8 n, u8 v) {
     cs.set(v);
     as.set(n);
     //delay.us(time.display);
     //delay.us(4000);
     display_delay();
     as.clear(n);
     //delay.us(time.blank);
     blank_delay();
     //delay.us(150);
}

void gric::Tubes::display_delay() {
     delay.us(tt);
}

void gric::Tubes::blank_delay() {
     delay.us(ttt);
}

