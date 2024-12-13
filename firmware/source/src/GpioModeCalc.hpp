//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PinConf.hpp"
#include "ch32x035.h"

#ifndef _GRIC_GPIO_MODE_CALC_HPP_
#define _GRIC_GPIO_MODE_CALC_HPP_

namespace gric {

     class GpioModeCalc {

     public:
	  GPIOMode_TypeDef get(const PinConf&) const;

     private:
	  GPIOMode_TypeDef get_out(PinMode::mode_t) const;
	  GPIOMode_TypeDef get_in(PinMode::mode_t) const;
     };
}
#endif // _GRIC_GPIO_MODE_CALC_HPP_
