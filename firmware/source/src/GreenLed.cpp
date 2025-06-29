//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "GreenLed.hpp"

gric::GreenLed::GreenLed(const Mcu& m, const McuNetConfig& c):
     SimpleLed(m, c, McuNet::L_GREEN)
{
     return;
}
