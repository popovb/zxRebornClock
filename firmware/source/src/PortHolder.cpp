//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PortHolder.hpp"

gric::u32 gric::PortHolder::get(PortName::name_t v) const {
     return ports[v];
}
