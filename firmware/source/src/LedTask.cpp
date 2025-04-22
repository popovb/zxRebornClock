//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedTask.hpp"

gric::LedTask::LedTask(LedTaskMode::mode_t v):
     mode(v)
{
     return;
}

gric::LedTask::LedTask(LedTaskMode::mode_t v1,
		       const LedTaskTime& v2):
     mode(v1),
     time(v2)
{
     return;
}
