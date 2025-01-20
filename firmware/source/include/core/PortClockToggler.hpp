//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortName.hpp"
#include "UartName.hpp"

#ifndef _GRIC_PORT_CLOCK_TOGGLER_HPP_
#define _GRIC_PORT_CLOCK_TOGGLER_HPP_

namespace gric {

     class PortClockToggler {

     public:
	  PortClockToggler();

	  void on(PortName::name_t);
	  void off(PortName::name_t);

	  void on(UartName::name_t);
	  void off(UartName::name_t);

	  bool is_on(PortName::name_t) const;
	  bool is_off(PortName::name_t) const;

	  bool is_on(UartName::name_t) const;
	  bool is_off(UartName::name_t) const;

     private:
	  static constexpr u8 len = 3;
	  bool state[len];
     };
}
#endif // _GRIC_PORT_CLOCK_TOGGLER_HPP_
