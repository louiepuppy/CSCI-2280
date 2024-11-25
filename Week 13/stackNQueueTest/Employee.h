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
    int idNum;
    double salary;
    string name;

public:
    Employee(int idnum = 0, double s = 0, string name = "");
    void get_Employee() const;
};

Employee::Employee(int id, double s, string name)
{
    idNum = id;
    salary = s;
}

ostream &operator<<(ostream &out, const Employee &emp)
{
    out << emp.name << ", ID: " << emp.idNum << ", Salary: $" << emp.salary << endl;
    return out;
}

istream &operator>>(istream &in, Employee &emp)
{
    cout << "Enter employee ID and salary: ";
    in >> emp.idNum >> emp.salary;
    return in;
}

void Employee::get_Employee() const
{
    cout << name << ", ID: " << idNum << ", Salary: $" << salary << endl;
}

#endif // EMPLOYEE_H