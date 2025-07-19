//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "FlashSettings.hpp"
#include <cstdlib>

struct _Settings {
     gric::i8 tz;
     //
     // TODO
     //
};

static _Settings _settings;

gric::FlashSettings::FlashSettings(Mcu& v):
     mcu(v),
     adr(0x0800F700),
     len(256)
{
     return;
}

void gric::FlashSettings::set_tz(const char* v) {
     _settings.tz = atoi(v);
}
