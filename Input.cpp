#include "Input.h"

Input::Input(const char* filename)
{
    if (filename && *filename)
        fHandle = fopen(filename, "rt");
}

Input::~Input()
{
    if (fHandle != nullptr)
        fclose(fHandle);
    fHandle = nullptr;
}

TYPE_OF_VALUE Input::Read(const char* format)
{
    if (fHandle)
    {
        if (!feof(fHandle))
        {
            TYPE_OF_VALUE number;
            fscanf(fHandle, format, &number);
            return number;
        }
    }
    return INIT_VALUE;
}
