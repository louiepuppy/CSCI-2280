#include <iostream>
#include "DynIntQueue.h"
using namespace std;

int main()
{
    DynIntQueue iQueue;
    cout << "Enqueuing 5 items..." << endl;
    for (int i = 0; i < 5; i++)
    {
        iQueue.enqueue(i*i);
    }

    cout << "The values in the queue are: ";
    while (!iQueue.isEmpty())
    {
        int value;
        iQueue.dequeue(value);
        cout << value << " ";
    }
    cout << endl;
    return 0;
}