#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

/*
    A pedometer treats walking 2,000 steps as walking 1 mile. Write a StepsToMiles() function that takes the number of steps as an integer
    parameter and returns the miles walked as a double. The StepsToMiles() function throws a runtime_error object with the message
    "Exception: Negative step count entered." when the number of steps is negative. Complete the main() function that reads the number
    of steps from a user, calls the StepsToMiles() function, and outputs the returned value from the StepsToMiles() function.
    Use a try-catch block to catch any runtime_error object thrown by the StepsToMiles() function and output the exception message.

    Output each floating-point value with two digits after the decimal point, which can be achieved by executing
    cout << fixed << setprecision(2); once before all other cout statements.
*/

double stepsToMiles(int steps);

int main()
{
    int steps1, steps2;
    double milesWalked1, milesWalked2;

    cout << fixed << setprecision(2);

    cout << "Enter number of steps walked: ";
    cin >> steps1;
    try {
        milesWalked1 = stepsToMiles(steps1);
        cout << "Miles walked: " << milesWalked1 << endl;
    }
    catch (const runtime_error &e) {
        cout << e.what() << endl;
    }

    cout << "Enter number of steps walked again: ";
    cin >> steps2;
    try {
        milesWalked2 = stepsToMiles(steps2);
        cout << "Miles walked: " << milesWalked2 << endl;
    }
    catch (const runtime_error &e) {
        cout << e.what() << endl;
    }

    return 0;
}

double stepsToMiles(int steps)
{
    if (steps < 0)
    {
        throw runtime_error("Exception: Negative step count entered.");
    }
    return steps / 2000.0;
}
