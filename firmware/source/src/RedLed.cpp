//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "RedLed.hpp"

gric::RedLed::RedLed(const Mcu& m, const McuNetConfig& c):
     SimpleLed(m, c, McuNet::L_RED)
{
     return;
}

// void gric::RedLed::on() {
//      led.on();
// }

// void gric::RedLed::off() {
//      led.off();
// }

// void gric::RedLed::init(const Mcu& m, const McuNetConfig& c) {
//      const PortPinConf& ppc = c.get(McuNet::L_RED);
//      led = m.get(LedConf(ppc.port, ppc.pin));
// }
