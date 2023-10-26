#include "InputStream.h"

InputStream::InputStream(const char* filename)
{
    if (filename && *filename)
    {
        source = new ifstream(filename);
    }
}

InputStream::~InputStream()
{
    delete source;
    source = nullptr;
}

TYPE_OF_VALUE InputStream::Read()
{
    TYPE_OF_VALUE    value;

    if (source && *source >> value)
        return value;
    return INIT_VALUE;
}
