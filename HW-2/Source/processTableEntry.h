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

    public:
        ProcessTableEntry(string filename);

        const string &getFilename() const;

        void setFilename(const string &filename);

        int getPID() const;

        void setPID(int PIDV);

        int getParentPID() const;

        void setParentPID(int parentPIDV);

        int getBaseRegister() const;

        void setBaseRegister(int baseRegisterV);

        int getLimitRegister() const;

        void setLimitRegister(int limitRegisterV);

        int getStartCycle() const;

        void setStartCycle(int startCycleV);

        int getProcessCycle() const;

        void setProcessCycle(int processCycleV);

        int getStateOfProcess() const;

        void setStateOfProcess(int stateOfProcessV);

        int getThePhysicalAdress() const;

        void setThePhysicalAdress(int thePhysicalAdressV);

        State8080& getChipRegisters() ;

        void setChipRegisters(State8080 chipRegistersV);

        void printProcessEntry();




    private:
        string filename;
        int PID;
        int parentPID;
        int baseRegister;
        uint32_t limitRegister;
        int startCycle;
        int processCycle;
        int stateOfProcess;
        int thePhysicalAdress;
        State8080 chipRegisters;

};
#endif //GTUOSPROCESS_PROCESSTABLEENTRY_H
