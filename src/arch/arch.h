#ifndef Arch_H
#define Arch_H


#include <vector>
#include <stdint.h>


namespace Arch{
	//TODO: change these to constexpr later
	const int _AMD64 = 1;
	const int _ARM = 2;			//unsupported atm
	const int _S390X = 3;		//unsupported atm
	const int andmore = 4;		//placeholder
}



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
