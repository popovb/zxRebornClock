//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_ESP_12_F_HPP_
#define _GRIC_ESP_12_F_HPP_

namespace gric {

     class Esp12f {

     public:
	  Esp12f(const Mcu&, const McuNetConfig&);

	  void enable() const;
	  void disable() const;

     private:
	  void init_pin(const Mcu&, const McuNetConfig&);
	  void init_uart(const Mcu&, const McuNetConfig&);

     private:
	  Pin chip_select;
	  Uart uart;
     };
}
#endif // _GRIC_ESP_12_F_HPP_
