#include "UnitTest++/UnitTest++.h"
#include <iostream>

#include "McuNet.hpp"

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
     using namespace gric;
     CHECK(McuNet::K1 == 0);
     CHECK(McuNet::K2 == 1);
     CHECK(McuNet::K3 == 2);
     CHECK(McuNet::K4 == 3);
     CHECK(McuNet::K5 == 4);
     CHECK(McuNet::K6 == 5);
     CHECK(McuNet::K7 == 6);
     CHECK(McuNet::K8 == 7);
     CHECK(McuNet::K9 == 8);
     CHECK(McuNet::K0 == 9);

     CHECK(McuNet::SA1 == 10);
     CHECK(McuNet::SA2 == 11);
     CHECK(McuNet::SA3 == 12);
     CHECK(McuNet::SA4 == 13);
}
