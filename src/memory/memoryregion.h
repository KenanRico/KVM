#ifndef MEMORY_REGION_H
#define MEMORY_REGION_H

#include <stdint.h>
#include <vector>
#include <string>

class MemoryRegion{
    public:
        std::string name;
        uint64_t start;
        uint64_t end;
        uint64_t size;
        std::vector<uint8_t> content;

        MemoryRegion() = delete;
        MemoryRegion(const std::string&, uint64_t, uint64_t);
        ~MemoryRegion();
        MemoryRegion(const MemoryRegion&);
        MemoryRegion& operator=(const MemoryRegion&);

        bool Copy(const std::vector<uint8_t>&, uint64_t, uint64_t);
};


#endif
