#include "binops.h"
#include "bin.h"

#include <isa/isa.h>
#include <isa/amd64/amd64.h>
#include <file/file.h>
#include <file/elf64/elf64.h>
#include <sys/sys.h>
#include <sys/unix/unix.h>
#include <log/log.h>

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <stdint.h>
#include <stdlib.h>




//TODO: modify this function to use move semantics to return vector
std::vector<uint8_t> CheckABI(const std::string& fn, int* fformat, int* isa, int* sys){

	std::vector<uint8_t> content = {};
	std::ifstream fin;
	fin.open(fn, std::ios::in|std::ios::binary);
	if(fin.is_open()){
		std::streampos start = fin.tellg();
		fin.seekg(0, std::ios::end);
		std::streampos end = fin.tellg();
		fin.seekg(0, std::ios::beg);
		content.resize(static_cast<size_t>(end-start));
		fin.read((char*)content.data(), content.size());
		fin.close();
	}else{
		Log::Error("Cannot open file");
		return {};
	}

	/* if file is not an EXEC, return empty content*/
	if(content.at(16)!=2){
		return {};
	}

	/* parse content for file format, then use that to get isa and sys */
	if(content[1]=='E' && content[2]=='L' && content[3]=='F'){
		if(content[4]==1){
			*fformat = File::_ELF32;
		}
		if(content[4]==2){
			*fformat = File::_ELF64;
		}
	}else{
		//unimplemented
	}
	switch(*fformat){
		case File::_ELF32:
		case File::_ELF64:
			*sys = Sys::_UNIX;
			switch(content[18]){
				case 0x3e:
					*isa = ISA::_AMD64;
					break;
				default:
					//unimplemented
					break;
			}
			break;
		default:
			//unimplemented
			break;
	}

	return content;
}

