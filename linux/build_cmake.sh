sed -i 's/\r$//' build_cmake.sh
rm bin/*
cmake ..
cmake --build .
mv SomethingVM bin/
