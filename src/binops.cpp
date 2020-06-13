#include <binops.h>
#include <bin.h>
#include <arch/arch.h>
#include <fformat/fformat.h>
#include <sys/sys.h>
#include <log/log.h>

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <stdint.h>
#include <stdlib.h>




//TODO: modify this function to use move semantics to return vector
std::vector<uint8_t> CheckABI(const std::string& fn, int* fformat, int* arch, int* sys){

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
	if(content.at(static_cast<size_t>(16))!=2){
		return {};
	}

	/* parse content for file format, then use that to get arch and sys */
	if(content[1]=='E' && content[2]=='L' && content[3]=='F'){
		if(content[4]==1){
			*fformat = Fformat::_ELF32;
		}
		if(content[4]==2){
			*fformat = Fformat::_ELF64;
		}
	}else{
		//unimplemented
	}
	switch(*fformat){
		case Fformat::_ELF32:
		case Fformat::_ELF64:
			*sys = Sys::_UNIX;
			switch(content[static_cast<size_t>(18)]){
				case 0x3e:
					*arch = Arch::_AMD64;
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

