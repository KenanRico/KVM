#ifndef ARCH_H
#define ARCH_H


namespace ARCH{
	//TODO: change these to constexpr later
	const int _AMD64 = 1;
	const int _ARM = 2;			//unsupported atm
	const int _S390X = 3;		//unsupported atm
	const int andmore = 4;		//placeholder
}



namespace ARCH{

	//variables and actions specific to amd64 arch
	class AMD64{
		public:
			AMD64();
			~AMD64();
		private:
			AMD64(const AMD64&) = delete;
			AMD64& operator=(const AMD64&) = delete;
	};

}


#endif
