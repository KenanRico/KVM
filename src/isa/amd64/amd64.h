#ifndef AMD64_H
#define AMD64_H


#include <vector>
#include <stdint.h>


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
		public:
			void GenerateCode(const std::vector<uint8_t>&, uint64_t, uint64_t);
			void GenerateData(const std::vector<uint8_t>&, uint64_t, uint64_t);
			void GenerateROData(const std::vector<uint8_t>&, uint64_t, uint64_t);
	};
}


#endif
