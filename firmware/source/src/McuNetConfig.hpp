//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNet.hpp"
#include "core/PortPinConf.hpp"

#ifndef _GRIC_MCU_NET_CONFIG_HPP_
#define _GRIC_MCU_NET_CONFIG_HPP_

namespace gric {

     class McuNetConfig {

     public:
	  struct NetPortPinConf {
	       McuNet::net_t net;
	       PortPinConf conf;
	  };

     public:
	  McuNetConfig();

	  const NetPortPinConf& operator[](u8) const;
	  const PortPinConf& get(McuNet::net_t) const;

	  u8 size() const;

     private:
	  static constexpr u8 len = 30;
	  const NetPortPinConf pp[len];
     };
}
#endif // _GRIC_MCU_NET_CONFIG_HPP_
