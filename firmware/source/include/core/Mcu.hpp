//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortPin.hpp"
#include "PinConf.hpp"
#include "PrintConf.hpp"
#include "LedConf.hpp"
#include "PortClockToggler.hpp"

#ifndef _GRIC_MCU_HPP_
#define _GRIC_MCU_HPP_

namespace gric {

     class Mcu {

     public:
	  Mcu();

	  void init(const PortPin&, const PinConf&);
	  void init(const PrintConf&) const;
	  void init(const LedConf&);

     private:
	  void init() const;
	  void nvic_config() const;
	  void clock_update() const;

     private:
	  PortClockToggler pct;
     };
}
#endif // _GRIC_MCU_HPP_
