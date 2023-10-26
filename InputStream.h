#pragma once
#include <fstream>
#include "Node.h"

using namespace std;

class InputStream
{
    private:
        ifstream* source = nullptr;
    public:
        InputStream(const char* filename);
        ~InputStream();
        TYPE_OF_VALUE Read();
};

