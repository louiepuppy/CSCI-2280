#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H
#include <iostream>
#include <cstdlib>
using namespace std;

class DynIntStack
{
private:
    struct StackNode
    {
        int value;
        StackNode *next;

        StackNode(int value1, StackNode *next1 = NULL)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode *top;

public:
    DynIntStack() {top = nullptr;}
    ~DynIntStack();
    void push(int);
    void pop(int&);
    bool isEmpty() const;

    // Stack Exception
    class Underflow {};
};

void DynIntStack::push(int num)
{
    top = new StackNode(num, top);
}

void DynIntStack::pop(int& num)
{
    StackNode *temp;

    if (isEmpty()) {throw DynIntStack::Underflow();}
    else
    {
        num = top->value;
        temp = top;
        top = top->next;
        delete temp;
    }
}

bool DynIntStack::isEmpty() const
{
    return top == nullptr;
}

DynIntStack::~DynIntStack()
{
    StackNode *garbage = top;
    while (garbage != nullptr)
    {
        top = top->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = top;
    }
}

#endif // DYNINTSTACK_H