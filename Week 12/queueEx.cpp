#include <iostream>
#include "IntQueue.h"
using namespace std;

int main()
{
    IntQueue iQueue(5);
    cout << "Enqueuing 5 items..." << endl;
    for (int i = 1; i <= 5; i++)
    {
        iQueue.enqueue(i*i);
    }
    cout << "Dequeueing items..." << endl;
    while (!iQueue.isEmpty())
    {
        int value;
        iQueue.dequeue(value);
        cout << value << " ";
    }
    cout << endl;
    return 0;
}