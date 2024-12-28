//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_MCU_SCLK_PIN_HPP_
#define _GRIC_MCU_SCLK_PIN_HPP_

namespace gric {

     class SclkPin {

     public:
	  SclkPin(const Mcu&, const McuNetConfig&);
     };
}
#endif // _GRIC_MCU_SCLK_PIN_HPP_
