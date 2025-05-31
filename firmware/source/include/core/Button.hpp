//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_MCU_BUTTON_HPP_
#define _GRIC_MCU_BUTTON_HPP_

namespace gric {

     class Button {

     public:
	  Button();
	  Button(u32, u32);

	  operator bool() const;

     private:
	  u32 port;
	  u32 pin;
     };
}
#endif // _GRIC_MCU_BUTTON_HPP_
