#ifndef UNIX_H
#define UNIX_H


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