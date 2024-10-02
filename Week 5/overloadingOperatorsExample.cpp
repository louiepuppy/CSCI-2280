#include <iostream>
using namespace std;

class coord
{
    int x, y;

public:
    coord(int i, int j)
    {
        x = i;
        y = j;
    }

    coord()
    {
        x = 0;
        y = 0;
    }

    coord operator+(coord ob2);

    void show()
    {
        cout << "x: " << x << ", y: " << y << endl
             << endl;
    }
};

coord coord::operator+(coord object2)
{
    coord temp;
    temp.x = x + object2.x;
    temp.y = y + object2.y;
    return temp;
}

int main()
{
    coord object1(10, 10), object2(5, 3), object3;
    cout << "The value of object1 is " << endl;
    object1.show();

    cout << "The value of object2 is " << endl;
    object2.show();

    object3 = object1 + object2;
    cout << "The sum of object1 and object2 is " << endl;
    object3.show();
}