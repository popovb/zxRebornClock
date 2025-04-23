//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedBlock.hpp"

#ifndef _GRIC_LED_BLOCK_CONTROL_HPP_
#define _GRIC_LED_BLOCK_CONTROL_HPP_

namespace gric {

     class LedBlockControl {

     public:
	  LedBlockControl(ms_t, const LedBlock&);

	  void poll() const;
     };
}
#endif // _GRIC_LED_BLOCK_CONTROL_HPP_
