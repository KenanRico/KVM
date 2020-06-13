#ifndef EXECUTABLE_H
#define EXECUTABLE_H


#include <bin.h>

#include <vector>
#include <stdint.h>


template<typename _FFORMAT, typename _ARCH, typename _SYS>
class Executable: public Bin{
	private:
		_FFORMAT fformat;
		_ARCH arch;
		_SYS sys;

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


/*
 * Constructor default initializes system; initializes ISA based on file content
 */
template<typename _FFORMAT, typename _ARCH, typename _SYS>
Executable<_FFORMAT, _ARCH, _SYS>::Executable(const std::vector<uint8_t>& content):
Bin(content),
fformat(content){
	//arch.Initialize(content, some_positions_in_elf_that_mark_sections);
}


template<typename _FFORMAT, typename _ARCH, typename _SYS>
Executable<_FFORMAT, _ARCH, _SYS>::~Executable(){

}


template<typename _FFORMAT, typename _ARCH, typename _SYS>
void Executable<_FFORMAT, _ARCH, _SYS>::Run(){
	/*
	// Dispatch loop
	while(sys.State()!=_SYS::State::HALT){
		const _ARCH::Instruction& inst = arch.NextInstruction();
		if(inst.Opcode()==_SYS::Opcode::INTERRUPT){
			sys.MakeSyscall(...);
		}else{
			arch.Execute(...);
		}
	}
	*/
}


#endif