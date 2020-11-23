#ifndef EXECUTABLE_H
#define EXECUTABLE_H


#include "bin.h"

#include <runtime/engine.h>

#include <vector>
#include <stdint.h>


template<typename _FILE, typename _ISA, typename _SYS>
class Executable: public Bin{
	private:
		_FILE file;
		_ISA isa;
		_SYS sys;

	private:
		Executable() = delete;
		Executable(const Executable&) = delete;
		Executable& operator=(const Executable&) = delete;
	public:
		Executable(const std::vector<uint8_t>&);
		~Executable();

	public:
		void MapMemory(RuntimeEngine*) override;
	private:

};


/*
 * Constructor default initializes system; initializes ISA based on file content
 */
template<typename _FILE, typename _ISA, typename _SYS>
Executable<_FILE, _ISA, _SYS>::Executable(const std::vector<uint8_t>& content):
Bin(content),
file(content){
}


template<typename _FILE, typename _ISA, typename _SYS>
Executable<_FILE, _ISA, _SYS>::~Executable(){

}


template<typename _FILE, typename _ISA, typename _SYS>
void Executable<_FILE, _ISA, _SYS>::MapMemory(RuntimeEngine* engine){
	file.MapMemory(engine, content);
}


#endif
