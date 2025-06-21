//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "SecondsCounter.hpp"

gric::SecondsCounter::SecondsCounter(u16 v):
     max(v)
{
     reset();
}

void gric::SecondsCounter::reset() {
     curr = 0;
}

void gric::SecondsCounter::operator++() {
     ++curr;
}
