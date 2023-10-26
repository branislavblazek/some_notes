#include "Core.h"

ComparePtr Core::GetCompare(char c)
{
    switch (c)
    {
        default:
        case 'a':
            return CompareAscent;
        case 'd':
            return CompareDescent;
    }
}

Core::~Core()
{
}
