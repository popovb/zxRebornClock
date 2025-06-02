//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/PinConf.hpp"

#ifndef _GRIC_BUTTON_PIN_CONF_HPP_
#define _GRIC_BUTTON_PIN_CONF_HPP_

namespace gric {

     struct ButtonPinConf : public PinConf {
	  ButtonPinConf();
	  ButtonPinConf(PinMode::mode_t);
     };
}
#endif // _GRIC_BUTTON_PIN_CONF_HPP_
