//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/Minutes.hpp"

ds1302::Minutes::Minutes() {
     return;
}

ds1302::Minutes::Minutes(u8 f) {
     data = to_bcd(f);
}

ds1302::u8 ds1302::Minutes::get() const {
     return from_bcd(data, 0x70);
}
