#ifndef EXECUTABLE_H
#define EXECUTABLE_H


#include "bin.h"

#include <memory/memoryregion.h>
#include <log/log.h>

#include <vector>
#include <stdint.h>
#include <unordered_map>


template<typename _FILE, typename _ISA, typename _SYS>
class Executable: public Bin{
	private:
		_FILE file;
		_ISA isa;
		_SYS sys;
		std::unordered_map<std::string, MemoryRegion> memory;

	private:
		Executable() = delete;
		Executable(const Executable&) = delete;
		Executable& operator=(const Executable&) = delete;
	public:
		Executable(const std::vector<uint8_t>&);
		~Executable();

	public:
		void PrintMemory() const override;
		void Run() override;

};


/*
 * Constructor default initializes system; initializes ISA based on file content
 */
template<typename _FILE, typename _ISA, typename _SYS>
Executable<_FILE, _ISA, _SYS>::Executable(const std::vector<uint8_t>& content):
Bin(content),
file(content){
	file.MapMemory(content, &memory);
}


template<typename _FILE, typename _ISA, typename _SYS>
Executable<_FILE, _ISA, _SYS>::~Executable(){

}


template<typename _FILE, typename _ISA, typename _SYS>
void Executable<_FILE, _ISA, _SYS>::PrintMemory() const{
    for(auto i=memory.begin(); i!=memory.end(); ++i){
        const std::string& name = i->first;
        const MemoryRegion& mr = i->second;
        Log::Debugf("%s: starts at %d, ends at %d\n", name.data(), mr.start, mr.end);
        for(size_t j=0; j<mr.content.size(); ++j){
            Log::Debugf("%lu ", mr.content[j]);
        }
        Log::Debugf("\n");
    }
}


template<typename _FILE, typename _ISA, typename _SYS>
void Executable<_FILE, _ISA, _SYS>::Run(){
	//run
	uint64_t entrypoint = file.EntryPointAddr(content);
	Log::Debugf("entrypoint = %lu\n\n\n\n", entrypoint);
	isa.SetRegister(_ISA::RegCode::PC, entrypoint);
	/*
	while(){
		std::vector<uint8_t> inst = isa.Dispatch(content);
		isa.IncPC();
		if(isa.IsSyscall(inst)){
			sys.Call(inst, isa.Registers());
		}else{
			isa.Execute(inst);
		}
	}
	*/
}


#endif