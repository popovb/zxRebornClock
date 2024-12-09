cmake_minimum_required(VERSION 3.18)

project(TESTS)

set(cur_dir     "${CMAKE_CURRENT_SOURCE_DIR}")
set(root_dir    "${CMAKE_CURRENT_SOURCE_DIR}/..")
#set(include_dir "${root_dir}/include")
set(src_dir     "${root_dir}/src")
#set(ds1302_dir  "${src_dir}/ds1302")

list(APPEND CMAKE_MODULE_PATH "${cur_dir}/cmake")
find_package(UnitTest++ REQUIRED)

###################################################################
#set(ds1302_src
#  ${ds1302_dir}/Command.cpp
#  ${ds1302_dir}/Data.cpp
#  ${ds1302_dir}/Seconds.cpp
#  ${ds1302_dir}/Minutes.cpp
#  ${ds1302_dir}/Hour.cpp
#  ${ds1302_dir}/Date.cpp
#  ${ds1302_dir}/Month.cpp
#  ${ds1302_dir}/Day.cpp
#  ${ds1302_dir}/Year.cpp
#  ${ds1302_dir}/WriteProtect.cpp
#)
#
#add_library(ds1302
#  ${ds1302_src}
#)
#
#target_include_directories(ds1302 PUBLIC
#  "${include_dir}"
#)
#
#if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
#  target_compile_options(ds1302 PRIVATE -pipe -g -W -Wall -Wextra)
#endif()
###################################################################

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
#  ds1302
  "${UNITTEST_LIBRARIES}"
#  draw
#  dumb
#  out
)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(test PRIVATE -pipe -g -W -Wall -Wextra)
endif()
###################################################################
