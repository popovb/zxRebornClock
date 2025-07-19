//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Mcu.hpp"

#ifndef _GRIC_FLASH_SETTINGS_HPP_
#define _GRIC_FLASH_SETTINGS_HPP_

namespace gric {

     class FlashSettings {

     public:
	  FlashSettings(Mcu&);

	  bool write() const;
	  void read() const;

	  void set_tz(const char*);
	  void set_ap(const char*);
	  void set_pass(const char*);

	  i8 get_tz() const;
	  const char* get_ap() const;
	  const char* get_pass() const;

     private:
	  Mcu& mcu;
	  const u32 adr;
	  const u32 len;

     private:
	  bool flash_erase() const;
	  bool flash_write() const;
     };
}
#endif // _GRIC_FLASH_SETTINGS_HPP_
