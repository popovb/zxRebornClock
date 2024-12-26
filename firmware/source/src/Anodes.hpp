//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Pin.hpp"

#ifndef _GRIC_ANODES_HPP_
#define _GRIC_ANODES_HPP_

namespace gric {

     class Anodes {

     public:
	  Anodes();

	  void setup() const;
	  void clear() const;
	  void set(u8) const;

     private:
	  static const u8 N = 4;
	  Pin pins[N];
     };
}
#endif // _GRIC_ANODES_HPP_
