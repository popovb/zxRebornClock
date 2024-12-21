//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRIC_DELAYER_NOP_HPP_
#define _GRIC_DELAYER_NOP_HPP_

///////////////////////////////////////////////////////////////////
namespace gric {

     template<u32 S>
     class DelayerNop {

     public:
	  void ms(u32) const;
	  void us(u32) const;

     private:
	  static constexpr u32 MS = S / 1000;
	  static constexpr u32 US = MS / 1000;
     };
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
template<gric::u32 S>
void gric::DelayerNop<S>::ms(u32 v) const {
     for (u32 i = 0; i < v * MS; i++)
	  __asm__("nop");
}

template<gric::u32 S>
void gric::DelayerNop<S>::us(u32 v) const {
     for (u32 i = 0; i < v * US; i++)
	  __asm__("nop");
}
///////////////////////////////////////////////////////////////////
#endif // _GRIC_DELAYER_NOP_HPP_
