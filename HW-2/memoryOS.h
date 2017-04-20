//
// Created by Alper on 20.04.2017.
//

#ifndef GTUOSPROCESS_MEMORYOS_H
#define GTUOSPROCESS_MEMORYOS_H


#include "memoryBase.h"

class MemoryOS : public MemoryBase{
    public:
            virtual uint8_t & at(uint32_t) = 0;
            virtual uint8_t & physicalAt(uint32_t) = 0;
};


#endif //GTUOSPROCESS_MEMORYOS_H