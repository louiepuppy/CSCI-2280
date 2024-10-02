#ifndef circleType_H
#define circleType_H

#include <iostream>
using namespace std;

class circleType
{
    private:
        double radius;
    
    public:
        void setRadius(double);
        double getRadius();
        double area();
        double getDiameter();
        void print();
        double circumference();
        circleType(double r = 0);
};

// Implement member functions here
circleType::circleType(double r)
{
    setRadius(r);
}

void circleType::setRadius(double r)
{
    if (r >= 0)
    {
        radius = r;
    }
    else
    {
        radius = 0;
    }
}

double circleType::getRadius()
{
    return radius;
}

double circleType::area()
{
    return 3.14159 * radius * radius;
}

double circleType::getDiameter()
{
    return 2 * radius;
}

void circleType::print()
{
    cout << "Circle with radius " << radius << ":" << endl;
    cout << "Area: " << area() << endl;
    cout << "Diameter: " << getDiameter() << endl;
    cout << "Circumference: " << circumference() << endl << endl;
}

double circleType::circumference()
{
    return 2 * 3.14159 * radius;
}

#endif