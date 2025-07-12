//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "UartExchanger.hpp"

gric::UartExchanger::UartExchanger(Mcu& v) {
     init_uart(v);
}

void gric::UartExchanger::init_uart(Mcu& m) {
     UartConf uc(UartName::Uart1, 115200);
     m.init(uc);
     uart = m.get(UartName::Uart1);
}
