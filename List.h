#pragma once
#include "Node.h"

class List
{
    private:
        Node* start = nullptr;
    public:
        ~List();
        void Order(const char* filename, ComparePtr pComparator);
        void OrderStream(const char* filename, ComparePtr pComparator);
        void Write(const char* filename);
        void WriteStream(const char* filename);
        void Print();
        void PrintStream();
    private:
        void MoveValueIntoList(TYPE_OF_VALUE value, ComparePtr pComparator);
        void Delete(Node* pNode);
        void Delete();
};

