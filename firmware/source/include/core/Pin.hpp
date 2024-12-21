//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_MCU_PIN_HPP_
#define _GRIC_MCU_PIN_HPP_

namespace gric {

     class Pin {

	  friend class Mcu;

     public:

     private:
	  bool emit;
	  u32 port;
	  u32 pin;

     private:
	  Pin(u32, u32);
     };
}
#endif // _GRIC_MCU_PIN_HPP_
