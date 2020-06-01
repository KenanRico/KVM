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
		LOG::Error("Please provide executable name");
		exit(-1);
	}

	std::string exefile = argv[1];
	int format, arch, sys = 0;
	std::vector<uint8_t> content = CheckABI(exefile, &format, &arch, &sys);
	if(content.size()==0){
		LOG::Error("Cannot load bin file");
		exit(-1);
	}

	std::unique_ptr<Bin> exe = nullptr;
	if(format==FFORMAT::_ELF && arch==ARCH::_AMD64 && sys==SYS::_UNIX){
		exe = CreateExecutable<FFORMAT::ELF, ARCH::AMD64, SYS::UNIX>(content);
	}else{
		//everything else is unimplemented
	}
	if(exe==nullptr){
		LOG::Error("Failed to retrieve execution envivronments from file");
		exit(-1);
	}

	exe->Run();

	return 0;
}
