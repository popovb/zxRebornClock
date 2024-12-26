//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_MCU_LED_HPP_
#define _GRIC_MCU_LED_HPP_

namespace gric {

     class Led {

	  friend class Mcu;

     public:
	  void on();
	  void off();
	  void toggle();

     private:
	  bool emit;
	  u32 port;
	  u32 pin;

     private:
	  Led(u32, u32);
     };
}
#endif // _GRIC_MCU_LED_HPP_
