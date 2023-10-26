//#include <crtdbg.h>

#include "List.h"
#include "Core.h"

List gzoznam;

int main(int argc, char* argv[])
{
    char* source = nullptr;
    char* target = nullptr;
    ComparePtr comparator = CompareAscent;

    if (argc > 1)
    {
        source = argv[1];
        if (argc > 2)
            target = argv[2];
        if (argc > 3)
        {
            comparator = Core().GetCompare(argv[3][0]);
        }
        List listOrder;
        listOrder.OrderStream(source, comparator);
        listOrder.WriteStream(target);
    }
    return 0;
}
