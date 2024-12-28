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
     };
}
#endif // _GRIC_MCU_RTC_PIN_HPP_
