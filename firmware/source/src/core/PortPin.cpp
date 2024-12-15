//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/PortPin.hpp"

gric::PortPin::PortPin(PortName::name_t n, pin_t p):
     port(n),
     pin(p)
{
     return;
}

gric::PortPin::PortPin(const LedConf& v):
     port(v.port),
     pin(v.pin)
{
     return;
}
