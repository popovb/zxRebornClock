//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "IoPin.hpp"

gric::IoPin::IoPin(const Mcu& mcu, const McuNetConfig& conf):
     RtcPin(mcu, mcu.get(conf.get(McuNet::RTC_IO)))
{
     return;
}
