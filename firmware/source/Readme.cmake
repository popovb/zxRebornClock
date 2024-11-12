mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../riscv.cmake ..
make clean; make
