#ifndef BIN_H
#define BIN_H

#include <runtime/engine.h>

#include <vector>
#include <stdint.h>


class Bin{
	protected:
		std::vector<uint8_t> content;
	public:
		Bin(const std::vector<uint8_t>&);
		virtual ~Bin();
		Bin() = delete;
		Bin(const Bin&) = delete;
		Bin& operator=(const Bin&) = delete;

	public:
		virtual void MapMemory(RuntimeEngine*) = 0;
};


#endif
