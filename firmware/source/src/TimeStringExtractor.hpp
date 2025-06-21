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

	  bool extract_to(u8, u8, u8) const;
     };
}
#endif // _GRIC_TIME_STRING_EXTRACTOR_HPP_
