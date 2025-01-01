//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_PORT_NAME_HPP_
#define _GRIC_PORT_NAME_HPP_

namespace gric {

     class PortName {

     public:
	  enum name_t : u8 {
	       A = 0,
	       B = 1,
	       C = 2,
	  };
     };
}
#endif // _GRIC_PORT_NAME_HPP_
