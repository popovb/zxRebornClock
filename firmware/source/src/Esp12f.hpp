//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"
#include "core/Pin.hpp"

#ifndef _GRIC_ESP_12_F_HPP_
#define _GRIC_ESP_12_F_HPP_

namespace gric {

     class Esp12f {

     public:
	  Esp12f(const Mcu&, const McuNetConfig&);

     private:
	  void init(const Mcu&, const McuNetConfig&);
     };
}
#endif // _GRIC_ESP_12_F_HPP_
