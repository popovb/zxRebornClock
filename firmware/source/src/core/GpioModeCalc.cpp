//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "GpioModeCalc.hpp"

GPIOMode_TypeDef gric::GpioModeCalc::get(const PinConf& pc) const {
     switch (pc.dir) {

     case PinDir::Out:
	  return get_out(pc.mode);

     case PinDir::In:
	  return get_in(pc.mode);

     default:
	  return get_out(pc.mode);
     }
}

GPIOMode_TypeDef gric::GpioModeCalc::get_out(PinMode::mode_t v) const {
     switch (v) {

     case PinMode::PushPull:
	  return GPIO_Mode_Out_PP;

     case PinMode::Alter:
	  return GPIO_Mode_AF_PP;

     default:
	  return GPIO_Mode_Out_PP;
     }
}

GPIOMode_TypeDef gric::GpioModeCalc::get_in(PinMode::mode_t v) const {
     switch (v) {

     case PinMode::Float:
	  return GPIO_Mode_IN_FLOATING;

     case PinMode::PullUp:
	  return GPIO_Mode_IPU;

     case PinMode::PullDown:
	  return GPIO_Mode_IPD;

     case PinMode::Analog:
	  return GPIO_Mode_AIN;

     default:
	  return GPIO_Mode_IN_FLOATING;
     }
}
