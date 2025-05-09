//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Tubes.hpp"

////////////////////////////////////////////////////////////////
#define _TUBES_DISPLAY_TIME   4
#define _TUBES_BLANK_TIME   150
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
gric::Tubes::Tubes(const Anodes& v1, const Cathodes& v2):
     as(v1),
     cs(v2)
{
     return;
}

gric::DisplayTime gric::Tubes::get_times() const {
     return DisplayTime(_TUBES_DISPLAY_TIME,
			_TUBES_BLANK_TIME,
			4);
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
     delayer.ms(_TUBES_DISPLAY_TIME);
     as.clear(n);
     delayer.us(_TUBES_BLANK_TIME);
}
////////////////////////////////////////////////////////////////
