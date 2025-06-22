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
bool gric::TimeStringExtractor::
extract_to(u8& h, u8& m, u8& s) const {
     h = m = s = 0;
     u8 cr2 = find_cr_2();
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
