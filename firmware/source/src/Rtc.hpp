//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "CePin.hpp"
#include "SclkPin.hpp"
#include "IoPin.hpp"
#include "Time.hpp"
#include "core/Mcu.hpp"
#include "core/DelayerNop.hpp"
#include "ds1302/Transfer.hpp"

#ifndef _GRIC_RTC_HPP_
#define _GRIC_RTC_HPP_

namespace gric {

     class Rtc {

     public:
	  Rtc(const Mcu&, const McuNetConfig&);

	  Time pull() const;
	  void set(const Time&);

     private:
	  CePin ce;
	  SclkPin sclk;
	  IoPin io;

	  using Delayer = DelayerNop<4'000'000>;
	  Delayer dln;

	  using Transfer = ds1302::Transfer<RtcPin, Delayer>;
	  Transfer transfer;
     };
}
#endif // _GRIC_RTC_HPP_
