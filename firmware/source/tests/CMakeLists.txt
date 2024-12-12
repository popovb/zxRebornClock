cmake_minimum_required(VERSION 3.18)

project(TESTS)

set(cur_dir     "${CMAKE_CURRENT_SOURCE_DIR}")
set(root_dir    "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(include_dir "${root_dir}/include")
set(src_dir     "${root_dir}/src")
set(vendor_dir  "${root_dir}/vendor")
set(debug_dir   "${root_dir}/debug")

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
set(src_src
  ${src_dir}/McuNetConfig.cpp
  ${src_dir}/Mcu.cpp
  ${src_dir}/PinConf.cpp
  ${src_dir}/PortPin.cpp
  ${src_dir}/PortClockToggler.cpp
  ${src_dir}/RccApb2Holder.cpp
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

#target_include_directories(test PRIVATE
#  "${src_dir}"
#)

target_link_libraries(test PRIVATE
  src
  "${UNITTEST_LIBRARIES}"
#  draw
#  dumb
#  out
)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(test PRIVATE -pipe -g -W -Wall -Wextra)
endif()
###################################################################
