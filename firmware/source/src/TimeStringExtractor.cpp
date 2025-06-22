//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "TimeStringExtractor.hpp"
#include <cstdlib>

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
gric::u8
gric::TimeStringExtractor::load_second(u8& i) const {
     char s[3] = { '\0', };
     u8 n = find_rev(i, ':');
     i = n;
     s[0] = str[i + 1];
     s[1] = str[i + 2];
     return atoi(s);
}

gric::u16
gric::TimeStringExtractor::load_year(u8 cr, u8& i) const {
     char y[5];
     u8 n = find_rev(cr, ' ');
     i = n;
     y[0] = str[i + 1];
     y[1] = str[i + 2];
     y[2] = str[i + 3];
     y[3] = str[i + 4];
     y[4] = '\0';
     return atoi(y);
}

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

gric::u8 gric::TimeStringExtractor::
find_rev(u8 i, char c) const {
     while (i != 0) {
	  if (str[i] == c) return i;
	  --i;
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
