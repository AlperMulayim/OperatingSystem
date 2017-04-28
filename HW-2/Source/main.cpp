#include <iostream>
#include "8080emuCPP.h"
#include "gtuos.h"
#include "memory.h"


using namespace std;

int main (int argc, char**argv)
{
	if (argc != 3){
		std::cerr << "Usage: prog exeFile debugOption\n";
		exit(1);
	}
	int DEBUG = atoi(argv[2]);

	OSMemory mem;
	CPU8080 theCPU(&mem);
	GTUOS theOS(argv[1],&mem);


	theCPU.ReadFileIntoMemoryAt(argv[1], 0x0000);
	unsigned emulatorCycle = 0;
	if(DEBUG == 0) {
		do {

			emulatorCycle +=  theCPU.Emulate8080p(DEBUG);
			theOS.setCurrentEmulatorCycle(emulatorCycle);
			if (theCPU.isSystemCall())
				theOS.handleCall(theCPU);
		} while (!theCPU.isHalted());

		printf("Cycle of System Calls : %d\n",theOS.getNumOfSystemCalls());
		printf("Emulator Cycle : %d\n",emulatorCycle);
		printf("Total Cycle : %d\n",emulatorCycle + theOS.getNumOfSystemCalls());
		printf("OS EMulator : %d\n",theOS.getTotalEmulatorCycle());
		printf("TOTAL  : %d\n",theOS.getTotalEmulatorCycle() + theOS.getNumOfSystemCalls());
		theOS.saveMemoryToFile(argv[1],theCPU);
        theOS.processTable.printProcessTable();
	}
	else if(DEBUG == 1){
		do {
			emulatorCycle = theCPU.Emulate8080p(DEBUG);
			if (theCPU.isSystemCall())
				theOS.handleCall(theCPU);
		} while (!theCPU.isHalted());

		printf("Cycle of System Calls : %d\n",theOS.getNumOfSystemCalls());
		printf("Emulator Cycle : %d\n",emulatorCycle);
		printf("Total Cycle : %d\n",emulatorCycle + theOS.getNumOfSystemCalls());

		theOS.saveMemoryToFile(argv[1],theCPU);

	}else if(DEBUG == 2){
		do { //press enter for debug mod
			emulatorCycle = theCPU.Emulate8080p(DEBUG);
			if (theCPU.isSystemCall()) {
				theOS.handleCall(theCPU);
				cin.get();
			}
			cin.get();
		} while (!theCPU.isHalted());
		printf("Cycle of System Calls : %d\n",theOS.getNumOfSystemCalls());
		printf("Emulator Cycle : %d\n",emulatorCycle);
		printf("Total Cycle : %d\n",emulatorCycle + theOS.getNumOfSystemCalls());
	}
    else if(DEBUG == 3){
        do { //press enter for debug mod
            emulatorCycle = theCPU.Emulate8080p(DEBUG);
            if (theCPU.isSystemCall()) {
                theOS.handleCall(theCPU);
            }
        } while (!theCPU.isHalted());
        printf("Cycle of System Calls : %d\n",theOS.getNumOfSystemCalls());
        printf("Emulator Cycle : %d\n",emulatorCycle);
        printf("Total Cycle : %d\n",emulatorCycle + theOS.getNumOfSystemCalls());

        theOS.processTable.printProcessTable();
        theOS.saveMemoryToFile(argv[1],theCPU);
    }

	return 0;
}


