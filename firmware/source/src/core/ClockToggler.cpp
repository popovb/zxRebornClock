//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/ClockToggler.hpp"
#include "RccPortHolder.hpp"
#include "RccUsartHolder.hpp"

#ifndef UNITTEST
#include "ch32x035.h"
#endif

gric::ClockToggler::ClockToggler():
     port_state{ false, },
     uart_state{ false, }
{
     return;
}

bool gric::ClockToggler::is_on(PortName::name_t v) const {
     return port_state[v];
}

bool gric::ClockToggler::is_off(PortName::name_t v) const {
     return !port_state[v];
}

bool gric::ClockToggler::is_on(UartName::name_t v) const {
     return uart_state[v];
}

bool gric::ClockToggler::is_off(UartName::name_t v) const {
     return !uart_state[v];
}

#ifdef UNITTEST
void gric::ClockToggler::on(PortName::name_t v) {
     port_state[v] = true;
}

void gric::ClockToggler::off(PortName::name_t v) {
     port_state[v] = false;
}

void gric::ClockToggler::on(UartName::name_t v) {
     uart_state[v] = true;
}

void gric::ClockToggler::off(UartName::name_t v) {
     uart_state[v] = false;
}
#else
void gric::ClockToggler::on(PortName::name_t v) {
     RccPortHolder rah;
     RCC_APB2PeriphClockCmd(rah.get(v), ENABLE);
     port_state[v] = true;
}

void gric::ClockToggler::off(PortName::name_t v) {
     RccPortHolder rah;
     RCC_APB2PeriphClockCmd(rah.get(v), DISABLE);
     port_state[v] = false;
}

void gric::ClockToggler::on(UartName::name_t v) {
     RccUsartHolder rah;
     RCC_APB1PeriphClockCmd(rah.get(v), ENABLE);
     uart_state[v] = true;
}

void gric::ClockToggler::off(UartName::name_t v) {
     RccUsartHolder rah;
     RCC_APB1PeriphClockCmd(rah.get(v), DISABLE);
     uart_state[v] = false;
}
#endif
