//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortPinConf.hpp"
#include "PinConf.hpp"
#include "PrintConf.hpp"
#include "LedConf.hpp"
#include "Led.hpp"
#include "Pin.hpp"
#include "PortClockToggler.hpp"

#ifndef _GRIC_MCU_HPP_
#define _GRIC_MCU_HPP_

namespace gric {

     class Mcu {

     public:
	  Mcu();

	  void init(const PortPinConf&, const PinConf&);
	  void init(const Pin&, const PinConf&) const;
	  Pin get(const PortPinConf&) const;

	  void init(const PrintConf&) const;

	  void init(const LedConf&);
	  Led get(const LedConf&) const;

     private:
	  void init() const;
	  void nvic_config() const;
	  void clock_update() const;

     private:
	  PortClockToggler pct;
     };
}
#endif // _GRIC_MCU_HPP_
