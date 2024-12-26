//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Cathodes.hpp"

gric::Cathodes::Cathodes(const Mcu& m, const McuNetConfig& mnc) {
     init(m, mnc);
     clear();
}
/*
  КАТОД 1  -> PA2
  КАТОД 2  -> PA3
  КАТОД 3  -> PA4
  КАТОД 4  -> PA5
  КАТОД 5  -> PA6
  КАТОД 6  -> PA7
  КАТОД 7  -> PB0
  КАТОД 8  -> PB1
  КАТОД 9  -> PB10
  КАТОД 0  -> PB11
 */
// gric::Cathodes::Cathodes() {
//      PortA a;
//      PortB b;
//      pins[0] = b[11];
//      pins[1] = a[2];
//      pins[2] = a[3];
//      pins[3] = a[4];
//      pins[4] = a[5];
//      pins[5] = a[6];
//      pins[6] = a[7];
//      pins[7] = b[0];
//      pins[8] = b[1];
//      pins[9] = b[10];
// }

// void gric::Cathodes::setup() const {
//      clear();
// }

void gric::Cathodes::clear() const {
     for (u8 i = 0; i < N; i++) pins[i].write(false);
}

void gric::Cathodes::set(u8 v) const {
     if (v >= N) v = N - 1;
     pins[v].write(true);
}
