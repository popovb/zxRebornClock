//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/Hour.hpp"

ds1302::Hour::Hour() {
     return;
}

ds1302::Hour::Hour(u8 f) {
     data = to_bcd(f);
}

ds1302::HourMode::mode_t
ds1302::Hour::get_hour_mode() const {
     return (HourMode::mode_t)(data >> 7);
}

ds1302::Meridiem::type_t
ds1302::Hour::get_meridiem() const {
     return (Meridiem::type_t)((data & 0x20) >> 5);
}

ds1302::u8 ds1302::Hour::get() const {
     if (get_hour_mode() == HourMode::H24)
	  return get_24();
     else
	  return get_12();
}

ds1302::u8 ds1302::Hour::get_24() const {
     return from_bcd(data, 0x30);
}

ds1302::u8 ds1302::Hour::get_12() const {
     return ((data & 0x0F) + (((data & 0x20) >> 5) * 12));
}
