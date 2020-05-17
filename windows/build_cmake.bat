pushd bin
del *.* /F /Q
popd
cmake -G "MinGW Makefiles" ..
cmake --build .
move SomethingVM.exe bin/
