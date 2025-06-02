//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Rtc.hpp"
#include "ds1302/Hour.hpp"
#include "ds1302/Minutes.hpp"

gric::Rtc::Rtc(const Mcu& mcu, const McuNetConfig& cnf):
     ce(mcu, cnf),
     sclk(mcu, cnf),
     io(mcu, cnf),
     transfer(ce, sclk, io, dln)
{
     return;
}

gric::Time gric::Rtc::pull() const {
     ds1302::Hour hh;
     ds1302::Minutes mm;

     using namespace ds1302;

     Command h(Register::Hour,
	       Target::Clock,
	       Direction::Read);
     Command m(Register::Minutes,
	       Target::Clock,
	       Direction::Read);

     transfer.read(h, hh);
     transfer.read(m, mm);

     return Time(hh.get(), mm.get());
}

void gric::Rtc::set(const Time& v) {
     ds1302::Hour hh(v.get_hour());
     ds1302::Minutes mm(v.get_minute());

     using namespace ds1302;

     Command h(Register::Hour,
	       Target::Clock,
	       Direction::Write);
     Command m(Register::Minutes,
	       Target::Clock,
	       Direction::Write);

     transfer.write(h, hh);
     transfer.write(m, mm);
}
