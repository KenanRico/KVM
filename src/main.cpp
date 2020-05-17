#include "bin.h"

#include <iostream>




int main(int argc, const char** argv){
	if(argc!=2){
		//TODO: need better logging
		std::cout<<"Please provide executable name\n";
		exit(-1);
	}
	Bin exe(argv[1]);

	return 0;
}
