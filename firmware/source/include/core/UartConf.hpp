//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "UartName.hpp"
#include "PinTxConf.hpp"
#include "PinRxConf.hpp"

#ifndef _GRIC_MCU_UART_CONF_HPP_
#define _GRIC_MCU_UART_CONF_HPP_

namespace gric {

     struct UartConf {
	  UartConf(UartName::name_t, u32,
		   const PinTxConf&, const PinRxConf&);

	  const UartName::name_t name;
	  const u32 speed;
	  const PinTxConf pin_tx;
	  const PinRxConf pin_rx;
     };
}
#endif // _GRIC_MCU_UART_CONF_HPP_
