#include <iostream>
#include "DynIntStack.h"
using namespace std;

int main()
{
    DynIntStack stack;
    int poppedValue;
    for (int i = 5; i <= 15; i = i + 5)
    {
        cout << "Pushing " << i << endl;
        stack.push(i);
    }
    cout << endl;

    for (int i = 1; i <= 3; i++)
    {
        cout << "Popping " << i << endl;
        stack.pop(poppedValue);
        cout << "Popped value: " << poppedValue << endl;
    }

    try
    {
        cout << "Attempting to pop again..." << endl;
        stack.pop(poppedValue);
    }
    catch (DynIntStack::Underflow)
    {
        cout << "Error: Stack underflow." << endl;
    }
    return 0;
}