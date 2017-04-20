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

void ProcessTableEntry::setFilename(const string &filename) {
    ProcessTableEntry::filename = filename;
}

int ProcessTableEntry::getPID() const {
    return PID;
}

void ProcessTableEntry::setPID(int PID) {
    ProcessTableEntry::PID = PID;
}

int ProcessTableEntry::getParentPID() const {
    return parentPID;
}

void ProcessTableEntry::setParentPID(int parentPID) {
    ProcessTableEntry::parentPID = parentPID;
}

int ProcessTableEntry::getBaseRegister() const {
    return baseRegister;
}

void ProcessTableEntry::setBaseRegister(int baseRegister) {
    ProcessTableEntry::baseRegister = baseRegister;
}

int ProcessTableEntry::getLimitRegister() const {
    return limitRegister;
}

void ProcessTableEntry::setLimitRegister(int limitRegister) {
    ProcessTableEntry::limitRegister = limitRegister;
}

int ProcessTableEntry::getStartCycle() const {
    return startCycle;
}

void ProcessTableEntry::setStartCycle(int startCycle) {
    ProcessTableEntry::startCycle = startCycle;
}

int ProcessTableEntry::getProcessCycle() const {
    return processCycle;
}

void ProcessTableEntry::setProcessCycle(int processCycle) {
    ProcessTableEntry::processCycle = processCycle;
}

int ProcessTableEntry::getStateOfProcess() const {
    return stateOfProcess;
}

void ProcessTableEntry::setStateOfProcess(int stateOfProcess) {
    ProcessTableEntry::stateOfProcess = stateOfProcess;
}

int ProcessTableEntry::getThePhysicalAdress() const {
    return thePhysicalAdress;
}

void ProcessTableEntry::setThePhysicalAdress(int thePhysicalAdress) {
    ProcessTableEntry::thePhysicalAdress = thePhysicalAdress;
}

const State8080 &ProcessTableEntry::getChipRegisters() const {
    return chipRegisters;
}

void ProcessTableEntry::setChipRegisters(const State8080 &chipRegisters) {
    ProcessTableEntry::chipRegisters = chipRegisters;
}
