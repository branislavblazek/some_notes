#pragma once
#include <cstdio>
#include "Node.h"

class Input
{
    private:
        FILE* fHandle = nullptr;
    public:
        Input(const char* filename);
        ~Input();
        TYPE_OF_VALUE Read(const char* format);
};

