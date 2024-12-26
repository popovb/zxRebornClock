//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/Month.hpp"

ds1302::Month::Month():
     Data(1)
{
     return;
}

ds1302::Month::Month(u8 f) {
     data = to_bcd(f);
}

ds1302::u8 ds1302::Month::get() const {
     return from_bcd(data, 0x10);
}
