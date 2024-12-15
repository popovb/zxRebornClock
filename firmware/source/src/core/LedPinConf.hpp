//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/PinConf.hpp"

#ifndef _GRIC_LED_PIN_CONF_HPP_
#define _GRIC_LED_PIN_CONF_HPP_

namespace gric {

     struct LedPinConf : public PinConf {
	  LedPinConf();
     };
}
#endif // _GRIC_LED_PIN_CONF_HPP_
