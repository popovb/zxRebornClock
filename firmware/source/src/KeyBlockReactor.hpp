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
	  KeyBlockReactor(const LedBlockControl&,
			  const Rtc&);

	  void handle(const KeyBlockEvent&) const;

     private:
	  const LedBlockControl& lbc;
	  const Rtc& rtc;
     };
}
#endif // _GRIC_KEY_BLOCK_REACTOR_HPP_
