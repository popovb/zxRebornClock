//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "ButtonPinConf.hpp"

gric::ButtonPinConf::ButtonPinConf():
     PinConf(PinDir::In, PinMode::Float)
{
     return;
}

gric::ButtonPinConf::ButtonPinConf(PinMode::mode_t v):
     PinConf(PinDir::In, v)
{
     return;
}
