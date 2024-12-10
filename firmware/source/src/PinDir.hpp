//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_PIN_DIR_HPP_
#define _GRIC_PIN_DIR_HPP_

namespace gric {

     class PinDir {

     public:
	  enum dir_t : u8 {
	       Out = 0,
	       In  = 1,
	  };
     };
}
#endif // _GRIC_PIN_DIR_HPP_
