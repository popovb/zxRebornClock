//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortPin.hpp"
#include "PinConf.hpp"

#ifndef _GRIC_GPIO_HPP_
#define _GRIC_GPIO_HPP_

namespace gric {

     class Gpio {

     public:
	  void init(const PortPin&, const PinConf&);
     };
}
#endif // _GRIC_GPIO_HPP_
