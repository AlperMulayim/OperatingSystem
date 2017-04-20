//
// Created by Alper on 20.04.2017.
//

#include <cstdlib>
#include "memoryOS.h"

MemoryOS::MemoryOS() {
    osMemory = (uint8_t*) malloc(0x65536);
    virtualMem = (uint8_t*) malloc(0x16348);
}

MemoryOS::~MemoryOS() {
    free(osMemory);
    free(virtualMem);
}

