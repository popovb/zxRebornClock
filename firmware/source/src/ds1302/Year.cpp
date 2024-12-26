//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/Year.hpp"

ds1302::Year::Year() {
     return;
}

ds1302::Year::Year(u8 f) {
     data = to_bcd(f);
}

ds1302::u8 ds1302::Year::get() const {
     return from_bcd(data, 0xF0);
}
