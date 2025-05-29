//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_MCU_NET_HPP_
#define _GRIC_MCU_NET_HPP_

namespace gric {

     class McuNet {

     public:
	  enum net_t : u8 {
	       K1       =  0,
	       K2       =  1,
	       K3       =  2,
	       K4       =  3,
	       K5       =  4,
	       K6       =  5,
	       K7       =  6,
	       K8       =  7,
	       K9       =  8,
	       K0       =  9,

	       SA1      = 10,
	       SA2      = 11,
	       SA3      = 12,
	       SA4      = 13,

	       RTC_CE   = 14,
	       RTC_SCLK = 15,
	       RTC_IO   = 16,

	       L_RED    = 17,
	       L_YELLOW = 18,
	       L_GREEN  = 19,
	       L_BLUE   = 20,

	       B_HH     = 21,
	       B_MM     = 22,
	       B_SS     = 23,
	       B_F      = 24,
	  };
     };
}
#endif // _GRIC_MCU_NET_HPP_
