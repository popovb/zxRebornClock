//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortName.hpp"
#include "LedConf.hpp"

#ifndef _GRIC_MCU_PORT_PIN_CONF_HPP_
#define _GRIC_MCU_PORT_PIN_CONF_HPP_

namespace gric {

     struct PortPinConf {
	  PortPinConf(PortName::name_t, pin_t);
	  PortPinConf(const LedConf&);

	  PortName::name_t port;
	  pin_t pin;
     };
}
#endif // _GRIC_MCU_PORT_PIN_CONF_HPP_
