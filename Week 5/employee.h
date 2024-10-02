#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
    protected:
        int empnum;
        double empsal;
    
    public:
        Employee()
        {
            empnum = 0;
            empsal = 0.0;
        }

        Employee(int n, double sal)
        {
            empnum = n;
            empsal = sal;
        }

        void showdata()
        {
            cout << "Employee Number: " << empnum << "\t\tEmployee Salary: $" << fixed << setprecision(2) << empsal << endl;
        }

        void getempvalues(int n, double s)
        {
            empnum = n;
            empsal = s;
        }
};

#endif