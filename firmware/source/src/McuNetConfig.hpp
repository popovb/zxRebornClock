//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNet.hpp"
#include "PortPin.hpp"

#ifndef _GRIC_MCU_NET_CONFIG_HPP_
#define _GRIC_MCU_NET_CONFIG_HPP_

namespace gric {

     class McuNetConfig {

     public:
	  const PortPin& operator[](McuNet::net_t) const;

     private:
	  static const u8 len = 14;
	  static const PortPin pp[len];
     };
}
#endif // _GRIC_MCU_NET_CONFIG_HPP_
