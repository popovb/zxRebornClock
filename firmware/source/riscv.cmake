set(CMAKE_SYSTEM_NAME Generic)

set(TOOL_BIN           "/home/boris/RISC/gcc/bin")

set(CMAKE_C_COMPILER   "${TOOL_BIN}/riscv-none-elf-gcc")
set(CMAKE_CXX_COMPILER "${TOOL_BIN}/riscv-none-elf-g++")
set(OBJCOPY            "${TOOL_BIN}/riscv-none-elf-objcopy")
set(OBJDUMP            "${TOOL_BIN}/riscv-none-elf-objdump")
set(SIZE               "${TOOL_BIN}/riscv-none-elf-size")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
