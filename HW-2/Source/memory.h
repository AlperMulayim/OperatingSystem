#ifndef H_OSMemory
#define H_OSMemory

#include "MemoryBase.h"
#include <iostream>

using namespace std;
class OSMemory : public MemoryBase {

public:
	OSMemory();
	~OSMemory();
	virtual uint8_t & at(uint32_t ind);
	virtual uint8_t & physicalAt(uint32_t ind);
	int getBaseRegister() const;
	void setBaseRegister(int baseRegister);
	int getLimitRegister() const;
	void setLimitRegister(int limitRegister);

private:
	uint8_t * mem;
	int baseRegister;
	int limitRegister;
};

#endif


