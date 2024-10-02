#ifndef cylinderType_H
#define cylinderType_H

#include <iostream>
#include "circleType.h"
using namespace std;

class cylinderType : public circleType
{
    private:
        double height;
    
    public:
        void setHeight(double);
        double getHeight();
        double area();
        double volume();
        void print();
        double circumference();
        cylinderType(double r = 0, double h = 0);
};

// Implement member functions here
cylinderType::cylinderType(double r, double h)
{
    setRadius(r);
    setHeight(h);
}

void cylinderType::print()
{
    cout << "Cylinder with radius " << getRadius() << " and height " << height << ":" << endl;
    cout << "Area: " << area() << endl;
    cout << "Volume: " << volume() << endl;
    cout << "Circumference: " << circumference() << endl << endl;
}

void cylinderType::setHeight(double h)
{
    if (h >= 0)
    {
        height = h;
    }
    else
    {
        height = 0;
    }
}

double cylinderType::getHeight()
{
    return height;
}

double cylinderType::area()
{
    return (2 * 3.14159 * getRadius() * height) + (2 * 3.14159 * getRadius() * getRadius());
}

double cylinderType::volume()
{
    return 3.14159 * getRadius() * getRadius() * height;
}

double cylinderType::circumference()
{
    return 2 * 3.14159 * getRadius();
}

#endif // cylinderType_H