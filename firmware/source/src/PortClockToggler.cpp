//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortClockToggler.hpp"

gric::PortClockToggler::PortClockToggler():
     state{ false, }
{
     return;
}

bool gric::PortClockToggler::is_on(PortName::name_t v) const {
     return state[v];
}
