#include "elf64.h"

#include <file/file.h>
#include <log/log.h>
#include <runtime/engine.h>
#include <runtime/memoryregion.h>

#include <cstring>
#include <iostream>
#include <unordered_map>

namespace File{

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
		/* using the name section index, locate the offset of name section, retrieve
		indices of names of interest (.text, .data, .rodata, etc..) */
		uint64_t name_section_offset = ToIntegral<uint64_t>(
			content,
			sh.start+sh.entry_size*sh.name_section_index+24,
			sh.start+sh.entry_size*sh.name_section_index+31
		);
		for(uint16_t i=0; i<sh.entry_number; ++i){
			uint64_t entryoffset = sh.start+sh.entry_size*i;
			SectionHeaderEntry she;
			she.name = ToIntegral<uint32_t>(
				content, entryoffset, entryoffset+3
			);
			she.addr = ToIntegral<uint64_t>(content, entryoffset+16, entryoffset+23);
			she.offset = ToIntegral<uint64_t>(content, entryoffset+24, entryoffset+31);
			she.size = ToIntegral<uint64_t>(content, entryoffset+32, entryoffset+39);
			std::string name = (char*)&content[name_section_offset+she.name];
			section_table_entries.insert({name, she});
		}
	}

	Elf64::~Elf64(){

	}

	uint64_t Elf64::StartOf(const std::string& section) const {
		return section_table_entries.at(section).offset;
	}

	uint64_t Elf64::AddrOf(const std::string& section) const {
		return section_table_entries.at(section).addr;
	}

	uint64_t Elf64::SizeOf(const std::string& section) const {
		return section_table_entries.at(section).size;
	}

	void Elf64::MapMemory(RuntimeEngine* engine, const std::vector<uint8_t>& content) const {
		for(std::unordered_map<std::string, SectionHeaderEntry>::const_iterator i=section_table_entries.begin(); i!=section_table_entries.end(); ++i){
			const std::string& name = i->first;
			const SectionHeaderEntry& she = i->second;
			if(she.addr==0){
				continue;
			}
			MemoryRegion mr(name, she.addr, she.addr+she.size-1);
			if(mr.Copy(content, she.offset, she.size)){
				engine->AddMemRegion(mr);
			}else{
				Log::Error("Failed to add memory region");
			}
		}
	}

	void Elf64::PrintLayout() const {
		for(std::unordered_map<std::string, SectionHeaderEntry>::const_iterator i=section_table_entries.begin(); i!=section_table_entries.end(); ++i){
			Log::Debugf("%s : ", i->first.data());
			Log::Debugf("in-memory address = %lu, offset = %lu, size = %lu\n", i->second.addr, i->second.offset, i->second.size);
		}
	}

}


