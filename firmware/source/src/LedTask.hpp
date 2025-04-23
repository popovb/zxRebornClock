//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedTaskMode.hpp"
#include "LedTaskTime.hpp"

#ifndef _GRIC_LED_TASK_HPP_
#define _GRIC_LED_TASK_HPP_

namespace gric {

     class LedTask {

	  friend class LedBlockControl;

     public:
	  LedTask(LedTaskMode::mode_t);
	  LedTask(LedTaskMode::mode_t, const LedTaskTime&, u32);

	  operator bool() const;

     private:
	  LedTaskMode::mode_t mode;
	  LedTaskTime time;
	  u32 repeat;

     private:
	  LedTask();
     };
}
#endif // _GRIC_LED_TASK_HPP_
