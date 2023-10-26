#include "Node.h"

Node::Node(TYPE_OF_VALUE pValue, Node* pNext)
    : value(pValue), next(pNext)
{
}

TYPE_OF_VALUE Node::Value()
{
    return value;
}

void Node::Value(TYPE_OF_VALUE pValue)
{
    value = pValue;
}

Node* Node::Next()
{
    return next;
}

void Node::Next(Node* pNext)
{
    next = pNext;
}

int CompareAscent(const void* value1Ptr, const void* value2Ptr)
{
    TYPE_OF_VALUE* ph1 = (TYPE_OF_VALUE*)value1Ptr;
    TYPE_OF_VALUE* ph2 = (TYPE_OF_VALUE*)value2Ptr;
    return *ph1 - *ph2;
}

int CompareDescent(const void* value1Ptr, const void* value2Ptr)
{
    return CompareAscent(value2Ptr, value1Ptr);
}
