#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
using namespace std;

class Employee
{
    friend ostream &operator<<(ostream &out, const Employee &emp);
    friend istream &operator>>(istream &in, Employee &emp);

private:
    int num;
    double sal;

public:
    Employee(int id, double s);
};

Employee::Employee(int id = 0, double s = 0)
{
    num = id;
    sal = s;
}

ostream &operator<<(ostream &out, const Employee &emp)
{
    out << "Employee Number: " << emp.num << ", Salary: $" << emp.sal << endl;
    return out;
}

istream &operator>>(istream &in, Employee &emp)
{
    cout << "Enter employee number and salary: ";
    in >> emp.num >> emp.sal;
    return in;
}

#endif // EMPLOYEE_H