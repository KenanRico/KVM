#include "amd64.h"
#include <log/log.h>

#include <vector>
#include <stdint.h>

namespace ISA{

	Amd64::Amd64(){
		Log::Message("Initializing Amd64 architecture");
	}

	Amd64::~Amd64(){

	}

	void Amd64::GenerateCode(const std::vector<uint8_t>& content, uint64_t start, uint64_t size){
		// print each instruction for debug
		Log::Debugf(".text section size = %lu bytes", size, nullptr);
		uint64_t end = start+size;
		for(uint64_t i=start; i<end; i+=8){
			Log::Debugf("%d %d %d %d %d %d %d %d", content[i+7], content[i+6], content[i+5], content[i+4], content[i+3], content[i+2], content[i+1], content[i], nullptr);
		}
	}

	void Amd64::GenerateData(const std::vector<uint8_t>& content, uint64_t start, uint64_t size){

	}

	void Amd64::GenerateROData(const std::vector<uint8_t>& content, uint64_t start, uint64_t size){

	}

}
