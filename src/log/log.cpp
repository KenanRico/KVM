#include "log.h"

#include <string>
#include <iostream>
#include <cstdarg>


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

	void Debugf(const char* fmt...){
		va_list args;
		va_start(args, fmt);
		while(*fmt!='\0'){
			if(*fmt=='%'){
				switch(*(++fmt)){
					case 'd':
						std::cout<<va_arg(args, int);
						break;
					case 'c':
						std::cout<<static_cast<char>(va_arg(args, int));
						break;
					case 'l':
						if(*(fmt+1)=='u'){
							++fmt;
							std::cout<<va_arg(args, unsigned long long);
						}else{
							std::cout<<va_arg(args, long long);
						}
						break;
					default:
						break;
				}
			}else{
				std::cout<<*fmt;
			}
			++fmt;
		}
		std::cout<<"\n";
	}

}
