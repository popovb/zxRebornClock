//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"

#ifndef _GRIC_CONFIGURATOR_HPP_
#define _GRIC_CONFIGURATOR_HPP_

namespace gric {

     class Configurator {

     public:
	  Configurator(Mcu&);

	  void init(const McuNetConfig&) const;

     private:
	  Mcu& mcu;
     };
}
#endif // _GRIC_CONFIGURATOR_HPP_
