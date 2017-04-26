#ifndef H_MEMORY
#define H_MEMORY

#include "memoryBase.h"
#include <iostream>

using namespace std;
class memory: public MemoryBase {

public:
	memory();
	~memory();
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


