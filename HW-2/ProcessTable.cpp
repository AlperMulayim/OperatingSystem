//
// Created by Alper on 20.04.2017.
//

#include "ProcessTable.h"


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
