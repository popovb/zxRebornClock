//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Delayer.hpp"
#include "debug.h"

gric::Delayer::Delayer() {
     Delay_Init();
}

void gric::Delayer::ms(u32 n) const {
     Delay_Ms(n);
}

void gric::Delayer::us(u32 n) const {
     Delay_Us(n);
}
