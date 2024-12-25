//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Gpio.hpp"
#include "PinHolder.hpp"
#include "GpioModeCalc.hpp"
#include "PortHolder.hpp"

#ifdef UNITTEST
void gric::Gpio::init(const PortPinConf&, const PinConf&) const {
     return;
}

void gric::Gpio::write_bit(u32, u32, bool) const {
     return;
}

bool gric::Gpio::read_bit(u32 p, u32 i) const {
     return true;
}
#else
#include "ch32x035.h"

void gric::Gpio::init(const PortPinConf& pp, const PinConf& pc) const {
     GPIO_InitTypeDef i;
     PinHolder ph;
     GpioModeCalc gmc;
     PortHolder poh;
     i.GPIO_Pin = ph.get(pp.pin);
     i.GPIO_Mode = gmc.get(pc);
     i.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_Init((GPIO_TypeDef*)poh.get(pp.port), &i);
}

void gric::Gpio::write_bit(u32 p, u32 i, bool v) const {
     BitAction vv = (v) ? Bit_SET : Bit_RESET;
     GPIO_WriteBit((GPIO_TypeDef*)p, i, vv);
}

bool gric::Gpio::read_bit(u32 p, u32 i) const {
     return GPIO_ReadInputDataBit((GPIO_TypeDef*)p, i);
}
#endif
