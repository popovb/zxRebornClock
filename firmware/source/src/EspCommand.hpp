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
	  static constexpr const char* station_mode =
	       "AT+CWMODE=1\r\n";
	  static constexpr const char* end =
	       "\r\n";
	  static constexpr const char* ap =
	       "AT+CWJAP_CUR";
	  static constexpr const char* ap_test =
	       "AT+CWJAP_CUR?\r\n";
	  static constexpr const char* ntp_cfg =
	       "AT+CIPSNTPCFG=1,0\r\n";
     public:
	  static void build_ap(char*, const char*, const char*);
     };
}
#endif // _GRIC_ESP_COMMAND_HPP_
