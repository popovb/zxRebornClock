//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/Date.hpp"

ds1302::Date::Date():
     Data(1)
{
     return;
}

ds1302::Date::Date(u8 f) {
     data = to_bcd(f);
}

ds1302::u8 ds1302::Date::get() const {
     return from_bcd(data, 0x30);
}
