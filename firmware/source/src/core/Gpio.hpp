//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/PortPinConf.hpp"
#include "core/PinConf.hpp"

#ifndef _GRIC_GPIO_HPP_
#define _GRIC_GPIO_HPP_

namespace gric {

     class Gpio {

     public:
	  void init(const PortPinConf&, const PinConf&) const;
	  void write_bit(u32, u32, bool);
     };
}
#endif // _GRIC_GPIO_HPP_
