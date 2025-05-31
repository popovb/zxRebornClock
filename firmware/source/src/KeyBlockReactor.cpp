//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "KeyBlockReactor.hpp"

gric::KeyBlockReactor::
KeyBlockReactor(const LedBlockControl& a, const Rtc& b):
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
