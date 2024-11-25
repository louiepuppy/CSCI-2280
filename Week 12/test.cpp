#include <iostream>
using namespace std;

void numSeries(int num)
{
    if (num == 0)
    {
        cout << 1 << " ";
    }
    else
    {
        numSeries(num - 1);
        num = num + 1;
        cout << num * 2 << " ";
    }
}

int main()
{
    numSeries(2);

    return 0;
}