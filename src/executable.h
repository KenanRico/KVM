#ifndef EXECUTABLE_H
#define EXECUTABLE_H


#include <bin.h>

#include <vector>
#include <stdint.h>



template<typename _FFORMAT, typename _ARCH, typename _SYS>
class Executable: public Bin{
	private:
		struct {
			_FFORMAT fformat;
			_ARCH arch;
			_SYS sys;
		} abi;

	private:
		Executable() = delete;
		Executable(const Executable&) = delete;
		Executable& operator=(const Executable&) = delete;
	public:
		Executable(const std::vector<uint8_t>&);
		~Executable();

	public:
		void Run() override;
	private:

};



template<typename _FFORMAT, typename _ARCH, typename _SYS>
Executable<_FFORMAT, _ARCH, _SYS>::Executable(const std::vector<uint8_t>& content): Bin(content){
	
}


template<typename _FFORMAT, typename _ARCH, typename _SYS>
Executable<_FFORMAT, _ARCH, _SYS>::~Executable(){

}


template<typename _FFORMAT, typename _ARCH, typename _SYS>
void Executable<_FFORMAT, _ARCH, _SYS>::Run(){

}


#endif
