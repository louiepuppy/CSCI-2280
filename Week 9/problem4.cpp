#include <iostream>
using namespace std;

/* 
    Write a recursive function named sumSquares that returns the sum of the squares of the
    numbers from 0 to num, in which num is a nonnegative int variable. Do not use global
    variables; use the appropriate parameters. Also write a program to test your function.
*/

int sumSquares(int num);

int main()
{
    int num = 5;
    cout << "Sum of squares from 0 to " << num << " is: " << sumSquares(num) << endl;
    num = 13;
    cout << "Sum of squares from 0 to " << num << " is: " << sumSquares(num) << endl;
    return 0;
}

int sumSquares(int num)
{
    if (num == 0)
        return 0;
    else
        return num * num + sumSquares(num - 1);
}