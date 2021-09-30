#include "amd64.h"
#include <log/log.h>

#include <vector>
#include <stdint.h>

namespace ISA{

	Amd64::Amd64(){
		Log::Message("Initializing Amd64 architecture");
		InitInstructionTable();
	}

	Amd64::~Amd64(){

	}

	Amd64::Instruction Amd64::Dispatch(const std::vector<uint8_t>& content) const {

		Instruction instruction;

		uint64_t pc = registers[static_cast<size_t>(RegCode::PC)];
		// check for REX prefix
		if(content[pc]==0x48){
			instruction.prefix = 0x48
			++pc;
		}
		// assign opcode
		instruction.opcode = ??
		// assign size
		instruction.size = ??
		// assign bytes
		instruction.bytes = ??

		return instruction;
	}

	uint64_t Amd64::GetRegister(RegCode i){
		return registers.at(static_cast<size_t>(i));
	}

	void Amd64::SetRegister(RegCode i, uint64_t v){
		registers.at(static_cast<size_t>(i)) = v;
	}


	void Amd64::Execute(const Instruction& inst){
		//uint64_t opcode = ...;
		//InstFuncPtrAmd64 instruction = instructions[opcode];
		//instruction(inst);
		//uint64_t result = (this->*instructions[opcode])(inst.bytes);
	}

}
