//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Rtc.hpp"

gric::Rtc::Rtc(const Mcu& mcu, const McuNetConfig& cnf):
     ce(mcu, cnf),
     sclk(mcu, cnf),
     io(mcu, cnf),
     transfer(ce, sclk, io, dln)
{
     return;
}
