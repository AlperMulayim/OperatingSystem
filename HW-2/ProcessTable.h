//
// Created by Alper on 20.04.2017.
//

#ifndef GTUOSPROCESS_PROCESSTABLE_H
#define GTUOSPROCESS_PROCESSTABLE_H


#include <vector>
#include "processTableEntry.h"

class ProcessTable {
    private:
        vector<ProcessTableEntry> processList;
    public:
        void addProcess(ProcessTableEntry process);
        ProcessTableEntry getProcess(ProcessTableEntry process);
        bool removeTheProcess(ProcessTableEntry proces);
        int getNumOfProcess();
        int isInTable(ProcessTableEntry process);
};


#endif //GTUOSPROCESS_PROCESSTABLE_H
