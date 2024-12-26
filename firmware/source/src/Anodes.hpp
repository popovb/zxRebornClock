//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"
#include "core/Pin.hpp"

#ifndef _GRIC_ANODES_HPP_
#define _GRIC_ANODES_HPP_

namespace gric {

     class Anodes {

     public:
	  Anodes(const Mcu&, const McuNetConfig&);

	  void clear() const;
	  void set(u8) const;

     private:
	  static const u8 N = 4;
	  Pin pins[N];

     private:
	  void init(const Mcu&, const McuNetConfig&);
	  void init(u8, const PortPinConf&, const Mcu&);
     };
}
#endif // _GRIC_ANODES_HPP_
