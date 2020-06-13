#include "log.h"

#include <string>
#include <iostream>


namespace Log{

	void Message(const std::string& str){
		std::cout<<"Message: "<<str<<"\n";
	}

	void Warning(const std::string& str){
		std::cout<<"Warning: "<<str<<"\n";
	}

	void Error(const std::string& str){
		std::cout<<"Error: "<<str<<"\n";
	}

}
