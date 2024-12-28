//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CePin.hpp"

gric::CePin::CePin(const Mcu& mcu, const McuNetConfig& conf):
     RtcPin(mcu, mcu.get(conf.get(McuNet::RTC_CE)))
{
     return;
}
