#ifndef PATENT_H
#define PATENT_H

#include <iostream>
#include "inventory.h"
#include "employee.h"
using namespace std;

class Patent : public Inventory, public Employee
{
    private:
        int patentnum;
    
    public:
        Patent(): Inventory(), Employee()
        {
            patentnum = 0;
        }

        Patent(int a, int b, int c, double p, double s) : Inventory(a, p), Employee(b, s)
        {
            patentnum = c;
        }

        void showall()
        {
            cout << "Patent Number: " << patentnum << endl;
            Inventory::showdata();
            Employee::showdata();
        }

        void getpatentvalues(int a, int b, int c, double p, double s)
        {
            getinventoryvalues(a, p);
            getempvalues(b, s);
            patentnum = c;
        }
};

#endif