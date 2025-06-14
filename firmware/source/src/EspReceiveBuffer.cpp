//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "EspReceiveBuffer.hpp"

void gric::EspReceiveBuffer::clean() {
     for (int i = 0; i < size; i++) buffer[i] = '\0';
}
