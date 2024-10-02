#include <iostream>
#include <iomanip>
#include "circleType.h"
#include "cylinderType.h"
using namespace std;

int main()
{
    double r, h, v, shipCostPerLiter, paintCostPerSqFt, shipCost, paintCost;
    cylinderType container;

    // Get input from user for the dimensions of the container and the paint costs
    cout << "Enter the radius of the container (in feet): ";
    cin >> r;
    container.setRadius(r);
    cout << "Enter the height of the container (in feet): ";
    cin >> h;
    container.setHeight(h);
    cout << "Enter the cost per liter of shipment: $";
    cin >> shipCostPerLiter;
    cout << "Enter the paint cost per square foot: $"; // assuming entire container is painted, sides, top and bottom
    cin >> paintCostPerSqFt;
    cout << endl << endl;

    // reminder 1 cubic foot = 28.32 liters and 1 liter = 0.353146667 cubic feet.
    v = container.volume() * 28.32;
    shipCost = v * shipCostPerLiter;
    paintCost = container.area() * paintCostPerSqFt;

    // Display the results
    cout << fixed << setprecision(2);
    cout << "Cost of shipping: $" << shipCost << endl;
    cout << "Cost for painting container: $" << paintCost << endl;

    return 0;
}