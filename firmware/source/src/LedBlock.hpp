//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_LED_BLOCK_HPP_
#define _GRIC_LED_BLOCK_HPP_

namespace gric {

     class LedBlock {

	  friend class LedBlockControl;

     public:
	  LedBlock(const Mcu&, const McuNetConfig&);

     private:
	  void init(const Mcu&, const McuNetConfig&);
	  void init(u8, const Mcu&, const PortPinConf&);

     private:
	  Led led[4];
     };
}
#endif // _GRIC_LED_BLOCK_HPP_
