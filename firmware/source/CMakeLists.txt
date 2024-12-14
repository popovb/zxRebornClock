cmake_minimum_required(VERSION 3.18)

project(zxRebornClock)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -fabi-version=0")

enable_language(ASM)

#################################################################
set(cur_dir     "${CMAKE_CURRENT_SOURCE_DIR}")
set(src_dir     "${cur_dir}/src")
set(vendor_dir  "${cur_dir}/vendor")
set(ld_dir      "${cur_dir}/ld")
set(include_dir "${cur_dir}/include")
set(debug_dir   "${cur_dir}/debug")
set(core_dir    "${src_dir}/core")
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
  -Os
  -fmessage-length=0
  -fsigned-char
  -ffunction-sections
  -fdata-sections
  -fno-common
)
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
  "${include_dir}"
  "${vendor_dir}"
  "${debug_dir}"
)

target_compile_options(vendor PRIVATE
  ${FLAGS}
)
#################################################################

#################################################################
set(core_src
  ${core_dir}/Delayer.cpp
  ${core_dir}/Mcu.cpp
  ${core_dir}/PortClockToggler.cpp
  ${core_dir}/Gpio.cpp
  ${core_dir}/GpioModeCalc.cpp
  ${core_dir}/PinConf.cpp
  ${core_dir}/PinHolder.cpp
  ${core_dir}/PortHolder.cpp
  ${core_dir}/PortPin.cpp
  ${core_dir}/RccApb2Holder.cpp
)

add_library(core
  ${core_src}
)

target_include_directories(core PRIVATE
  "${include_dir}"
  "${vendor_dir}"
  "${debug_dir}"
)

target_compile_options(core PRIVATE
  ${FLAGS}
)
#################################################################

#################################################################
set(name "zxRebornClock")

set(src
  ${src_dir}/interrupt.c
  ${src_dir}/system_clock.c
  ${src_dir}/main.cpp
)

add_executable(${name}.elf
  ${src}
)

target_link_libraries(${name}.elf PRIVATE
  core
  vendor
)

target_compile_options(${name}.elf PUBLIC
  ${FLAGS}
)

#target_include_directories(${name}.elf PUBLIC
#  "${include_dir}"
#)

target_link_options(${name}.elf PUBLIC
  ${FLAGS}
  -T ${ld_dir}/link.ld
  -nostartfiles
  --specs=nano.specs
  --specs=nosys.specs
  -Xlinker
  --gc-sections
  -Wl,-Map,${name}.map
  -misa-spec=2.2
  -march=rv32imac_xw
  -dumpdir
)
#################################################################

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
