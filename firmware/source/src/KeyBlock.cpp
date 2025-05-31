//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "KeyBlock.hpp"

gric::KeyBlock::KeyBlock(const Mcu& m, const McuNetConfig& c) {
     init(m, c);
}
/*
void gric::KeyBlock::init(const Mcu& mcu,
			  const McuNetConfig& mnc) {
     init(0, mcu, mnc.get(McuNet::L_RED));
     init(1, mcu, mnc.get(McuNet::L_YELLOW));
     init(2, mcu, mnc.get(McuNet::L_GREEN));
     init(3, mcu, mnc.get(McuNet::L_BLUE));
}

void gric::KeyBlock::init(u8 i, const Mcu& mcu, const PortPinConf& ppc) {
     led[i] = mcu.get(KeyConf(ppc.port, ppc.pin));
}
*/
