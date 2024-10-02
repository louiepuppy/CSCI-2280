#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
using namespace std;

class Inventory
{
    protected:
        int itemnum;
        double itemprice;
    
    public:
        Inventory()
        {
            itemnum = 0;
            itemprice = 0.0;
        }

        Inventory(int n, double pr)
        {
            itemnum = n;
            itemprice = pr;
        }

        void showdata()
        {
            cout << endl;
            cout << "Item Number: " << itemnum << "\t\tItem Price: $" << itemprice << endl;
        }

        void getinventoryvalues(int a, double p)
        {
            itemnum = a;
            itemprice = p;
        }
};

#endif