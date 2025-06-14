//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "SimpleLed.hpp"

gric::SimpleLed::SimpleLed(const Mcu& m,
			   const McuNetConfig& c,
			   McuNet::net_t n) {
     init(m, c, n);
}

void gric::SimpleLed::on() {
     led.on();
}

void gric::SimpleLed::off() {
     led.off();
}

void gric::SimpleLed::init(const Mcu& m,
			   const McuNetConfig& c,
			   McuNet::net_t v) {
     const PortPinConf& ppc = c.get(v);
     led = m.get(LedConf(ppc.port, ppc.pin));
}
