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

	uint64_t Amd64::GetRegister(RegCode i){
		return registers.at(static_cast<size_t>(i));
	}

	void Amd64::SetRegister(RegCode i, uint64_t v){
		registers.at(static_cast<size_t>(i)) = v;
	}
}
