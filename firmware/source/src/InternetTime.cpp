//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "InternetTime.hpp"
#include "EspCommand.hpp"

gric::InternetTime::InternetTime(const Esp12f& v):
     esp(v),
     state(Disable),
     sc(3600)
{
     return;
}

void gric::InternetTime::test() {
     erb.reset();
     state = Disable;

     esp.on();
     dl.ms(300);
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

     if (erb.ok()) state = Enable;
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

     default:
	  return;
     }
}
