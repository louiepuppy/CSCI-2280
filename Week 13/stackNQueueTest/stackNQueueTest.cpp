#include <iostream>
#include <string>
#include "DynQueue.h"
#include "DynStack.h"
#include "Employee.h"
using namespace std;

int main()
{
    int choice = -1;
    Employee employee;
    DynQueue<Employee> employeeQueue;
    DynStack<Employee> employeeStack;
    DynQueue<int> intQueue;
    DynStack<int> intStack;
    DynQueue<char> charQueue;
    DynStack<char> charStack;
    DynQueue<string> stringQueue;
    DynStack<string> stringStack;
    int intVal;
    string strVal;
    char charVal;

    while (choice != 0)
    {
        cout << "Dynamic Queue and Stack Example" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Add employee to queue" << endl;
        cout << "2. Remove employee from queue" << endl;
        cout << "3. Add employee to stack" << endl;
        cout << "4. Remove employee from stack" << endl;
        cout << "5. Display employees in queue" << endl;
        cout << "6. Display employees in stack" << endl;
        cout << "7. Test stacks and queues" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        DynQueue<Employee> tempQueue = employeeQueue;
        DynStack<Employee> tempStack = employeeStack;

        switch (choice)
        {
        case 1:
            cout << "Enter employee info:" << endl;
            cin >> employee;
            employeeQueue.enqueue(employee);
            cout << "Employee successfully enqueued." << endl
                 << endl;
            break;
        case 2:
            if (!employeeQueue.isEmpty())
            {
                employeeQueue.dequeue(employee);
                cout << "Employee dequeued: \n"
                     << employee << endl
                     << endl;
            }
            else
            {
                cout << "Queue is empty. Cannot dequeue." << endl
                     << endl;
            }
            break;
        case 3:
            cout << "Enter employee information:" << endl;
            cin >> employee;
            employeeStack.push(employee);
            cout << "Employee successfully pushed." << endl
                 << endl;
            break;
        case 4:
            if (!employeeStack.isEmpty())
            {
                employeeStack.pop(employee);
                cout << "Employee popped: \n"
                     << employee << endl
                     << endl;
            }
            else
            {
                cout << "Stack is empty. Cannot pop." << endl
                     << endl;
            }
            break;
        case 5:
            while (!tempQueue.isEmpty())
            {
                tempQueue.dequeue(employee);
                cout << employee << endl;
            }
            cout << endl
                 << "Displayed all employees in the queue." << endl
                 << endl;
            break;
        case 6:
            while (!tempStack.isEmpty())
            {
                tempStack.pop(employee);
                cout << employee << endl;
            }
            cout << endl
                 << "Displayed all employees in the stack." << endl
                 << endl;
            break;
        case 7:
            cout << "Enqueuing 5 integers." << endl;
            for (int i = 1; i <= 5; i++)
            {
                intQueue.enqueue(i*i);
            }
            cout << "Dequeuing 3 integers." << endl;
            for (int i = 0; i < 3; i++)
            {
                intQueue.dequeue(intVal);
                cout << "Dequeued integer: " << intVal << endl;
            }

            cout << endl
                 << "Stacking 5 integers." << endl;
            for (int i = 1; i <= 5; i++)
            {
                intStack.push(i*i);
            }
            cout << "Popping 3 integers." << endl;
            for (int i = 0; i < 3; i++)
            {
                intStack.pop(intVal);
                cout << "Popped integer: " << intVal << endl;
            }

            cout << endl
                 << "Enqueuing 5 characters." << endl;
            for (char c = 'a'; c <= 'e'; c++)
            {
                charQueue.enqueue(c);
            }
            cout << "Dequeuing 3 characters." << endl;
            for (int i = 0; i < 3; i++)
            {
                charQueue.dequeue(charVal);
                cout << "Dequeued character: " << charVal << endl;
            }

            cout << endl
                 << "Stacking 5 characters." << endl;
            for (char c = 'a'; c <= 'e'; c++)
            {
                charStack.push(c);
            }
            cout << "Popping 3 characters." << endl;
            for (int i = 0; i < 3; i++)
            {
                charStack.pop(charVal);
            }

            cout << endl
                 << "Enqueuing 5 strings." << endl;
            for (int i = 1; i <= 5; i++)
            {
                stringQueue.enqueue("String " + to_string(i));
            }
            cout << "Dequeuing 3 strings." << endl;
            for (int i = 0; i < 3; i++)
            {
                stringQueue.dequeue(strVal);
                cout << "Dequeued string: " << strVal << endl;
            }

            cout << endl
                 << "Stacking 5 strings." << endl;
            for (int i = 1; i <= 5; i++)
            {
                stringStack.push("String " + to_string(i));
            }
            cout << "Popping 3 strings." << endl;
            for (int i = 0; i < 3; i++)
            {
                stringStack.pop(strVal);
                cout << "Popped string: " << strVal << endl;
            }
            
            cout << "All tests completed successfully." << endl
                 << endl;
            break;
        case 0:
            cout << "Displaying final contents of stack and queue." << endl;
            while (!employeeQueue.isEmpty())
            {
                employeeQueue.dequeue(employee);
                cout << "Employee dequeued: \n"
                     << employee << endl;
            }
            cout << endl;
            while (!employeeStack.isEmpty())
            {
                employeeStack.pop(employee);
                cout << "Employee popped: \n"
                     << employee << endl;
            }
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Not a choice. Please enter a new number." << endl;
            break;
        }
    }
    return 0;
}