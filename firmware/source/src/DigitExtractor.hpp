//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _GRI_DIGIT_EXTRACTOR_HPP_
#define _GRI_DIGIT_EXTRACTOR_HPP_

///////////////////////////////////////////////////////////////////
namespace gri {

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
template<gri::u8 N>
void gri::DigitExtractor<N>::extract(u8 v[N], u32 vin) const {
     clear(v);
     for (u8 i = 0; i < N; i++) {
	  v[i] = vin % 10;
	  vin = vin / 10;
     }
}

template<gri::u8 N>
void gri::DigitExtractor<N>::clear(u8 v[N]) const {
     for (u8 i = 0; i < N; i++) v[i] = 0;
}
///////////////////////////////////////////////////////////////////
#endif // _GRI_DIGIT_EXTRACTOR_HPP_
