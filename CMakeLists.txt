cmake_minimum_required(VERSION 2.8)

project(SomethingVM CXX)

set(SRCDIR src)
set(SOURCE
	${SRCDIR}/main.cpp
	${SRCDIR}/bin.cpp 
	${SRCDIR}/binops.cpp 
	${SRCDIR}/arch/amd64/amd64.cpp
	${SRCDIR}/sys/unix/unix.cpp
	${SRCDIR}/fformat/elf64/elf64.cpp
	${SRCDIR}/log/log.cpp
)

include_directories(${SRCDIR})

add_executable(SomethingVM ${SOURCE})
