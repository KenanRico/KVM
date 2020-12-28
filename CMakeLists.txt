cmake_minimum_required(VERSION 2.8)

project(SomethingVM CXX)

set(SRCDIR src)
set(SOURCE
	${SRCDIR}/main.cpp
	${SRCDIR}/executable/bin.cpp 
	${SRCDIR}/executable/binops.cpp 
	${SRCDIR}/isa/amd64/amd64.cpp
	${SRCDIR}/sys/unix/unix.cpp
	${SRCDIR}/file/elf64/elf64.cpp
	${SRCDIR}/log/log.cpp
	${SRCDIR}/memory/memoryregion.cpp
)

include_directories(${SRCDIR})

add_executable(SomethingVM ${SOURCE})
