#include <iostream>
#include "cylinderType.h"
#include "circleType.h"
using namespace std;

int main()
{
    double r, h;
    circleType cir1(8);
    cir1.print();

    cylinderType c1, c2(5, 8);

    cout << endl << endl << "The info of Cylinder C1 is:" << endl;
    c1.print();
    cout << endl << endl;
    cout << "The info of Cylinder C2 is:" << endl;
    c2.print();

}