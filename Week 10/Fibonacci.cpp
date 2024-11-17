#include <iostream>
using namespace std;

/*
    The Fibonacci sequence begins with 0 and then 1 follows. All subsequent values are
    the sum of the previous two, for example: 0, 1, 1, 2, 3, 5, 8, 13. Complete the
    Fibonacci() function, which takes in an index (starting at 0), n, and returns the
    nth value in the sequence. Any negative index values should return -1.
*/

int Fibonacci(int n)
{
    /* Type your code here. */
    if (n < 0)
        return -1;
    else if (n <= 1)
        return n;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int startNum;

    cin >> startNum;  
    cout << "Fibonacci(" << startNum << ") is " << Fibonacci(startNum) << endl;

    return 0;
}
