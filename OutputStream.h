#pragma once
#include <fstream>
#include "Node.h"

class OutputStream
{
    private:
        std::ofstream* target = nullptr;
    public:
        OutputStream(const char* filename);
        ~OutputStream();

        void Write(TYPE_OF_VALUE pValue);
};

