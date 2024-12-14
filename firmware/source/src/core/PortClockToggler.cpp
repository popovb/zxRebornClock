//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/PortClockToggler.hpp"
#include "RccApb2Holder.hpp"

#ifndef UNITTEST
#include "ch32x035.h"
#endif

gric::PortClockToggler::PortClockToggler():
     state{ false, }
{
     return;
}

bool gric::PortClockToggler::is_on(PortName::name_t v) const {
     return state[v];
}

bool gric::PortClockToggler::is_off(PortName::name_t v) const {
     return !state[v];
}

#ifdef UNITTEST
void gric::PortClockToggler::on(PortName::name_t v) {
     state[v] = true;
}

void gric::PortClockToggler::off(PortName::name_t v) {
     state[v] = false;
}
#else
void gric::PortClockToggler::on(PortName::name_t v) {
     RccApb2Holder rah;
     RCC_APB2PeriphClockCmd(rah.get(v), ENABLE);
     state[v] = true;
}

void gric::PortClockToggler::off(PortName::name_t v) {
     RccApb2Holder rah;
     RCC_APB2PeriphClockCmd(rah.get(v), DISABLE);
     state[v] = false;
}
#endif
