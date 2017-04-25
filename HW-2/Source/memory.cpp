//
// Created by Alper on 24.04.2017.
//

#include <cstdlib>
#include "memory.h"


memory::memory() {
    mem = (uint8_t*) malloc(0x1000000);
}

memory::~memory() {
    free(mem);
}

uint8_t &memory::at(uint32_t ind) {
    return mem[ind ];
}

uint8_t &memory::physicalAt(uint32_t ind) {
    return mem[ind];
}


int memory::getBaseRegister() const {
    return baseRegister;
}

void memory::setBaseRegister(int baseRegister) {
    memory::baseRegister = baseRegister;
}

int memory::getLimitRegister() const {
    return limitRegister;
}

void memory::setLimitRegister(int limitRegister) {
    memory::limitRegister = limitRegister;
}

