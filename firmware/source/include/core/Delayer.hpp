//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_DELAYER_HPP_
#define _GRIC_DELAYER_HPP_

namespace gric {

     class Delayer {

     public:
	  Delayer();

	  void ms(u32) const;
	  void us(u32) const;
     };
}
#endif // _GRIC_DELAYER_HPP_
