//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Esp12f.hpp"
#include "FlashSettings.hpp"
#include "SecondsCounter.hpp"
#include "core/DelayerNop.hpp"

#ifndef _GRIC_INTERNET_TIME_HPP_
#define _GRIC_INTERNET_TIME_HPP_

namespace gric {

     class InternetTime {

     private:
	  enum esp_state_t {
	       Off,
	       On,
	  };

	  enum stage_t {
	       Sleep,
	       Mode,
	       Ap,
	       ApPause,
	       NtpPause,
	       Ntp,
	  };

     public:
	  InternetTime(const Esp12f&, const FlashSettings&);

	  void forced();
	  void test();
	  void poll();

	  bool has_new_time() const;
	  void reset_new_time();

	  u8 hour() const;
	  u8 minute() const;
	  u8 second() const;

     private:
	  const Esp12f& esp;
	  const FlashSettings& fs;

	  esp_state_t esp_state;
	  stage_t stage;
	  bool on_start;
	  EspReceiveBuffer erb;
	  bool new_time;

	  using Delayer = DelayerNop<4'000'000>;
	  Delayer dl;

	  constexpr static u8 tryed = 100;
	  SecondsCounter sc;

	  u8 h;
	  u8 m;
	  u8 s;

	  u8 ap_pause;
	  u8 ntp_pause;

     private:
	  void start();
	  void poll_on_sleep();
	  void poll_on_mode();
	  void poll_on_ap();
	  void poll_on_ap_pause();
	  void poll_on_ntp_pause();
	  void poll_on_ntp();
	  void fix_time();
     };
}
#endif // _GRIC_INTERNET_TIME_HPP_
