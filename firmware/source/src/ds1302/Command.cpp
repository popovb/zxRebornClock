//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ds1302/Command.hpp"

ds1302::Command::Command(Register::reg_t r,
			 Target::target_t t,
			 Direction::dir_t d):
     reg(r),
     trgt(t),
     dir(d)
{
     return;
}

ds1302::u8 ds1302::Command::get_byte() const {
     return (0x80 | (trgt << 6) | reg | dir);
}
