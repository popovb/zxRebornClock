//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#ifndef _GRIC_ESP_RECEIVE_BUFFER_HPP_
#define _GRIC_ESP_RECEIVE_BUFFER_HPP_

namespace gric {

     class EspReceiveBuffer {

     public:
	  static constexpr const int size = 232;
	  char buffer[size];

     public:
	  void clean();
     };
}
#endif // _GRIC_ESP_RECEIVE_BUFFER_HPP_
