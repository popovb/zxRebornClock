//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/PortPinConf.hpp"
#include "core/PinConf.hpp"
#include "core/Pin.hpp"

#ifndef _GRIC_GPIO_HPP_
#define _GRIC_GPIO_HPP_

namespace gric {

     class Gpio {

     public:
	  void init(const PortPinConf&, const PinConf&) const;
	  void init(const Pin&, const PinConf&) const;
	  void write_bit(u32, u32, bool) const;
	  bool read_bit(u32, u32) const;
     };
}
#endif // _GRIC_GPIO_HPP_
