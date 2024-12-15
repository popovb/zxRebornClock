//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Mcu.hpp"
#include "Gpio.hpp"
#include "LedPinConf.hpp"

#ifndef UNITTEST
#include "ch32x035.h"
#include "debug.h"
#endif

gric::Mcu::Mcu() {
     init();
}

void gric::Mcu::init() const {
     nvic_config();
     clock_update();
}

void gric::Mcu::init(const PortPin& pp, const PinConf& pc) {
     if (pct.is_off(pp.port)) pct.on(pp.port);
     Gpio gpio;
     gpio.init(pp, pc);
}

void gric::Mcu::init(const LedConf& v) {
     PortPin pp(v);
     LedPinConf lpc;
     init(pp, lpc);
}

#ifdef    UNITTEST

void gric::Mcu::init(const PrintConf&) const {
     return;
}

void gric::Mcu::nvic_config() const {
     return;
}

void gric::Mcu::clock_update() const {
     return;
}

#else //  UNITTEST

void gric::Mcu::nvic_config() const {
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
}

void gric::Mcu::clock_update() const {
     SystemCoreClockUpdate();
}

void gric::Mcu::init(const PrintConf& v) const {
     USART_Printf_Init(v.speed);
     printf("SystemCoreClock: %d\r\n", (int)SystemCoreClock);
     printf("ChipID: %08x\r\n", (int)DBGMCU_GetCHIPID());
}

#endif // UNITTEST
