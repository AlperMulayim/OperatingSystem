//
// Created by Alper on 20.04.2017.
//

#ifndef GTUOSPROCESS_MEMORYOS_H
#define GTUOSPROCESS_MEMORYOS_H


#include "memoryBase.h"

class MemoryOS : public MemoryBase{

    private:
        uint8_t *osMemory;
        uint8_t *virtualMem;
    public:
        MemoryOS();
        ~MemoryOS();
        virtual uint8_t & at(uint32_t ind );
        virtual uint8_t & physicalAt(uint32_t ind);
};


#endif //GTUOSPROCESS_MEMORYOS_H
