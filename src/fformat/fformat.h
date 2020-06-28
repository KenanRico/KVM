#ifndef FFORMAT_H
#define FFORMAT_H


#include <stdint.h>
#include <vector>

#include <log/log.h>


namespace Fformat{

	// file format numbers
	// TODO: change to constexpr later
	constexpr int _ELF32 = 1;
	constexpr int _ELF64 = 2;

	// util functions
	template<typename T>
	T ToIntegral(const std::vector<uint8_t>& content, int first, int last){
		size_t size = last-first+1;
		if(size != sizeof(T)){
			Log::Error("Size discrepancy in ToIntegral");
			return 0;
		}
		T integral = 0;
		for(size_t i=0; i<size; ++i){
			integral |= content[first+i] << i*8;
		}
		return integral;
	}

}


#endif