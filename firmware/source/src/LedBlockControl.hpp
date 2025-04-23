//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedBlock.hpp"
#include "LedTask.hpp"

#ifndef _GRIC_LED_BLOCK_CONTROL_HPP_
#define _GRIC_LED_BLOCK_CONTROL_HPP_

namespace gric {

     class LedBlockControl {

     public:
	  LedBlockControl(ms_t, const LedBlock&);

	  void poll() const;

     private:
	  const ms_t poll_period;
	  const LedBlock& block;

     private:
	  const static u8 len = 4;
	  LedTask task[len];

     private:
	  void poll(u8) const;
     };
}
#endif // _GRIC_LED_BLOCK_CONTROL_HPP_
