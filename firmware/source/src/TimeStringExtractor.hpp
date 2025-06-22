//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_TIME_STRING_EXTRACTOR_HPP_
#define _GRIC_TIME_STRING_EXTRACTOR_HPP_

namespace gric {

     class TimeStringExtractor {

     public:
	  TimeStringExtractor(const char*);

	  bool extract_to(u8&, u8&, u8&) const;

     private:
	  const char* str;

     private:
	  u8 find_cr_2() const;
	  u16 load_year(u8, u8&) const;
	  u8 load_second(u8&) const;
	  u8 load_minute(u8&) const;
	  u8 load_hour(u8&) const;
	  u8 find_rev(u8, char) const;
     };
}
#endif // _GRIC_TIME_STRING_EXTRACTOR_HPP_
