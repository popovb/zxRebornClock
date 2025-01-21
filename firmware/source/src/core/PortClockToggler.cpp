//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/PortClockToggler.hpp"
#include "RccApb2Holder.hpp"
#include "RccUsartHolder.hpp"

#ifndef UNITTEST
#include "ch32x035.h"
#endif

gric::PortClockToggler::PortClockToggler():
     port_state{ false, },
     uart_state{ false, }
{
     return;
}

bool gric::PortClockToggler::is_on(PortName::name_t v) const {
     return port_state[v];
}

bool gric::PortClockToggler::is_off(PortName::name_t v) const {
     return !port_state[v];
}

bool gric::PortClockToggler::is_on(UartName::name_t v) const {
     return uart_state[v];
}

bool gric::PortClockToggler::is_off(UartName::name_t v) const {
     return !uart_state[v];
}

#ifdef UNITTEST
void gric::PortClockToggler::on(PortName::name_t v) {
     port_state[v] = true;
}

void gric::PortClockToggler::off(PortName::name_t v) {
     port_state[v] = false;
}

void gric::PortClockToggler::on(UartName::name_t v) {
     uart_state[v] = true;
}

void gric::PortClockToggler::off(UartName::name_t v) {
     uart_state[v] = false;
}
#else
void gric::PortClockToggler::on(PortName::name_t v) {
     RccApb2Holder rah;
     RCC_APB2PeriphClockCmd(rah.get(v), ENABLE);
     port_state[v] = true;
}

void gric::PortClockToggler::off(PortName::name_t v) {
     RccApb2Holder rah;
     RCC_APB2PeriphClockCmd(rah.get(v), DISABLE);
     port_state[v] = false;
}

void gric::PortClockToggler::on(UartName::name_t v) {
     RccUsartHolder rah;
     RCC_APB1PeriphClockCmd(rah.get(v), ENABLE);
     uart_state[v] = true;
}

void gric::PortClockToggler::off(UartName::name_t v) {
     RccUsartHolder rah;
     RCC_APB1PeriphClockCmd(rah.get(v), DISABLE);
     uart_state[v] = false;
}
#endif
