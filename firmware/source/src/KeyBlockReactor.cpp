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
