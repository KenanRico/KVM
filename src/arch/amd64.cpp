#include <arch/arch.h>
#include <log/log.h>
#include <vector>
#include <stdint.h>

namespace Arch{

	Amd64::Amd64(){
		Log::Message("Initializing Amd64 architecture");
	}

	Amd64::~Amd64(){

	}

	void Amd64::Initialize(const std::vector<uint8_t>& content, int start, int end){

	}
}
