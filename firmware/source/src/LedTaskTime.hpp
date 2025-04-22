//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_LED_TASK_TIME_HPP_
#define _GRIC_LED_TASK_TIME_HPP_

namespace gric {

     struct LedTaskTime {
	  LedTaskTime();
	  LedTaskTime(ms_t);
	  LedTaskTime(ms_t, ms_t);
     };
}
#endif // _GRIC_LED_TASK_TIME_HPP_
