//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "KeyBlock.hpp"

gric::KeyBlock::KeyBlock(const Mcu& m, const McuNetConfig& c):
     h(4, 101),
     m(4, 101),
     s(4, 101),
     f(4, 101)
{
     init(m, c);
}

void gric::KeyBlock::init(const Mcu& mcu,
			  const McuNetConfig& mnc) {
     init(h, mcu, mnc.get(McuNet::B_HH));
     init(m, mcu, mnc.get(McuNet::B_MM));
     init(s, mcu, mnc.get(McuNet::B_SS));
     init(f, mcu, mnc.get(McuNet::B_F));
}
/*
void gric::KeyBlock::init(Button& i,
			  const Mcu& mcu,
			  const PortPinConf& ppc) {
     i = mcu.get(ButtonConf(ppc.port, ppc.pin));
}
*/
