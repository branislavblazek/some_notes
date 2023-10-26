#include "List.h"
#include "Input.h"
#include "Output.h"
#include "InputStream.h"
#include "OutputStream.h"

void List::Order(const char *filename, ComparePtr pComparator)
{
    Input* reader = DBGNEW Input(filename);
    TYPE_OF_VALUE value = reader->Read("%d");
    while (value != INIT_VALUE)
    {
        MoveValueIntoList(value, pComparator);
        value = reader->Read("%d");
    }
    delete reader;
}

void List::OrderStream(const char* filename, ComparePtr pComparator)
{
    InputStream* readerStream = DBGNEW InputStream(filename);
    TYPE_OF_VALUE value = readerStream->Read();
    while (value != INIT_VALUE)
    {
        MoveValueIntoList(value, pComparator);
        value = readerStream->Read();
    }
    delete readerStream;
}

void List::Write(const char* filename)
{
    Output* writer = DBGNEW Output(filename);
    Node* helper = start;
    while (helper != nullptr)
    {
        writer->Write(helper->Value(), "%d\n");
        helper = helper->Next();
    }
    delete writer;
}

void List::WriteStream(const char* filename)
{
    OutputStream* writerStream = DBGNEW OutputStream(filename);
    Node* helper = start;
    while (helper != nullptr)
    {
        writerStream->Write(helper->Value());
        helper = helper->Next();
    }
    delete writerStream;
}

void List::Print()
{
    Write(nullptr);
}

void List::PrintStream()
{
    WriteStream(nullptr);
}

void List::MoveValueIntoList(TYPE_OF_VALUE value, ComparePtr pComparator)
{
    if (!start)
    {
        start = DBGNEW Node(value, nullptr);
    }
    else
    {
        Node* before = nullptr;
        Node* after = start;
        TYPE_OF_VALUE actualValue = after->Value();
        while (after != nullptr && pComparator(&value, &actualValue) > 0)
        {
            before = after;
            after = after->Next();
            if (after != nullptr)
                actualValue = after->Value();
        }
        Node* newNode = DBGNEW Node(value, after);
        if (before != nullptr)
            before->Next(newNode);
        else
            start = newNode;
    }
}

List::~List()
{
    if (start != nullptr)
        Delete();
}


void List::Delete(Node* pNode)
{
    if (pNode->Next() != nullptr)
        Delete(pNode->Next());
    delete pNode;
}

void List::Delete()
{
    Node* helperDelete = start;
    while (helperDelete != nullptr)
    {
        Node* helper = helperDelete->Next();
        delete helperDelete;
        helperDelete = helper;
    }
}
