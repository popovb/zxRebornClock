cmake_minimum_required(VERSION 3.18)

project(TESTS)

set(cur_dir     "${CMAKE_CURRENT_SOURCE_DIR}")
set(root_dir    "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(include_dir "${root_dir}/include")
set(src_dir     "${root_dir}/src")
set(vendor_dir  "${root_dir}/vendor")
set(debug_dir   "${root_dir}/debug")
set(core_dir    "${src_dir}/core")

list(APPEND CMAKE_MODULE_PATH "${cur_dir}/cmake")
find_package(UnitTest++ REQUIRED)

add_compile_definitions(UNITTEST)

###################################################################
#file(GLOB dumb_src "${dumb_dir}/*.cpp")
#
#add_library(dumb
#  ${dumb_src}
#)
#
#target_include_directories(dumb PUBLIC
#  "${include_dir}"
#)
#
#if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
#  target_compile_options(dumb PRIVATE -pipe -g -W -Wall -Wextra)
#endif()
###################################################################

###################################################################
set(core_src
  ${core_dir}/Mcu.cpp
  ${core_dir}/PinConf.cpp
  ${core_dir}/LedConf.cpp
  ${core_dir}/LedPinConf.cpp
  ${core_dir}/PortPin.cpp
  ${core_dir}/PortClockToggler.cpp
  ${core_dir}/RccApb2Holder.cpp
  ${core_dir}/Gpio.cpp
  ${core_dir}/PinHolder.cpp
  ${core_dir}/GpioModeCalc.cpp
  ${core_dir}/PortHolder.cpp
  ${core_dir}/PrintConf.cpp
)

add_library(core
  ${core_src}
)

target_include_directories(core PRIVATE
  "${vendor_dir}"
  "${include_dir}"
  "${debug_dir}"
)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(core PRIVATE -pipe -g -W -Wall -Wextra)
endif()
###################################################################

###################################################################
set(src_src
  ${src_dir}/McuNetConfig.cpp
)

add_library(src
  ${src_src}
)

target_include_directories(src PUBLIC
  "${src_dir}"
  "${vendor_dir}"
  "${include_dir}"
  "${debug_dir}"
)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(src PRIVATE -pipe -g -W -Wall -Wextra)
endif()
###################################################################

###################################################################
set(test_src
  test.cpp
)

add_executable(test
  ${test_src}
)

target_include_directories(test PRIVATE
  "${src_dir}"
)

target_link_libraries(test PRIVATE
  src
  core
  "${UNITTEST_LIBRARIES}"
#  draw
#  dumb
#  out
)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(test PRIVATE -pipe -g -W -Wall -Wextra)
endif()
###################################################################
