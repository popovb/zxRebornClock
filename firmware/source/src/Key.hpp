//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Button.hpp"

#ifndef _GRIC_KEY_HPP_
#define _GRIC_KEY_HPP_

namespace gric {

     class Key {

     public:
	  using press_t      = u32;
	  using long_press_t = u32;

     public:
	  Key(const Button&, press_t, long_press_t);

     private:
     };
}
#endif // _GRIC_KEY_HPP_
