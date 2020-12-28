#include "memoryregion.h"

#include <log/log.h>

#include <cstring>



MemoryRegion::MemoryRegion(const std::string& _name, uint64_t _start, uint64_t _end):
name(_name),
start(_start),
end(_end),
size(_end-_start+1){

}

MemoryRegion::~MemoryRegion(){

}

MemoryRegion::MemoryRegion(const MemoryRegion& rhs):
name(rhs.name),
start(rhs.start),
end(rhs.end),
size(rhs.size),
content(rhs.content){

}

MemoryRegion& MemoryRegion::operator=(const MemoryRegion& rhs){
    this->name = rhs.name; 
    this->start = rhs.start; 
    this->end = rhs.end; 
    this->size = rhs.size; 
    this->content = rhs.content; 
    return *this;
}

bool MemoryRegion::Copy(const std::vector<uint8_t>& c, uint64_t offset, uint64_t sz){
    if(this->size!=sz){
        return false;
    }
    content.resize(sz);
    // TODO: Currently directly copying; If endianess needs to be reversed in memory, do it here
    std::memcpy(content.data(), c.data()+offset, sz);
    return true;
}