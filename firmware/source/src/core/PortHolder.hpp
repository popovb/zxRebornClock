//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/PortName.hpp"

#ifndef _GRIC_PORT_HOLDER_HPP_
#define _GRIC_PORT_HOLDER_HPP_

namespace gric {

     class PortHolder {

     public:
	  u32 get(PortName::name_t) const;

     private:
	  static const u8 len = 3;
	  static const u32 ports[len];
     };
}
#endif // _GRIC_PORT_HOLDER_HPP_
