//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "TimeChecker.hpp"

gric::TimeChecker::operator bool() const {
     if (! prev) return false;
     if (! curr) return false;
     if (prev == curr) return true;
     if (prev.hour == curr.hour) return check_if_eq_hour();
     return check_if_ne_hour();
}

void gric::TimeChecker::put(const Time& v) {
     prev = curr;
     curr = v;
}

bool gric::TimeChecker::check_if_eq_hour() const {
     i8 delta = curr.minute - prev.minute;
     if (delta == 1) return true;
     return false;
}

bool gric::TimeChecker::check_if_ne_hour() const {
     i8 d_hour = curr.hour - prev.hour;
     if (d_hour != 1) return false;
     i8 d_minute = prev.minute - curr.minute;
     if (d_minute != 59) return false;
     return true;
}

void gric::TimeChecker::fill(u8* v) const {
     curr.fill(v);
}

void gric::TimeChecker::fill_prev(u8* v) const {
     prev.fill(v);
}
