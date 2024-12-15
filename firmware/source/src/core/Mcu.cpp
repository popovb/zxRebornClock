//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Mcu.hpp"
#include "Gpio.hpp"

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

void gric::Mcu::init(const PrintConf&) const {
     return;
}

#ifdef    UNITTEST

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
     printf("SystemCoreClock: %d\r\n", SystemCoreClock);
     printf("ChipID: %08x\r\n", DBGMCU_GetCHIPID());
}

#endif // UNITTEST
