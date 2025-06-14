//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"

gric::McuNetConfig::McuNetConfig():
     pp{
	  { McuNet::K1,       { PortName::A,  7 } },
	  { McuNet::K2,       { PortName::A,  6 } },
	  { McuNet::K3,       { PortName::A,  5 } },
	  { McuNet::K4,       { PortName::A,  4 } },
	  { McuNet::K5,       { PortName::C,  6 } },
	  { McuNet::K6,       { PortName::A, 10 } },
	  { McuNet::K7,       { PortName::A, 14 } },
	  { McuNet::K8,       { PortName::A, 13 } },
	  { McuNet::K9,       { PortName::A, 12 } },
	  { McuNet::K0,       { PortName::A, 11 } },

	  { McuNet::SA1,      { PortName::A,  1 } },

	  //
	  // TODO : перепутаны на плате
	  //
	  { McuNet::SA2,      { PortName::A,  0 } },
	  { McuNet::SA3,      { PortName::A, 23 } },

	  { McuNet::SA4,      { PortName::A, 22 } },

	  { McuNet::RTC_CE,   { PortName::B,  1 } },
	  { McuNet::RTC_SCLK, { PortName::C,  7 } },
	  { McuNet::RTC_IO,   { PortName::B,  0 } },

	  { McuNet::L_RED,    { PortName::B,  8 } },
	  { McuNet::L_YELLOW, { PortName::B,  7 } },
	  { McuNet::L_GREEN,  { PortName::B,  6 } },
	  { McuNet::L_BLUE,   { PortName::B,  5 } },

	  { McuNet::B_HH,     { PortName::C, 14 } },
	  { McuNet::B_MM,     { PortName::C, 15 } },
	  { McuNet::B_SS,     { PortName::A,  8 } },
	  { McuNet::B_F,      { PortName::A,  9 } },

	  { McuNet::ESP_EN,   { PortName::B,  2 } },
	  { McuNet::ESP_RX,   { PortName::A,  2 } },
	  { McuNet::ESP_TX,   { PortName::A,  3 } },
     }
{
     return;
}

const gric::McuNetConfig::NetPortPinConf&
gric::McuNetConfig::operator[](u8 v) const {
     if (v >= len) return pp[len - 1];
     return pp[v];
}

const gric::PortPinConf&
gric::McuNetConfig::get(McuNet::net_t v) const {
     for (u8 i = 0; i < len; i++) {
	  const auto& vv = pp[i];
	  if (vv.net == v) return vv.conf;
     }
     return pp[len - 1].conf;
}

gric::u8 gric::McuNetConfig::size() const {
     return len;
}
