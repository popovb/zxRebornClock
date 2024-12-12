//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortName.hpp"

#ifndef _GRIC_PORT_CLOCK_TOGGLER_HPP_
#define _GRIC_PORT_CLOCK_TOGGLER_HPP_

namespace gric {

     class PortClockToggler {

     public:
	  PortClockToggler();

	  void on(PortName::name_t);
	  void off(PortName::name_t);

	  bool is_on(PortName::name_t) const;
	  bool is_off(PortName::name_t) const;

     private:
	  bool a;
	  bool b;
	  bool c;
	  bool d;
     };
}
#endif // _GRIC_PORT_CLOCK_TOGGLER_HPP_
