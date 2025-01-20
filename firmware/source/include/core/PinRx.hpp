//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "PortPinConf.hpp"

#ifndef _GRIC_MCU_PIN_RX_HPP_
#define _GRIC_MCU_PIN_RX_HPP_

namespace gric {

     struct PinRx : public PortPinConf {
	  PinRx(PortName::name_t, pin_t);
     };
}
#endif // _GRIC_MCU_PIN_RX_HPP_
