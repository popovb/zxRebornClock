//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "KeyBlockReactor.hpp"
#include "Hour.hpp"
#include "Minute.hpp"

gric::KeyBlockReactor::
KeyBlockReactor(LedBlockControl& a, const Rtc& b):
     lbc(a),
     rtc(b)
{
     return;
}

void gric::KeyBlockReactor::
handle(const KeyBlockEvent& kbe, u8 v[4]) const {
     hour(kbe.hour, v[3], v[2]);
     minute(kbe.minute, v[1], v[0]);
     second(kbe.second);
     func(kbe.func);
}

void gric::KeyBlockReactor::hour(KeyEvent::event_t e,
				 u8 v1, u8 v2) const {
     if (e != KeyEvent::Press) return;
     Hour h(v1, v2);
     ++h;
     rtc.set(h);
}

void gric::KeyBlockReactor::minute(KeyEvent::event_t e,
				   u8 v1, u8 v2) const {
     if (e != KeyEvent::Press) return;
     Minute m(v1, v2);
     ++m;
     rtc.set(m);
}

void gric::KeyBlockReactor::second(KeyEvent::event_t e) const {
     if (e != KeyEvent::Press) return;
     rtc.clear_second();
}

void gric::KeyBlockReactor::func(KeyEvent::event_t e) const {
     if (e != KeyEvent::Press) return;
     LedTaskTime ltt(250, 250);
     LedTask t(LedTaskMode::Limit, ltt, 1);
     lbc.set(LedColor::Blue, t);
}
