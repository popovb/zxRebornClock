//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedBlockControl.hpp"

gric::LedBlockControl::LedBlockControl(ms_t v1, LedBlock& v2):
     poll_period(v1),
     block(v2),
     on_start{false, false, false, false,},
     on_time{0, 0, 0, 0,},
     off_time{0, 0, 0, 0,},
     repeat{0, 0, 0, 0,}
{
     return;
}

void gric::LedBlockControl::set(LedColor::color_t i, const LedTask& v) {
     task[i] = v;
     on_start[i] = true;
     on_time[i] = v.time.on;
     off_time[i] = v.time.off;
     repeat[i] = v.repeat;
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
     on_time[i] -= poll_period;
     if (on_time[i] > 0) return;
     block.led[i].off();
}

void gric::LedBlockControl::poll_continue_down(u8 i) {
     off_time[i] -= poll_period;
     if (off_time[i] > 0) return;
     --repeat[i];

     switch (task[i].mode) {

     case LedTaskMode::Limit:
	  if (repeat[i] != 0) return poll_restart(i);
	  task[i].mode = LedTaskMode::Off;
	  break;

     case LedTaskMode::Unlimit:
	  return poll_restart(i);

     default:
	  break;
     }
}

void gric::LedBlockControl::poll_restart(u8 i) {
     block.led[i].on();
     on_time[i] = task[i].time.on;
     off_time[i] = task[i].time.off;
}
