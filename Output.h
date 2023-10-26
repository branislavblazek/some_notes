#pragma once
#include "Node.h"
#include <cstdio>

class Output
{
    private:
        FILE* fHandle = nullptr;
    public:
        Output(const char* filename);
        ~Output();
        void Write(TYPE_OF_VALUE pValue, const char* format);
};

