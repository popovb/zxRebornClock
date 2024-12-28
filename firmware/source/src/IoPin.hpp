//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "RtcPin.hpp"
#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_MCU_IO_PIN_HPP_
#define _GRIC_MCU_IO_PIN_HPP_

namespace gric {

     class IoPin : public RtcPin {

     public:
	  IoPin(const Mcu&, const McuNetConfig&);
     };
}
#endif // _GRIC_MCU_IO_PIN_HPP_
