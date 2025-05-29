//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_KEY_STATE_HPP_
#define _GRIC_KEY_STATE_HPP_

namespace gric {

     class KeyState {

     public:
	  enum state_t : u8 {
	       Up   = 0,
	       Down = 1,
	  };
     };
}
#endif // _GRIC_KEY_STATE_HPP_
