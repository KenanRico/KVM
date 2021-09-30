#ifndef AMD64_H
#define AMD64_H


#include <vector>
#include <array>
#include <stdint.h>
#include <unordered_map>


#define MEM_SIZE 4194304 // 4MB


namespace ISA{

	class Amd64;

	using InstFuncPtrAmd64 = uint64_t(Amd64::*)(const std::vector<uint8_t>&);

	//variables and actions specific to amd64 arch
	class Amd64{
		public:
			enum class RegCode: size_t{
				RAX = 0,
				RCX = 1,
				RDX = 2,
				RBX = 3,
				RSP = 4,
				RBP = 5,
				RSI = 6,
				RDI = 7,
				R8 = 8,
				R9 = 9,
				R10 = 10,
				R11 = 11,
				R12 = 12,
				R13 = 13,
				R14 = 14,
				R15 = 15,
				PC = 16
			};
			struct Instruction{
				std::vector<uint8_t> prefix;
				std::vector<uint8_t> opcode;
				std::vector<uint8_t> modrm;
				std::vector<uint8_t> sib;
				std::vector<uint8_t> displacement;
				std::vector<uint8_t> immediate;
				int size;
				std::vector<uint8_t> bytes;
			};
		 private:
			//registers
			std::array<uint64_t, 17> registers;
			//memory
			//instruction
			std::unordered_map<uint64_t, InstFuncPtrAmd64> instructions;
		private:
			uint64_t XOR(const std::vector<uint8_t>&);
		public:
			Amd64();
			~Amd64();
			Amd64(const Amd64&) = delete;
			Amd64& operator=(const Amd64&) = delete;

			uint64_t GetRegister(RegCode);
			void SetRegister(RegCode, uint64_t);
			Instruction Dispatch(const std::vector<uint8_t>&) const;
			bool IsSyscall(const Instruction&);
			void Execute(const Instruction&);
	};
}


#endif
