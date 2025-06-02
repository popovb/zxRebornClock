//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "KeyBlockEvent.hpp"
#include "LedBlockControl.hpp"
#include "Rtc.hpp"

#ifndef _GRIC_KEY_BLOCK_REACTOR_HPP_
#define _GRIC_KEY_BLOCK_REACTOR_HPP_

namespace gric {

     class KeyBlockReactor {

     public:
	  KeyBlockReactor(LedBlockControl&,
			  const Rtc&);

	  void handle(const KeyBlockEvent&, u8[4]) const;

     private:
	  LedBlockControl& lbc;
	  const Rtc& rtc;

     private:
	  void hour(KeyEvent::event_t) const;
	  void minute(KeyEvent::event_t) const;
	  void second(KeyEvent::event_t) const;
	  void func(KeyEvent::event_t) const;
     };
}
#endif // _GRIC_KEY_BLOCK_REACTOR_HPP_
