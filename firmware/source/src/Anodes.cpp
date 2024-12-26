//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Anodes.hpp"

gric::Anodes::Anodes(const Mcu& m, const McuNetConfig& mnc) {
     init(m, mnc);
}

void gric::Anodes::init(const Mcu& m, const McuNetConfig& mnc) {
     const auto& a1 = mnc.get(McuNet::SA1);
     init(1, a1);
     const auto& a2 = mnc.get(McuNet::SA2);
     init(2, a2);
     const auto& a3 = mnc.get(McuNet::SA3);
     init(3, a3);
     const auto& a4 = mnc.get(McuNet::SA4);
     init(4, a4);
}

// gric::Anodes::Anodes() {
//      PortB b;
//      pins[0] = b[15];
//      pins[1] = b[14];
//      pins[2] = b[13];
//      pins[3] = b[12];
// }

// void gric::Anodes::setup() const {
//      clear();
// }

void gric::Anodes::clear() const {
     for (u8 i = 0; i < N; i++) pins[i].write(false);
}

void gric::Anodes::set(u8 v) const {
     --v;
     if (v >= N) v = N - 1;
     pins[v].write(true);
}
