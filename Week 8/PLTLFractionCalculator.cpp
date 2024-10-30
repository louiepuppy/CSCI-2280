#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "fraction.h"
using namespace std;

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    fraction a, b, result;

    cout << "Fraction Calculator" << endl;
    cout << "-------------------" << endl;
    cout << "1. Add two fractions" << endl;
    cout << "2. Subtract two fractions" << endl;
    cout << "3. Multiply two fractions" << endl;
    cout << "4. Divide two fractions" << endl;
    cout << "5. Simplify a fraction" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    try
    {
        cin >> choice;
    }
    catch (invalid_argument& e)
    {
        cout << "Invalid input. Please enter a number." << endl;
        cin.clear();
        menu();
    }

    while (choice != 0)
    {
        try
        {
            switch (choice)
            {
            case 1:
                cin >> a >> b;
                result = a + b;
                cout << "Result: " << result << endl;
                break;
            case 2:
                cin >> a >> b;
                result = a - b;
                cout << "Result: " << result << endl;
                break;
            case 3:
                cin >> a >> b;
                result = a * b;
                cout << "Result: " << result << endl;
                break;
            case 4:
                cin >> a >> b;
                result = a / b;
                cout << "Result: " << result << endl;
                break;
            case 5:
                cin >> a;
                a.simplify();
                cout << "Simplified result: " << a << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                throw runtime_error("Invalid input.");
                break;
            }
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;
        }
        catch (const runtime_error& e)
        {
            cerr << "Error: " << e.what() << endl;
            cout << "Please try again." << endl;
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;
        }
    }
}
