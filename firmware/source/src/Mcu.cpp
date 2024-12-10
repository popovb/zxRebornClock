//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Mcu.hpp"

#ifndef UNITTEST
#include "ch32x035.h"
#endif

gric::Mcu::Mcu() {
     init();
}

void gric::Mcu::init() const {
     nvic_config();
     clock_update();
}

#ifdef    UNITTEST

void gric::Mcu::nvic_config() const {
     return;
}

void gric::Mcu::clock_update() const {
     return;
}

#else //  UNITTEST

void gric::Mcu::nvic_config() const {
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
}

void gric::Mcu::clock_update() const {
     SystemCoreClockUpdate();
}

#endif // UNITTEST
