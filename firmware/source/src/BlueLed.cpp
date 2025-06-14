//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "BlueLed.hpp"

gric::BlueLed::BlueLed(const Mcu& m, const McuNetConfig& c):
     SimpleLed(m, c, McuNet::L_BLUE)
{
     return;
}
