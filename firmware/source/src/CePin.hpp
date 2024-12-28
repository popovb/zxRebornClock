//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "RtcPin.hpp"
#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_MCU_CE_PIN_HPP_
#define _GRIC_MCU_CE_PIN_HPP_

namespace gric {

     class CePin : public RtcPin {

     public:
	  CePin(const Mcu&, const McuNetConfig&);
     };
}
#endif // _GRIC_MCU_CE_PIN_HPP_
