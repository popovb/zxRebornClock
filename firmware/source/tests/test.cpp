#include "UnitTest++/UnitTest++.h"
#include <iostream>
/*
#include "ds1302/Target.hpp"
#include "ds1302/Direction.hpp"
#include "ds1302/Register.hpp"
#include "ds1302/Command.hpp"
#include "ds1302/ClockHalt.hpp"
#include "ds1302/Seconds.hpp"
#include "ds1302/Minutes.hpp"
#include "ds1302/Meridiem.hpp"
#include "ds1302/HourMode.hpp"
#include "ds1302/Hour.hpp"
#include "ds1302/Date.hpp"
#include "ds1302/Month.hpp"
#include "ds1302/Day.hpp"
#include "ds1302/Year.hpp"
#include "ds1302/WriteProtect.hpp"
#include "ds1302/Transfer.hpp"
*/

int main(int, const char**) {
     return UnitTest::RunAllTests();
}

TEST(test_00) {
     CHECK(true);
     // using namespace ds1302;
     // CHECK(Target::Clock == 0);
     // CHECK(Target::Ram == 1);
}
