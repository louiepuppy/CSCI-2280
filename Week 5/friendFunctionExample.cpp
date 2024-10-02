#include <iostream>
using namespace std;

class coord
{
    int x, y;

    friend void setxy(coord&, int, int);

    public:
        coord(int x = 0, int y = 0) : x(x), y(y) {}
        void display()
        {
            cout << " x = " << x << " and y = " << y << endl;
        }
};

void setxy(coord& points, int val1, int val2)
{
    points.x = val1;
    points.y = val2;
}

int main()
{
    int value1, value2;
    coord point1;
    cout << endl << "The value of object point is " << endl;
    point1.display();
    cout << endl << endl;

    cout << "Enter two values ";
    cin >> value1 >> value2;
    setxy(point1, value1, value2);
    cout << endl << "The updated value of object point is " << endl;
    point1.display();
    cout << endl;

    return 0;
}