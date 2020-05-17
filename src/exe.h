#ifndef EXE_H
#define EXE_H

#include <vector>
#include <string>
#include <stdint.h>


#define FF_INVALID 0
#define FF_ELF 1


class Exe{
	private:
		uint8_t type;
		std::string fn;
		std::vector<uint8_t> content;
	
	public:
		Exe(const char*);
		~Exe();

		std::vector<uint8_t>& Content();

	private:
		Exe() = delete;
		Exe(const Exe&) = delete;
		Exe& operator=(const Exe&) = delete;

		void GetContent();
	
};

#endif
