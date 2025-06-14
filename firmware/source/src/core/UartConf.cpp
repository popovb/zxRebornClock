//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/UartConf.hpp"

gric::UartConf::UartConf(UartName::name_t a,
			 u32 b):
     name(a),
     speed(b)
{
     return;
}
