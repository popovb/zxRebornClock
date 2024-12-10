#include "UnitTest++/UnitTest++.h"
#include <iostream>

#include "McuNet.hpp"
#include "PortName.hpp"
#include "McuNetConfig.hpp"
#include "Mcu.hpp"
#include "PinDir.hpp"
#include "PinMode.hpp"
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

TEST(test_01) {
     using namespace gric;
     CHECK(PortName::A == 0);
     CHECK(PortName::B == 1);
     CHECK(PortName::C == 2);
     CHECK(PortName::D == 3);
}

TEST(test_02) {
     using namespace gric;
     pin_t p = 2;
     CHECK(p == 2);
}

TEST(test_03) {
     using namespace gric;
     McuNetConfig mnc;

     const auto& c = mnc[McuNet::K1];
     CHECK(c.port == PortName::C);
     CHECK(c.pin == 14);

     const auto& a = mnc[McuNet::K5];
     CHECK(a.port == PortName::A);
     CHECK(a.pin == 14);

     const auto& b = mnc[McuNet::K0];
     CHECK(b.port == PortName::A);
     CHECK(b.pin == 23);

     const auto& d = mnc[McuNet::SA4];
     CHECK(d.port == PortName::A);
     CHECK(d.pin == 13);
}

TEST(test_04) {
     using namespace gric;
     Mcu mcu;
}

TEST(test_05) {
     using namespace gric;
     CHECK(PinDir::Out == 0);
     CHECK(PinDir::In == 1);
}

TEST(test_06) {
     using namespace gric;
     CHECK(PinMode::PushPull == 0);
     CHECK(PinMode::Float == 1);
     CHECK(PinMode::PullUp == 2);
     CHECK(PinMode::PullDown == 3);
}
     
     //Mcu mcu;
     //Configurator cnf(mcu);
     //
     // TODO
     //
