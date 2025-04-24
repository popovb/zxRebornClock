//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedBlockControl.hpp"

gric::LedBlockControl::LedBlockControl(ms_t v1, LedBlock& v2):
     poll_period(v1),
     block(v2),
     on_start{true, true, true, true,}
{
     return;
}

void gric::LedBlockControl::poll() {
     for (u8 i = 0; i < len; i++) {
	  auto& t = task[i];
	  if (! t) continue;
	  poll(i);
     }
}

void gric::LedBlockControl::poll(u8 i) {
     if (on_start[i]) return poll_start(i);
     poll_continue(i);
}

void gric::LedBlockControl::poll_start(u8 i) {
     on_start[i] = false;
     block.led[i].on();
}

void gric::LedBlockControl::poll_continue(u8 i) {
     if (block.led[i]) return poll_continue_up(i);
     poll_continue_down(i);
}

void gric::LedBlockControl::poll_continue_up(u8 i) {
     task[i].time.on -= poll_period;
     if (task[i].time.on > 0) return;
     block.led[i].off();
}
