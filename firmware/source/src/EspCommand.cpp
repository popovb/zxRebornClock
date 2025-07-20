//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "EspCommand.hpp"
#include <cstring>

void gric::EspCommand::build_ap(char* b,
				const char* a,
				const char* pass) {
     int ndx = 0;
     strcpy(&b[ndx], ap);
     ndx = strlen(b);

     strcpy(&b[ndx], "=\"");
     ndx = strlen(b);

     strcpy(&b[ndx], a);
     ndx = strlen(b);

     strcpy(&b[ndx], "\",\"");
     ndx = strlen(b);

     strcpy(&b[ndx], pass);
     ndx = strlen(b);

     strcpy(&b[ndx], "\"");
     ndx = strlen(b);

     strcpy(&b[ndx], end);
}
