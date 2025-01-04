//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"

gric::McuNetConfig::McuNetConfig():
     pp{
	  { McuNet::K1,       { PortName::C, 14 } },
	  { McuNet::K2,       { PortName::A,  8 } },
	  { McuNet::K3,       { PortName::A, 10 } },
	  { McuNet::K4,       { PortName::A, 12 } },
	  { McuNet::K5,       { PortName::A, 14 } },
	  { McuNet::K6,       { PortName::A, 17 } },
	  { McuNet::K7,       { PortName::A, 18 } },
	  { McuNet::K8,       { PortName::A, 19 } },
	  { McuNet::K9,       { PortName::A, 21 } },
	  { McuNet::K0,       { PortName::A, 23 } },

	  { McuNet::SA1,      { PortName::C, 15 } },
	  { McuNet::SA2,      { PortName::A,  9 } },
	  { McuNet::SA3,      { PortName::A, 11 } },
	  { McuNet::SA4,      { PortName::A, 13 } },

	  { McuNet::WL,       { PortName::A,  0 } },

	  { McuNet::RTC_CE,   { PortName::A,  6 } },
	  { McuNet::RTC_SCLK, { PortName::B,  0 } },
	  { McuNet::RTC_IO,   { PortName::C,  6 } },
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
