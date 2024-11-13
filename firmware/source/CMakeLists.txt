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
#-imultilib rv32imac_xw/ilp32
#################################################################

#################################################################
set(vendor_src
  ${vendor_dir}/ch32x035_adc.c
  ${vendor_dir}/ch32x035_dma.c
  ${vendor_dir}/ch32x035_gpio.c
  ${vendor_dir}/ch32x035_misc.c
  ${vendor_dir}/ch32x035_rcc.c
  ${vendor_dir}/ch32x035_usart.c
  ${vendor_dir}/ch32x035_awu.c
  ${vendor_dir}/ch32x035_exti.c
  ${vendor_dir}/ch32x035_i2c.c
  ${vendor_dir}/ch32x035_opa.c
  ${vendor_dir}/ch32x035_spi.c
  ${vendor_dir}/ch32x035_wwdg.c
  ${vendor_dir}/ch32x035_dbgmcu.c
  ${vendor_dir}/ch32x035_flash.c
  ${vendor_dir}/ch32x035_iwdg.c
  ${vendor_dir}/ch32x035_pwr.c
  ${vendor_dir}/ch32x035_tim.c
  ${vendor_dir}/core_riscv.c
  ${vendor_dir}/startup_ch32x035.S
  ${debug_dir}/debug.c
)

add_library(vendor
  ${vendor_src}
)

target_include_directories(vendor PUBLIC
  "${vendor_dir}"
  "${debug_dir}"
)

target_compile_options(vendor PRIVATE
  ${FLAGS}
)
#################################################################

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
