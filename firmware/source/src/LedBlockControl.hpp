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
	  LedBlockControl(ms_t, LedBlock&);

	  void poll();

     private:
	  const ms_t poll_period;
	  LedBlock& block;

     private:
	  const static u8 len = 4;
	  LedTask task[len];
	  bool on_start[len];

     private:
	  void poll(u8);
	  void poll_start(u8);
	  void poll_continue(u8);
	  void poll_continue_up(u8);
	  void poll_continue_down(u8) const;
     };
}
#endif // _GRIC_LED_BLOCK_CONTROL_HPP_
