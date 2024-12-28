//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "SclkPin.hpp"

gric::SclkPin::SclkPin(const Mcu& mcu, const McuNetConfig& conf):
     RtcPin(mcu, mcu.get(conf.get(McuNet::RTC_SCLK)))
{
     return;
}
