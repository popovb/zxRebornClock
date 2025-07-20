//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "core/Types.hpp"

#ifndef _GRIC_ESP_RECEIVE_BUFFER_HPP_
#define _GRIC_ESP_RECEIVE_BUFFER_HPP_

namespace gric {

     class EspReceiveBuffer {

     public:
	  EspReceiveBuffer();

	  void put(char);

	  bool completed(u8) const;
	  bool ok() const;
	  bool no_ap() const;

	  void reset();

	  const char* get() const;

     private:
	  static constexpr const int size = 128;
	  char buffer[size];
	  u8 ndx;
	  u8 cr;
     };
}
#endif // _GRIC_ESP_RECEIVE_BUFFER_HPP_
