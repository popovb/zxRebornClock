//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "RtcPin.hpp"

gric::RtcPin::RtcPin(const Mcu& m, Pin p):
     mcu(m),
     pin(p)
{
     return;
}

void gric::RtcPin::write(bool v) const {
     pin.write(v);
}

bool gric::RtcPin::read() const {
     return pin.read();
}
