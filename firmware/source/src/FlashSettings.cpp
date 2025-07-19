//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "FlashSettings.hpp"

gric::FlashSettings::FlashSettings(Mcu& v):
     mcu(v),
     adr(0x0800F700),
     len(256)
{
     return;
}
