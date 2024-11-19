#ifndef INTSTACK_H
#define INTSTACK_H
#include <iostream>
using namespace std;

class IntStack
{
private:
    int *stackArray;
    int stackSize;
    int top;

public:
    IntStack(int);
    ~IntStack();
    void push(int);
    void pop(int&);
    bool isFull();
    bool isEmpty();
};

IntStack::IntStack(int size)
{
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

IntStack::~IntStack()
{
    delete[] stackArray;
}

void IntStack::push(int num)
{
    if (isFull())
    {
        cout << "Stack is full. Cannot push " << num << endl;
    }
    else
    {
        top++;
        stackArray[top] = num;
    }
}

void IntStack::pop(int& num)
{
    if (isEmpty())
    {
        cout << "Stack is empty. Cannot pop" << endl;
    }
    else
    {
        num = stackArray[top];
        top--;
    }
}

bool IntStack::isFull()
{
    bool status;

    if (top == stackSize - 1)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    return status;
}

bool IntStack::isEmpty()
{
    bool status;
    if (top == -1)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    return status;
}

#endif