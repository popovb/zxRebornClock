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

/*
typedef enum
{
    GPIO_Mode_AIN = 0x0,
    GPIO_Mode_IN_FLOATING = 0x04,
    GPIO_Mode_IPD = 0x28,
    GPIO_Mode_IPU = 0x48,
    * GPIO_Mode_Out_PP = 0x10,
    * GPIO_Mode_AF_PP = 0x18
} GPIOMode_TypeDef;

     switch (v) {

     case PinMode::PushPull:
	  return GPIO_Mode_Out_PP;

     case PinMode::Float:
	  break;

     case PinMode::PullUp:
	  break;

     case PinMode::PullDown:
	  break;

     case PinMode::Analog:
	  break;

     case PinMode::Alter:
	  return GPIO_Mode_AF_PP;
     }


 */
