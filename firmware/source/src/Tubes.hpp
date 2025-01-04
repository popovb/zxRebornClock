//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Anodes.hpp"
#include "Cathodes.hpp"
#include "core/DelayerNop.hpp"

#ifndef _GRIC_TUBES_HPP_
#define _GRIC_TUBES_HPP_

namespace gric {

     class Tubes {

     public:
	  Tubes(const Anodes&, const Cathodes&);

	  void display(u8[4]) const;

     private:
	  const Anodes& as;
	  const Cathodes& cs;

     private:
	  DelayerNop<4'000'000> delay;
	  static constexpr u16 blank_time_us =
	       900; // 100 - 300 us
	  static constexpr u16 display_time_ms =
	       4; // 1 - 4 ms

     private:
	  void blank() const;
	  void display_1(u8[4]) const;
	  void display_2(u8[4]) const;
	  void display_3(u8[4]) const;
	  void display_4(u8[4]) const;
     };
}
#endif // _GRIC_TUBES_HPP_
