//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Configurator.hpp"

gric::Configurator::Configurator(Mcu& v):
     mcu(v)
{
     return;
}

void gric::Configurator::init(const McuNetConfig& v) const {
     for (u8 i = 0; i < v.size(); i++) {
	  init(v[i]);
     }
}

void gric::Configurator::
init(const McuNetConfig::NetPortPinConf& v) const {
     switch (v.net) {
     case McuNet::K1:
     case McuNet::K2:
     case McuNet::K3:
     case McuNet::K4:
     case McuNet::K5:
     case McuNet::K6:
     case McuNet::K7:
     case McuNet::K8:
     case McuNet::K9:
     case McuNet::K0:
     case McuNet::SA1:
     case McuNet::SA2:
     case McuNet::SA3:
     case McuNet::SA4:
	  init_push_pull(v.conf);
	  return;

     case McuNet::WL:
	  init_led(v.conf);
	  return;

     default:
	  return;
     }
}

void gric::Configurator::init_push_pull(const PortPinConf& v) const {
     PinConf pc(PinDir::Out, PinMode::PushPull);
     mcu.init(v, pc);
}
