#ifndef H_GTUOS
#define H_GTUOS
#include <fstream>
#include "8080emuCPP.h"
#include "ProcessTable.h"
#include "ProcessTable.h"
#include <string.h>

using namespace std;
class GTUOS{
public:
	GTUOS(string fileName);
	uint64_t handleCall(const CPU8080 & cpu);
	void PRINT_B(const CPU8080 &cpu);
	void PRINT_MEM(const CPU8080 &cpu);
	void READ_B(const CPU8080 &cpu);
	void READ_MEM(const CPU8080 &cpu);
	void PRINT_STR(const CPU8080 &cpu);
	void READ_STR(const CPU8080 &cpu);
	void FORK(const CPU8080 &cpu);
	void EXEC(const CPU8080 &cpu);
	void WAITPID(const CPU8080 &cpu);
	bool saveMemoryToFile(string filename,const CPU8080 &cpu);
	int getNumOfSystemCalls();
    void copyMemory(const CPU8080 &cpu,uint32_t startAdr,uint32_t limitStartAddr, uint32_t endAdr);
	ProcessTable processTable = ProcessTable(20);
private:
	int cycleOfSystemCall = 0;

};

#endif
