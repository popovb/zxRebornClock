//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "TimeStringExtractor.hpp"

gric::TimeStringExtractor::TimeStringExtractor(const char* v):
     str(v)
{
     return;
}
/*
const char* in = "AT+CIPSNTPTIME?\r\n\
+CIPSNTPTIME:Thu Aug 04 14:48:05 2016\r\n\
OK\r";
*/
gric::u8 gric::TimeStringExtractor::find_cr_2() const {
     char* p = (char*)str;
     u8 i = 0;
     u8 cr = 0;
     while ((*p) != 0) {
	  if ((*p) == '\r') ++cr;
	  if (cr == 2) return i;
	  ++i;
	  ++p;
     }
     return 0;
}

bool gric::TimeStringExtractor::
extract_to(u8& h, u8& m, u8& s) const {
     h = m = s = 0;
     u8 cr2 = find_cr_2();
     if (cr2 == 0) return false;
     u8 next;
     u16 y = load_year(cr2, next);
     s = load_second(next);
     m = load_minute(next);
     m = load_hour(next);
     //
     // TODO
     //
     return true;
}
