//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Pin.hpp"

#ifndef _GRIC_CATHODES_HPP_
#define _GRIC_CATHODES_HPP_

namespace gric {

     class Cathodes {

     public:
	  Cathodes();

	  void setup() const;
	  void clear() const;
	  void set(u8) const;

     private:
	  static const u8 N = 10;
	  Pin pins[N];
     };
}
#endif // _GRIC_CATHODES_HPP_
