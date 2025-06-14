//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Esp12f.hpp"

gric::Esp12f::Esp12f(const Mcu& m, const McuNetConfig& mnc) {
     init_pin(m, mnc);
     init_uart(m, mnc);
}
