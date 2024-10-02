#include <iostream>
#include "patent.h"
using namespace std;

int main()
{
    Patent NewItem(222, 333, 999, 2345, 3455), Item2;

    cout << "Here is the output of NewItem object" << endl;
    NewItem.showall();
    cout << endl;

    cout << "Here is the output of Item2 object" << endl;
    Item2.showall();
    cout << endl;

    cout << "Here is the output of Item2 object with values" << endl;
    Item2.getpatentvalues(555, 666, 888, 1235, 2870);
    Item2.showall();
    cout << endl;


}