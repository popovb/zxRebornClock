//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Anodes.hpp"
#include "PortB.hpp"

/*
  АНОД 1 -> PB15
  АНОД 2 -> PB14
  АНОД 3 -> PB13
  АНОД 4 -> PB12
 */
gri::Anodes::Anodes() {
     PortB b;
     pins[0] = b[15];
     pins[1] = b[14];
     pins[2] = b[13];
     pins[3] = b[12];
}

void gri::Anodes::setup() const {
     clear();
}

void gri::Anodes::clear() const {
     for (u8 i = 0; i < N; i++) pins[i].clear();
}

void gri::Anodes::set(u8 v) const {
     --v;
     if (v >= N) v = N - 1;
     pins[v].set();
}
