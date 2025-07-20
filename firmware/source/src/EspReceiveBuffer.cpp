//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "EspReceiveBuffer.hpp"

gric::EspReceiveBuffer::EspReceiveBuffer() {
     reset();
}

void gric::EspReceiveBuffer::reset() {
     ndx = 0;
     cr = 0;
     for (int i = 0; i < size; i++) buffer[i] = '\0';
}

void gric::EspReceiveBuffer::put(char v) {
     buffer[ndx] = v;
     if (v == '\r') ++cr;
     if (ndx == (size - 2)) return;
     ++ndx;
}

bool gric::EspReceiveBuffer::completed(u8 v) const {
     return (cr == v);
}

const char* gric::EspReceiveBuffer::get() const {
     return buffer;
}

bool gric::EspReceiveBuffer::ok() const {
     if (ndx < 8) return false;
     if (buffer[ndx - 2] != 'K') return false;
     if (buffer[ndx - 3] != 'O') return false;
     return true;
}
/*
AT+CWJAP_CUR?
No AP

OK
*/
