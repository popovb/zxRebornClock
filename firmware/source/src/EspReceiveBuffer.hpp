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

	  static constexpr const int size = 128;
	  char buffer[size];

	  void put(char);
	  bool completed() const;

     public:
	  void clean();

     private:
	  u8 ndx;
	  u8 cr;
     };
}
#endif // _GRIC_ESP_RECEIVE_BUFFER_HPP_
