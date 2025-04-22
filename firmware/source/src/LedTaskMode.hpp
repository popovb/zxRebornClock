//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#ifndef _GRIC_LED_TASK_MODE_HPP_
#define _GRIC_LED_TASK_MODE_HPP_

namespace gric {

     class LedTaskMode {

     public:
	  enum mode_t {
	       Off     = 0,
	       Limit   = 1,
	       Unlimit = 2,
	  };
     };
}
#endif // _GRIC_LED_TASK_MODE_HPP_
