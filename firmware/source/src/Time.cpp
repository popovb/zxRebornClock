//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Time.hpp"
#include "DigitExtractor.hpp"

/////////////////////////////////////////////////////////////////
gric::Time::Time():
     hour(-1),
     minute(-1),
     second(-1)
{
     return;
}

gric::Time::Time(u8 h, u8 m):
     hour(h),
     minute(m),
     second(0)
{
     return;
}

gric::Time::Time(u8 h, u8 m, u8 s):
     hour(h),
     minute(m),
     second(s)
{
     return;
}

gric::Time::operator bool() const {
     if (second < 0) return false;
     if (minute < 0) return false;
     if (hour < 0) return false;
     if (second > 59) return false;
     if (minute > 59) return false;
     if (hour > 23) return false;
     return true;
}

void gric::Time::fill(u8* v) const {
     DigitExtractor<2> de;
     de.extract(v, minute);
     v += 2;
     de.extract(v, hour);
}

gric::i8 gric::Time::get_hour() const {
     return hour;
}

gric::i8 gric::Time::get_minute() const {
     return minute;
}

gric::i8 gric::Time::get_second() const {
     return second;
}
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
bool gric::operator==(const Time& l, const Time& r) {
     if (l.hour == r.hour)
	  if (l.minute == r.minute) return true;
     return false;
}
/////////////////////////////////////////////////////////////////
