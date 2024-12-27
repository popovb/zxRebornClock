//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "TimeChecker.hpp"

gric::TimeChecker::operator bool() const {
     if (! prev) return false;
     if (! curr) return false;
     //
     // TODO
     //
     return true;
}

void gric::TimeChecker::put(const Time& v) {
     prev = curr;
     curr = v;
}
