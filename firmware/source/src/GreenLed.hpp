//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "SimpleLed.hpp"
#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_GREEN_LED_HPP_
#define _GRIC_GREEN_LED_HPP_

namespace gric {

     class GreenLed : public SimpleLed {

     public:
	  GreenLed(const Mcu&,
		   const McuNetConfig&);
     };
}
#endif // _GRIC_GREEN_LED_HPP_
