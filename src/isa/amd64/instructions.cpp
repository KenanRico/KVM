#include "amd64.h"

#include <util/bits.h>

#include <stdint.h>
#include <vector>


namespace ISA{

	void AMD64::InitInstructionTable(){
		this->instrucitons.insert(std::make_pair(???, XOR));
	}


	uint64_t AMD64::XOR(const std::vector<uint8_t>& bytes){
		uint16_t regs = ToIntegral<uint16_t>(bytes, bytes.size()-2, bytes.size()-1)
		uint8_t dest = (regs>>3) & 0x7;
		uint8_t src = regs & 0x7;
		registers[dest] = registers[dest] ^ registers[src];
	}
}
