if [ ! -d  build ]; then
	mkdir build
fi

cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../toolchain_arm-none-eabi.cmake
cmake --build .
