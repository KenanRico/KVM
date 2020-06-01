#ifndef SYS_H
#define SYS_H


namespace SYS{

	//TODO: change to constexpr later
	const int _UNIX = 1;
	const int _WINDOWS = 2;
	const int _ZOS = 3;

	class UNIX;
}


namespace SYS{

	//behaviors specific to UNIX os
	class UNIX{
		public:
			UNIX();
			~UNIX();
		private:
			UNIX(const UNIX&) = delete;
			UNIX& operator=(const UNIX&) = delete;
	};

}


#endif
