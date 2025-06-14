//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_CONFIGURATOR_HPP_
#define _GRIC_CONFIGURATOR_HPP_

namespace gric {

     class Configurator {

     public:
	  Configurator(Mcu&);

	  void init(const McuNetConfig&) const;

     private:
	  Mcu& mcu;

     private:
	  void init(const McuNetConfig::NetPortPinConf&) const;
	  void init_push_pull(const PortPinConf&) const;
	  void init_led(const PortPinConf&) const;
	  void init_button(const PortPinConf&,
			   PinMode::mode_t) const;
	  void init_tx_for_esp(const PortPinConf&) const;
	  void init_rx_for_esp(const PortPinConf&) const;
     };
}
#endif // _GRIC_CONFIGURATOR_HPP_
