//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#ifndef _GRIC_ESP_COMMAND_HPP_
#define _GRIC_ESP_COMMAND_HPP_

namespace gric {

     class EspCommand {

     public:
	  static constexpr const char* at =
	       "AT\r\n";
	  static constexpr const char* uart_def =
	       "AT+UART_DEF?\r\n";

	  static constexpr const char* echo_off =
	       "ATE0\r\n";
     };
}
#endif // _GRIC_ESP_COMMAND_HPP_
