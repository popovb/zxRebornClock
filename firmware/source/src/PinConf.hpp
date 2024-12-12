//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PinDir.hpp"
#include "PinMode.hpp"

#ifndef _GRIC_PIN_CONF_HPP_
#define _GRIC_PIN_CONF_HPP_

namespace gric {

     struct PinConf {
	  PinConf(PinDir::dir_t, PinMode::mode_t);
     };
}
#endif // _GRIC_PIN_CONF_HPP_
