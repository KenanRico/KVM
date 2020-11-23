#include "engine.h"
#include "memoryregion.h"

#include <log/log.h>



RuntimeEngine::RuntimeEngine(){

}

RuntimeEngine::~RuntimeEngine(){

}

void RuntimeEngine::Run(){
    // This is where the guest program actually starts executing
}

void RuntimeEngine::AddMemRegion(const MemoryRegion& mr){
    memory.insert({mr.name, mr});
}


void RuntimeEngine::PrintMemory() const{
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