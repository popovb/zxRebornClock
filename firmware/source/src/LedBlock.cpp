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
