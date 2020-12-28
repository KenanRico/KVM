#include <executable/binops.h>
#include <isa/isa.h>
#include <isa/amd64/amd64.h>
#include <file/file.h>
#include <file/elf64/elf64.h>
#include <sys/sys.h>
#include <sys/unix/unix.h>
#include <log/log.h>
#include <executable/executable.h>

#include <iostream>
#include <memory>
#include <stdint.h>




int main(int argc, const char** argv){

	if(argc!=2){
		Log::Error("Please provide executable name");
		exit(-1);
	}

	std::string exefile = argv[1];
	int format, isa, sys = 0;
	std::vector<uint8_t> content = CheckABI(exefile, &format, &isa, &sys);
	if(content.size()==0){
		Log::Error("Cannot load bin file");
		exit(-1);
	}

	std::unique_ptr<Bin> exe = nullptr;
	if(format==File::_ELF64 && isa==ISA::_AMD64 && sys==Sys::_UNIX){
		exe = CreateExecutable<File::Elf64, ISA::Amd64, Sys::Unix>(content);
	}else{
		//everything else is unimplemented
	}
	if(exe==nullptr){
		Log::Error("Failed to retrieve execution envivronments from file");
		exit(-1);
	}

	exe->PrintMemory();

	exe->Run();


	return 0;
}
