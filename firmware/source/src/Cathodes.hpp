//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Pin.hpp"

#ifndef _GRI_CATHODES_HPP_
#define _GRI_CATHODES_HPP_

namespace gri {

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
#endif // _GRI_CATHODES_HPP_
