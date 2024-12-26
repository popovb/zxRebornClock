//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/WriteProtect.hpp"

ds1302::WriteProtect::WriteProtect() {
     return;
}

ds1302::u8 ds1302::WriteProtect::get() const {
     return (data >> 7);
}

void ds1302::WriteProtect::set() {
     data |= 0x80;
}

void ds1302::WriteProtect::reset() {
     data &= 0x00;
}
