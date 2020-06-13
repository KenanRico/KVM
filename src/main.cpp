#include <binops.h>
#include <arch/arch.h>
#include <fformat/fformat.h>
#include <sys/sys.h>
#include <log/log.h>
#include <executable.h>

#include <iostream>
#include <memory>
#include <stdint.h>




int main(int argc, const char** argv){

	if(argc!=2){
		Log::Error("Please provide executable name");
		exit(-1);
	}

	std::string exefile = argv[1];
	int format, arch, sys = 0;
	std::vector<uint8_t> content = CheckABI(exefile, &format, &arch, &sys);
	if(content.size()==0){
		Log::Error("Cannot load bin file");
		exit(-1);
	}

	std::unique_ptr<Bin> exe = nullptr;
	if(format==Fformat::_ELF64 && arch==Arch::_AMD64 && sys==Sys::_UNIX){
		exe = CreateExecutable<Fformat::Elf64, Arch::Amd64, Sys::Unix>(content);
	}else{
		//everything else is unimplemented
	}
	if(exe==nullptr){
		Log::Error("Failed to retrieve execution envivronments from file");
		exit(-1);
	}

	exe->Run();

	return 0;
}
