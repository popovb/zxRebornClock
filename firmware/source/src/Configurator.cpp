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
     case McuNet::RTC_CE:
     case McuNet::RTC_SCLK:
     case McuNet::RTC_IO:
     case McuNet::ESP_EN:
	  init_push_pull(v.conf);
	  return;

     case McuNet::L_RED:
     case McuNet::L_YELLOW:
     case McuNet::L_GREEN:
     case McuNet::L_BLUE:
	  init_led(v.conf);
	  return;

     case McuNet::B_HH:
     case McuNet::B_MM:
	  init_button(v.conf, PinMode::Float);
	  return;

     case McuNet::B_SS:
     case McuNet::B_F:
	  init_button(v.conf, PinMode::PullDown);
	  return;

     case McuNet::ESP_RX:
	  init_tx_for_esp(v.conf);
	  return;

     case McuNet::ESP_TX:
	  init_rx_for_esp(v.conf);
	  return;

     case McuNet::RX:
	  init_uart_rx(v.conf);
	  return;

     case McuNet::TX:
	  init_uart_tx(v.conf);
	  return;

     default:
	  return;
     }
}

void gric::Configurator::
init_push_pull(const PortPinConf& v) const {
     PinConf pc(PinDir::Out, PinMode::PushPull);
     mcu.init(v, pc);
}

void gric::Configurator::init_led(const PortPinConf& v) const {
     LedConf lc(v.port, v.pin);
     mcu.init(lc);
}

void gric::Configurator::
init_button(const PortPinConf& v, PinMode::mode_t p) const {
     ButtonConf bc(v.port, v.pin);
     mcu.init(bc, p);
}

void gric::Configurator::
init_tx_for_esp(const PortPinConf& v) const {
     PinTxConf p(v.port, v.pin);
     mcu.init(p);
}

void gric::Configurator::
init_rx_for_esp(const PortPinConf& v) const {
     PinRxConf p(v.port, v.pin);
     mcu.init(p);
}
