//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Anodes.hpp"
#include "Cathodes.hpp"
#include "DisplayTime.hpp"
#include "core/DelayerNop.hpp"

#ifndef _GRIC_TUBES_HPP_
#define _GRIC_TUBES_HPP_

namespace gric {

     class Tubes {

     public:
	  Tubes(const DisplayTime&, const Anodes&, const Cathodes&);

	  void display(u8[4]) const;

	  u32 calc_iters_per_second() const;

     private:
	  const DisplayTime& time;
	  const Anodes& as;
	  const Cathodes& cs;

     private:
	  DelayerNop<4'000'000> delay;

     private:
	  void display_1(u8) const;
	  void display_2(u8) const;
	  void display_3(u8) const;
	  void display_4(u8) const;
	  void display_(u8, u8) const;
     };
}
#endif // _GRIC_TUBES_HPP_
