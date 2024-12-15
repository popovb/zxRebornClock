//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_PRINT_CONF_HPP_
#define _GRIC_PRINT_CONF_HPP_

namespace gric {

     struct PrintConf {
	  PrintConf(speed_t);

	  speed_t speed;
     };
}
#endif // _GRIC_PRINT_CONF_HPP_
