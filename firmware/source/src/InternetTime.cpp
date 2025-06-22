//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "InternetTime.hpp"
#include "EspCommand.hpp"
#include "TimeStringExtractor.hpp"

gric::InternetTime::InternetTime(const Esp12f& v):
     esp(v),
     state(Disable),
     new_time(false),
     sc(3600)
{
     return;
}

void gric::InternetTime::enable_ntp() const {
     esp.send(EspCommand::ntp_cfg);
}

void gric::InternetTime::test() {
     erb.reset();
     state = Disable;

     esp.on();
     dl.ms(3000);
     esp.uart_enable();

     esp.send(EspCommand::at);
     u8 n = 0;
     while (! erb.completed()) {
	  if (n == tryed) break;
	  if (esp.has_data()) {
	       esp.receive_byte(erb);
	       n = 0;
	  } else {
	       ++n;
	  }
     }

     if (erb.ok()) {
	  state = Enable;
	  enable_ntp();

     } else {
	  esp.off();
     }
     esp.uart_disable();
}

void gric::InternetTime::poll_esp_on() {
     erb.reset();
     esp.uart_enable();
     esp.send(EspCommand::time);
     u8 n = 0;
     while (! erb.completed()) {
	  if (n == tryed) break;
	  if (esp.has_data()) {
	       esp.receive_byte(erb);
	       n = 0;
	  } else {
	       ++n;
	  }
     }

     esp.uart_disable();
     state = Enable;

     TimeStringExtractor tse(erb.get());
     if (tse.extract_to(h, m, s))
	  new_time = true;
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

void gric::InternetTime::poll() {
     switch (state) {
     case Disable:
	  return;

     case Enable:
	  return poll_enable();

     case EspOn:
	  return poll_esp_on();

     default:
	  return;
     }
}

void gric::InternetTime::poll_enable() {
     new_time = false;
     ++sc;
     if (! sc) return;
     sc.reset();
     state = EspOn;
}

void gric::InternetTime::forced() {
     if (state == Disable) return;
     new_time = false;
     sc.reset();
     state = EspOn;
}

bool gric::InternetTime::has_new_time() const {
     return new_time;
}
