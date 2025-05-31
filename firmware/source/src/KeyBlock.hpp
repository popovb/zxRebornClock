//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_KEY_BLOCK_HPP_
#define _GRIC_KEY_BLOCK_HPP_

namespace gric {

     class KeyBlock {

     public:
	  KeyBlock(const Mcu&, const McuNetConfig&);

     private:
	  void init(const Mcu&, const McuNetConfig&);
	  void init(Button&, const Mcu&, const PortPinConf&);

     private:
	  Button h;
	  Button m;
	  Button s;
	  Button f;
     };
}
#endif // _GRIC_KEY_BLOCK_HPP_
