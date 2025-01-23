//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "PortPinConf.hpp"

#ifndef _GRIC_MCU_PIN_TX_CONF_HPP_
#define _GRIC_MCU_PIN_TX_CONF_HPP_

namespace gric {

     struct PinTxConf : public PortPinConf {
	  PinTxConf(PortName::name_t, pin_t);
     };
}
#endif // _GRIC_MCU_PIN_TX_CONF_HPP_
