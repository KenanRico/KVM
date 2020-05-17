#include "exe.h"

#include <string>
#include <vector>
#include <fstream>



Exe::Exe(const char* _fn): fn(_fn), type(FF_INVALID){
	GetContent();
}

Exe::~Exe(){

}

void Exe::GetContent(){
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
		//TODO: report error
	}
}

std::vector<uint8_t>& Exe::Content(){
	return content;
}
