#include "UnitTest++/UnitTest++.h"
#include <iostream>

#include "McuNet.hpp"
#include "TimeChecker.hpp"
#include "Configurator.hpp"
#include "Anodes.hpp"
#include "Esp12f.hpp"
#include "LedColor.hpp"
#include "LedBlock.hpp"
#include "LedTaskMode.hpp"
#include "LedTaskTime.hpp"
#include "LedTask.hpp"
#include "LedBlockControl.hpp"
#include "DisplayTime.hpp"
#include "Tubes.hpp"
#include "core/PortName.hpp"
#include "core/UartName.hpp"
#include "core/PinTxConf.hpp"
#include "core/PinRxConf.hpp"
#include "core/UartConf.hpp"
#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"
#include "core/PinDir.hpp"
#include "core/PinMode.hpp"
#include "core/PinConf.hpp"
#include "core/ClockToggler.hpp"
#include "core/Gpio.hpp"
#include "core/PrintConf.hpp"
#include "core/LedConf.hpp"
#include "core/PortHolder.hpp"
#include "ch32x035.h"

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
}

TEST(test_02) {
     using namespace gric;
     pin_t p = 2;
     CHECK(p == 2);
}

TEST(test_03) {
     using namespace gric;
     McuNetConfig mnc;

     const auto& c = mnc.get(McuNet::K1);
     CHECK(c.port == PortName::C);
     CHECK(c.pin == 14);

     const auto& a = mnc.get(McuNet::K5);
     CHECK(a.port == PortName::A);
     CHECK(a.pin == 14);

     const auto& b = mnc.get(McuNet::K0);
     CHECK(b.port == PortName::A);
     CHECK(b.pin == 23);

     const auto& d = mnc.get(McuNet::SA4);
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
     ClockToggler pct;
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

TEST(test_14) {
     using namespace gric;
     TimeChecker tc;
     CHECK(! tc);
}

TEST(test_15) {
     using namespace gric;
     TimeChecker tc;
     Time t1(9, 15);
     tc.put(t1);
     CHECK(! tc);
}

TEST(test_16) {
     using namespace gric;
     TimeChecker tc;
     Time t1(9, 15);
     tc.put(t1);
     tc.put(t1);
     CHECK(tc);
}

TEST(test_17) {
     using namespace gric;
     TimeChecker tc;
     Time t1(9, 15);
     Time t2(9, 16);
     tc.put(t1);
     tc.put(t2);
     CHECK(tc);
}

TEST(test_18) {
     using namespace gric;
     TimeChecker tc;
     Time t1(9, 15);
     Time t2(9, 17);
     tc.put(t1);
     tc.put(t2);
     CHECK(! tc);
}

TEST(test_19) {
     using namespace gric;
     TimeChecker tc;
     Time t1(9, 15);
     Time t2(9, 16);
     tc.put(t1);
     tc.put(t2);
     CHECK(tc);
}

TEST(test_20) {
     using namespace gric;
     TimeChecker tc;
     Time t1(9, 59);
     Time t2(10, 0);
     tc.put(t1);
     tc.put(t2);
     CHECK(tc);
}

TEST(test_21) {
     using namespace gric;
     TimeChecker tc;
     Time t1(9, 59);
     Time t2(10, 1);
     tc.put(t1);
     tc.put(t2);
     CHECK(! tc);
}

TEST(test_22) {
     using namespace gric;
     TimeChecker tc;
     Time t1(9, 59);
     Time t2(9, 0);
     tc.put(t1);
     tc.put(t2);
     CHECK(! tc);
}

TEST(test_23) {
     using namespace gric;
     Time t(10, 56);
     u8 v[4] = { 0, 0, 0, 0, };
     t.fill(v);
     CHECK(v[0] == 6);
     CHECK(v[1] == 5);
     CHECK(v[2] == 0);
     CHECK(v[3] == 1);
}

TEST(test_24) {
     using namespace gric;
     PortHolder poh;
     CHECK(poh.get(PortName::A) == GPIOA_BASE);
     CHECK(poh.get(PortName::B) == GPIOB_BASE);
     CHECK(poh.get(PortName::C) == GPIOC_BASE);

     u32 a = 0x40000000 + 0x10000 + 0x0800;
     u32 b = 0x40000000 + 0x10000 + 0x0C00;
     u32 c = 0x40000000 + 0x10000 + 0x1000;

     CHECK(poh.get(PortName::A) == a);
     CHECK(poh.get(PortName::B) == b);
     CHECK(poh.get(PortName::C) == c);

     CHECK(poh.get(PortName::A) == 0X40010800);
     CHECK(poh.get(PortName::B) == 0X40010C00);
     CHECK(poh.get(PortName::C) == 0X40011000);

     CHECK(poh.get(PortName::A) == 1073809408);
     CHECK(poh.get(PortName::B) == 1073810432);
     CHECK(poh.get(PortName::C) == 1073811456);
}

TEST(test_25) {
     using namespace gric;
     Mcu mcu;
     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);

     Anodes as(mcu, mnc);
}

TEST(test_26) {
     using namespace gric;
     CHECK(UartName::Uart1 == 0);
     CHECK(UartName::Uart2 == 1);
     CHECK(UartName::Uart3 == 2);
     CHECK(UartName::Uart4 == 3);
}

TEST(test_27) {
     using namespace gric;
     PinTxConf ptx(PortName::A, 2);
     PinRxConf prx(PortName::A, 3);
}

TEST(test_28) {
     using namespace gric;
     PinTxConf ptx(PortName::A, 2);
     PinRxConf prx(PortName::A, 3);
     UartConf uc(UartName::Uart1, 115200, ptx, prx);
}

TEST(test_29) {
     using namespace gric;
     PinTxConf ptx(PortName::A, 2);
     PinRxConf prx(PortName::A, 3);
     UartConf uc(UartName::Uart1, 115200, ptx, prx);

     Mcu mcu;
     mcu.init(uc);
}

TEST(test_30) {
     using namespace gric;
     CHECK(LedColor::Red == 0);
     CHECK(LedColor::Yellow == 1);
     CHECK(LedColor::Green == 2);
     CHECK(LedColor::Blue == 3);
}

TEST(test_31) {
     using namespace gric;
     Mcu mcu;
     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);
     LedBlock lb(mcu, mnc);
}

TEST(test_32) {
     using namespace gric;
     CHECK(LedTaskMode::Off == 0);
     CHECK(LedTaskMode::Limit == 1);
     CHECK(LedTaskMode::Unlimit == 2);
}

TEST(test_33) {
     using namespace gric;
     LedTaskTime ltt1;
     LedTaskTime ltt2(1000);
     LedTaskTime ltt3(500, 500);
}

TEST(test_34) {
     using namespace gric;
     LedTask ld1(LedTaskMode::Off);
     LedTaskTime ltt3(500, 500);
     LedTask ld2(LedTaskMode::Limit, ltt3);
}

TEST(test_35) {
     using namespace gric;
     Mcu mcu;
     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);
     LedBlock lb(mcu, mnc);

     // LedBlockControl lbc(20, lb); // Расчёт сделать явно!
     //
     // TODO
     //
}

TEST(test_36) {
     using namespace gric;
     DisplayTime dt(2, 3, 4);
}

TEST(test_37) {
     using namespace gric;
     Mcu mcu;
     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);

     Anodes as(mcu, mnc);
     Cathodes cs(mcu, mnc);

     DisplayTime dt(2, 3, 4);
     Tubes tb(dt, as, cs);
}

TEST(test_38) {
     using namespace gric;
     Mcu mcu;
     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);

     Anodes as(mcu, mnc);
     Cathodes cs(mcu, mnc);

     DisplayTime dt(2, 3, 4);
     Tubes tb(dt, as, cs);
     CHECK(tb.calc_iters_per_second() == 50);
}
/*
TEST(test_30) {
     using namespace gric;
     Mcu mcu;
     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);

     Esp12f esp(mcu, mnc);
}
*/
