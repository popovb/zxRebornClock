//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Rtc.hpp"
#include "ds1302/Hour.hpp"
#include "ds1302/Minutes.hpp"
#include "ds1302/Seconds.hpp"

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

void gric::Rtc::set(const Time& v) const {
     set_hour(v.get_hour());
     set_minute(v.get_minute());
}

void gric::Rtc::set_w_second(const Time& v) const {
     set_hour(v.get_hour());
     set_minute(v.get_minute());
     set_second(v.get_second());
}

void gric::Rtc::set(const Hour& h) const {
     set_hour(h.get());
}

void gric::Rtc::set(const Minute& m) const {
     set_minute(m.get());
}

void gric::Rtc::set_hour(u8 v) const {
     ds1302::Hour hh(v);

     using namespace ds1302;
     Command h(Register::Hour,
	       Target::Clock,
	       Direction::Write);

     transfer.write(h, hh);
}

void gric::Rtc::set_minute(u8 v) const {
     ds1302::Minutes mm(v);

     using namespace ds1302;
     Command m(Register::Minutes,
	       Target::Clock,
	       Direction::Write);

     transfer.write(m, mm);
}

void gric::Rtc::set_second(u8 v) const {
     ds1302::Seconds mm(v);

     using namespace ds1302;
     Command m(Register::Seconds,
	       Target::Clock,
	       Direction::Write);

     transfer.write(m, mm);
}
