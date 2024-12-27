//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "Time.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_RTC_HPP_
#define _GRIC_RTC_HPP_

namespace gric {

     class Rtc {

     public:
	  Rtc(const Mcu&, const McuNetConfig&);

	  Time pull() const;
     };
}
#endif // _GRIC_RTC_HPP_
