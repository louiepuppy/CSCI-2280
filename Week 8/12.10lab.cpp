#include <iostream>
using namespace std;

/*
    Write a program that takes in three integers as inputs and outputs the largest value.
    Use a try block to perform all the statements. Use a catch block to catch any ios_base::failure
    caused by missing inputs and output the number of inputs read and the largest value.
    Output "No max" if no inputs are read.

    Note: Because inputs are pre-entered when running a program in the zyLabs environment,the system
    throws the ios_base::failure when inputs are missing. Test the program by running the program in the Develop mode.

    Hint: Use a counter to keep track of the number of inputs read and compare the inputs accordingly
    in the catch block when an exception is caught.
*/

int main() {
    cin.exceptions(ios::failbit); // Allow cin to throw exceptions
    int val1, val2, val3;
    int max;
    int inputCount = 0;
    
    val1 = 0;
    val2 = 0;
    val3 = 0;
    
    try {
        cout << "Enter up to three values: ";
        
        cin >> val1;
        inputCount += 1; 
        max = val1; 
        
        cin >> val2;
        inputCount += 1;
        if (val2 > max) {
            max = val2;
        }
        
        cin >> val3;
        inputCount += 1;
        if (val3 > max) {
            max = val3;
        }
    }
    catch (ios_base::failure&) {
        if (inputCount == 0) {
            cout << "No inputs read." << endl;
            cout << "No max" << endl;
        }
        else {
            cout << inputCount << " input(s) read." << endl;
            cout << "Max is " << max << endl;
        }
        return 0;
    }

    cout << "Max is " << max << endl;
    return 0;
}
