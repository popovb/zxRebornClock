//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"

///////////////////////////////////////////////////////////////////
const gric::PortPinConf
gric::McuNetConfig::pp[] = {
     { PortName::C, 14 },
     { PortName::A,  8 },
     { PortName::A, 10 },
     { PortName::A, 12 },
     { PortName::A, 14 },
     { PortName::A, 17 },
     { PortName::A, 18 },
     { PortName::A, 19 },
     { PortName::A, 21 },
     { PortName::A, 23 },
     { PortName::C, 15 },
     { PortName::A,  9 },
     { PortName::A, 11 },
     { PortName::A, 13 },
};
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
const gric::PortPinConf&
gric::McuNetConfig::operator[](McuNet::net_t v) const {
     return pp[v];
}
///////////////////////////////////////////////////////////////////
