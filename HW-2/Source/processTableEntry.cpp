//
// Created by Alper on 20.04.2017.
//

#include "processTableEntry.h"

ProcessTableEntry::ProcessTableEntry(string filename)
{
    this->filename = filename;
}

const string &ProcessTableEntry::getFilename() const {
    return filename;
}

void ProcessTableEntry::setFilename(const string &filenameV) {
    filename = filenameV;
}

int ProcessTableEntry::getPID() const {
    return PID;
}

void ProcessTableEntry::setPID(int PIDV) {
    PID = PIDV;
}

int ProcessTableEntry::getParentPID() const {
    return parentPID;
}

void ProcessTableEntry::setParentPID(int parentPIDV) {
    parentPID = parentPIDV;
}

int ProcessTableEntry::getBaseRegister() const {
    return baseRegister;
}

void ProcessTableEntry::setBaseRegister(int baseRegisterV) {
    baseRegister = baseRegisterV;
}

int ProcessTableEntry::getLimitRegister() const {
    return limitRegister;
}

void ProcessTableEntry::setLimitRegister(int limitRegisterV) {
    limitRegister = limitRegisterV;
}

int ProcessTableEntry::getStartCycle() const {
    return startCycle;
}

void ProcessTableEntry::setStartCycle(int startCycleV) {
    startCycle = startCycleV;
}

int ProcessTableEntry::getProcessCycle() const {
    return processCycle;
}

void ProcessTableEntry::setProcessCycle(int processCycleV) {
    processCycle = processCycleV;
}

int ProcessTableEntry::getStateOfProcess() const {
    return stateOfProcess;
}

void ProcessTableEntry::setStateOfProcess(int stateOfProcessV) {
    stateOfProcess = stateOfProcessV;
}

int ProcessTableEntry::getThePhysicalAdress() const {
    return thePhysicalAdress;
}

void ProcessTableEntry::setThePhysicalAdress(int thePhysicalAdressV) {
    thePhysicalAdress = thePhysicalAdressV;
}

State8080 ProcessTableEntry::getChipRegisters() const {
    return chipRegisters;
}

void ProcessTableEntry::setChipRegisters(State8080 chipRegistersV) {
    chipRegisters = chipRegistersV;
}

void ProcessTableEntry::printProcessEntry() {
    cout <<"--------Process INFO---------"<<endl;
    cout <<"Name            : " <<getFilename() <<endl;
    cout <<"PID             : " <<getPID() <<endl;
    cout <<"ParentPID       : " <<getParentPID() <<endl;
    //cout <<"Base Register   : "<<getBaseRegister()<<endl;
    //cout <<"Limit Register  : "<<getLimitRegister()<<endl;
    printf("Base Register   : 0x%04x \n",getBaseRegister());
    printf("Limit Register  : 0x%04x \n",getLimitRegister());
    cout <<"Start Cycle     : "<<getStartCycle()<<endl;
    cout <<"Process Cycle   : "<<getProcessCycle()<<endl;
    cout <<"State           : "<<getStateOfProcess()<<endl;
    //cout <<"Physical Adress : "<<getThePhysicalAdress()<<endl;
    printf("Physical Aadres : 0x%04x \n",getThePhysicalAdress());
    cout <<"CPU State : "<<endl;
    printf("A $%02x B $%02x C $%02x D $%02x E $%02x H $%02x L $%02x SP %04x\n", chipRegisters.a, chipRegisters.b, chipRegisters.c,
           chipRegisters.d, chipRegisters.e, chipRegisters.h, chipRegisters.l, chipRegisters.sp);
    cout <<"-------------------------------"<<endl;
}
