//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "KeyBlockReactor.hpp"

gric::KeyBlockReactor::
KeyBlockReactor(LedBlockControl& a, const Rtc& b):
     lbc(a),
     rtc(b)
{
     return;
}

void gric::KeyBlockReactor::
handle(const KeyBlockEvent& kbe) const {
     hour(kbe.hour);
     minute(kbe.minute);
     second(kbe.second);
     func(kbe.func);
}

void gric::KeyBlockReactor::hour(KeyEvent::event_t e) const {
     if (e != KeyEvent::Press) return;
     LedTaskTime ltt(250, 250);
     LedTask t(LedTaskMode::Limit, ltt, 1);
     lbc.set(LedColor::Red, t);
}

void gric::KeyBlockReactor::minute(KeyEvent::event_t e) const {
     if (e != KeyEvent::Press) return;
     LedTaskTime ltt(250, 250);
     LedTask t(LedTaskMode::Limit, ltt, 1);
     lbc.set(LedColor::Yellow, t);
}
