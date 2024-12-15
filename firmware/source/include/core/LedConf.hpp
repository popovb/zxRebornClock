//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortName.hpp"

#ifndef _GRIC_MCU_LED_CONF_HPP_
#define _GRIC_MCU_LED_CONF_HPP_

namespace gric {

     struct LedConf {
	  LedConf(PortName::name_t, pin_t);

	  PortName::name_t port;
	  pin_t pin;
     };
}
#endif // _GRIC_MCU_LED_CONF_HPP_
