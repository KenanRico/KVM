#ifndef ENGINE_H
#define ENGINE_H

#include "memoryregion.h"

#include <stdint.h>
#include <array>
#include <unordered_map>

class RuntimeEngine{
    private:
        std::unordered_map<std::string, MemoryRegion> memory;
    public:
        RuntimeEngine();
        ~RuntimeEngine();
        RuntimeEngine(const RuntimeEngine&) = delete;
        RuntimeEngine& operator=(const RuntimeEngine&) = delete;
    public:
        void Run();
        void AddMemRegion(const MemoryRegion&);

        //debug
        void PrintMemory() const;
};

#endif