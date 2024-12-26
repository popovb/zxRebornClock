//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/Day.hpp"

ds1302::Day::Day():
     Data(1)
{
     return;
}

ds1302::Day::Day(u8 f) {
     data = to_bcd(f);
}

ds1302::u8 ds1302::Day::get() const {
     return (data & 0x07);
}
