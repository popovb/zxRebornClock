//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortPinConf.hpp"
#include "PinConf.hpp"
#include "PrintConf.hpp"
#include "LedConf.hpp"
#include "ButtonConf.hpp"
#include "UartConf.hpp"
#include "PinTxConf.hpp"
#include "PinRxConf.hpp"
#include "Led.hpp"
#include "Button.hpp"
#include "Uart.hpp"
#include "Pin.hpp"
#include "ClockToggler.hpp"

#ifndef _GRIC_MCU_HPP_
#define _GRIC_MCU_HPP_

namespace gric {

     class Mcu {

     public:
	  Mcu();

	  void init(const PortPinConf&, const PinConf&);
	  void init(const Pin&, const PinConf&) const;
	  void init(const PrintConf&) const;
	  void init(const LedConf&);
	  void init(const ButtonConf&, PinMode::mode_t);
	  void init(const UartConf&);
	  void init(const PinTxConf&);
	  void init(const PinRxConf&);

	  Pin get(const PortPinConf&) const;
	  Led get(const LedConf&) const;
	  Button get(const ButtonConf&) const;
	  Uart get(UartName::name_t) const;

     private:
	  void init() const;
	  void nvic_config() const;
	  void clock_update() const;
	  void init(UartName::name_t, u32) const;

     private:
	  ClockToggler pct;
     };
}
#endif // _GRIC_MCU_HPP_
