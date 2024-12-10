//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Mcu.hpp"

gric::Mcu::Mcu() {
     init();
}

void gric::Mcu::init() const {
     nvic_config();
     clock_update();
}
