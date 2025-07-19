//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "FlashSettings.hpp"
#include <cstdlib>
#include <cstring>

struct _Settings {
     gric::i8 tz;
     char ap[64];
     char pass[64];
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

void gric::FlashSettings::set_ap(const char* v) {
     strncpy(_settings.ap, v, 63);
     _settings.ap[63] = '\0';
}

void gric::FlashSettings::set_pass(const char* v) {
     strncpy(_settings.pass, v, 63);
     _settings.pass[63] = '\0';
}
