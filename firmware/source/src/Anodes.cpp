//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Anodes.hpp"

gric::Anodes::Anodes(const Mcu& m, const McuNetConfig& mnc) {
     init(m, mnc);
     clear();
}

void gric::Anodes::init(const Mcu& m, const McuNetConfig& mnc) {
     const auto& a1 = mnc.get(McuNet::SA1);
     init(0, a1, m);
     const auto& a2 = mnc.get(McuNet::SA2);
     init(1, a2, m);
     const auto& a3 = mnc.get(McuNet::SA3);
     init(2, a3, m);
     const auto& a4 = mnc.get(McuNet::SA4);
     init(3, a4, m);
}

void gric::Anodes::init(u8 i, const PortPinConf& ppc,
			const Mcu& mcu) {
     pins[i] = mcu.get(ppc);
}

void gric::Anodes::clear() const {
     for (u8 i = 0; i < N; i++) pins[i].write(false);
}

void gric::Anodes::set(u8 v) const {
     --v;
     if (v >= N) v = N - 1;
     pins[v].write(true);
}

void gric::Anodes::clear(u8 v) const {
     --v;
     if (v >= N) v = N - 1;
     pins[v].write(false);
}
