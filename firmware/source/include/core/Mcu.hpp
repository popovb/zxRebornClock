//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortPin.hpp"
#include "PinConf.hpp"
#include "PortClockToggler.hpp"

#ifndef _GRIC_MCU_HPP_
#define _GRIC_MCU_HPP_

namespace gric {

     class Mcu {

     public:
	  Mcu();

	  void init(const PortPin&, const PinConf&);

     private:
	  void init() const;
	  void nvic_config() const;
	  void clock_update() const;

     private:
	  PortClockToggler pct;
     };
}
#endif // _GRIC_MCU_HPP_
