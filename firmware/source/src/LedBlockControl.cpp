//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedBlockControl.hpp"

gric::LedBlockControl::LedBlockControl(ms_t v1, const LedBlock& v2):
     poll_period(v1),
     block(v2),
     on_start{true, true, true, true,}
{
     return;
}

void gric::LedBlockControl::poll() const {
     for (u8 i = 0; i < len; i++) {
	  auto& t = task[i];
	  if (! t) continue;
	  poll(i);
     }
}

void gric::LedBlockControl::poll(u8 i) const {
     if (on_start[i]) return poll_start(i);
     poll_continue(i);
}
