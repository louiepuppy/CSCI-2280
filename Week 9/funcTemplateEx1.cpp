#include <iostream>
#include <iomanip>
using namespace std;

template<typename T1>

T1 square(T1 num)
{
    return num * num;
}

int main()
{
    cout << setprecision(5) << fixed;

    cout << "Enter an integer: ";
    int iValue;
    cin >> iValue;

    cout << "The square is " << square(iValue) << endl;

    cout << "Enter a double: ";
    double dValue;
    cin >> dValue;
    
    cout << "The square is " << square(dValue) << endl;

    return 0;
}