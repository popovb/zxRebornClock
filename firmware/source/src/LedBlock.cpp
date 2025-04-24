//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedBlock.hpp"

gric::LedBlock::LedBlock(const Mcu& m, const McuNetConfig& c):
     led{
	  Led(0, 0),
	  Led(0, 0),
	  Led(0, 0),
	  Led(0, 0),
     }
{
     init(m, c);
}

void gric::LedBlock::init(const Mcu& mcu,
			  const McuNetConfig& mnc) {
     init(0, mcu, mnc.get(McuNet::L_RED));
     init(1, mcu, mnc.get(McuNet::L_YELLOW));
     init(2, mcu, mnc.get(McuNet::L_GREEN));
     init(3, mcu, mnc.get(McuNet::L_BLUE));
}

void gric::LedBlock::init(u8 i, const Mcu& mcu, const PortPinConf& ppc) {
     led[i] = mcu.get(LedConf(ppc.port, ppc.pin));
}
