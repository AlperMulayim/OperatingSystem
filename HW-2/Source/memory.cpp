//
// Created by Alper on 24.04.2017.
//

#include <cstdlib>
#include "memory.h"

OSMemory::OSMemory() {
    mem = (uint8_t*) malloc(0x10000);
    setBaseRegister(0x0000);
    setLimitRegister(0x4000);
}

OSMemory::~OSMemory() {
    free(mem);
}

uint8_t &OSMemory::at(uint32_t ind) {
    if(ind + getBaseRegister() > getLimitRegister()){
        cerr << "Meory out of Bound Illegal OSMemory adress "<<endl;
        cerr <<"ind : "<<ind <<" base : "<<getBaseRegister()<<" limit :"<<getLimitRegister()<<endl;
        exit(0);
    }
    return physicalAt(ind + getBaseRegister());
}

uint8_t &OSMemory::physicalAt(uint32_t ind) {
    return  mem[ind];
}


int OSMemory::getBaseRegister() const {
    return baseRegister;
}

void OSMemory::setBaseRegister(int baseRegisterV) {
    baseRegister = baseRegisterV;
}

int OSMemory::getLimitRegister() const {
    return limitRegister;
}

void OSMemory::setLimitRegister(int limitRegisterV) {
    limitRegister = limitRegisterV;
}




