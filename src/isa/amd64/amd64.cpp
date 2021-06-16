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

	Amd64::Instruction Amd64::Dispatch(const std::vector<uint8_t>& content) const {
		//placeholder
		Instruction instruction;
		uint64_t pc = registers[static_cast<size_t>(RegCode::PC)];
		for(int i=0; i<16; ++i){
			uint8_t byte = content[pc+i];
			if(){

			}
		}
		//instruction.
		return instruction;
	}

	uint64_t Amd64::GetRegister(RegCode i){
		return registers.at(static_cast<size_t>(i));
	}

	void Amd64::SetRegister(RegCode i, uint64_t v){
		registers.at(static_cast<size_t>(i)) = v;
	}


	void Amd64::Execute(const Instruction& inst){
		uint64_t opcode = ...;
		InstFuncPtrAmd64 instruction = instructions[opcode];
		instruction(inst);
		uint64_t result = (this->*instructions[opcode])(inst.bytes);
	}

}