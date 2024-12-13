//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortName.hpp"
#include "ch32x035.h"

#ifndef _GRIC_PORT_HOLDER_HPP_
#define _GRIC_PORT_HOLDER_HPP_

namespace gric {

     class PortHolder {

     public:
	  GPIO_TypeDef* get(PortName::name_t) const;

     private:
	  static const u8 len = 4;
	  static const GPIO_TypeDef* ports[len];
     };
}
#endif // _GRIC_PORT_HOLDER_HPP_
