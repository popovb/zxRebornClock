//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Time.hpp"

#ifndef _GRIC_TIME_CHECKER_HPP_
#define _GRIC_TIME_CHECKER_HPP_

namespace gric {

     class TimeChecker {

     public:
	  void put(const Time&);
	  operator bool() const;

     private:
	  Time prev;
	  Time curr;

     private:
	  bool check_if_eq_hour() const;
	  bool check_if_ne_hour() const;
     };
}
#endif // _GRIC_TIME_CHECKER_HPP_
