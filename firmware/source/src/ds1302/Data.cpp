//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/Data.hpp"

ds1302::Data::Data():
     data(0)
{
     return;
}

ds1302::Data::Data(u8 n):
     data(n)
{
     return;
}

ds1302::u8 ds1302::Data::get_byte() const {
     return data;
}

void ds1302::Data::set_byte(u8 n) {
     data = n;
}

ds1302::u8 ds1302::Data::to_bcd(u8 f) const {
     u8 d = f / 10;
     u8 c = f % 10;
     return ((d << 4) | c);
}

ds1302::u8 ds1302::Data::from_bcd(u8 value, u8 mask) const {
     return ((value & 0x0F) + (((value & mask) >> 4) * 10));
}
