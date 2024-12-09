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
	  PortPin& operator[](McuNet::net_t) const;
     };
}
#endif // _GRIC_MCU_NET_CONFIG_HPP_
