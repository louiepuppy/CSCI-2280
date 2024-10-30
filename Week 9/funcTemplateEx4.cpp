#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

template <typename T>
void swap1(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void print(T a, T b)
{
    cout << "a: " << a << ", b: " << b << endl;
}

int main()
{
    int num1 = 20, num2 = 30;
    double val1 = 22.89, val2 = 33.99;
    string name1 = "John Doe", name2 = "Mary Lopez";
    Employee emp1(111, 450), emp2(222, 900);

    cout << "Before swapping integer values" << endl;
    print(num1, num2);
    swap1(num1, num2);
    cout << endl
         << "After swapping integer values" << endl;
    print(num1, num2);

    cout << endl
         << "Before swapping double values" << endl;
    print(val1, val2);
    swap1(val1, val2);
    cout << endl
         << "After swapping double values" << endl;
    print(val1, val2);

    cout << endl
         << "Before swapping string values" << endl;
    print(name1, name2);
    swap1(name1, name2);
    cout << endl
         << "After swapping string values" << endl;
    print(name1, name2);

    cout << endl
         << "Before swapping Employee objects" << endl;
    cout << emp1;
    cout << emp2;
    swap1(emp1, emp2);
    cout << endl
         << "After swapping Employee objects" << endl;
    cout << emp1;
    cout << emp2;

    return 0;
}