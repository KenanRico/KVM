#ifndef ELF_64_H
#define ELF_64_H

#include <stdint.h>
#include <unordered_map>


namespace Fformat{
	class Elf64{
		private:
		class SectionHeaderEntry{
			//private:
			public:
				uint32_t name;
				uint32_t type;
				uint64_t flags;
				uint64_t addr;
				uint64_t offset;
				uint64_t size;
				uint32_t link;
				uint32_t info;
				uint64_t addralign;
				uint64_t entsize;
			public:
				SectionHeaderEntry(){}
		};
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
			std::unordered_map<std::string, SectionHeaderEntry> section_table_entries;
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