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

     private:
	  static constexpr u16 pause_time   = 3;
	  static constexpr u16 display_time = 2;

     private:
	  void display_1(u8) const;
	  void display_2(u8) const;
	  void display_3(u8) const;
	  void display_4(u8) const;
	  void display_(u8, u8) const;
     };
}
#endif // _GRIC_TUBES_HPP_
