#include <iostream>
#include "IntStack.h"
using namespace std;

int main()
{
    IntStack stack(5);
    int catchVar;

    cout << "Pushing 5" << endl;
    stack.push(5);
    cout << "Pushing 10" << endl;
    stack.push(10);
    cout << "Pushing 15" << endl;
    stack.push(15);
    cout << "Pushing 20" << endl;
    stack.push(20);
    cout << "Pushing 25" << endl;
    stack.push(25);
    cout << "Pushing 30" << endl;
    stack.push(30);

    cout << "Popping..." << endl;
    stack.pop(catchVar);
    cout << catchVar << endl;
    stack.pop(catchVar);
    cout << catchVar << endl;
    stack.pop(catchVar);
    cout << catchVar << endl;
    stack.pop(catchVar);
    cout << catchVar << endl;
    stack.pop(catchVar);
    cout << catchVar << endl;
    stack.pop(catchVar);
    cout << catchVar << endl;

    return 0;
}