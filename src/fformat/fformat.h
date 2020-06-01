#ifndef FFORMAT_H
#define FFORMAT_H


namespace FFORMAT{

	//TODO: change to constexpr later
	const int _ELF = 1;

}


namespace FFORMAT{

	class ELF{
		public:
			ELF();
			~ELF();
		private:
			ELF(const ELF&) = delete;
			ELF& operator=(const ELF&) = delete;

	};

}


#endif
