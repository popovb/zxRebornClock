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
	  static constexpr const char* time =
	       "AT+CIPSNTPTIME?\r\n";
	  static constexpr const char* uart_def =
	       "AT+UART_DEF?\r\n";
     };
}
#endif // _GRIC_ESP_COMMAND_HPP_
