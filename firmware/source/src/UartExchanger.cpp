//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "UartExchanger.hpp"

gric::UartExchanger::UartExchanger(Mcu& v) {
     init_uart(v);
}
