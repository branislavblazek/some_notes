#include "Output.h"

Output::Output(const char* filename)
{
    if (filename && *filename)
        fHandle = fopen(filename, "wt");
}

Output::~Output()
{
    if (fHandle)
        fclose(fHandle);
    fHandle = nullptr;
}

void Output::Write(TYPE_OF_VALUE pValue, const char* format)
{
    if (fHandle)
        fprintf(fHandle, format, pValue);
    else
        printf(format, pValue);
}
