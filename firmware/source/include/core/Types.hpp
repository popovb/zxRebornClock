//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include <cstdint>

#ifndef _GRIC_TYPES_HPP_
#define _GRIC_TYPES_HPP_

namespace gric {

     using u8    = std::uint8_t;
     using u16   = std::uint16_t;
     using u32   = std::uint32_t;

     using i8    = std::int8_t;

     using pin_t   = u8;
     using speed_t = u32;

     using ms_t = u32;
}
#endif // _GRIC_TYPES_HPP_
