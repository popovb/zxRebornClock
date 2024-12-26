//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "WorkLed.hpp"

gric::WorkLed::WorkLed(const Mcu& m, const McuNetConfig& mnc) {
     init(m, mnc);
}

void gric::WorkLed::init(const Mcu& m, const McuNetConfig& mnc) {
     const auto& v = mnc.get(McuNet::WL);
     LedConf lc(v.port, v.pin);
     (*this) = m.get(lc);
}
