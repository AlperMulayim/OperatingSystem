//
// Created by Alper on 20.04.2017.
//

#include "ProcessTable.h"


ProcessTable::ProcessTable(int givenPID) {
    this->givenPID = givenPID;
}

int ProcessTable::getWorkingPID() const {
    return workingPID;
}

void ProcessTable::setWorkingPID(int workingPIDV) {
    workingPID = workingPIDV;
}

void ProcessTable::addProcess(ProcessTableEntry process) {
    processList.push_back(process);
}

ProcessTableEntry ProcessTable::getProcess(ProcessTableEntry process) {
    int processNum = isInTable(process);
    if(processNum != -1){
        return processList.at(processNum);
    }
}

int  ProcessTable::isInTable(ProcessTableEntry process) {
    int result = -1;

    for(int i = 0 ; i < processList.size(); ++i){
        if((processList[i].getFilename() == process.getFilename()) &&
                (processList[i].getPID() == process.getPID())){
            result  = i;
        }
    }
    return  result;
}

int ProcessTable::getNumOfProcess() {
    return  processList.size();
}

bool ProcessTable::removeTheProcess(ProcessTableEntry process) {
    int processNum = isInTable(process);

    if(processNum != -1){
        processList.erase(processList.begin() + processNum);
    }
}

void ProcessTable::setGivenPID() {
    givenPID = givenPID + 1;
}

int ProcessTable::generatePID() {
    setGivenPID();
    return givenPID;
}

ProcessTableEntry ProcessTable::getProcessByID(int pid) {

    ProcessTableEntry proc("NOT PROCESS");
    proc.setPID(-1);
    for(int i = 0 ; i< processList.size(); ++i){
        if(processList[i].getPID() == pid){
            return processList[i];
        }
    }
    return  proc;
}

void ProcessTable::printProcessTable() {
    cout <<"-------PROCESS TABLE-------"<<endl;
    for(int i = 0; i<processList.size();++i){
        cout << "Process ("<<i <<")"<<endl;
        cout <<"------------------------------"<<endl;
        processList[i].printProcessEntry();
    }
}

