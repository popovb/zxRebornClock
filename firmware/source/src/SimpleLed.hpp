//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_SIMPLE_LED_HPP_
#define _GRIC_SIMPLE_LED_HPP_

namespace gric {

     class SimpleLed {

     public:
	  SimpleLed(const Mcu&,
		    const McuNetConfig&,
		    McuNet::net_t);

      	  void on();
      	  void off();

      private:
     // 	  void init(const Mcu&, const McuNetConfig&);

     // private:
      	  Led led;
     };
}
#endif // _GRIC_SIMPLE_LED_HPP_
