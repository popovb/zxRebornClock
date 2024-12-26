//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_DIGIT_EXTRACTOR_HPP_
#define _GRIC_DIGIT_EXTRACTOR_HPP_

///////////////////////////////////////////////////////////////////
namespace gric {

     template<u8 N>
     class DigitExtractor {

     public:
	  void extract(u8[N], u32) const;

     private:
	  void clear(u8[N]) const;
     };
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
template<gric::u8 N>
void gric::DigitExtractor<N>::extract(u8 v[N], u32 vin) const {
     clear(v);
     for (u8 i = 0; i < N; i++) {
	  v[i] = vin % 10;
	  vin = vin / 10;
     }
}

template<gric::u8 N>
void gric::DigitExtractor<N>::clear(u8 v[N]) const {
     for (u8 i = 0; i < N; i++) v[i] = 0;
}
///////////////////////////////////////////////////////////////////
#endif // _GRIC_DIGIT_EXTRACTOR_HPP_
