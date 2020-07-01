#ifndef EXECUTABLE_H
#define EXECUTABLE_H


#include <bin.h>

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
		void Run() override;
	private:

};


/*
 * Constructor default initializes system; initializes ISA based on file content
 */
template<typename _FILE, typename _ISA, typename _SYS>
Executable<_FILE, _ISA, _SYS>::Executable(const std::vector<uint8_t>& content):
Bin(content),
file(content){
	//arch.Initialize(content, some_positions_in_elf_that_mark_sections);
	isa.GenerateCode(content, file.StartOf(".text"), file.SizeOf(".text"));
	isa.GenerateData(content, file.StartOf(".data"), file.SizeOf(".data"));
	isa.GenerateROData(content, file.StartOf(".rodata"), file.SizeOf(".rodata"));
}


template<typename _FILE, typename _ISA, typename _SYS>
Executable<_FILE, _ISA, _SYS>::~Executable(){

}


template<typename _FILE, typename _ISA, typename _SYS>
void Executable<_FILE, _ISA, _SYS>::Run(){
	/*
	// Dispatch loop
	while(sys.State()!=_SYS::State::HALT){
		const _ISA::Instruction& inst = arch.NextInstruction();
		if(inst.Opcode()==_SYS::Opcode::INTERRUPT){
			sys.MakeSyscall(...);
		}else{
			arch.Execute(...);
		}
	}
	*/
}


#endif
