//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedTask.hpp"

gric::LedTask::LedTask():
     mode(LedTaskMode::Off),
     repeat(0)
{
     return;
}

gric::LedTask::LedTask(LedTaskMode::mode_t v):
     mode(v),
     repeat(0)
{
     return;
}

gric::LedTask::LedTask(LedTaskMode::mode_t v1,
		       const LedTaskTime& v2, u32 v3):
     mode(v1),
     time(v2),
     repeat(v3)
{
     return;
}

gric::LedTask::operator bool() const {
     return (mode != LedTaskMode::Off);
}
