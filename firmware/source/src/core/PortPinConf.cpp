//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/PortPinConf.hpp"

gric::PortPinConf::PortPinConf(PortName::name_t n, pin_t p):
     port(n),
     pin(p)
{
     return;
}

gric::PortPinConf::PortPinConf(const LedConf& v):
     port(v.port),
     pin(v.pin)
{
     return;
}
