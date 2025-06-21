//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Esp12f.hpp"
#include "SecondsCounter.hpp"
#include "core/DelayerNop.hpp"

#ifndef _GRIC_INTERNET_TIME_HPP_
#define _GRIC_INTERNET_TIME_HPP_

namespace gric {

     class InternetTime {

     private:
	  enum state_t {
	       Disable,
	       Enable,
	       EspOn,
	  };

     public:
	  InternetTime(const Esp12f&);

	  void test();
	  void poll();
	  bool has_new_time() const;

	  u8 hour() const;
	  u8 minute() const;
	  u8 second() const;

     private:
	  const Esp12f& esp;
	  state_t state;
	  EspReceiveBuffer erb;

	  using Delayer = DelayerNop<4'000'000>;
	  Delayer dl;

	  constexpr static u8 tryed = 100;
	  SecondsCounter sc;

	  u8 h;
	  u8 m;
	  u8 s;

     private:
	  void poll_enable();
	  void poll_esp_on();
     };
}
#endif // _GRIC_INTERNET_TIME_HPP_
