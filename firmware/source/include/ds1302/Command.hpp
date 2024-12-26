//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Target.hpp"
#include "Direction.hpp"
#include "Register.hpp"

#ifndef _DS1302_COMMAND_HPP_
#define _DS1302_COMMAND_HPP_

namespace ds1302 {

     class Command {

     public:
	  Command(Register::reg_t,
		  Target::target_t,
		  Direction::dir_t);

	  u8 get_byte() const;

     private:
	  const Register::reg_t reg;
	  const Target::target_t trgt;
	  const Direction::dir_t dir;
     };
}
#endif // _DS1302_COMMAND_HPP_
