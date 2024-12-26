//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Cathodes.hpp"

gric::Cathodes::Cathodes(const Mcu& m, const McuNetConfig& mnc) {
     init(m, mnc);
     clear();
}

void gric::Cathodes::init(const Mcu& m, const McuNetConfig& mnc) {
     const auto& k0 = mnc.get(McuNet::K0);
     init(0, k0, m);

     const auto& k1 = mnc.get(McuNet::K1);
     init(1, k1, m);

     const auto& k2 = mnc.get(McuNet::K2);
     init(2, k2, m);

     const auto& k3 = mnc.get(McuNet::K3);
     init(3, k3, m);

     const auto& k4 = mnc.get(McuNet::K4);
     init(4, k4, m);

     const auto& k5 = mnc.get(McuNet::K5);
     init(5, k5, m);

     const auto& k6 = mnc.get(McuNet::K6);
     init(6, k6, m);

     const auto& k7 = mnc.get(McuNet::K7);
     init(7, k7, m);

     const auto& k8 = mnc.get(McuNet::K8);
     init(8, k8, m);

     const auto& k9 = mnc.get(McuNet::K9);
     init(9, k9, m);
}

void gric::Cathodes::init(u8 i, const PortPinConf& ppc, const Mcu& mcu) {
     pins[i] = mcu.get(ppc);
}

void gric::Cathodes::clear() const {
     for (u8 i = 0; i < N; i++) pins[i].write(false);
}

void gric::Cathodes::set(u8 v) const {
     if (v >= N) v = N - 1;
     pins[v].write(true);
}
