#ifndef FFORMAT_H
#define FFORMAT_H


#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include <unordered_map>

#include <log/log.h>


namespace Fformat{

	//TODO: change to constexpr later
	const int _ELF32 = 1;
	const int _ELF64 = 2;

}


namespace Fformat{
	template<typename T>
	T ToIntegral(const std::vector<uint8_t>& content, int first, int last){
		size_t size = last-first+1;
		if(size != sizeof(T)){
			Log::Error("Size discrepancy in ToIntegral");
			return 0;
		}
		T integral = 0;
		for(size_t i=0; i<size; ++i){
			integral |= content[first+i] << i*8;
		}
		return integral;
	}
}


namespace Fformat{
	class Elf32{};
}


namespace Fformat{
	class Elf64{
		private:
			struct {
				uint64_t start;
				uint16_t entry_size;
				uint16_t entry_number;
			} ph;
			struct {
				uint64_t start;
				uint16_t entry_size;
				uint16_t entry_number;
				uint16_t name_section_index;
			} sh;
			std::unordered_map<std::string, uint64_t> section_offset_table;
		public:
			enum class Position: size_t {
				TYPE = 16,
				ARCH = 18,
			};
		public:
			Elf64(const std::vector<uint8_t>&);
			~Elf64();
			Elf64() = delete;
			Elf64(const Elf64&) = delete;
			Elf64& operator=(const Elf64&) = delete;
	};
}


#endif
