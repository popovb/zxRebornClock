//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Pin.hpp"

#ifndef _GRI_ANODES_HPP_
#define _GRI_ANODES_HPP_

namespace gri {

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
#endif // _GRI_ANODES_HPP_
