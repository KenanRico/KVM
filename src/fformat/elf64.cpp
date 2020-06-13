#include <fformat/fformat.h>
#include <log/log.h>

#include <iostream>
namespace Fformat{

	Elf64::Elf64(const std::vector<uint8_t>& content){
		Log::Message("Initializing 64-bit Elf file format");
		ph.start = ToIntegral<uint64_t>(content, 32, 39);
		ph.entry_size = ToIntegral<uint16_t>(content, 54, 55);
		ph.entry_number = ToIntegral<uint16_t>(content, 56, 57);
		sh.start = ToIntegral<uint64_t>(content, 40, 47);
		sh.entry_size = ToIntegral<uint16_t>(content, 58, 59);
		sh.entry_number = ToIntegral<uint16_t>(content, 60, 61);
	}

	Elf64::~Elf64(){

	}

}


