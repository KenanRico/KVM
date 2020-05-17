cmake_minimum_required(VERSION 2.8)

project(SomethingVM CXX)

set(SRCDIR src)
set(SOURCE ${SRCDIR}/main.cpp ${SRCDIR}/exe.cpp)

add_executable(SomethingVM ${SOURCE})
