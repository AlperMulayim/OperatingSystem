#ifndef H_GTUOS
#define H_GTUOS
#include <fstream>
#include "8080emuCPP.h"


class GTUOS{
	public:
		uint64_t handleCall(const CPU8080 & cpu);
		void PRINT_B(const CPU8080 &cpu);
		void PRINT_MEM(const CPU8080 &cpu);
        void READ_B(const CPU8080 &cpu);
        void READ_MEM(const CPU8080 &cpu);
        void PRINT_STR(const CPU8080 &cpu);
        void READ_STR(const CPU8080 &cpu);
        bool saveMemoryToFile(const CPU8080 &cpu);
        int getNumOfSystemCalls();

private:
    int cycleOfSystemCall = 0;
};

#endif
