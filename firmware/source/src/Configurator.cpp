//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Configurator.hpp"

gric::Configurator::Configurator(Mcu& v):
     mcu(v)
{
     return;
}

void gric::Configurator::init(const McuNetConfig& v) const {
     for (u8 i = 0; i < v.size(); i++) {
	  init(v[i]);
     }
}
