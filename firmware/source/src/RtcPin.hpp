//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Mcu.hpp"

#ifndef _GRIC_MCU_RTC_PIN_HPP_
#define _GRIC_MCU_RTC_PIN_HPP_

namespace gric {

     class RtcPin {

     public:
	  RtcPin(const Mcu&, Pin);

	  void init_in() const;
	  void init_out() const;

	  void write(bool) const;
	  bool read() const;

     private:
	  const Mcu& mcu;
	  const Pin pin;
     };
}
#endif // _GRIC_MCU_RTC_PIN_HPP_
