//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedBlockControl.hpp"

gric::LedBlockControl::LedBlockControl(ms_t v1, const LedBlock& v2):
     poll_period(v1),
     block(v2)
{
     return;
}
