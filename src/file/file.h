#ifndef FILE_H
#define FILE_H


#include <stdint.h>
#include <vector>

#include <log/log.h>
#include <util/bits.h>


namespace File{

	// file format numbers
	// TODO: change to constexpr later
	constexpr int _ELF32 = 1;
	constexpr int _ELF64 = 2;

}


#endif
