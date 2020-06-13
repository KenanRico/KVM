#ifndef Sys_H
#define Sys_H


namespace Sys{

	//TODO: change to constexpr later
	const int _UNIX = 1;
	const int _WINDOWS = 2;
	const int _ZOS = 3;

	class Unix;
}


namespace Sys{

	//behaviors specific to UNIX os
	class Unix{
		public:
			Unix();
			~Unix();
			Unix(const Unix&) = delete;
			Unix& operator=(const Unix&) = delete;
	};

}


#endif
