//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "LedPinConf.hpp"

gric::LedPinConf::LedPinConf():
     PinConf(PinDir::Out, PinMode::PushPull)
{
     return;
}
