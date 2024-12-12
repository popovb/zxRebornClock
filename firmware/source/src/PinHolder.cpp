//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PinHolder.hpp"
#include "ch32x035.h"

///////////////////////////////////////////////////////////////////
const gric::u32
gric::PinHolder::pins[] = {
     GPIO_Pin_0,
     GPIO_Pin_1,
     GPIO_Pin_2,
     GPIO_Pin_3,
     GPIO_Pin_4,
     GPIO_Pin_5,
     GPIO_Pin_6,
     GPIO_Pin_7,
     GPIO_Pin_8,
     GPIO_Pin_9,
     GPIO_Pin_10,
     GPIO_Pin_11,
     GPIO_Pin_12,
     GPIO_Pin_13,
     GPIO_Pin_14,
     GPIO_Pin_15,
     GPIO_Pin_16,
     GPIO_Pin_17,
     GPIO_Pin_18,
     GPIO_Pin_19,
     GPIO_Pin_20,
     GPIO_Pin_21,
     GPIO_Pin_22,
     GPIO_Pin_23,
};
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
gric::u32 gric::PinHolder::get(pin_t v) const {
     if (v >= len) v = len - 1;
     return pins[v];
}
///////////////////////////////////////////////////////////////////
