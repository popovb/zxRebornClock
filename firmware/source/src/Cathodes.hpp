//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"
#include "core/Pin.hpp"

#ifndef _GRIC_CATHODES_HPP_
#define _GRIC_CATHODES_HPP_

namespace gric {

     class Cathodes {

     public:
	  Cathodes(const Mcu&, const McuNetConfig&);

	  void clear() const;
	  void set(u8) const;

     private:
	  static const u8 N = 10;
	  Pin pins[N];
     };
}
#endif // _GRIC_CATHODES_HPP_
