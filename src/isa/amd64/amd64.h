#ifndef AMD64_H
#define AMD64_H


#include <vector>
#include <array>
#include <stdint.h>


#define MEM_SIZE 4194304 // 4MB


namespace ISA{
	//variables and actions specific to amd64 arch
	class Amd64{
		private:
			//registers
			//memory
			//instruction
		public:
			Amd64();
			~Amd64();
			Amd64(const Amd64&) = delete;
			Amd64& operator=(const Amd64&) = delete;
	};
}


#endif
