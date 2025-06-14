//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Esp12f.hpp"

gric::Esp12f::Esp12f(const Mcu& m, const McuNetConfig& mnc) {
     init_pin(m, mnc);
     init_uart(m, mnc);
}

void gric::Esp12f::enable() const {
     chip_select.write(true);
}

void gric::Esp12f::
init_pin(const Mcu& m, const McuNetConfig& mnc) {
     const PortPinConf& ppc = mnc.get(McuNet::ESP_EN);
     chip_select = m.get(PortPinConf(ppc.port, ppc.pin));
}

void gric::Esp12f::
init_uart(const Mcu& m, const McuNetConfig& mnc) {
     // const PortPinConf& ppc = mnc.get(McuNet::ESP_EN);
     // chip_select = m.get(PortPinConf(ppc.port, ppc.pin));
     //
     // TODO
     //
}
