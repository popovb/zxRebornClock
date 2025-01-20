//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "UartName.hpp"
#include "PinTx.hpp"
#include "PinRx.hpp"

#ifndef _GRIC_MCU_UART_CONF_HPP_
#define _GRIC_MCU_UART_CONF_HPP_

namespace gric {

     struct UartConf {
	  UartConf(UartName::name_t, u32,
		   const PinTx&, const PinRx&);

	  const UartName::name_t name;
	  const u32 speed;
	  const PinTx pin_tx;
	  const PinRx pin_rx;
     };
}
#endif // _GRIC_MCU_UART_CONF_HPP_
