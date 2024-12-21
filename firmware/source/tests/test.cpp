#include "UnitTest++/UnitTest++.h"
#include <iostream>

#include "McuNet.hpp"
#include "core/PortName.hpp"
#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"
#include "core/PinDir.hpp"
#include "core/PinMode.hpp"
#include "core/PinConf.hpp"
#include "core/PortClockToggler.hpp"
#include "core/Gpio.hpp"
#include "core/PrintConf.hpp"
#include "core/LedConf.hpp"

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
     CHECK(PinMode::Analog == 4);
     CHECK(PinMode::Alter == 5);
}

TEST(test_07) {
     using namespace gric;
     PinConf pc(PinDir::Out, PinMode::PushPull);
     CHECK(pc.dir == PinDir::Out);
     CHECK(pc.mode == PinMode::PushPull);
}

TEST(test_08) {
     using namespace gric;
     PinConf pc(PinDir::Out, PinMode::PushPull);
     PortPinConf pp(PortName::A, 0);
     Mcu mcu;
     mcu.init(pp, pc);
}

TEST(test_09) {
     using namespace gric;
     PortClockToggler pct;
     CHECK(pct.is_off(PortName::A));
     CHECK(! pct.is_on(PortName::A));
     pct.on(PortName::A);
     CHECK(pct.is_on(PortName::A));
     pct.off(PortName::A);
     CHECK(pct.is_off(PortName::A));
}

TEST(test_10) {
     using namespace gric;
     PinConf pc(PinDir::Out, PinMode::PushPull);
     PortPinConf pp(PortName::A, 0);
     Gpio gpio;
     gpio.init(pp, pc);
}

TEST(test_11) {
     using namespace gric;
     PrintConf pc(115200);
     Mcu mcu;
     mcu.init(pc);
}

TEST(test_12) {
     using namespace gric;
     LedConf led(PortName::A, 0);
     Mcu mcu;
     mcu.init(led);
}

TEST(test_13) {
     using namespace gric;
     LedConf lc(PortName::A, 0);
     Mcu mcu;
     mcu.init(lc);
     Led led = mcu.get(lc);
     led.on();
     led.off();
     led.toggle();
     led.off();
}

     //Mcu mcu;
     //Configurator cnf(mcu);
     //
     // TODO
     //
