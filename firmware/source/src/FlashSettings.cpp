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

void gric::FlashSettings::read() const {
     _settings = *(_Settings*)adr;
}

gric::i8 gric::FlashSettings::get_tz() const {
     return _settings.tz;
}

const char* gric::FlashSettings::get_ap() const {
     return _settings.ap;
}

const char* gric::FlashSettings::get_pass() const {
     return _settings.pass;
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

bool gric::FlashSettings::write() const {
     if (flash_erase())
	  return flash_write();
     return false;
}

bool gric::FlashSettings::flash_erase() const {
     return mcu.flash_erase(adr, len);
}

bool gric::FlashSettings::flash_write() const {
     return mcu.flash_write(adr, (u32*)&_settings, len);
}
