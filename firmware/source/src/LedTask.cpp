//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "LedTask.hpp"

gric::LedTask::LedTask():
     mode(LedTaskMode::Off)
{
     return;
}

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

gric::LedTask::operator bool() const {
     return (mode != LedTaskMode::Off);
}
