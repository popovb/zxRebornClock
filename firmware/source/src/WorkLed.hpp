//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"
#include "core/Led.hpp"

#ifndef _GRIC_WORK_LED_HPP_
#define _GRIC_WORK_LED_HPP_

namespace gric {

     class WorkLed : public Led {

     public:
	  WorkLed(const Mcu&, const McuNetConfig&);
	  WorkLed& operator=(const Led&);

     private:
	  void init(const Mcu&, const McuNetConfig&);
     };
}
#endif // _GRIC_WORK_LED_HPP_
