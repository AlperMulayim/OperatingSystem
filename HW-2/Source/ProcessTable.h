//
// Created by Alper on 20.04.2017.
//

#ifndef GTUOSPROCESS_PROCESSTABLE_H
#define GTUOSPROCESS_PROCESSTABLE_H


#include <vector>
#include "processTableEntry.h"

class ProcessTable {

public:
        ProcessTable(int givenPID);
        int getWorkingPID() const;
        int getGivenLimitRegister();
        void setGivenLimitRegister(int givenLimitRegister);
        int getGivenBaseRegister();
        void setGivenBaseRegister(int givenBaseRegister);
        void setWorkingPID(int workingPID);
        void addProcess(ProcessTableEntry process);
        ProcessTableEntry getProcess(ProcessTableEntry process);
        void setGivenPID();
        bool removeTheProcess(ProcessTableEntry proces);
        int getNumOfProcess();
        int isInTable(ProcessTableEntry process);
        int generatePID();
        void printProcessTable();
        ProcessTableEntry &getProcessByID(int pid);
        ProcessTableEntry &getNextProcess();

private:
        vector<ProcessTableEntry> processList;
        int givenPID;
        int workingPID;
        int givenLimitRegister;
        int givenBaseRegister;

};


#endif //GTUOSPROCESS_PROCESSTABLE_H
