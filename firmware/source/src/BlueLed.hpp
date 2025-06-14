//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "SimpleLed.hpp"
#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_BLUE_LED_HPP_
#define _GRIC_BLUE_LED_HPP_

namespace gric {

     class BlueLed : public SimpleLed {

     public:
	  BlueLed(const Mcu&,
		  const McuNetConfig&);
     };
}
#endif // _GRIC_BLUE_LED_HPP_
