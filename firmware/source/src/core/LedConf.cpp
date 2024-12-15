//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/LedConf.hpp"

gric::LedConf::LedConf(PortName::name_t n, pin_t p):
     port(n),
     pin(p)
{
     return;
}
