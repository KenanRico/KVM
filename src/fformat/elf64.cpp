#include <fformat/fformat.h>
#include <log/log.h>

#include <iostream>
namespace Fformat{

	Elf64::Elf64(const std::vector<uint8_t>& content){
		Log::Message("Initializing 64-bit Elf file format");
		// program header and section header values
		ph.start = ToIntegral<uint64_t>(content, 32, 39);
		ph.entry_size = ToIntegral<uint16_t>(content, 54, 55);
		ph.entry_number = ToIntegral<uint16_t>(content, 56, 57);
		sh.start = ToIntegral<uint64_t>(content, 40, 47);
		sh.entry_size = ToIntegral<uint16_t>(content, 58, 59);
		sh.entry_number = ToIntegral<uint16_t>(content, 60, 61);
		sh.name_section_index = ToIntegral<uint16_t>(content, 62, 63);
		// declare sections of interest
		section_offset_table.insert(std::make_pair(".text", 0));
		section_offset_table.insert(std::make_pair(".data", 0));
		section_offset_table.insert(std::make_pair(".rodata", 0));
		/* using the name section index, locate the offset of name section, retrieve
		indices of names of interest (.text, .data, .rodata, etc..) */
		uint64_t name_section_start = ToIntegral<uint64_t>(
			content,
			sh.start+sh.entry_size*sh.name_section_index+24,
			sh.start+sh.entry_size*sh.name_section_index+31
		);
		uint16_t i = 0;
		while(i<=sh.entry_number){
			if(content[name_section_start]==0){
				++name_section_start;
				++i;
				std::cout<<"\n";
				continue;
			}
			std::cout<<(char)content[name_section_start];
			++name_section_start;
		}
	}

	Elf64::~Elf64(){

	}

}


