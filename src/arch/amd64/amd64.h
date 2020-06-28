#ifndef AMD64_H
#define AMD64_H


#include <vector>
#include <stdint.h>


namespace Arch{
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
			void Initialize(const std::vector<uint8_t>&, int, int);
	};
}


#endif