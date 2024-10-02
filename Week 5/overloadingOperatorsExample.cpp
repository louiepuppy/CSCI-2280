#include <iostream>
#include <fstream>
using namespace std;

class coord
{
    int x, y;

    friend ostream& operator<<(ostream&, coord&);
    friend istream& operator>>(istream&, coord&);
    friend coord operator-(coord&, coord&);

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
    coord operator=(coord&);
    bool operator==(coord&);
    bool operator>(coord&);
    bool operator<(coord&);

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

bool coord::operator==(coord& obj2)
{
    if (x == obj2.x && y == obj2.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

coord coord::operator=(coord& obj2)
{
    x = obj2.x;
    y = obj2.y;
    return obj2;
}

bool coord::operator<(coord& obj2)
{
    if (x < obj2.x && y < obj2.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool coord::operator>(coord& obj2)
{
    if (x > obj2.x && y > obj2.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

coord operator-(coord& obj1, coord& obj2)
{
    return coord(obj1.x - obj2.x, obj1.y - obj2.y);
}

ostream& operator<<(ostream& output, coord& obj)
{
    cout << "x = " << obj.x << ", y = " << obj.y;
    return output;
}

istream& operator>>(istream& input, coord& obj)
{
    cout << "Enter x and y: ";
    input >> obj.x >> obj.y;
    return input;
}



int main()
{
    coord object1(10, 10), object2(5, 3), object3;
    cout << "The value of object1 is " << endl;
    // object1.show();
    cout << object1 << endl;

    cout << "The value of object2 is " << endl;
    // object2.show();
    cout << object2 << endl;

    object3 = object1 + object2;
    cout << "The sum of object1 and object2 is " << endl;
    // object3.show();
    cout << object3 << endl;

    object3 = object1 - object2;
    cout << "The difference of object1 and object2 is " << endl;
    // object3.show();
    cout << object3 << endl;

    object3 = object1;
    cout << "The values of object1 have been copied to object3 is " << endl;
    // object3.show();
    cout << object3 << endl;

    cout << "Are object1 and object3 equal?" << (object1 == object3? "Yes" : "No") << endl;

    cout << "Is object1 greater than object2?" << (object1 > object2? "Yes" : "No") << endl;

    cout << "Is object1 less than object2?" << (object1 < object2? "Yes" : "No") << endl;

    cin >> object2;
    cout << "The new values of object2 is" << object2;
    cout << endl;
}