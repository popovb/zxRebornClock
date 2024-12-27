//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "TimeChecker.hpp"

gric::TimeChecker::operator bool() const {
     if (! prev) return false;
     if (! curr) return false;
     if (prev == curr) return true;
     if (prev.hour == curr.hour) return check_if_eq_hour();
     //
     // TODO
     //
     return false;
}

void gric::TimeChecker::put(const Time& v) {
     prev = curr;
     curr = v;
}
