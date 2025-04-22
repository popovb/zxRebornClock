//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedBlock.hpp"

gric::LedBlock::LedBlock(const Mcu& m, const McuNetConfig& c):
     led{
	  { 0, 0 },
	  { 0, 0 },
	  { 0, 0 },
	  { 0, 0 },
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
     // const PortPinConf& rc = mnc.get(McuNet::L_RED);
     // const PortPinConf& ry = mnc.get(McuNet::L_YELLOW);
     // const PortPinConf& rg = mnc.get(McuNet::L_GREEN);
     // const PortPinConf& rb = mnc.get(McuNet::L_BLUE);
     //
     // TODO
     //
