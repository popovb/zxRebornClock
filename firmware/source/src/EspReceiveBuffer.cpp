//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "EspReceiveBuffer.hpp"

gric::EspReceiveBuffer::EspReceiveBuffer() {
     clean();
}

void gric::EspReceiveBuffer::clean() {
     ndx = 0;
     cr = 0;
     for (int i = 0; i < size; i++) buffer[i] = '\0';
}

void gric::EspReceiveBuffer::put(char v) {
     buffer[ndx++] = v;
     if (v == '\r') ++cr;
     // if (ndx == (size - 2)) return;
     // ++ndx;
}

bool gric::EspReceiveBuffer::completed() const {
     return (cr == 3);
}
