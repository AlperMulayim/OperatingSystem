//
// Created by Alper on 24.04.2017.
//

#include <cstdlib>
#include "memory.h"

memory::memory() {
    mem = (uint8_t*) malloc(0x10000);
    setBaseRegister(0x0000);
    setLimitRegister(0x4000);
}

memory::~memory() {
    free(mem);
}

uint8_t &memory::at(uint32_t ind) {
    if(ind + getBaseRegister() > getLimitRegister()){
        cerr << "Meory out of Bound Illegal Memory adress "<<endl;
        cerr <<"ind : "<<ind <<" base : "<<getBaseRegister()<<" limit :"<<getLimitRegister()<<endl;
        exit(0);
    }
    return physicalAt(ind + getBaseRegister());
}

uint8_t &memory::physicalAt(uint32_t ind) {
    return  mem[ind];
}


int memory::getBaseRegister() const {
    return baseRegister;
}

void memory::setBaseRegister(int baseRegisterV) {
    baseRegister = baseRegisterV;
}

int memory::getLimitRegister() const {
    return limitRegister;
}

void memory::setLimitRegister(int limitRegisterV) {
    limitRegister = limitRegisterV;
}


