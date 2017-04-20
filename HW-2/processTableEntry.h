//
// Created by Alper on 20.04.2017.
//

#ifndef GTUOSPROCESS_PROCESSTABLEENTRY_H
#define GTUOSPROCESS_PROCESSTABLEENTRY_H

#include <iostream>
#include <string.h>
#include "8080emuCPP.h"

using namespace std;
class ProcessTableEntry {
    private:
        string filename;
        int PID;
        int parentPID;
        int baseRegister;
        int limitRegister;
        int startCycle;
        int processCycle;
        int stateOfProcess;
        int thePhysicalAdress;
        State8080 chipRegisters;
public :
    ProcessTableEntry(string filename);

    const string &getFilename() const;

    void setFilename(const string &filename);

    int getPID() const;

    void setPID(int PID);

    int getParentPID() const;

    void setParentPID(int parentPID);

    int getBaseRegister() const;

    void setBaseRegister(int baseRegister);

    int getLimitRegister() const;

    void setLimitRegister(int limitRegister);

    int getStartCycle() const;

    void setStartCycle(int startCycle);

    int getProcessCycle() const;

    void setProcessCycle(int processCycle);

    int getStateOfProcess() const;

    void setStateOfProcess(int stateOfProcess);

    int getThePhysicalAdress() const;

    void setThePhysicalAdress(int thePhysicalAdress);

    const State8080 &getChipRegisters() const;

    void setChipRegisters(const State8080 &chipRegisters);
};


#endif //GTUOSPROCESS_PROCESSTABLEENTRY_H
