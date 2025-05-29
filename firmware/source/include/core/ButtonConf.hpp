//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "PortName.hpp"

#ifndef _GRIC_MCU_BUTTON_CONF_HPP_
#define _GRIC_MCU_BUTTON_CONF_HPP_

namespace gric {

     struct ButtonConf {
	  ButtonConf(PortName::name_t, pin_t);

	  PortName::name_t port;
	  pin_t pin;
     };
}
#endif // _GRIC_MCU_BUTTON_CONF_HPP_
