#ifndef H_GTUOS
#define H_GTUOS
#include <fstream>
#include "8080emuCPP.h"
#include "ProcessTable.h"
#include "ProcessTable.h"
#include "memory.h"
#include <string.h>

using namespace std;
class GTUOS{

public:
	GTUOS(string fileName,OSMemory *mainMemory);
	uint64_t handleCall(CPU8080 & cpu);
	void PRINT_B(const CPU8080 &cpu);
	void PRINT_MEM(const CPU8080 &cpu);
	void READ_B(const CPU8080 &cpu);
	void READ_MEM(const CPU8080 &cpu);
	void PRINT_STR(const CPU8080 &cpu);
	void READ_STR(const CPU8080 &cpu);
	void FORK(const CPU8080 &cpu);
	void EXEC( CPU8080 &cpu);
	void WAITPID(const CPU8080 &cpu);
	bool saveMemoryToFile(string filename,const CPU8080 &cpu);
	int getNumOfSystemCalls();
    void copyMemory(const CPU8080 &cpu,uint32_t startAdr,uint32_t limitStartAddr, uint32_t endAdr);
	int getTotalEmulatorCycle() const;
	void setTotalEmulatorCycle(int totalEmulatorCycle);
	int getCurrentEmulatorCycle() const;
	void setCurrentEmulatorCycle(int currentEmulatorCycle);

	ProcessTable processTable = ProcessTable(20);
	OSMemory *memory;

private:
	int currentEmulatorCycle = 0;
	int cycleOfSystemCall = 0;
	int totalEmulatorCycle = 0;

};

#endif
