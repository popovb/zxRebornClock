//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/Seconds.hpp"

ds1302::Seconds::Seconds() {
     return;
}

ds1302::Seconds::Seconds(ClockHalt::flag_t f):
     Data(f << 7)
{
     return;
}

ds1302::Seconds::Seconds(u8 f) {
     data = data | to_bcd(f);
}

ds1302::ClockHalt::flag_t
ds1302::Seconds::get_flag() const {
     return (ClockHalt::flag_t)(data >> 7);
}

ds1302::u8 ds1302::Seconds::get() const {
     return from_bcd(data, 0x70);
}
