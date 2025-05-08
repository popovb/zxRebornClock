//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Anodes.hpp"
#include "Cathodes.hpp"
#include "DisplayTime.hpp"
#include "core/DelayerNop.hpp"
#include "core/Delayer.hpp"

#ifndef _GRIC_TUBES_HPP_
#define _GRIC_TUBES_HPP_

namespace gric {

     class Tubes {

     public:
	  Tubes(DisplayTime&, const Anodes&, const Cathodes&);

	  void display(u8[4]);

     private:
	  DisplayTime& time;
	  const Anodes& as;
	  const Cathodes& cs;

     private:
	  Delayer delay;

     private:
	  void display_1(u8);
	  void display_2(u8);
	  void display_3(u8);
	  void display_4(u8);
	  void display_(u8, u8);
	  void display_delay();
	  void blank_delay();
	  //volatile u32 tt;
     };
}
#endif // _GRIC_TUBES_HPP_
