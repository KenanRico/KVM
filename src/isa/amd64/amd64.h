#ifndef AMD64_H
#define AMD64_H


#include <vector>
#include <array>
#include <stdint.h>


#define MEM_SIZE 4194304 // 4MB


namespace ISA{
	//variables and actions specific to amd64 arch
	class Amd64{
		public:
			enum class RegCode: size_t{
				RAX = 0,
				RBX = 1,
				RCX = 2,
				RDX = 3,
				RBP = 4,
				RSP = 5,
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
		private:
			//registers
			std::array<uint64_t, 17> registers;
			//memory
			//instruction
		public:
			Amd64();
			~Amd64();
			Amd64(const Amd64&) = delete;
			Amd64& operator=(const Amd64&) = delete;

			uint64_t GetRegister(RegCode);
			void SetRegister(RegCode, uint64_t);
	};
}


#endif
