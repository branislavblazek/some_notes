#pragma once
//#include <crtdbg.h>

#ifdef _DEBUG
#define DBGNEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DBGNEW new
#endif

int CompareAscent(const void* value1Ptr, const void* value2Ptr);
int CompareDescent(const void* value1Ptr, const void* value2Ptr);
typedef int (*ComparePtr)(const void* value1Ptr, const void* value2Ptr);


typedef double TYPE_OF_VALUE;
const TYPE_OF_VALUE INIT_VALUE = 0;

class Node
{
    private:
        TYPE_OF_VALUE value = INIT_VALUE;
        Node* next = nullptr;
    public:
        Node(TYPE_OF_VALUE pValue, Node* pNext);
        TYPE_OF_VALUE Value();
        void Value(TYPE_OF_VALUE pValue);

        Node* Next();
        void Next(Node* pNext);
};

