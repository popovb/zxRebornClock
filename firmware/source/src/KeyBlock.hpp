//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "Key.hpp"
#include "KeyBlockEvent.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_KEY_BLOCK_HPP_
#define _GRIC_KEY_BLOCK_HPP_

namespace gric {

     class KeyBlock {

     public:
	  KeyBlock(const Mcu&, const McuNetConfig&);

	  KeyBlockEvent poll();

	  bool f_pressed() const;

     private:
	  void init(const Mcu&, const McuNetConfig&);
	  void init(Key&, const Mcu&, const PortPinConf&);

     private:
	  Key h;
	  Key m;
	  Key s;
	  Key f;
     };
}
#endif // _GRIC_KEY_BLOCK_HPP_
