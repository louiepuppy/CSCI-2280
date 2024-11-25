#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>
class DynStack
{
private:
    struct StackNode
    {
        T value;
        StackNode *next;

        StackNode(T value1, StackNode *next1 = NULL)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode *top;

public:
    DynStack() {top = nullptr;}
    ~DynStack();
    void push(T);
    void pop(T&);
    bool isEmpty() const;

    // Stack Exception
    class Underflow {};
};

template<typename T>
void DynStack<T>::push(T num)
{
    top = new StackNode(num, top);
}

template<typename T>
void DynStack<T>::pop(T& num)
{
    StackNode *temp;

    if (isEmpty()) {throw DynStack::Underflow();}
    else
    {
        num = top->value;
        temp = top;
        top = top->next;
        delete temp;
    }
}

template<typename T>
bool DynStack<T>::isEmpty() const
{
    return top == nullptr;
}

template<typename T>
DynStack<T>::~DynStack()
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

#endif // DYNSTACK_H