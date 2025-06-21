//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Esp12f.hpp"

#ifndef _GRIC_INTERNET_TIME_HPP_
#define _GRIC_INTERNET_TIME_HPP_

namespace gric {

     class InternetTime {

     public:
	  InternetTime(const Esp12f&);

	  void test();

     private:
	  const Esp12f& esp;
     };
}
#endif // _GRIC_INTERNET_TIME_HPP_
