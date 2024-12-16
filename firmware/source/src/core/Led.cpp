//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Led.hpp"

void gric::Led::toggle() {
     if (emit) {
	  off();
	  emit = false;

     } else {
	  on();
	  emit = true;
     }
}
