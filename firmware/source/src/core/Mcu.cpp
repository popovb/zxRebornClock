//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Mcu.hpp"
#include "Gpio.hpp"
#include "LedPinConf.hpp"
#include "PortHolder.hpp"
#include "PinHolder.hpp"

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

void gric::Mcu::init(const UartConf& uc) {
     if (pct.is_off(uc.name)) pct.on(uc.name);
     init(uc.pin_tx);
     init(uc.pin_rx);
     init(uc.name, uc.speed);
}

void gric::Mcu::init(const PinTx& v) {
     PinConf pc(PinDir::Out, PinMode::Alter);
     init(v, pc);
}

void gric::Mcu::init(const PinRx& v) {
     PinConf pc(PinDir::In, PinMode::Float);
     init(v, pc);
}

void gric::Mcu::init(const PortPinConf& pp, const PinConf& pc) {
     if (pct.is_off(pp.port)) pct.on(pp.port);
     Gpio gpio;
     gpio.init(pp, pc);
}

void gric::Mcu::init(const Pin& p, const PinConf& pc) const {
     Gpio gpio;
     gpio.init(p, pc);
}

void gric::Mcu::init(const LedConf& v) {
     PortPinConf pp(v);
     LedPinConf lpc;
     init(pp, lpc);
     get(v).off();
}

gric::Led gric::Mcu::get(const LedConf& lc) const {
     PortHolder poh;
     PinHolder pih;
     return Led(poh.get(lc.port), pih.get(lc.pin));
}

gric::Pin gric::Mcu::get(const PortPinConf& pc) const {
     PortHolder poh;
     PinHolder pih;
     return Pin(poh.get(pc.port), pih.get(pc.pin));
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
