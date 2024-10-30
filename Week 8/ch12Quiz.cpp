#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

/*
    Write a program that prompts the user to enter time in 12-hour notation. The program then outputs the time
    in 24-hour notation. Your program must contain three exception classes: invalidHr, invalidMin, and invalidSec.
    If the user enters an invalid value for hours, then the program should throw and catch an invalidHr object.
    Similar conventions for the invalid values of minutes and seconds.
*/

class InvalidHr : public runtime_error 
{
public:
    InvalidHr(const string& what) : runtime_error(what) {}
};

class InvalidMin : public runtime_error 
{
public:
    InvalidMin(const string& what) : runtime_error(what) {}
};

class InvalidSec : public runtime_error 
{
public:
    InvalidSec(const string& what) : runtime_error(what) {}
};

int main() 
{
    int hrInput = -1;
    int minInput = -1;
    int secInput = -1;
    string AMPMInput;
    char continueProgram = 'y';

    int _24Hr;

    while (continueProgram != 'n')
    {
        while (hrInput <= 0 || hrInput > 12)
        {
            cout << "Enter hours: ";
            cin >> hrInput;

            try 
            {
                if (hrInput < 0 || hrInput > 12)
                    throw InvalidHr("Invalid hours. Enter a value between 1 and 12.");
            }
            catch (InvalidHr& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        
        while (minInput < 0 || minInput >= 60)
        {
            cout << "Enter minutes: ";
            cin >> minInput;

            try 
            {
                if (minInput < 0 || minInput >= 60)
                    throw InvalidMin("Invalid minutes. Enter a value between 0 and 59.");
            }
            catch (InvalidMin& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        
        while (secInput < 0 || secInput >= 60)
        {
            cout << "Enter seconds: ";
            cin >> secInput;

            try 
            {
                if (secInput < 0 || secInput >= 60)
                    throw InvalidSec("Invalid seconds. Enter a value between 0 and 59.");
            }
            catch (InvalidSec& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }

        while (AMPMInput != "AM" && AMPMInput != "PM")
        {
            cout << "Enter AM or PM: ";
            cin >> AMPMInput;

            transform(AMPMInput.begin(), AMPMInput.end(), AMPMInput.begin(), ::toupper);

            if (AMPMInput != "AM" && AMPMInput != "PM")
            {
                cout << "Invalid input. Enter 'AM' or 'PM'." << endl;
            }
        }

        if (AMPMInput == "AM")
        {
            _24Hr = (hrInput == 12) ? 0 : hrInput;
        }
        else if (AMPMInput == "PM")
        {
            _24Hr = (hrInput == 12) ? 12 : hrInput + 12;
        }

        cout << "Time in 24-hour notation: " << _24Hr << ":" << minInput << ":" << secInput << endl;

        hrInput = -1;
        minInput = -1;
        secInput = -1;
        AMPMInput = "";

        cout << "Would you like to try again? (y/n): ";
        cin >> continueProgram;
    }

    return 0;
}