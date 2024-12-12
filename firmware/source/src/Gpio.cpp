//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Gpio.hpp"
#include "PinHolder.hpp"
#include "ch32x035.h"

void gric::Gpio::init(const PortPin& pp, const PinConf& pc) {
     GPIO_InitTypeDef i;
     PinHolder ph;
     i.GPIO_Pin = ph.get(pp.pin);
     // GpioModeCalc gmc;
     // i.GPIO_Mode = gmc.get(pc);
     // i.GPIO_Speed = GPIO_Speed_50MHz;
     // PortHolder poh;
     // GPIO_Init(poh.get(pp.port), &i);
}
