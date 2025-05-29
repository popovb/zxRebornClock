//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_MCU_BUTTON_HPP_
#define _GRIC_MCU_BUTTON_HPP_

namespace gric {

     class Button {

	  friend class Mcu;

     public:
	  operator bool() const;

     private:
	  u32 port;
	  u32 pin;

     private:
	  Button(u32, u32);
     };
}
#endif // _GRIC_MCU_BUTTON_HPP_
