cmake_minimum_required(VERSION 3.18)

project(zxRebornClock)

enable_language(ASM)

#################################################################
set(cur_dir     "${CMAKE_CURRENT_SOURCE_DIR}")
set(src_dir     "${cur_dir}/src")
set(vendor_dir  "${cur_dir}/vendor")
set(ld_dir      "${cur_dir}/ld")
set(include_dir "${cur_dir}/include")
set(debug_dir   "${src_dir}/debug")
#################################################################

#################################################################
set(FLAGS
  -g
  -W
  -Wall
  -Wextra
  -Wunused
  -Wuninitialized
  -march=rv32imacxw
  -mabi=ilp32
  -msmall-data-limit=8
  -msave-restore
  -misa-spec=2.2
  -march=rv32imac_xw
  -Os
  -fmessage-length=0
  -fsigned-char
  -ffunction-sections
  -fdata-sections
  -fno-common
)  
#################################################################

#-imultilib rv32imac_xw/ilp32
#
# TODO
#

#################################################################
add_custom_command(TARGET ${name}.elf POST_BUILD
  COMMAND ${SIZE} --format=berkley ${name}.elf
  COMMENT "Print size")

add_custom_command(TARGET ${name}.elf POST_BUILD
  COMMAND ${OBJCOPY} -O ihex ${name}.elf  ${name}.hex
  COMMENT "Creating HEX")

add_custom_command(TARGET ${name}.elf POST_BUILD
  COMMAND ${OBJCOPY} -O binary ${name}.elf  ${name}.bin
  COMMENT "Creating BIN")

add_custom_command(TARGET ${name}.elf POST_BUILD
  COMMAND ${OBJDUMP} --all-headers
  --demangle --disassemble -M xw ${name}.elf > ${name}.lst
  COMMENT "Disassembling")
#################################################################
