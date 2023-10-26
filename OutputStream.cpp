#include <iostream>
#include "OutputStream.h"

OutputStream::OutputStream(const char* filename)
{
    if (filename && *filename)
        target = new std::ofstream(filename);
}

OutputStream::~OutputStream()
{
    delete target;
    target = nullptr;
}

void OutputStream::Write(TYPE_OF_VALUE pValue)
{
    if (target)
        *target << pValue << std::endl;
    else
        std::cout << pValue << std::endl;
}
