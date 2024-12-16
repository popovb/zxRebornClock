//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Gpio.hpp"
#include "PinHolder.hpp"
#include "GpioModeCalc.hpp"
#include "PortHolder.hpp"

#ifdef UNITTEST
void gric::Gpio::init(const PortPin&, const PinConf&) const {
     return;
}
#else
#include "ch32x035.h"

void gric::Gpio::init(const PortPin& pp, const PinConf& pc) const {
     GPIO_InitTypeDef i;
     PinHolder ph;
     GpioModeCalc gmc;
     PortHolder poh;
     i.GPIO_Pin = ph.get(pp.pin);
     i.GPIO_Mode = gmc.get(pc);
     i.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_Init((GPIO_TypeDef*)poh.get(pp.port), &i);
}
#endif
