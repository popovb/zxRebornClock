//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#ifndef _GRIC_ESP_RECEIVE_BUFFER_HPP_
#define _GRIC_ESP_RECEIVE_BUFFER_HPP_

namespace gric {

     class EspReceiveBuffer {

     public:
	  static constexpr const int size = 32;
	  char buffer[32];
     };
}
#endif // _GRIC_ESP_RECEIVE_BUFFER_HPP_
