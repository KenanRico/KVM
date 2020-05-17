#ifndef BIN_H
#define BIN_H

#include <vector>
#include <string>
#include <stdint.h>


#define FF_INVALID 0
#define FF_ELF 1


class Bin{
	private:
		uint8_t type;
		std::string fn;
		std::vector<uint8_t> content;
	
	public:
		Bin(const char*);
		~Bin();

		std::vector<uint8_t>& Content();

	private:
		Bin() = delete;
		Bin(const Bin&) = delete;
		Bin& operator=(const Bin&) = delete;

		void GetContent();
	
};

#endif
