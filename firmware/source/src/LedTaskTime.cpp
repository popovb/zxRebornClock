//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedTaskTime.hpp"

gric::LedTaskTime::LedTaskTime():
     on(1000),
     off(1000)
{
     return;
}

gric::LedTaskTime::LedTaskTime(ms_t v):
     on(v),
     off(v)
{
     return;
}

gric::LedTaskTime::LedTaskTime(ms_t v1, ms_t v2):
     on(v1),
     off(v2)
{
     return;
}
