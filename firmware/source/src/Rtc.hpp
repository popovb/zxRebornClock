//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "CePin.hpp"
#include "SclkPin.hpp"
#include "IoPin.hpp"
#include "Time.hpp"
#include "Hour.hpp"
#include "Minute.hpp"
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

	  void set(const Time&) const;
	  void set_w_second(const Time&) const;
	  void set(const Hour&) const;
	  void set(const Minute&) const;

	  void clear_second() const;

     private:
	  CePin ce;
	  SclkPin sclk;
	  IoPin io;

	  using Delayer = DelayerNop<4'000'000>;
	  Delayer dln;

	  using Transfer = ds1302::Transfer<RtcPin, Delayer>;
	  Transfer transfer;

     private:
	  void set_hour(u8) const;
	  void set_minute(u8) const;
	  void set_second(u8) const;
     };
}
#endif // _GRIC_RTC_HPP_
