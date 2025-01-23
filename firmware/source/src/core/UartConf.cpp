//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/UartConf.hpp"

gric::UartConf::UartConf(UartName::name_t a,
			 u32 b,
			 const PinTxConf& c,
			 const PinRxConf& d):
     name(a),
     speed(b),
     pin_tx(c),
     pin_rx(d)
{
     return;
}
