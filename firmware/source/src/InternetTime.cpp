//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "InternetTime.hpp"
#include "EspCommand.hpp"
#include "TimeStringExtractor.hpp"

gric::InternetTime::InternetTime(const Esp12f& v,
				 const FlashSettings& x):
     esp(v),
     fs(x),
     esp_state(Off),
     stage(Sleep),
     on_start(true),
     new_time(false),
     sc(3600)
{
     return;
}

void gric::InternetTime::test() {
     esp.on();
     dl.ms(1000);
     esp.uart_enable();

     send_and_receive(EspCommand::at, 3);
     if (erb.ok()) esp_state = On;

     esp.uart_disable();
     esp.off();
}

void gric::InternetTime::send_and_receive(const char* s, u8 v) {
     erb.reset();
     esp.send(s);
     u8 n = 0;
     while (! erb.completed(v)) {
	  if (n == tryed) break;
	  if (esp.has_data()) {
	       esp.receive_byte(erb);
	       n = 0;
	  } else {
	       ++n;
	  }
     }
}

void gric::InternetTime::poll_on_ntp() {
     send_and_receive(EspCommand::time, 4);

     esp.uart_disable();
     esp.off();
     stage = Sleep;

     TimeStringExtractor tse(erb.get());
     if (tse.extract_to(h, m, s)) {
	  new_time = true;
	  fix_time();
     }
}

gric::u8 gric::InternetTime::hour() const {
     return h;
}

gric::u8 gric::InternetTime::minute() const {
     return m;
}

gric::u8 gric::InternetTime::second() const {
     return s;
}

void gric::InternetTime::poll_on_sleep() {
     if (on_start) start();
     ++sc;
     if (sc) start();
}

void gric::InternetTime::start() {
     esp.on();
     esp.uart_enable();
     stage = Mode;
     on_start = false;
     sc.reset();
}

void gric::InternetTime::poll_on_mode() {
     esp.send(EspCommand::station_mode);
     stage = Ap;
}

void gric::InternetTime::poll_on_ap() {
     char b[192];
     EspCommand::build_ap(b, fs.get_ap(), fs.get_pass());
     esp.send(b);
     stage = ApPause;
     ap_pause = 10;
}

void gric::InternetTime::poll_on_ap_pause() {
     --ap_pause;
     if (ap_pause != 0) return;
     stage = ApTest;
}

void gric::InternetTime::poll_on_ap_test() {
     send_and_receive(EspCommand::ap_test, 4);

     if (erb.no_ap()) {
	  esp.uart_disable();
	  esp.off();
	  stage = Sleep;
	  return;
     }

     esp.send(EspCommand::ntp_cfg);
     stage = NtpPause;
     ntp_pause = 35;
}

void gric::InternetTime::poll_on_ntp_pause() {
     --ntp_pause;
     if (ntp_pause != 0) return;
     stage = Ntp;
}

void gric::InternetTime::poll() {
     if (esp_state == Off) return;

     switch (stage) {

     case Sleep:
	  return poll_on_sleep();

     case Mode:
	  return poll_on_mode();

     case Ap:
	  return poll_on_ap();

     case ApPause:
	  return poll_on_ap_pause();

     case ApTest:
	  return poll_on_ap_test();

     case NtpPause:
	  return poll_on_ntp_pause();

     case Ntp:
	  return poll_on_ntp();

     default:
	  break;
     }
}

void gric::InternetTime::forced() {
     on_start = true;
}

bool gric::InternetTime::has_new_time() const {
     return new_time;
}

void gric::InternetTime::reset_new_time() {
     new_time = false;
}

void gric::InternetTime::fix_time() {
     i8 nh = h + fs.get_tz();
     if (nh >= 24) nh = nh - 24;
     if (nh < 0) nh = nh + 24;
     h = nh;
}
