//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Time.hpp"

gric::Time::Time():
     hour(-1),
     minute(-1)
{
     return;
}

gric::Time::operator bool() const {
     if (minute < 0) return false;
     if (hour < 0) return false;
     if (minute > 59) return false;
     if (hour > 23) return false;
     return true;
}
