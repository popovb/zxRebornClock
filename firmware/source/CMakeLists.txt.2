cmake_minimum_required(VERSION 3.10)

project(test)

enable_language(ASM)

set(cur_dir    "${CMAKE_CURRENT_SOURCE_DIR}")
set(root       "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(src_dir    "${root}/user")
set(debug_dir  "${root}/debug")
set(vendor_dir "${root}/vendor")
set(ld_dir     "${root}/ld")

set(name "MyBlink")

file(GLOB src    "${src_dir}/*.c")
file(GLOB debug  "${debug_dir}/*.c")
file(GLOB vendor "${vendor_dir}/*.c")

add_executable(${name}.elf
  ${vendor}
  ${src}
  ${debug}
  ${vendor_dir}/startup_ch32x035.S
)

set(FLAGS
  -g
  -march=rv32imac_xw
  -mabi=ilp32
  -msmall-data-limit=8
  -mno-save-restore
  -Os
  -fmessage-length=0
  -fsigned-char
  -ffunction-sections
  -fdata-sections
)  

target_compile_options(${name}.elf PUBLIC
  ${FLAGS}
)

target_include_directories(${name}.elf PUBLIC
  "${vendor_dir}"
  "${src_dir}"
  "${debug_dir}"
)

target_link_options(${name}.elf PUBLIC
  ${FLAGS}
  -T ${ld_dir}/Link.ld
  -nostartfiles
  -Xlinker
  --gc-sections
  -Wl,-Map,${name}.map
  --specs=nano.specs
  --specs=nosys.specs
)

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
